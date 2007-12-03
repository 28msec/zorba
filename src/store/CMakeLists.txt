SET(STORE_SRCS
    api/item.cpp
    api/store.cpp
    naive/basic_item_factory.cpp
    naive/simple_collection.cpp
    naive/simple_temp_seq.cpp
    naive/atomic_items.cpp
    naive/node_items.cpp
    naive/qname_pool.cpp
    naive/simple_store.cpp
    naive/simple_loader.cpp
    naive/ordpath.cpp
    util/string_pool.cpp)


HEADER_GROUP_SUBFOLDER(STORE_SRCS api)
HEADER_GROUP_SUBFOLDER(STORE_SRCS naive)
HEADER_GROUP_SUBFOLDER(STORE_SRCS util)
HEADER_GROUP_SUBFOLDER(STORE_SRCS update)