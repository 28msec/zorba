SET(STORE_SRCS
    api/item.cpp
    api/store_consts.cpp
    naive/basic_item_factory.cpp
    naive/simple_collection.cpp
    naive/simple_temp_seq.cpp
    naive/atomic_items.cpp
    naive/node_items.cpp
    naive/node_vector.cpp
    naive/node_updates.cpp
    naive/node_iterators.cpp
    naive/qname_pool.cpp
    naive/simple_store.cpp
    naive/simple_loader.cpp
    naive/simple_pul.cpp
    naive/ordpath.cpp
    naive/nsbindings.cpp
    naive/item_iterator.cpp
    util/handle_hashset_string.cpp
    util/mutex.cpp
    util/latch.cpp)


HEADER_GROUP_SUBFOLDER(STORE_SRCS api)
HEADER_GROUP_SUBFOLDER(STORE_SRCS naive)
HEADER_GROUP_SUBFOLDER(STORE_SRCS util)
HEADER_GROUP_SUBFOLDER(STORE_SRCS update)
