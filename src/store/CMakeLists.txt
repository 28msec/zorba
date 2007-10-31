SET(STORE_SRCS
    api/item.cpp
    naive/basic_item_factory.cpp
    naive/simple_collection.cpp
    naive/simple_temp_seq.cpp
    naive/atomic_items.cpp
    naive/node_items.cpp
    naive/qname_pool.cpp
    naive/simple_store.cpp)


#SET(QNPOOL_SRCS store/naive/test_qname_pool.cpp)
#ADD_EXECUTABLE(test_pool ${QNPOOL_SRCS})
#TARGET_LINK_LIBRARIES(test_pool zorba)


HEADER_GROUP_SUBFOLDER(STORE_SRCS api)
HEADER_GROUP_SUBFOLDER(STORE_SRCS naive)
HEADER_GROUP_SUBFOLDER(STORE_SRCS update)
