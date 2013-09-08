CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
INCLUDE(ExternalProject)

##############################################################################
##############################################################################
#  PREPARE OPENSSL
##############################################################################
##############################################################################

SET (GNU_BIN ${CMAKE_CURRENT_BINARY_DIR}/bin)
FILE(MAKE_DIRECTORY ${GNU_BIN})

##############################################################################
##############################################################################
#  GZIP
##############################################################################
#FILE(DOWNLOAD ${PACKAGE_URL} ${LIB_DOWNLOADS}\\${PACKAGE_NAME}.zip SHOW_PROGRESS EXPECTED_MD5 "${PACKAGE_MD5}" )
SET(GZIP_PAK gzip-1.3.12-1)
 EXTERNALPROJECT_ADD (
  ${GZIP_PAK}
  URL http://hivelocity.dl.sourceforge.net/project/gnuwin32/gzip/1.3.12-1/gzip-1.3.12-1-bin.zip
  URL_MD5 b24802293f74ab11aaa5786f36c59819
  PREFIX ${GZIP_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${GZIP_PAK}/src/${GZIP_PAK}/bin 
    ${GNU_BIN}
  INSTALL_COMMAND ""
)

##############################################################################
##############################################################################
#  ZIP
##############################################################################
SET(ZIP_PAK zip-3.0)
EXTERNALPROJECT_ADD (
  ${ZIP_PAK}
  URL http://superb-dca3.dl.sourceforge.net/project/gnuwin32/zip/3.0/zip-3.0-bin.zip
  URL_MD5 5b268fe06ce5f89bc5762805a7a9d7aa
  DEPENDS ${GZIP_PAK}
  PREFIX ${ZIP_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${ZIP_PAK}/src/${ZIP_PAK}/bin 
    ${GNU_BIN}
  INSTALL_COMMAND ""
)

##############################################################################
##############################################################################
#  BZIP2
##############################################################################
SET(BZIP2_PAK bzip2-1.0.5)
EXTERNALPROJECT_ADD (
  ${BZIP2_PAK}
  URL http://hivelocity.dl.sourceforge.net/project/gnuwin32/bzip2/1.0.5/bzip2-1.0.5-bin.zip
  URL_MD5 a1155c41b1954a2f6da1014c7c1a1263
  DEPENDS ${ZIP_PAK}
  PREFIX ${BZIP2_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${BZIP2_PAK}/src/${BZIP2_PAK}/bin 
    ${GNU_BIN}
  INSTALL_COMMAND ""
)

##############################################################################
##############################################################################
#  BSDTAR
##############################################################################
SET(BSDTAR_PAK libarchive-2.4.12-1)
EXTERNALPROJECT_ADD (
  ${BSDTAR_PAK}
  URL http://iweb.dl.sourceforge.net/project/gnuwin32/libarchive/2.4.12-1/libarchive-2.4.12-1-bin.zip
  URL_MD5 f2bd5a4ee39d9fc64b456d516f90afad
  DEPENDS ${BZIP2_PAK}
  PREFIX ${BSDTAR_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${BSDTAR_PAK}/src/${BSDTAR_PAK}/bin 
    ${GNU_BIN}
  INSTALL_COMMAND ""
)

##############################################################################
##############################################################################
#  TAR
##############################################################################
SET(TAR_PAK tar-1.13-1)
EXTERNALPROJECT_ADD (
  ${TAR_PAK}
  URL http://iweb.dl.sourceforge.net/project/gnuwin32/tar/1.13-1/tar-1.13-1-bin.zip
  URL_MD5 a92857ec82db569f0a8fa5370642dc69
  DEPENDS ${BSDTAR_PAK}
  PREFIX ${TAR_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${TAR_PAK}/src/${TAR_PAK}/bin 
    ${GNU_BIN}
  INSTALL_COMMAND ""
)

##############################################################################
##############################################################################
#  LIBINTL
##############################################################################
SET(LIBINTL_PAK libintl-0.11.5-2)
EXTERNALPROJECT_ADD (
  ${LIBINTL_PAK}
  URL http://kent.dl.sourceforge.net/project/gnuwin32/libintl/0.11.5-2/libintl-0.11.5-2-bin.zip
  URL_MD5 220c1168c34fe0f4f3ed50fa50b66942
  DEPENDS ${TAR_PAK}
  PREFIX ${LIBINTL_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBINTL_PAK}/src/${LIBINTL_PAK}/bin 
    ${GNU_BIN}
  INSTALL_COMMAND ""
)
##############################################################################
##############################################################################
#  ZLIB
##############################################################################
SET(ZLIB_PAK zlib128-dll)
EXTERNALPROJECT_ADD (
  ${ZLIB_PAK}
  URL http://softlayer-dal.dl.sourceforge.net/project/libpng/zlib/1.2.8/zlib128-dll.zip
  URL_MD5 42eccc2af5bac6b7a1188d7817d03549
  DEPENDS ${LIBINTL_PAK}
  PREFIX ${ZLIB_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${ZLIB_PAK}/src/${ZLIB_PAK} 
    ${GNU_BIN}
  INSTALL_COMMAND ""
)


##############################################################################
##############################################################################
#  OPENSSL
##############################################################################
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_tar.cmake "
  SET(ENV{PATH} \"\$ENV{PATH};${GNU_BIN}\")
  FILE(DOWNLOAD http://www.openssl.org/source/openssl-1.0.1e.tar.gz ${CMAKE_CURRENT_BINARY_DIR}/openssl.tar.gz SHOW_PROGRESS)
  EXECUTE_PROCESS( COMMAND bsdtar -xf openssl.tar.gz WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )
  MESSAGE(STATUS \"Re-extracting to avoid previous path errors.\")
  EXECUTE_PROCESS( COMMAND bsdtar -xf openssl.tar.gz WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )
  MESSAGE(STATUS \"Compresing in a Zip file.\")
  EXECUTE_PROCESS( COMMAND zip -rq openssl-1.0.1e.zip openssl-1.0.1e WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )
  
")


SET(LIBOPENSSL_ZIP_PAK opensslzip)
EXTERNALPROJECT_ADD (
  ${LIBOPENSSL_ZIP_PAK}
  # dummy file
  URL http://kent.dl.sourceforge.net/project/gnuwin32/patch/2.5.9-7/patch-2.5.9-7-bin.zip
  URL_MD5 b9c8b31d62f4b2e4f1887bbb63e8a905
  DEPENDS ${ZLIB_PAK}
  PREFIX ${LIBOPENSSL_ZIP_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_tar.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy 
      ${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e.zip 
      ${CMAKE_CURRENT_BINARY_DIR}/../openssl-1.0.1e.zip
)


