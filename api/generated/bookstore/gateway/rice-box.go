package bookstoreGwService

import (
	"github.com/GeertJohan/go.rice/embedded"
	"time"
)

func init() {

	// define files
	file2 := &embedded.EmbeddedFile{
		Filename:    "example.swagger.json",
		FileModTime: time.Unix(1505413500, 0),
		Content:     string("{\n  \"swagger\": \"2.0\",\n  \"info\": {\n    \"title\": \"Service name\",\n    \"version\": \"version not set\"\n  },\n  \"schemes\": [\n    \"http\",\n    \"https\"\n  ],\n  \"consumes\": [\n    \"application/json\"\n  ],\n  \"produces\": [\n    \"application/json\"\n  ],\n  \"paths\": {\n    \"/books/{Spec.ISBNId}\": {\n      \"get\": {\n        \"operationId\": \"AutoGetBook\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreBook\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"Spec.ISBNId\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"T.Kind\",\n            \"description\": \"Kind represents the type of the API object.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"T.APIVersion\",\n            \"description\": \"APIVersion defines the version of the API object.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Name\",\n            \"description\": \"Name of the object, unique within a Namespace for scoped objects.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Tenant\",\n            \"description\": \"Tenant is global namespace isolation for various objects. This can be automatically\\nfilled in many cases based on the tenant a user, who created the object, belongs go.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Namespace\",\n            \"description\": \"Namespace of the object, for scoped objects.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.ResourceVersion\",\n            \"description\": \"Resource version in the object store. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.UUID\",\n            \"description\": \"UUID is the unique identifier for the object. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.Author\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.IdProvider\",\n            \"description\": \"Spec is not allowed to be Null hence disabling nullable.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Status.Inventory\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"integer\",\n            \"format\": \"int32\"\n          }\n        ],\n        \"tags\": [\n          \"BookstoreV1\"\n        ]\n      }\n    },\n    \"/orders\": {\n      \"get\": {\n        \"operationId\": \"AutoListOrder\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreOrderList\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Name\",\n            \"description\": \"Name of the object, unique within a Namespace for scoped objects.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Tenant\",\n            \"description\": \"Tenant is global namespace isolation for various objects. This can be automatically\\nfilled in many cases based on the tenant a user, who created the object, belongs go.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Namespace\",\n            \"description\": \"Namespace of the object, for scoped objects.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.ResourceVersion\",\n            \"description\": \"Resource version in the object store. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.UUID\",\n            \"description\": \"UUID is the unique identifier for the object. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"LabelSelector\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"FieldSelector\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"PrefixWatch\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"boolean\",\n            \"format\": \"boolean\"\n          }\n        ],\n        \"tags\": [\n          \"BookstoreV1\"\n        ]\n      },\n      \"post\": {\n        \"operationId\": \"AutoAddOrder\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreOrder\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"body\",\n            \"in\": \"body\",\n            \"required\": true,\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreOrder\"\n            }\n          }\n        ],\n        \"tags\": [\n          \"BookstoreV1\"\n        ]\n      }\n    },\n    \"/orders/{O.Name}\": {\n      \"get\": {\n        \"operationId\": \"AutoGetOrder\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreOrder\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Name\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"T.Kind\",\n            \"description\": \"Kind represents the type of the API object.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"T.APIVersion\",\n            \"description\": \"APIVersion defines the version of the API object.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Tenant\",\n            \"description\": \"Tenant is global namespace isolation for various objects. This can be automatically\\nfilled in many cases based on the tenant a user, who created the object, belongs go.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.Namespace\",\n            \"description\": \"Namespace of the object, for scoped objects.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.ResourceVersion\",\n            \"description\": \"Resource version in the object store. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"O.UUID\",\n            \"description\": \"UUID is the unique identifier for the object. This can only be set by the server.\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Spec.Id\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"Status.Status\",\n            \"in\": \"query\",\n            \"required\": false,\n            \"type\": \"string\",\n            \"enum\": [\n              \"CREATED\",\n              \"PROCESSING\",\n              \"FILLED\",\n              \"SHIPPED\",\n              \"COMPLETED\"\n            ],\n            \"default\": \"CREATED\"\n          }\n        ],\n        \"tags\": [\n          \"BookstoreV1\"\n        ]\n      },\n      \"delete\": {\n        \"operationId\": \"AutoDeleteOrder\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreOrder\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Name\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          }\n        ],\n        \"tags\": [\n          \"BookstoreV1\"\n        ]\n      },\n      \"put\": {\n        \"operationId\": \"AutoUpdateOrder\",\n        \"responses\": {\n          \"200\": {\n            \"description\": \"\",\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreOrder\"\n            }\n          }\n        },\n        \"parameters\": [\n          {\n            \"name\": \"O.Name\",\n            \"in\": \"path\",\n            \"required\": true,\n            \"type\": \"string\"\n          },\n          {\n            \"name\": \"body\",\n            \"in\": \"body\",\n            \"required\": true,\n            \"schema\": {\n              \"$ref\": \"#/definitions/bookstoreOrder\"\n            }\n          }\n        ],\n        \"tags\": [\n          \"BookstoreV1\"\n        ]\n      }\n    }\n  },\n  \"definitions\": {\n    \"apiListMeta\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"ResourceVersion\": {\n          \"type\": \"string\",\n          \"description\": \"Resource version of object store at the time of list generation.\"\n        }\n      },\n      \"description\": \"ListMeta contains the metadata for list of objects.\"\n    },\n    \"apiListWatchOptions\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"O\": {\n          \"$ref\": \"#/definitions/apiObjectMeta\"\n        },\n        \"LabelSelector\": {\n          \"type\": \"string\"\n        },\n        \"FieldSelector\": {\n          \"type\": \"string\"\n        },\n        \"PrefixWatch\": {\n          \"type\": \"boolean\",\n          \"format\": \"boolean\"\n        }\n      }\n    },\n    \"apiObjectMeta\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Name\": {\n          \"type\": \"string\",\n          \"description\": \"Name of the object, unique within a Namespace for scoped objects.\"\n        },\n        \"Tenant\": {\n          \"type\": \"string\",\n          \"description\": \"Tenant is global namespace isolation for various objects. This can be automatically\\nfilled in many cases based on the tenant a user, who created the object, belongs go.\"\n        },\n        \"Namespace\": {\n          \"type\": \"string\",\n          \"description\": \"Namespace of the object, for scoped objects.\"\n        },\n        \"ResourceVersion\": {\n          \"type\": \"string\",\n          \"description\": \"Resource version in the object store. This can only be set by the server.\"\n        },\n        \"UUID\": {\n          \"type\": \"string\",\n          \"description\": \"UUID is the unique identifier for the object. This can only be set by the server.\"\n        },\n        \"Labels\": {\n          \"type\": \"object\",\n          \"additionalProperties\": {\n            \"type\": \"string\"\n          },\n          \"description\": \"Labels are arbitrary (key,value) pairs associated with any object.\"\n        }\n      },\n      \"description\": \"ObjectMeta contains metadata that all objects stored in kvstore must have.\"\n    },\n    \"apiTypeMeta\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Kind\": {\n          \"type\": \"string\",\n          \"description\": \"Kind represents the type of the API object.\"\n        },\n        \"APIVersion\": {\n          \"type\": \"string\",\n          \"description\": \"APIVersion defines the version of the API object.\"\n        }\n      },\n      \"description\": \"TypeMeta contains the metadata about kind and version for all API objects.\"\n    },\n    \"bookstoreAutoMsgBookWatchHelper\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Type\": {\n          \"type\": \"string\"\n        },\n        \"Object\": {\n          \"$ref\": \"#/definitions/bookstoreBook\"\n        }\n      }\n    },\n    \"bookstoreAutoMsgOrderWatchHelper\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Type\": {\n          \"type\": \"string\"\n        },\n        \"Object\": {\n          \"$ref\": \"#/definitions/bookstoreOrder\"\n        }\n      }\n    },\n    \"bookstoreAutoMsgPublisherWatchHelper\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Type\": {\n          \"type\": \"string\"\n        },\n        \"Object\": {\n          \"$ref\": \"#/definitions/bookstorePublisher\"\n        }\n      }\n    },\n    \"bookstoreBook\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"O\": {\n          \"$ref\": \"#/definitions/apiObjectMeta\"\n        },\n        \"Spec\": {\n          \"$ref\": \"#/definitions/bookstoreBookSpec\",\n          \"description\": \"Added in  version 2 of the API.\"\n        },\n        \"Status\": {\n          \"$ref\": \"#/definitions/bookstoreBookStatus\"\n        }\n      }\n    },\n    \"bookstoreBookList\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"ListMeta\": {\n          \"$ref\": \"#/definitions/apiListMeta\"\n        },\n        \"Items\": {\n          \"type\": \"array\",\n          \"items\": {\n            \"$ref\": \"#/definitions/bookstoreBook\"\n          }\n        }\n      }\n    },\n    \"bookstoreBookSpec\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"ISBNId\": {\n          \"type\": \"string\"\n        },\n        \"Author\": {\n          \"type\": \"string\"\n        },\n        \"IdProvider\": {\n          \"type\": \"string\",\n          \"description\": \"Spec is not allowed to be Null hence disabling nullable.\"\n        }\n      }\n    },\n    \"bookstoreBookStatus\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Inventory\": {\n          \"type\": \"integer\",\n          \"format\": \"int32\"\n        }\n      }\n    },\n    \"bookstoreOrder\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"O\": {\n          \"$ref\": \"#/definitions/apiObjectMeta\"\n        },\n        \"Spec\": {\n          \"$ref\": \"#/definitions/bookstoreOrderSpec\"\n        },\n        \"Status\": {\n          \"$ref\": \"#/definitions/bookstoreOrderStatus\"\n        }\n      }\n    },\n    \"bookstoreOrderItem\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"ISBNId\": {\n          \"type\": \"string\"\n        },\n        \"Quantity\": {\n          \"type\": \"integer\",\n          \"format\": \"int64\"\n        }\n      }\n    },\n    \"bookstoreOrderList\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"ListMeta\": {\n          \"$ref\": \"#/definitions/apiListMeta\"\n        },\n        \"Items\": {\n          \"type\": \"array\",\n          \"items\": {\n            \"$ref\": \"#/definitions/bookstoreOrder\"\n          }\n        }\n      }\n    },\n    \"bookstoreOrderSpec\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Id\": {\n          \"type\": \"string\"\n        },\n        \"Order\": {\n          \"type\": \"array\",\n          \"items\": {\n            \"$ref\": \"#/definitions/bookstoreOrderItem\"\n          }\n        }\n      }\n    },\n    \"bookstoreOrderStatus\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Status\": {\n          \"$ref\": \"#/definitions/bookstoreOrderStatusOrderStatus\"\n        },\n        \"Filled\": {\n          \"type\": \"array\",\n          \"items\": {\n            \"$ref\": \"#/definitions/bookstoreOrderSpec\"\n          }\n        }\n      }\n    },\n    \"bookstoreOrderStatusOrderStatus\": {\n      \"type\": \"string\",\n      \"enum\": [\n        \"CREATED\",\n        \"PROCESSING\",\n        \"FILLED\",\n        \"SHIPPED\",\n        \"COMPLETED\"\n      ],\n      \"default\": \"CREATED\"\n    },\n    \"bookstorePublisher\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"O\": {\n          \"$ref\": \"#/definitions/apiObjectMeta\"\n        },\n        \"Spec\": {\n          \"$ref\": \"#/definitions/bookstorePublisherSpec\"\n        }\n      }\n    },\n    \"bookstorePublisherList\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"T\": {\n          \"$ref\": \"#/definitions/apiTypeMeta\"\n        },\n        \"ListMeta\": {\n          \"$ref\": \"#/definitions/apiListMeta\"\n        },\n        \"Items\": {\n          \"type\": \"array\",\n          \"items\": {\n            \"$ref\": \"#/definitions/bookstorePublisher\"\n          }\n        }\n      }\n    },\n    \"bookstorePublisherSpec\": {\n      \"type\": \"object\",\n      \"properties\": {\n        \"Id\": {\n          \"type\": \"string\"\n        },\n        \"Address\": {\n          \"type\": \"string\"\n        }\n      }\n    }\n  }\n}\n"),
	}

	// define dirs
	dir1 := &embedded.EmbeddedDir{
		Filename:   "",
		DirModTime: time.Unix(1504746965, 0),
		ChildFiles: []*embedded.EmbeddedFile{
			file2, // "example.swagger.json"

		},
	}

	// link ChildDirs
	dir1.ChildDirs = []*embedded.EmbeddedDir{}

	// register embeddedBox
	embedded.RegisterEmbeddedBox(`../../../../../sw/api/generated/bookstore/swagger`, &embedded.EmbeddedBox{
		Name: `../../../../../sw/api/generated/bookstore/swagger`,
		Time: time.Unix(1504746965, 0),
		Dirs: map[string]*embedded.EmbeddedDir{
			"": dir1,
		},
		Files: map[string]*embedded.EmbeddedFile{
			"example.swagger.json": file2,
		},
	})
}
