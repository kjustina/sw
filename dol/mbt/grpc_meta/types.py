import json
import re
import string
import random
import pdb
import os

from google.protobuf import json_format
from google.protobuf.descriptor import FieldDescriptor

#This is bad design but when right now object generation is tied to the types
import config_mgr

_tag_checker_map = {
     "key_field"     : lambda x, y : (x == "gogoproto.moretags" or x == "gogoproto.jsontag") and "key" in y,
     "ext_ref_field" : lambda x, y : (x == "gogoproto.moretags" or x == "gogoproto.jsontag") and "ref" in y,
     "api_field"     : lambda x, y : x  == "gogoproto.moretags" and "api_status" in y,
     "handle_field"  : lambda x, y : x  == "gogoproto.moretags" and "handle" in y,
     "unique_field"  : lambda x, y : x  == "gogoproto.moretags" and "unique" in y,
     "range_field"   : lambda x, y : x  == "gogoproto.moretags" and "range" in y,
}

def _tag_checker_helper(field, option_checker):
    if not field:
        return
    options = field.GetOptions()
    if options:
        for sub_field, value in options.ListFields():
            if option_checker(sub_field.full_name, value):
                return True
    
def is_key_field(field):
    return _tag_checker_helper(field, _tag_checker_map["key_field"])

def is_api_status_field(field):
    return _tag_checker_helper(field, _tag_checker_map["api_field"])

def is_ext_ref_field(field):
    return _tag_checker_helper(field, _tag_checker_map["ext_ref_field"])

def is_handle_field(field):
    return _tag_checker_helper(field, _tag_checker_map["handle_field"])
                        
def is_range_field(field):
    return _tag_checker_helper(field, _tag_checker_map["range_field"])

def is_unique_field(field):
    return _tag_checker_helper(field, _tag_checker_map["unique_field"])

def get_constraints(field):
    options = field.GetOptions().__str__()
    if 'constraint' in options:
        constraints = re.search(r'(?<=constraints=\{).*?(?=\})', options).group(0)
        if '==' in options:
            return constraints.split('==')
        else:
            return constraints.split('=')
    return None

def generate_float(field):
    return random.uniform(0.0, 99999.99)
    
def generate_int(field):
    if is_range_field(field):
        range_str = field.GetOptions().__str__().split(":")[-1].strip()
        range_str = range_str.replace("\"", "")
        range_str = range_str.split("-")
        return random.randint(int(range_str[0]), int(range_str[1]))
    return random.randint(0, 99999)

def generate_bool(field):
    return random.choice([True, False])

def generate_string(field):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for _ in range(16))

def generate_enum(field):
    return random.randint(0, len(field.enum_type.values))

def generate_bytes(field):
    return os.urandom(16)

type_map = {
    FieldDescriptor.TYPE_DOUBLE: generate_float,
    FieldDescriptor.TYPE_FLOAT: generate_float,
    FieldDescriptor.TYPE_INT32: generate_int,
    FieldDescriptor.TYPE_INT64: generate_int,
    FieldDescriptor.TYPE_UINT32: generate_int,
    FieldDescriptor.TYPE_UINT64: generate_int,
    FieldDescriptor.TYPE_SINT32: generate_int,
    FieldDescriptor.TYPE_SINT64: generate_int,
    FieldDescriptor.TYPE_FIXED32: generate_int,
    FieldDescriptor.TYPE_FIXED64: generate_int,
    FieldDescriptor.TYPE_SFIXED32: generate_int,
    FieldDescriptor.TYPE_SFIXED64: generate_int,
    FieldDescriptor.TYPE_BOOL: generate_bool,
    FieldDescriptor.TYPE_STRING: generate_string,
    FieldDescriptor.TYPE_BYTES: generate_bytes,
    FieldDescriptor.TYPE_ENUM: generate_enum,
}

class GrpcMetaField:
    _meta_fields_ = {}
    def __init__(self, grpc_field = None):
        self.ext_ref = None
        self.type = None
        self.label = None
        self.options = grpc_field.GetOptions() if grpc_field else None
        self._grpc_field = grpc_field
        self._ext_ref = None
        self.oneOf = False
        self.containingOneof = None
        self.constraints = None
        self.full_name = None
    
    def __repr__(self):
        return json.dumps({"type" : str(self.type), "label" : self.label})
    
    @classmethod
    def factory(cls, meta_field):
        try:
            return cls._meta_fields_[meta_field]
        except KeyError:
            print (meta_field)
            assert 0

    @classmethod
    def register(cls, meta_field):
        def decorator(subclass):
            cls._meta_fields_[meta_field] = subclass
            return subclass
        return decorator

    def process_data(self, message):
        return self.type.process_data(message)
    
    def generate_data(self, key=None, ext_refs=None, is_key_field=False, constraints=None):
        # if self._ext_ref:
        #     #if There is an external Reference,
        #     return config_mgr.GetRandomConfigObjectByKeyType(self._ext_ref)
        return self.type.generate_data(key, ext_refs, self.is_key_field(), constraints=constraints)
    
    def is_field_handle(self):
        return is_handle_field(self._grpc_field)
        if self.options:
            for field, value in self.options.ListFields():
                if field.full_name == "gogoproto.jsontag" and value == "handle":
                    return True

    def is_key_field(self):
        return is_key_field(self._grpc_field)
                    
    def is_ext_ref_field(self):
        return is_ext_ref_field(self._grpc_field)

    def is_unique_field(self):
        return is_unique_field(self._grpc_field)

    def get_range(self):
        if self.options:
            for field, value in self.options.ListFields():
                if _tag_checker_map["range_field"](field.full_name, value):
                    range_str = value.split(":")[1].split("-")
                    return int(range_str[0]), int(range_str[1])
                    
        return 0, 99999
    
@GrpcMetaField.register(FieldDescriptor.CPPTYPE_UINT32)
class GrpcMetaFieldUint32(GrpcMetaField):
    
    def __init__(self, grpc_field):
        super(GrpcMetaFieldUint32, self).__init__(grpc_field)
        self.type = FieldDescriptor.CPPTYPE_UINT32
        self._range = self.get_range()

    def process_data(self, message):
        return message
        
    def generate_data(self, key, ext_refs, is_key_field=False, constraints=None):
        return  random.randint(self._range[0], self._range[1])

@GrpcMetaField.register(FieldDescriptor.CPPTYPE_UINT64)
class GrpcMetaFieldUint64(GrpcMetaField):
    
    def __init__(self, grpc_field):
        super(GrpcMetaFieldUint64, self).__init__(grpc_field)
        self.type = FieldDescriptor.CPPTYPE_UINT64

    def process_data(self, message):
        return message
    
    def generate_data(self, key, ext_refs, is_key_field=False, constraints=None):
        return  random.randint(0, 99999)

@GrpcMetaField.register(FieldDescriptor.CPPTYPE_STRING)
class GrpcMetaFieldString(GrpcMetaField):
    
    def __init__(self, grpc_field):
        super(GrpcMetaFieldString, self).__init__(grpc_field)
        self.type = FieldDescriptor.CPPTYPE_STRING

    def process_data(self, message):
        return message
    
    def generate_data(self, key, ext_refs, is_key_field=False, constraints=None):
        letters = string.ascii_lowercase
        return ''.join(random.choice(letters) for _ in range(16))
        
@GrpcMetaField.register(FieldDescriptor.CPPTYPE_BOOL)
class GrpcMetaFieldBool(GrpcMetaField):
    
    def __init__(self, grpc_field):
        super(GrpcMetaFieldBool, self).__init__(grpc_field)
        self.type = FieldDescriptor.CPPTYPE_BOOL

    def process_data(self, message):
        return message
    
    def generate_data(self, key, ext_refs, is_key_field=False, constraints=None):
        return random.choice([True, False])

@GrpcMetaField.register(FieldDescriptor.CPPTYPE_ENUM)
class GrpcMetaFieldEnum(GrpcMetaField):
    
    def __init__(self, grpc_field):
        super(GrpcMetaFieldEnum, self).__init__(grpc_field)
        self.type = FieldDescriptor.CPPTYPE_ENUM

    def process_data(self, message):
        return message
    
    def generate_data(self, key, ext_refs, is_key_field=False, constraints=None):
        enum_value = random.randint(0, len(self._grpc_field.enum_type.values) - 1)
        return self._grpc_field.enum_type.values[enum_value].name


