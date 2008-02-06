CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/system/zorba_version.cpp.cmake ${CMAKE_CURRENT_BINARY_DIR}/system/zorba_version.cpp)

SET(SYSTEM_SRCS
    globalenv.cpp
    zorba_engine.cpp
    zorba.cpp
)

SET(SYSTEM_BUILD_SRCS
  ${CMAKE_CURRENT_BINARY_DIR}/system/zorba_version.cpp
  )
