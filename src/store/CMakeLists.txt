SET(STORE_SRCS
    api/item.cpp
    naive/basic_item_factory.cpp
    naive/simple_collection.cpp
    naive/simple_temp_seq.cpp
    naive/atomic_items.cpp
    naive/node_items.cpp
    naive/simple_store.cpp)
#    update/update_values.cpp)

ADD_LIBRARY(store ${STORE_SRCS})
