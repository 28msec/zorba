CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/api/version.cpp.cmake ${CMAKE_CURRENT_BINARY_DIR}/api/version.cpp)

SET(API_SRCS
    zorba.cpp
    zorbaimpl.cpp
    xqueryimpl.cpp
    default_error_handler.cpp
    exception.cpp
    error.cpp
    staticcontextimpl.cpp
    dynamiccontextimpl.cpp
    resultiteratorimpl.cpp
    string.cpp
    itemfactoryimpl.cpp
    serialization/serializer.cpp
    item.cpp
    typeidentimpl.cpp
    unmarshaller.cpp
    xmldatamanagerimpl.cpp
    resultiteratorchainer.cpp
    )

SET(API_BUILD_SRCS
  ${CMAKE_CURRENT_BINARY_DIR}/api/version.cpp
  )
