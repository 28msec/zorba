SET(TYPES_SRCS
    casting.cpp
    node_test.cpp
    root_typemanager.cpp
    typeimpl.cpp
    delegating_typemanager.cpp)

ADD_SRC_SUBFOLDER(TYPES_SRCS schema SCHEMA_SRCS)