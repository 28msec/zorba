CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
INCLUDE(ExternalProject)
PROJECT(winports)

SET(SCRIPTS_DIR "scripts")
FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}")
##############################################################################
##############################################################################
#  PATCH
##############################################################################
SET(PATCH_PAK patch-2.5.9)
EXTERNALPROJECT_ADD (
  ${PATCH_PAK}
  URL http://kent.dl.sourceforge.net/project/gnuwin32/patch/2.5.9-7/patch-2.5.9-7-bin.zip
  URL_MD5 b9c8b31d62f4b2e4f1887bbb63e8a905
  PREFIX ${PATCH_PAK}
  #DEPENDS ${LIBXML2_PAK}
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
      ${CMAKE_CURRENT_BINARY_DIR}/${PATCH_PAK}/src/${PATCH_PAK}/bin 
      ${CMAKE_CURRENT_BINARY_DIR}/${PATCH_PAK}/bin
)
SET(PATCH_EXE ${CMAKE_CURRENT_BINARY_DIR}/${PATCH_PAK}/bin/patch.exe)

##############################################################################
##############################################################################
#  GRAPHVIZ
##############################################################################
SET(GRAPHVIZ_PAK graphviz-2.30.1)
EXTERNALPROJECT_ADD (
  ${GRAPHVIZ_PAK}
  URL http://www.graphviz.org/pub/graphviz/stable/windows/graphviz-2.30.1.zip
  URL_MD5 4a28bddcdfd00f8d1afffd91ee098172
  PREFIX ${GRAPHVIZ_PAK}
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND "" 
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/${GRAPHVIZ_PAK}/src/${GRAPHVIZ_PAK} 
    ${CMAKE_CURRENT_BINARY_DIR}/${GRAPHVIZ_PAK}
)

#############################################################################
##############################################################################
#  GEOS
##############################################################################
SET(GEOS_PAK geos-3.3.8)
#LIBGEOS PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos.patch "
90a91,93
> !ELSEIF \"$(_NMAKE_VER)\" == \"11.00.60315.1\"
> GEOS_MSVC = 11.0
> GEOS_MSC = 1700
")
#PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_patch.cmake "
  EXECUTE_PROCESS(COMMAND ${PATCH_EXE} nmake.opt ${CMAKE_CURRENT_BINARY_DIR}/libgeos.patch -f
  WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\"  )
")

#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND autogen.bat
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\"
  )
")
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_build.cmake "
  SET(ENV{INCLUDE} \"\$ENV{INCLUDE};C:\\\\Program Files (x86)\\\\Microsoft SDKs\\\\Windows\\\\v7.1A\\\\Include\")
  SET(ENV{INCLUDE} \"\$ENV{INCLUDE};C:\\\\Program Files (x86)\\\\Microsoft SDKs\\\\Windows\\\\v7.0A\\\\Include\")
  EXECUTE_PROCESS(
    COMMAND nmake /f makefile.vc MSVC_VER=1700
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\"
  )
")
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_install.cmake "
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/bin)
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/lib)
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}/src/geos.dll ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/bin/geos.dll
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}/src/geos.lib ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/lib/geos.lib
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}/src/geos_c.dll ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/bin/geos_c.dll
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}/src/geos_c_i.lib ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/lib/geos_c_i.lib
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}/src/geos_i.lib ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/lib/geos_i.lib
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}/include ${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/include
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${GEOS_PAK}/src/${GEOS_PAK}\" )
")
EXTERNALPROJECT_ADD (
  ${GEOS_PAK}
  URL http://download.osgeo.org/geos/geos-3.3.8.tar.bz2
  URL_MD5 75be476d0831a2d14958fed76ca266de
  PREFIX ${GEOS_PAK}
  DEPENDS ${PATCH_PAK}
  PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_patch.cmake
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_build.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libgeos_install.cmake
)

##############################################################################
##############################################################################
#  DOXYGEN
##############################################################################
SET(DOXYGEN_PAK doxygen-1.8.4)
EXTERNALPROJECT_ADD (
  ${DOXYGEN_PAK}
  #URL http://ftp.stack.nl/pub/users/dimitri/doxygen-1.8.4.windows.x64.bin.zip
  #URL_MD5 bcbb2140bba22a95cd915ba19340851a
  
  URL http://ftp.stack.nl/pub/users/dimitri/doxygen-1.8.4.windows.bin.zip
  URL_MD5 af35822049dac03e5ed96aaa672f9dc2
  PREFIX ${DOXYGEN_PAK}
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND  ${CMAKE_COMMAND} -E copy_directory 
      ${CMAKE_CURRENT_BINARY_DIR}/${DOXYGEN_PAK}/src/${DOXYGEN_PAK} 
      ${CMAKE_CURRENT_BINARY_DIR}/${DOXYGEN_PAK}
)

##############################################################################
##############################################################################
#  TIDY
##############################################################################
#PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_patch.cmake "
  FILE(GLOB TIDY_PROJECT \"${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/*.*\")
  FOREACH(TIDY_FILE \${TIDY_PROJECT})
    FILE(READ \${TIDY_FILE} FILE_TO_CHANGE)
    STRING(REPLACE \"\\n\" \"\\n\" FILE_TO_CHANGE \"\${FILE_TO_CHANGE}\")
    FILE(WRITE \${TIDY_FILE} \${FILE_TO_CHANGE})
  ENDFOREACH()
")
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv tidy.dsw /Upgrade
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/\"
  )
")
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_build.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv tidy.sln /Build \"Release|Win32\"
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/\"
  )
")
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_install.cmake "
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/Release/tidy.exe
        ${CMAKE_CURRENT_BINARY_DIR}/tidy/tidy.exe
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}\" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/ReleaseDLL/libtidy.dll
        ${CMAKE_CURRENT_BINARY_DIR}/tidy/libtidy.dll
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}\" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/ReleaseDLL/libtidy.lib
        ${CMAKE_CURRENT_BINARY_DIR}/tidy/libtidy.lib
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}\" )
")
EXTERNALPROJECT_ADD (
  tidy
  URL http://tidy.cvs.sourceforge.net/viewvc/tidy/tidy/?view=tar
  
  PREFIX tidy
  PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_patch.cmake
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_build.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libtidy_install.cmake
)

##############################################################################
##############################################################################
#  ZLIB
##############################################################################
SET(ZLIB1_PAK zlib-1.2.8)
EXTERNALPROJECT_ADD(
  ${ZLIB1_PAK}
  URL http://zlib.net/zlib128-dll.zip
  PREFIX ${ZLIB1_PAK}
  URL_MD5 42eccc2af5bac6b7a1188d7817d03549
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory 
      ${CMAKE_CURRENT_BINARY_DIR}/${ZLIB1_PAK}/src/${ZLIB1_PAK} 
      ${CMAKE_CURRENT_BINARY_DIR}/${ZLIB1_PAK}
)

##############################################################################
##############################################################################
#  PERL
##############################################################################
SET(PERL_PAK perl-5.16.3.1)
EXTERNALPROJECT_ADD(
  ${PERL_PAK}
  URL http://strawberryperl.com/download/5.16.3.1/strawberry-perl-5.16.3.1-32bit-portable.zip
  URL_MD5 8f3ef667e9a2b7fc402610da29bb8074
  PREFIX ${PERL_PAK}
  #SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/perl-5.16.3.1
  PATCH_COMMAND  ""
  CONFIGURE_COMMAND  ""
  BUILD_COMMAND  ""
  INSTALL_COMMAND  ""
)
SET(PERL_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PERL_PAK}/src/${PERL_PAK}/perl/bin/)

##############################################################################
##############################################################################
#  OPENSSL
##############################################################################
SET(OPENSSL_PAK openssl-1.0.1e)
#Patch for linux archiver
ADD_SUBDIRECTORY(openssl)

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libopenssl_configure.cmake "

  SET(ENV{PATH} \"\$ENV{PATH};${PERL_PATH}\")
  
  EXECUTE_PROCESS(
    COMMAND perl
    Configure enable-camellia 
    --openssldir=${CMAKE_CURRENT_BINARY_DIR}/${OPENSSL_PAK} 
    VC-WIN32
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${OPENSSL_PAK}/src/${OPENSSL_PAK}\"
  )
  
  EXECUTE_PROCESS(
    COMMAND \"${CMAKE_CURRENT_BINARY_DIR}/${OPENSSL_PAK}/src/${OPENSSL_PAK}/ms/do_nt.bat\"
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${OPENSSL_PAK}/src/${OPENSSL_PAK}\"
  )
")
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libopenssl_nmake.cmake "
  SET(ENV{PATH} \"\$ENV{PATH};${PERL_PATH}\")
  EXECUTE_PROCESS(
    COMMAND nmake /f ms/ntdll.mak
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${OPENSSL_PAK}/src/${OPENSSL_PAK}\"
  )
")
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libopenssl_install.cmake "
  SET(ENV{PATH} \"\$ENV{PATH};${PERL_PATH}\")
  EXECUTE_PROCESS(
    COMMAND nmake /f ms/ntdll.mak install
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${OPENSSL_PAK}/src/${OPENSSL_PAK}\"
  )
")


EXTERNALPROJECT_ADD(
  ${OPENSSL_PAK}
  #fixed file
  URL file://${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e.zip
  DEPENDS opensslzip ${PERL_PAK}
  PREFIX ${OPENSSL_PAK}
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libopenssl_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libopenssl_nmake.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libopenssl_install.cmake
)
SET(OPENSSL_ROOT ${CMAKE_CURRENT_BINARY_DIR}/${OPENSSL_PAK})


##############################################################################
##############################################################################
#  LIBCURL
##############################################################################
SET(LIBCURL_PAK libcurl-7.29.0)
EXTERNALPROJECT_ADD(
  ${LIBCURL_PAK}
  URL http://curl.haxx.se/download/curl-7.29.0.tar.gz
  URL_MD5 4f57d3b4a3963038bd5e04dbff385390
  PREFIX ${LIBCURL_PAK}
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/${LIBCURL_PAK}
             -DBUILD_CURL_EXE=ON -DBUILD_CURL_TESTS=OFF 
             -DCMAKE_USE_OPENSSL=ON -DOPENSSL_ROOT_DIR=${OPENSSL_ROOT}
             -DCURL_ZLIB=ON 
             -DHTTP_ONLY=OFF 
             -DCMAKE_BUILD_TYPE=RELEASE
)

##############################################################################
##############################################################################
#  LIBICONV
##############################################################################
SET(LIBICONV_PAK libiconv-1.14)
EXTERNALPROJECT_ADD(
  ${LIBICONV_PAK}
  DEPENDS ${PATCH_PAK}
  URL http://ftp.gnu.org/pub/gnu/libiconv/libiconv-1.14.tar.gz
  URL_MD5 e34509b1623cec449dfeb73d7ce9c6c6
  PREFIX ${LIBICONV_PAK}
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/${LIBICONV_PAK} -DCMAKE_BUILD_TYPE=RELEASE
  PATCH_COMMAND ${CMAKE_COMMAND} -D PATCH_COMMAND=${PATCH_EXE} -D CMAKELISTS_DIR=${CMAKE_CURRENT_SOURCE_DIR}/libiconv -P ${CMAKE_CURRENT_SOURCE_DIR}/libiconv/move.cmake
)

##############################################################################
##############################################################################
#  LIBXML2
##############################################################################
SET(LIBXML2_PAK libxml2-2.9.1)
SET(LIBXML2_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/${LIBXML2_PAK}/src/${LIBXML2_PAK}/win32)
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxml2_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND assoc .js=JSFile
  )    
  EXECUTE_PROCESS(
    COMMAND cscript configure.js compiler=msvc 
    prefix=..\\\\..\\\\..
    iconv=no
    zlib=yes
    include=${CMAKE_CURRENT_BINARY_DIR}/${ZLIB1_PAK}/include
    lib=${CMAKE_CURRENT_BINARY_DIR}/${ZLIB1_PAK}/lib
    WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  )"
)
#MAKE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxml2_nmake.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc
    WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  )"
)
#MAKE INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxml2_nmake_install.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc install
    WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  )"
)
#CONFIGURE, MAKE AND INSTALL
EXTERNALPROJECT_ADD(
  ${LIBXML2_PAK}
  URL ftp://xmlsoft.org/libxml2/libxml2-2.9.1.tar.gz
  URL_MD5 9c0cfef285d5c4a5c80d00904ddab380
  PREFIX ${LIBXML2_PAK}
  DEPENDS ${ZLIB1_PAK} ${LIBICONV_PAK}
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxml2_configure.cmake
  BUILD_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxml2_nmake.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxml2_nmake_install.cmake
)


##############################################################################
##############################################################################
#  LIBXSLT
##############################################################################
SET(LIBXSLT_PAK libxslt-1.1.28)
SET(LIBXSLT_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/${LIBXSLT_PAK}/src/${LIBXSLT_PAK}/win32)
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND cscript configure.js compiler=msvc 
    prefix=..\\\\..\\\\..
    iconv=no
    zlib=yes
    xslt_debug=no
    include=${CMAKE_CURRENT_BINARY_DIR}/${LIBXML2_PAK}/include/libxml2
    lib=${CMAKE_CURRENT_BINARY_DIR}/${LIBXML2_PAK}/lib
    WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  ) "
)
#MAKE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_nmake.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc
    WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  ) "
)
#MAKE INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_nmake_install.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc install
    WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  ) "
)
#MAKE PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_patch.cmake 
"
  FILE(READ \"${LIBXSLT_WIN32_DIR}/Makefile.msvc\" LIBXSLT_MAKEFILE)
  STRING(REPLACE \"LDFLAGS = $(LDFLAGS) /OPT:NOWIN98\" \"#LDFLAGS = $(LDFLAGS) /OPT:NOWIN98\" LIBXSLT_MAKEFILE \"\${LIBXSLT_MAKEFILE}\")
  FILE(WRITE \"${LIBXSLT_WIN32_DIR}/Makefile.msvc\" \${LIBXSLT_MAKEFILE})
" 
)
#CONFIGURE, MAKE AND INSTALL
EXTERNALPROJECT_ADD (
  ${LIBXSLT_PAK}
  URL ftp://xmlsoft.org/libxslt/libxslt-1.1.28.tar.gz
  URL_MD5 9667bf6f9310b957254fdcf6596600b7
  PREFIX ${LIBXSLT_PAK}
  DEPENDS ${LIBXML2_PAK}
  PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_patch.cmake
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_configure.cmake
  BUILD_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_nmake.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libxslt_nmake_install.cmake
)

##############################################################################
##############################################################################
#  ICU
##############################################################################
SET(LIBICU_PAK icu4c-4_8_1_1)
SET(LIBICU_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/${LIBICU_PAK}/src/${LIBICU_PAK}/source/allinone)
SET(LIBICU_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/${LIBICU_PAK} )
SET(LIBICU_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/${LIBICU_PAK}/src/${LIBICU_PAK} )
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libicu_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv /upgrade allinone.sln
    WORKING_DIRECTORY \"${LIBICU_WIN32_DIR}\"
  ) "
)
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libicu_build.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv allinone.sln /build \"Release|Win32\"
    WORKING_DIRECTORY \"${LIBICU_WIN32_DIR}\"
  ) "
)
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libicu_install.cmake "
  EXECUTE_PROCESS (
    COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${LIBICU_BUILD_DIR}/bin\" \"${LIBICU_INSTALL_DIR}/bin\"
    WORKING_DIRECTORY \"${LIBICU_INSTALL_DIR}/bin\"
  ) 
  EXECUTE_PROCESS (
    COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${LIBICU_BUILD_DIR}/include\" \"${LIBICU_INSTALL_DIR}/include\"
    WORKING_DIRECTORY \"${LIBICU_INSTALL_DIR}/include\"
  ) 
  EXECUTE_PROCESS (
    COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${LIBICU_BUILD_DIR}/lib\" \"${LIBICU_INSTALL_DIR}/lib\"
    WORKING_DIRECTORY \"${LIBICU_INSTALL_DIR}/lib\"
  ) "
)
#CONFIGURE, MAKE AND INSTALL
EXTERNALPROJECT_ADD (
  ${LIBICU_PAK}
  #ICU 5.1
  #URL http://download.icu-project.org/files/icu4c/51.1/icu4c-51_1-src.zip
  #URL_MD5 b4303a43caa79018e3b6ec18148fdb1a
  #ICU 4.8
  URL http://download.icu-project.org/files/icu4c/4.8.1.1/icu4c-4_8_1_1-src.zip
  URL_MD5 890862544bdb9012f5758bd76e82c2b4
  PREFIX ${LIBICU_PAK}
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libicu_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libicu_build.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libicu_install.cmake
)

##############################################################################
##############################################################################
#  XERCES
##############################################################################
SET(XERCES_PAK xerces-c-3.1.1)
SET(XERCES_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/${XERCES_PAK}/src/${XERCES_PAK}/projects/Win32/VC10/xerces-all)
SET(XERCES_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/${XERCES_PAK} )
SET(XERCES_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/${XERCES_PAK}/src/${XERCES_PAK} )
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libXERCES_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv /upgrade xerces-all.sln
    WORKING_DIRECTORY \"${XERCES_WIN32_DIR}\"
  ) "
)
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libXERCES_build.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv xerces-all.sln /build \"Release|Win32\"
    WORKING_DIRECTORY \"${XERCES_WIN32_DIR}\"
  ) "
)
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libXERCES_install.cmake 
" 
  FILE(MAKE_DIRECTORY \"${XERCES_INSTALL_DIR}/lib\")
  EXECUTE_PROCESS (
    COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${XERCES_BUILD_DIR}/src\" \"${XERCES_INSTALL_DIR}/include\"
    WORKING_DIRECTORY \"${XERCES_INSTALL_DIR}\"
  ) 
  EXECUTE_PROCESS (
    COMMAND ${CMAKE_COMMAND} -E copy_directory  \"${XERCES_BUILD_DIR}/Build/Win32/VC10/Release\" \"${XERCES_INSTALL_DIR}/bin\"
    WORKING_DIRECTORY \"${XERCES_INSTALL_DIR}\"
  ) 
  EXECUTE_PROCESS (
    COMMAND ${CMAKE_COMMAND} -E copy  \"${XERCES_BUILD_DIR}/Build/Win32/VC10/Release/xerces-c_3.lib\" \"${XERCES_INSTALL_DIR}/lib/xerces-c_3.lib\"
    WORKING_DIRECTORY \"${XERCES_INSTALL_DIR}\"
  ) 
  FILE(GLOB_RECURSE XERCES_CPP_FILES \"${XERCES_INSTALL_DIR}/include/*.cpp\")
  FOREACH(XERCES_CPP IN ITEMS \${XERCES_CPP_FILES})
    FILE(REMOVE \${XERCES_CPP})
  ENDFOREACH()
  
")
#CONFIGURE, MAKE AND INSTALL
EXTERNALPROJECT_ADD (
  ${XERCES_PAK}
  URL http://www.apache.org/dist/xerces/c/3/sources/xerces-c-3.1.1.zip
  URL_MD5 a42e0a35b8be37667bb7df6fb51feded
  PREFIX ${XERCES_PAK}
  #DEPENDS ${LIBXML2_PAK}
  #PATCH_COMMAND echo %cd%
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libXERCES_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libXERCES_build.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/libXERCES_install.cmake
)

##############################################################################
##############################################################################
#  SWIG 2.0.10
##############################################################################
SET(SWIG_PAK swigwin-2.0.10)
EXTERNALPROJECT_ADD(
  ${SWIG_PAK}
  URL http://hivelocity.dl.sourceforge.net/project/swig/swigwin/swigwin-2.0.10/swigwin-2.0.10.zip
  URL_MD5 d41d8cd98f00b204e9800998ecf8427e
  PREFIX ${SWIG_PAK}
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory 
      ${CMAKE_CURRENT_BINARY_DIR}/${SWIG_PAK}/src/${SWIG_PAK}
      ${CMAKE_CURRENT_BINARY_DIR}/${SWIG_PAK}
)

##############################################################################
##############################################################################
#  PYTHON 2.7.5
##############################################################################
SET(PYTHON_PAK python-2.7.5)
SET(PYTHON_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/PCBuild)
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/python_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv /upgrade pcbuild.sln
    WORKING_DIRECTORY \"${PYTHON_WIN32_DIR}\"
  )
")
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/python_build.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv pcbuild.sln /build \"Debug|Win32\"
    WORKING_DIRECTORY \"${PYTHON_WIN32_DIR}\"
  )
  EXECUTE_PROCESS(
    COMMAND devenv pcbuild.sln /build \"Release|Win32\"
    WORKING_DIRECTORY \"${PYTHON_WIN32_DIR}\"
  )
")
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/python_install.cmake "
  FILE(RENAME ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/Doc 
              ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/Doc )
  FILE(RENAME ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/Lib
              ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/Lib )
  FILE(RENAME ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/Tools
              ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/Tools )
  FILE(RENAME ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/Include
              ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/Include )

  #all .h
  FILE(GLOB PYTHON_FILES 
            \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/PC/*.h\")
  FOREACH(PYTHON_FILE \${PYTHON_FILES})
    CONFIGURE_FILE(\${PYTHON_FILE} \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/Include\" COPYONLY)
  ENDFOREACH()

  #all dlls
  FILE(MAKE_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/DLLs\") 
  FILE(GLOB PYTHON_FILES 
            \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/PCBuild/*.pyd\" 
            \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/PCBuild/*.dll\")
  FOREACH(PYTHON_FILE \${PYTHON_FILES})
    CONFIGURE_FILE(\${PYTHON_FILE} \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/DLLs\" COPYONLY)
  ENDFOREACH()

  #exe and dlls
  FILE(GLOB PYTHON_FILES 
            \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/PCBuild/*.exe\" 
            \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/PCBuild/*.dll\")
  FOREACH(PYTHON_FILE \${PYTHON_FILES})
    CONFIGURE_FILE(\${PYTHON_FILE} \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}\" COPYONLY)
  ENDFOREACH()

  # libs
  FILE(MAKE_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/libs\") 
  FILE(GLOB PYTHON_FILES 
            \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/src/${PYTHON_PAK}/PCBuild/*.lib\")
  FOREACH(PYTHON_FILE \${PYTHON_FILES})
    CONFIGURE_FILE(\${PYTHON_FILE} \"${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_PAK}/libs\" COPYONLY)
  ENDFOREACH()
")

EXTERNALPROJECT_ADD(
  ${PYTHON_PAK}
  URL http://www.python.org/ftp/python/2.7.5/Python-2.7.5.tgz
  URL_MD5 b4f01a1d0ba0b46b05c73b2ac909b1df
  PREFIX ${PYTHON_PAK}
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/python_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/python_build.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/python_install.cmake
)

##############################################################################
##############################################################################
#  RUBY 2.0.0
##############################################################################
SET(RUBY_PAK ruby-2.0.0)
SET(RUBY_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/${RUBY_PAK}/src/${RUBY_PAK}/Win32)
SET(RUBY_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/${RUBY_PAK} )
SET(RUBY_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/${RUBY_PAK}/build )
FILE(MAKE_DIRECTORY ${RUBY_BUILD_DIR})
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/ruby_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND \"${RUBY_WIN32_DIR}/configure.bat --prefix=\\\"\\\"\"
    WORKING_DIRECTORY \"${RUBY_BUILD_DIR}\"
  )
")
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/ruby_build.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake
    WORKING_DIRECTORY \"${RUBY_BUILD_DIR}\"
  )
")
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/ruby_install.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake DESTDIR=${RUBY_INSTALL_DIR} install
    WORKING_DIRECTORY \"${RUBY_BUILD_DIR}\"
  )
")

EXTERNALPROJECT_ADD(
  ${RUBY_PAK}
  URL http://cache.ruby-lang.org/pub/ruby/2.0/ruby-2.0.0-p247.tar.gz
  URL_MD5 c351450a0bed670e0f5ca07da3458a5b
  PREFIX ${RUBY_PAK}
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/ruby_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/ruby_build.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/ruby_install.cmake
)

##############################################################################
##############################################################################
#  PHP 5.5
##############################################################################
SET(PHP_PAK php-5.5)
SET(PHP_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/${PHP_PAK}/src/${PHP_PAK}/Win32)
SET(PHP_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/${PHP_PAK} )
SET(PHP_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/${PHP_PAK}/build )

FILE(MAKE_DIRECTORY ${PHP_BUILD_DIR})
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/php_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND \"${PHP_WIN32_DIR}/configure.bat\"
    WORKING_DIRECTORY \"${PHP_BUILD_DIR}\"
  )
")
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/php_build.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake
    WORKING_DIRECTORY \"${PHP_BUILD_DIR}\"
  )
")
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/php_install.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake DESTDIR=${PHP_INSTALL_DIR} install
    WORKING_DIRECTORY \"${PHP_BUILD_DIR}\"
  )
  FILE(RENAME ${PHP_INSTALL_DIR}/usr/bin ${PHP_INSTALL_DIR}/bin)
  FILE(RENAME ${PHP_INSTALL_DIR}/usr/include ${PHP_INSTALL_DIR}/include)
  FILE(RENAME ${PHP_INSTALL_DIR}/usr/lib ${PHP_INSTALL_DIR}/lib)
  FILE(RENAME ${PHP_INSTALL_DIR}/usr/share ${PHP_INSTALL_DIR}/share)
")

EXTERNALPROJECT_ADD(
  ${PHP_PAK}
  URL http://cache.php-lang.org/pub/php/2.0/php-2.0.0-p247.tar.gz
  URL_MD5 c351450a0bed670e0f5ca07da3458a5b
  PREFIX ${PHP_PAK}
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/php_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/php_build.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/php_install.cmake
)

##############################################################################
##############################################################################
#  CLEANUP
##############################################################################
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/cleanup.cmake "
  FILE(GLOB TEMP_FILES \"${CMAKE_CURRENT_BINARY_DIR}/lib*.cmake\" \"${CMAKE_CURRENT_BINARY_DIR}/python*.cmake\")
  FOREACH(TEMP_F \${TEMP_FILES})
    FILE(REMOVE \${TEMP_F})
  ENDFOREACH()
")
EXTERNALPROJECT_ADD (
  CLEANUP
  URL ${CMAKE_CURRENT_SOURCE_DIR}/cleanup.zip
  PREFIX CLEANUP
  DEPENDS opensslzip tidy 
          ${DOXYGEN_PAK} ${GEOS_PAK} ${GRAPHVIZ_PAK} ${LIBICU_PAK} ${LIBCURL_PAK} ${LIBXSLT_PAK} ${LIBXML2_PAK} 
          ${PERL_PAK} ${ZLIB1_PAK} ${SWIG_PAK} ${XERCES_PAK} ${OPENSSL_PAK} ${PYTHON_PAK} ${RUBY_PAK}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPTS_DIR}/cleanup.cmake
  INSTALL_COMMAND  ""
)

##############################################################################
##############################################################################
#  
##############################################################################




MESSAGE(STATUS "Directory to set with ZORBA_THIRD_PARTY_REQUIREMENTS: " ${CMAKE_CURRENT_BINARY_DIR})



