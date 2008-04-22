SET(STORE_SRCS
    api/store_consts.cpp
    api/update_consts.cpp
    util/mutex.cpp
    util/latch.cpp)

IF(ZORBA_MINIMAL_STORE)
LIST(APPEND STORE_SRCS 
    minimal/min_item_factory.cpp
    minimal/min_collection.cpp
    minimal/min_temp_seq.cpp
    minimal/min_atomic_items.cpp
    minimal/min_item.cpp
    minimal/min_node_items.cpp
    minimal/min_node_vector.cpp
    minimal/min_node_updates.cpp
    minimal/min_node_iterators.cpp
    minimal/min_store.cpp
    minimal/min_loader.cpp
    minimal/min_pul.cpp
    minimal/min_ordpath.cpp
    minimal/min_nsbindings.cpp
    minimal/min_item_iterator.cpp
    minimal/min_query_context.cpp)
HEADER_GROUP_SUBFOLDER(STORE_SRCS minimal)
ELSE(ZORBA_MINIMAL_STORE)
LIST(APPEND STORE_SRCS 
    naive/basic_item_factory.cpp
    naive/simple_collection.cpp
    naive/simple_temp_seq.cpp
    naive/atomic_items.cpp
    naive/item.cpp
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
    naive/query_context.cpp
    naive/string_pool.cpp
    )
HEADER_GROUP_SUBFOLDER(STORE_SRCS naive)
ENDIF(ZORBA_MINIMAL_STORE)

HEADER_GROUP_SUBFOLDER(STORE_SRCS api)
HEADER_GROUP_SUBFOLDER(STORE_SRCS util)
HEADER_GROUP_SUBFOLDER(STORE_SRCS update)
