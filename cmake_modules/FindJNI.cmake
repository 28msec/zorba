# - Find JNI This module finds if JNI (Java Native Interface) is
# installed and determines where the include files are.. This code
# sets the following variables:
#
# JNI_INCLUDE_PATH = path to where jni.h can be found 
# JNI_MD)INCLUDE_PATH = path to where jni_md.h can be found 


SET(JNI_POSSIBLE_INCLUDE_PATHS
  /usr/lib/jvm/java/include 
  )

find_path ( JNI_INCLUDE_PATH jni.h PATHS ${JNI_POSSIBLE_INCLUDE_PATHS} )
find_path ( JNI_MD_INCLUDE_PATH jni_md.h PATHS ${JNI_POSSIBLE_INCLUDE_PATHS}/linux )

MARK_AS_ADVANCED(
  JNI_FOUND_INCLUDE_PATH
  )

IF(APPLE)
# this is a hack for now
  SET(CMAKE_SHARED_MODULE_CREATE_C_FLAGS
   "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -Wl,-flat_namespace")
ENDIF(APPLE)


STRING( COMPARE EQUAL ${JNI_INCLUDE_PATH} "JNI_INCLUDE_PATH-NOTFOUND" JNI_NOT_FOUND )
IF( NOT JNI_INCLUDE_PATH_NOT_FOUND)
    SET(JNI_FOUND "yes")
    MESSAGE(STATUS "Found JNI-Version 1.6.0" )
ENDIF(NOT JNI_INCLUDE_PATH_NOT_FOUND )
