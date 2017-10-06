package networkencryptionGwService

import (
	"github.com/GeertJohan/go.rice/embedded"
	"time"
)

func init() {

	// define files
	file2 := &embedded.EmbeddedFile{
		Filename:    "networkencryption.swagger.json",
		FileModTime: time.Unix(1507254003, 0),
		Content:     string("{\n  \"swagger\": \"2.0\",\n  \"info\": {\n    \"title\": \"Service name\",\n    \"version\": \"version not set\"\n  },\n  \"schemes\": [\n    \"http\",\n    \"https\"\n  ],\n  \"consumes\": [\n    \"application/json\"\n  ],\n  \"produces\": [\n    \"application/json\"\n  ],\n  \"paths\": {\n    \"/{O.Tenant}\": {\n      \"post\": {\n        \"operationId\": \"AutoAddTrafficEncryptionPolicy\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Tenant\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"body\",\n            \"in\": \"body\",\n            \"required\": true,\n            \"schema\": {\n              \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\"\n            }\n          }\n        ],\n        \"tags\": [\n          \"TrafficEncryptionPolicyV1\"\n        ]\n      }\n    },\n    \"/{O.Tenant}/trafficEncryptionPolicy\": {\n      \"get\": {\n        \"operationId\": \"AutoGetTrafficEncryptionPolicy\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Tenant\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"T.Kind\",\n            \"description\": \"Kind represents the type of the API object.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"T.APIVersion\",\n            \"description\": \"APIVersion defines the version of the API object.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Name\",\n            \"description\": \"Name of the object, unique within a Namespace for scoped objects.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Namespace\",\n            \"description\": \"Namespace of the object, for scoped objects.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.ResourceVersion\",\n            \"description\": \"Resource version in the object store. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.UUID\",\n            \"description\": \"UUID is the unique identifier for the object. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.Mode\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.Tls.Version\",\n            \"description\": \"Possible values: TLS, IPsec.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.Tls.CipherSuite\",\n            \"description\": \"TLS Parameters for workload-to-workload connections.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.IPsec.EncryptionTransform\",\n            \"description\": \"ESP encryption algorithm. Default is \\\"aes-256-gcm-128\\\" (See RFC4106).\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.IPsec.IntegrityTransform\",\n            \"description\": \"ESP integrity algorithm.\\nDefault is \\\"NULL\\\" (must be \\\"NULL\\\" if AES-GCM is used for encryption).\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.KeyRotationIntervalSecs\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"integer\",\n            \"format\": \"int64\"\n          }\n        ],\n        \"tags\": [\n          \"TrafficEncryptionPolicyV1\"\n        ]\n      },\n      \"delete\": {\n        \"operationId\": \"AutoDeleteTrafficEncryptionPolicy\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Tenant\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          }\n        ],\n        \"tags\": [\n          \"TrafficEncryptionPolicyV1\"\n        ]\n      },\n      \"put\": {\n        \"operationId\": \"AutoUpdateTrafficEncryptionPolicy\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Tenant\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"body\",\n            \"in\": \"body\",\n            \"required\": true,\n            \"schema\": {\n              \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\"\n            }\n          }\n        ],\n        \"tags\": [\n          \"TrafficEncryptionPolicyV1\"\n        ]\n      }\n    }\n  },\n  \"definitions\": {\n    \"apiListMeta\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"ResourceVersion\": {\n          \"type\": \"string\",\n          \"description\": \"Resource version of object store at the time of list generation.\"\n        }\n      },\n      \"description\": \"ListMeta contains the metadata for list of objects.\"\n    },\n    \"apiListWatchOptions\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"O\": {\n          \"$ref\": \"#/definitions/apiObjectMeta\"\n        },\n        \"LabelSelector\": {\n          \"type\": \"string\"\n        },\n        \"FieldSelector\": {\n          \"type\": \"string\"\n        },\n        \"PrefixWatch\": {\n          \"type\": \"boolean\",\n          \"format\": \"boolean\"\n        }\n      }\n    },\n    \"apiObjectMeta\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Name\": {\n          \"type\": \"string\",\n          \"description\": \"Name of the object, unique within a Namespace for scoped objects.\"\n        },\n        \"Tenant\": {\n          \"type\": \"string\",\n          \"description\": \"Tenant is global namespace isolation for various objects. This can be automatically\\nfilled in many cases based on the tenant a user, who created the object, belongs go.\"\n        },\n        \"Namespace\": {\n          \"type\": \"string\",\n          \"description\": \"Namespace of the object, for scoped objects.\"\n        },\n        \"ResourceVersion\": {\n          \"type\": \"string\",\n          \"description\": \"Resource version in the object store. This can only be set by the server.\"\n        },\n        \"UUID\": {\n          \"type\": \"string\",\n          \"description\": \"UUID is the unique identifier for the object. This can only be set by the server.\"\n        },\n        \"Labels\": {\n          \"type\": \"object\",\n          \"additionalProperties\": {\n            \"type\": \"string\"\n          },\n          \"description\": \"Labels are arbitrary (key,value) pairs associated with any object.\"\n        }\n      },\n      \"description\": \"ObjectMeta contains metadata that all objects stored in kvstore must have.\"\n    },\n    \"apiTypeMeta\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Kind\": {\n          \"type\": \"string\",\n          \"description\": \"Kind represents the type of the API object.\"\n        },\n        \"APIVersion\": {\n          \"type\": \"string\",\n          \"description\": \"APIVersion defines the version of the API object.\"\n        }\n      },\n      \"description\": \"TypeMeta contains the metadata about kind and version for all API objects.\"\n    },\n    \"networkencryptionAutoMsgTrafficEncryptionPolicyWatchHelper\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Type\": {\n          \"type\": \"string\",\n          \"title\": \"TLS version: only supported value at present is 1.2\"\n        },\n        \"Object\": {\n          \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\",\n          \"title\": \"The name of the cipher suite in IANA format\\ndefault is TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384\"\n        }\n      }\n    },\n    \"networkencryptionIPsecProtocolSpec\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"EncryptionTransform\": {\n          \"type\": \"string\",\n          \"title\": \"ESP encryption algorithm. Default is \\\"aes-256-gcm-128\\\" (See RFC4106)\"\n        },\n        \"IntegrityTransform\": {\n          \"type\": \"string\",\n          \"title\": \"ESP integrity algorithm.\\nDefault is \\\"NULL\\\" (must be \\\"NULL\\\" if AES-GCM is used for encryption)\"\n        }\n      }\n    },\n    \"networkencryptionTLSProtocolSpec\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Version\": {\n          \"type\": \"string\",\n          \"title\": \"Possible values: TLS, IPsec\"\n        },\n        \"CipherSuite\": {\n          \"type\": \"string\",\n          \"title\": \"TLS Parameters for workload-to-workload connections\"\n        }\n      }\n    },\n    \"networkencryptionTrafficEncryptionPolicy\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"O\": {\n          \"$ref\": \"#/definitions/apiObjectMeta\"\n        },\n        \"Spec\": {\n          \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicySpec\"\n        },\n        \"Status\": {\n          \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicyStatus\"\n        }\n      }\n    },\n    \"networkencryptionTrafficEncryptionPolicyList\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"ListMeta\": {\n          \"$ref\": \"#/definitions/apiListMeta\"\n        },\n        \"Items\": {\n          \"type\": \"array\",\n          \"items\": {\n            \"$ref\": \"#/definitions/networkencryptionTrafficEncryptionPolicy\"\n          },\n          \"description\": \"Spec contains the configuration of the encryption policy.\"\n        }\n      }\n    },\n    \"networkencryptionTrafficEncryptionPolicySpec\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Mode\": {\n          \"type\": \"string\"\n        },\n        \"Tls\": {\n          \"$ref\": \"#/definitions/networkencryptionTLSProtocolSpec\"\n        },\n        \"IPsec\": {\n          \"$ref\": \"#/definitions/networkencryptionIPsecProtocolSpec\"\n        },\n        \"KeyRotationIntervalSecs\": {\n          \"type\": \"integer\",\n          \"format\": \"int64\"\n        }\n      }\n    },\n    \"networkencryptionTrafficEncryptionPolicyStatus\": {\n      \"type\": \"object\"\n    }\n  }\n}\n"),
	}

	// define dirs
	dir1 := &embedded.EmbeddedDir{
		Filename:   "",
		DirModTime: time.Unix(1506583701, 0),
		ChildFiles: []*embedded.EmbeddedFile{
			file2, // "networkencryption.swagger.json"

		},
	}

	// link ChildDirs
	dir1.ChildDirs = []*embedded.EmbeddedDir{}

	// register embeddedBox
	embedded.RegisterEmbeddedBox(`../../../../../sw/api/generated/networkencryption/swagger`, &embedded.EmbeddedBox{
		Name: `../../../../../sw/api/generated/networkencryption/swagger`,
		Time: time.Unix(1506583701, 0),
		Dirs: map[string]*embedded.EmbeddedDir{
			"": dir1,
		},
		Files: map[string]*embedded.EmbeddedFile{
			"networkencryption.swagger.json": file2,
		},
	})
}
