INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES ("sys/param.h;sys/mount.h;unicode/utypes.h;unicode/coll.h;unicode/ustring.h" HAVE_SYS_MOUNT_H)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR})


