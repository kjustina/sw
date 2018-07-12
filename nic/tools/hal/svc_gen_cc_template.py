//:: import os
//:: import importlib
//:: import sys
//::
#include "nic/include/hal_cfg.hpp"
#include "nic/include/base.hpp"
#include "nic/include/trace.hpp"
#include "nic/include/hal_state.hpp"
//::
//::  file_name_prefix = fileName.replace('_pb2.py', '')
//::  hdr_file = file_name_prefix + '_svc_gen.hpp'
//::  plugin_files = ["l2segment", "vrf", "qos", "endpoint", "nat", "telemetry", "multicast", "nwsec", "nw", "acl"]
//::
#include "nic/gen/hal/svc/${hdr_file}"
//::
//:: if 'WS_TOP' not in os.environ:
//::     # This should have been set, before invoking the template.
//::     assert False
//:: #endif
//:: # Add the proto directory to the path.
//:: ws_top = os.environ['WS_TOP']
//:: fullpath = ws_top + '/nic/gen/proto/hal/'
//:: sys.path.insert(0, fullpath)
//::
//:: def write_api_stats_enum(enumC, hal_name):
//::     stats_file_path = ws_top + '/nic/gen/hal/include/hal_api_stats.hpp'
//::     stats_file = open(stats_file_path, "a")
//::     hal_name_upper = hal_name.upper();
//::     e1 = "ENTRY(HAL_API_"
//::     e2 = hal_name_upper
//::     e3 = ","
//::     e4 = "_SUCCESS,"
//::     e5 = "_FAIL,"
//::     enum_str = str(enumC) + ","
//::     enum_name = "\"" + hal_name + " call\")"
//::     stats_file.write("\t%-69s%-4s %-50s\t\\\r\n" % (e1 + e2 + e3, enum_str, enum_name))
//::     enumC = enumC + 1
//::     enum_str = str(enumC) + ","
//::     enum_name = "\"" + hal_name + " success\")"
//::     stats_file.write("\t%-69s%-4s %-50s\t\\\r\n" % (e1 + e2 + e4, enum_str, enum_name))
//::     enumC = enumC + 1
//::     enum_str = str(enumC) + ","
//::     enum_name = "\"" + hal_name + " fail\")"
//::     stats_file.write("\t%-69s%-4s %-50s\t\\\r\n" % (e1 + e2 + e5, enum_str, enum_name))
//:: #enddef
//::
//:: def convert_to_snake_case(name, fileName, input_name, output_name):
//::     import re
//::     import os
//::     global ws_top
//::     global file_name_prefix
//::     global plugin_files
//::     s1 = re.sub('([A-Z])(.)', r'\1_\2', name[::-1], 1).lower()
//::     s1 = s1[::-1]
//::     s2 = re.sub('([a-z0-9])([A-Z])', r'\1_\2', name).lower()
//::     if file_name_prefix in plugin_files:
//::        hal_src_path = ws_top + '/nic/hal/plugins/cfg/'
//::     else:
//::        hal_src_path = ws_top + '/nic/hal/src/'
//::     #endif
//::     for root, dirs, files in os.walk(hal_src_path):
//::         for file_name in files:
//::            if file_name.endswith('.hpp') and file_name_prefix in file_name:
//::                contents = open(os.path.join(root, file_name)).read()
//::                if re.search(r'\b{0}\b'.format(s1), contents):
//::                    return s1
//::                #endif
//::                if re.search(r'\b{0}\b'.format(s2), contents):
//::                    print ('using ' + s2 + ' in ' + file_name + ' proto: ' + fileName + 'root: ' + os.path.basename(root))
//::                    return s2
//::                #endif
//::                if file_name == (file_name_prefix + '.hpp'):
//::                    print ('could NOT find method ' + s1 + ' or ' + s2 + ' in ' + file_name + ' proto: ' + fileName)
//::                #endif
//::            #endif
//::         #endfor
//::     #endfor
//:: #enddef
//::
//:: def get_src_dir(fileName):
//::    import os
//::    global file_name_prefix
//::    global plugin_files
//::    if file_name_prefix in plugin_files:
//::        hal_src_path = ws_top + '/nic/hal/plugins/cfg/'
//::    else:
//::        hal_src_path = ws_top + '/nic/hal/src/'
//::    #endif
//::    for root, dirs, files in os.walk(hal_src_path):
//::        for file_name in files:
//::            if file_name == (file_name_prefix + '.hpp'):
//::                # print ('get_src_dir: file_name: ' + file_name + ', fileName: ' + file_name_prefix + ', root: ' + root)
//::                return os.path.basename(root)
//::            #endif
//::        #endfor
//::    #endfor
//:: #enddef
//::
//::
//::
//:: fileModule = importlib.import_module(fileName[:-3])
//:: includeFileName = fileName[:-7]
//:: src_dir_name = get_src_dir(fileName)
//::
//:: if includeFileName in plugin_files:
#include "nic/hal/plugins/cfg/${src_dir_name}/${includeFileName}.hpp"
//::
//:: else:
//::
#include "nic/hal/src/${src_dir_name}/${includeFileName}.hpp"
//::
//:: #endif
//::
//:: enumC = int(enumCount)
//:: for service in fileModule.DESCRIPTOR.services_by_name.items():
//::     pkg = fileModule.DESCRIPTOR.package.lower()
//::
using grpc::ServerContext;
using grpc::Status;
using ${pkg}::${service[0]};
//::
//::     for method in service[1].methods_by_name.items():
//::         input_name  = pkg + '::' + method[1].input_type.name
//::         output_name = pkg + '::' + method[1].output_type.name
//::         repeated_field = False
//::         for field in method[1].output_type.fields:
//::             field_name = field.name
//::             if field.type == 11:
//::                 repeated_field = True
//::             else:
//::                 print ('***** RESPONSE NOT REPEATED: ' + pkg)
//::             #endif
//::         #endfor
//::         hal_name = convert_to_snake_case(method[0], fileName, input_name, output_name)
//::         hal_name_upper = hal_name.upper();
//::         if 'Get' in method[0]:
//::             op = 'CFG_OP_READ'
//::             repeated_field = False
//::         else:
//::             op = 'CFG_OP_WRITE'
//::         #endif
//::
Status
${service[0]}ServiceImpl::${method[0]}(ServerContext *context,
                                       const ${input_name} *req,
                                       ${output_name} *rsp)
{
    uint32_t    i, nreqs = req->request_size();

    HAL_TRACE_DEBUG("Rcvd ${method[0]}");
    if (nreqs == 0) {
        return Status(grpc::StatusCode::INVALID_ARGUMENT, "Empty Request");
    }
//::    write_api_stats_enum(enumC, hal_name)
//::    enumC = enumC + 3

    HAL_API_STATS_ADD(hal::HAL_API_${hal_name_upper}, nreqs);
    hal::hal_cfg_db_open(hal::${op});
    for (i = 0; i < nreqs; i++) {
        auto request = req->request(i);
//::
//::             if repeated_field == True:
//::
        auto response = rsp->add_response();
        hal::${hal_name}(request, response);
//::
//::             else:
//::
        hal::${hal_name}(request, rsp);
//::
//::             #endif
//::
    }
    hal::hal_cfg_db_close();
    return Status::OK;
}
//::
//::     #endfor
//:: #endfor
