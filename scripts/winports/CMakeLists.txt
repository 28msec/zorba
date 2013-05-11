CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
INCLUDE(ExternalProject)
PROJECT(winports)

##############################################################################
##############################################################################
#  DOWNLOAD_EXTRACT
##############################################################################
# This function downloads a package from PACKAGE_URL
# and verifies that PACKAGE_MD5 corresponds
# then, if WITH_DIR is set to YES, it creates PACKAGE_NAME directory 
# and extract the content of the downloaded file in this directory
# if WITH_DIR is set to NO, it extracts the file in CMAKE_CURRENT_BINARY_DIR directory
# 
FUNCTION (DOWNLOAD_EXTRACT PACKAGE_NAME WITH_DIR PACKAGE_URL PACKAGE_MD5)
  SET(FINAL_DESTINATION ${CMAKE_CURRENT_BINARY_DIR}\\${PACKAGE_NAME})
  IF(EXISTS ${FINAL_DESTINATION})
    MESSAGE(STATUS "Package ${PACKAGE_NAME} already in place: ${FINAL_DESTINATION}")
    RETURN()
  ENDIF(EXISTS ${FINAL_DESTINATION})

  MESSAGE(STATUS "Setting up ${PACKAGE_NAME}")

  SET(DOWNLOAD_PACKAGE YES)
  
  IF(WITH_DIR)
    FILE(MAKE_DIRECTORY ${FINAL_DESTINATION})
  ELSE(WITH_DIR)
    SET(FINAL_DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  ENDIF(WITH_DIR)
  
  IF (EXISTS ${LIB_DOWNLOADS}\\${PACKAGE_NAME}.zip)
    FILE(MD5 ${LIB_DOWNLOADS}\\${PACKAGE_NAME}.zip EXIST_MD5)
    IF (${EXIST_MD5} STREQUAL ${PACKAGE_MD5})
      MESSAGE(STATUS "${PACKAGE_NAME} already downloaded.")
      SET(DOWNLOAD_PACKAGE NO)
    ENDIF (${EXIST_MD5} STREQUAL ${PACKAGE_MD5})
  ENDIF (EXISTS ${LIB_DOWNLOADS}\\${PACKAGE_NAME}.zip)
  
  IF (DOWNLOAD_PACKAGE)
    FILE(DOWNLOAD ${PACKAGE_URL} ${LIB_DOWNLOADS}\\${PACKAGE_NAME}.zip SHOW_PROGRESS EXPECTED_MD5 "${PACKAGE_MD5}" )
  ENDIF (DOWNLOAD_PACKAGE)

  MESSAGE(STATUS "Extracting ${PACKAGE_NAME}")
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E tar xzf ${LIB_DOWNLOADS}\\${PACKAGE_NAME}.zip
    WORKING_DIRECTORY ${FINAL_DESTINATION}
  )
ENDFUNCTION (DOWNLOAD_EXTRACT)



##############################################################################
##############################################################################
MESSAGE(STATUS "Libraries directory: " ${CMAKE_CURRENT_BINARY_DIR})
SET (LIB_DOWNLOADS ${CMAKE_CURRENT_BINARY_DIR}\\downloads)
FILE(MAKE_DIRECTORY ${LIB_DOWNLOADS})
MESSAGE(STATUS "Libraries directory: " ${CMAKE_CURRENT_BINARY_DIR})


##############################################################################
##############################################################################
#  PATCH
##############################################################################
 EXTERNALPROJECT_ADD (
  patch-2.5.9
  #URL http://kent.dl.sourceforge.net/project/gnuwin32/patch/2.5.9-7/patch-2.5.9-7-bin.zip
  URL file://C:/dev/winports/patch-2.5.9-7-bin.zip
  URL_MD5 b9c8b31d62f4b2e4f1887bbb63e8a905
  PREFIX patch-2.5.9
  #DEPENDS libxml2-2.9.1
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND  ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/patch-2.5.9/src/patch-2.5.9/bin ${CMAKE_CURRENT_BINARY_DIR}/patch-2.5.9/bin
)
SET(PATCH_COMMAND ${CMAKE_CURRENT_BINARY_DIR}/patch-2.5.9/bin/patch.exe)

##############################################################################
##############################################################################
#  ZLIB
##############################################################################
EXTERNALPROJECT_ADD(
  zlib-1.2.8
  URL http://zlib.net/zlib-1.2.8.tar.gz
  PREFIX zlib-1.2.8
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.8 -DCMAKE_BUILD_TYPE=RELEASE
)

##############################################################################
##############################################################################
#  PERL
##############################################################################
EXTERNALPROJECT_ADD(
  perl-5.16.3.1
  #URL http://strawberryperl.com/download/5.16.3.1/strawberry-perl-5.16.3.1-32bit-portable.zip
  URL file://C:/dev/winports/strawberry-perl-5.16.3.1-32bit-portable.zip
  URL_MD5 8f3ef667e9a2b7fc402610da29bb8074
  PREFIX perl-5.16.3.1
  #SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/perl-5.16.3.1
  PATCH_COMMAND  ""
  CONFIGURE_COMMAND  ""
  BUILD_COMMAND  ""
  INSTALL_COMMAND  ""
)
SET(PERL_COMMAND ${CMAKE_CURRENT_BINARY_DIR}/perl-5.16.3.1/src/perl-5.16.3.1/perl/bin/perl.exe)
MESSAGE(STATUS "PERL COMMAND: ${PERL_COMMAND}")
##############################################################################
##############################################################################
#  OPENSSL
##############################################################################
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_patch.cmake "
  FILE(READ \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e/ms/do_nt.bat\" DO_NASM)
  STRING(REPLACE \"perl\" \"${PERL_COMMAND}\" DO_NASM \${DO_NASM})
  FILE(WRITE \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e/ms/do_nt.bat\" \${DO_NASM})
")
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND ${PERL_COMMAND} 
    Configure enable-camellia 
    --openssldir=${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e 
    VC-WIN32
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e\"
  )
  
  EXECUTE_PROCESS(
    COMMAND \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e/ms/do_nt.bat\"
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e\"
  )
")
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_nmake.cmake "
  FILE(READ \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e/ms/ntdll.mak\" NTDLL_MAK)
  STRING(REPLACE \"perl\" \"${PERL_COMMAND}\" NTDLL_MAK \${NTDLL_MAK})
  FILE(WRITE \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e/ms/ntdll.mak\" \${NTDLL_MAK})

  EXECUTE_PROCESS(
    COMMAND nmake -f ms/ntdll.mak
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e\"
  )
")
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_install.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake -f ms/ntdll.mak install
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e\"
  )
")


EXTERNALPROJECT_ADD(
  openssl-1.0.1e
  DEPENDS perl-5.16.3.1
  #URL http://www.openssl.org/source/openssl-1.0.1e.tar.gz
  URL file://C:/dev/winports/openssl-1.0.1e.zip
  PREFIX openssl-1.0.1e
  PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_patch.cmake
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_nmake.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_install.cmake
)



##############################################################################
##############################################################################
#  LIBCURL
##############################################################################
EXTERNALPROJECT_ADD(
  libcurl-7.29.0
  #URL http://curl.haxx.se/download/curl-7.29.0.tar.gz
  URL file://C:/dev/winports/curl-7.29.0.tar.gz
  PREFIX libcurl-7.29.0
  DEPENDS openssl-1.0.1e
  CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/libcurl-7.29.0
             -DBUILD_CURL_EXE=OFF -DBUILD_CURL_TESTS=OFF -DCURL_STATICLIB=ON -DCMAKE_USE_OPENSSL=OFF
             -DCURL_ZLIB=OFF -DHTTP_ONLY=ON -DCMAKE_BUILD_TYPE=RELEASE
)

# ##############################################################################
# ##############################################################################
# #  LIBICONV
# ##############################################################################
# EXTERNALPROJECT_ADD(
  # libiconv-1.14
  # DEPENDS patch-2.5.9
  # #URL http://ftp.gnu.org/pub/gnu/libiconv/libiconv-1.14.tar.gz
  # URL file://C:/dev/winports/libiconv-1.14.tar.gz
  # PREFIX libiconv-1.14
  # CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/libiconv-1.14 -DCMAKE_BUILD_TYPE=RELEASE
  # PATCH_COMMAND ${CMAKE_COMMAND} -D PATCH_COMMAND=${PATCH_COMMAND} -D CMAKELISTS_DIR=${CMAKE_CURRENT_SOURCE_DIR}/libiconv -P ${CMAKE_CURRENT_SOURCE_DIR}/libiconv/move.cmake
# )

# ##############################################################################
# ##############################################################################
# #  LIBXML2
# ##############################################################################
# SET(LIBXML2_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/libxml2-2.9.1/src/libxml2-2.9.1/win32)
# #CONFIGURE FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxml2_configure.cmake "
  # EXECUTE_PROCESS(
    # COMMAND cscript configure.js compiler=msvc 
    # prefix=..\\\\..\\\\..
    # iconv=no
    # zlib=yes
    # include=${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.8/include
    # lib=${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.8/lib
    # WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  # )"
# )
# #MAKE FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake.cmake "
  # EXECUTE_PROCESS(
    # COMMAND nmake /f Makefile.msvc
    # WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  # )"
# )
# #MAKE INSTALL FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake_install.cmake "
  # EXECUTE_PROCESS(
    # COMMAND nmake /f Makefile.msvc install
    # WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  # )"
# )
# #CONFIGURE, MAKE AND INSTALL
# EXTERNALPROJECT_ADD(
  # libxml2-2.9.1
  # URL file://C:/dev/winports/libxml2-2.9.1.tar.gz
  # #URL ftp://xmlsoft.org/libxml2/libxml2-2.9.1.tar.gz
  # PREFIX libxml2-2.9.1
  # DEPENDS zlib-1.2.8 libiconv-1.14
  # CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxml2_configure.cmake
  # BUILD_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake.cmake
  # INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake_install.cmake
# )


# ##############################################################################
# ##############################################################################
# #  LIBXSLT
# ##############################################################################
# SET(LIBXSLT_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/libxslt-1.1.28/src/libxslt-1.1.28/win32)
# #CONFIGURE FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_configure.cmake "
  # EXECUTE_PROCESS(
    # COMMAND cscript configure.js compiler=msvc 
    # prefix=..\\\\..\\\\..
    # iconv=no
    # zlib=yes
    # xslt_debug=no
    # include=${CMAKE_CURRENT_BINARY_DIR}/libxml2-2.9.1/include/libxml2
    # lib=${CMAKE_CURRENT_BINARY_DIR}/libxml2-2.9.1/lib
    # WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  # ) "
# )
# #MAKE FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake.cmake "
  # EXECUTE_PROCESS(
    # COMMAND nmake /f Makefile.msvc
    # WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  # ) "
# )
# #MAKE INSTALL FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake_install.cmake "
  # EXECUTE_PROCESS(
    # COMMAND nmake /f Makefile.msvc install
    # WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  # ) "
# )
# #MAKE PATCH FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_patch.cmake 
# "
  # FILE(READ \"${LIBXSLT_WIN32_DIR}/Makefile.msvc\" LIBXSLT_MAKEFILE)
  # STRING(REPLACE \"LDFLAGS = $(LDFLAGS) /OPT:NOWIN98\" \"#LDFLAGS = $(LDFLAGS) /OPT:NOWIN98\" LIBXSLT_MAKEFILE \"\${LIBXSLT_MAKEFILE}\")
  # FILE(WRITE \"${LIBXSLT_WIN32_DIR}/Makefile.msvc\" \${LIBXSLT_MAKEFILE})
# " 
# )
# #CONFIGURE, MAKE AND INSTALL
# EXTERNALPROJECT_ADD (
  # libxslt-1.1.28
  # #URL ftp://xmlsoft.org/libxslt/libxslt-1.1.28.tar.gz
  # URL file://C:/dev/winports/libxslt-1.1.28.tar.gz
  # PREFIX libxslt-1.1.28
  # DEPENDS libxml2-2.9.1
  # PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_patch.cmake
  # CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_configure.cmake
  # BUILD_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake.cmake
  # INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake_install.cmake
# )

# ##############################################################################
# ##############################################################################
# #  ICU
# ##############################################################################
# SET(LIBICU_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/icu4c-4_8_1_1/src/icu4c-4_8_1_1/source/allinone)
# SET(LIBICU_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/icu4c-4_8_1_1 )
# SET(LIBICU_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/icu4c-4_8_1_1/src/icu4c-4_8_1_1 )
# #CONFIGURE FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libicu_configure.cmake "
  # EXECUTE_PROCESS(
    # COMMAND devenv /upgrade allinone.sln
    # WORKING_DIRECTORY \"${LIBICU_WIN32_DIR}\"
  # ) "
# )
# #BUILD FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libicu_build.cmake "
  # EXECUTE_PROCESS(
    # COMMAND devenv allinone.sln /build \"Release|Win32\"
    # WORKING_DIRECTORY \"${LIBICU_WIN32_DIR}\"
  # ) "
# )
# #BUILD FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libicu_install.cmake "
  # EXECUTE_PROCESS (
    # COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${LIBICU_BUILD_DIR}/bin\" \"${LIBICU_INSTALL_DIR}/bin\"
    # WORKING_DIRECTORY \"${LIBICU_INSTALL_DIR}/bin\"
  # ) 
  # EXECUTE_PROCESS (
    # COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${LIBICU_BUILD_DIR}/include\" \"${LIBICU_INSTALL_DIR}/include\"
    # WORKING_DIRECTORY \"${LIBICU_INSTALL_DIR}/include\"
  # ) 
  # EXECUTE_PROCESS (
    # COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${LIBICU_BUILD_DIR}/lib\" \"${LIBICU_INSTALL_DIR}/lib\"
    # WORKING_DIRECTORY \"${LIBICU_INSTALL_DIR}/lib\"
  # ) "
# )
# #CONFIGURE, MAKE AND INSTALL
# EXTERNALPROJECT_ADD (
  # icu4c-4_8_1_1
  # #URL http://download.icu-project.org/files/icu4c/51.1/icu4c-51_1-src.zip
  # #URL file://C:/dev/winports/icu4c-51_1-src.zip
  # #URL_MD5 b4303a43caa79018e3b6ec18148fdb1a

  # #URL http://download.icu-project.org/files/icu4c/4.8.1.1/icu4c-4_8_1_1-src.zip
  # URL file://C:/dev/winports/icu4c-4_8_1_1-src.zip
  # URL_MD5 890862544bdb9012f5758bd76e82c2b4
  # PREFIX icu4c-4_8_1_1
  # #DEPENDS libxml2-2.9.1
  # #PATCH_COMMAND echo %cd%
  # CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libicu_configure.cmake
  # BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libicu_build.cmake
  # INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libicu_install.cmake
# )

# ##############################################################################
# ##############################################################################
# #  XERCES
# ##############################################################################
# SET(XERCES_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/xerces-c-3.1.1/src/xerces-c-3.1.1/projects/Win32/VC10/xerces-all)
# SET(XERCES_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/xerces-c-3.1.1 )
# SET(XERCES_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/xerces-c-3.1.1/src/xerces-c-3.1.1 )
# #CONFIGURE FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_configure.cmake "
  # EXECUTE_PROCESS(
    # COMMAND devenv /upgrade xerces-all.sln
    # WORKING_DIRECTORY \"${XERCES_WIN32_DIR}\"
  # ) "
# )
# #BUILD FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_build.cmake "
  # EXECUTE_PROCESS(
    # COMMAND devenv xerces-all.sln /build \"Release|Win32\"
    # WORKING_DIRECTORY \"${XERCES_WIN32_DIR}\"
  # ) "
# )
# #INSTALL FILE
# FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_install.cmake 
# " 
  # FILE(MAKE_DIRECTORY \"${XERCES_INSTALL_DIR}/lib\")
  # EXECUTE_PROCESS (
    # COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${XERCES_BUILD_DIR}/src\" \"${XERCES_INSTALL_DIR}/include\"
    # WORKING_DIRECTORY \"${XERCES_INSTALL_DIR}\"
  # ) 
  # EXECUTE_PROCESS (
    # COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${XERCES_BUILD_DIR}/Build/Win32/VC10/Release\" \"${XERCES_INSTALL_DIR}/bin\"
    # WORKING_DIRECTORY \"${XERCES_INSTALL_DIR}\"
  # ) 
  # EXECUTE_PROCESS (
    # COMMAND ${CMAKE_COMMAND} -E copy  \"${XERCES_BUILD_DIR}/Build/Win32/VC10/Release/xerces-c_3.lib\" \"${XERCES_INSTALL_DIR}/lib/xerces-c_3.lib\"
    # WORKING_DIRECTORY \"${XERCES_INSTALL_DIR}\"
  # ) 
  # FILE(GLOB_RECURSE XERCES_CPP_FILES \"${XERCES_INSTALL_DIR}/include/*.cpp\")
  # FOREACH(XERCES_CPP IN ITEMS \${XERCES_CPP_FILES})
    # FILE(REMOVE \${XERCES_CPP})
  # ENDFOREACH()
  
# ")
# #CONFIGURE, MAKE AND INSTALL
# EXTERNALPROJECT_ADD (
  # xerces-c-3.1.1
  # #URL http://www.apache.org/dist/xerces/c/3/sources/xerces-c-3.1.1.zip
  # URL file://C:/dev/winports/xerces-c-3.1.1.zip
  # #URL_MD5 b4303a43caa79018e3b6ec18148fdb1a
  # PREFIX xerces-c-3.1.1
  # #DEPENDS libxml2-2.9.1
  # #PATCH_COMMAND echo %cd%
  # CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_configure.cmake
  # BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_build.cmake
  # INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_install.cmake
# )


# ##############################################################################
# ##############################################################################
# #  
# ##############################################################################

