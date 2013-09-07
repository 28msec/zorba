CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
INCLUDE(ExternalProject)
PROJECT(winports)

##############################################################################
##############################################################################
#  PATCH
##############################################################################
 EXTERNALPROJECT_ADD (
  patch-2.5.9
  URL http://kent.dl.sourceforge.net/project/gnuwin32/patch/2.5.9-7/patch-2.5.9-7-bin.zip
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
#  GRAPHVIZ
##############################################################################
EXTERNALPROJECT_ADD (
  graphviz-2.30.1
  URL http://www.graphviz.org/pub/graphviz/stable/windows/graphviz-2.30.1.zip
  URL_MD5 4a28bddcdfd00f8d1afffd91ee098172
  PREFIX graphviz-2.30.1
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND "" 
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/graphviz-2.30.1/src/graphviz-2.30.1 ${CMAKE_CURRENT_BINARY_DIR}/graphviz-2.30.1
)

#############################################################################
##############################################################################
#  GEOS
##############################################################################
#LIBGEOS PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libgeos.patch "
90a91,93
> !ELSEIF \"$(_NMAKE_VER)\" == \"11.00.60315.1\"
> GEOS_MSVC = 11.0
> GEOS_MSC = 1700
")
#PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libgeos_patch.cmake "
  EXECUTE_PROCESS(COMMAND ${PATCH_COMMAND} nmake.opt ${CMAKE_CURRENT_BINARY_DIR}/libgeos.patch -f
  WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\"  )
")

#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libgeos_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND autogen.bat
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\"
  )
")
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libgeos_build.cmake "
  SET(ENV{INCLUDE} \"\$ENV{INCLUDE};C:\\\\Program Files (x86)\\\\Microsoft SDKs\\\\Windows\\\\v7.1A\\\\Include\")
  SET(ENV{INCLUDE} \"\$ENV{INCLUDE};C:\\\\Program Files (x86)\\\\Microsoft SDKs\\\\Windows\\\\v7.0A\\\\Include\")
  EXECUTE_PROCESS(
    COMMAND nmake /f makefile.vc MSVC_VER=1700
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\"
  )
")
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libgeos_install.cmake "
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/bin)
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/lib)
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8/src/geos.dll ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/bin/geos.dll
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8/src/geos.lib ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/lib/geos.lib
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8/src/geos_c.dll ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/bin/geos_c.dll
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8/src/geos_c_i.lib ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/lib/geos_c_i.lib
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8/src/geos_i.lib ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/lib/geos_i.lib
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\" )
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8/include ${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/include
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/geos-3.3.8/src/geos-3.3.8\" )
")
EXTERNALPROJECT_ADD (
  geos-3.3.8
  URL http://download.osgeo.org/geos/geos-3.3.8.tar.bz2
  URL_MD5 75be476d0831a2d14958fed76ca266de
  PREFIX geos-3.3.8
  DEPENDS patch-2.5.9
  PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libgeos_patch.cmake
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libgeos_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libgeos_build.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libgeos_install.cmake
)

##############################################################################
##############################################################################
#  DOXYGEN
##############################################################################
EXTERNALPROJECT_ADD (
  doxygen-1.8.4
  #URL http://ftp.stack.nl/pub/users/dimitri/doxygen-1.8.4.windows.x64.bin.zip
  #URL_MD5 bcbb2140bba22a95cd915ba19340851a
  
  URL http://ftp.stack.nl/pub/users/dimitri/doxygen-1.8.4.windows.bin.zip
  URL_MD5 af35822049dac03e5ed96aaa672f9dc2
  PREFIX doxygen-1.8.4
  PATCH_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND  ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/doxygen-1.8.4/src/doxygen-1.8.4 ${CMAKE_CURRENT_BINARY_DIR}/doxygen-1.8.4
)

##############################################################################
##############################################################################
#  TIDY
##############################################################################
#PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libtidy_patch.cmake "
  FILE(GLOB TIDY_PROJECT \"${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/*.*\")
  FOREACH(TIDY_FILE \${TIDY_PROJECT})
    FILE(READ \${TIDY_FILE} FILE_TO_CHANGE)
    STRING(REPLACE \"\\n\" \"\\n\" FILE_TO_CHANGE \"\${FILE_TO_CHANGE}\")
    FILE(WRITE \${TIDY_FILE} \${FILE_TO_CHANGE})
  ENDFOREACH()
")
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libtidy_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv tidy.dsw /Upgrade
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/\"
  )
")
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libtidy_build.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv tidy.sln /Build \"Release|Win32\"
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/tidy/src/tidy/build/msvc/\"
  )
")
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libtidy_install.cmake "
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
  PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libtidy_patch.cmake
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libtidy_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libtidy_build.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libtidy_install.cmake
)

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
  URL http://strawberryperl.com/download/5.16.3.1/strawberry-perl-5.16.3.1-32bit-portable.zip
  URL_MD5 8f3ef667e9a2b7fc402610da29bb8074
  PREFIX perl-5.16.3.1
  #SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/perl-5.16.3.1
  PATCH_COMMAND  ""
  CONFIGURE_COMMAND  ""
  BUILD_COMMAND  ""
  INSTALL_COMMAND  ""
)
SET(PERL_PATH ${CMAKE_CURRENT_BINARY_DIR}/perl-5.16.3.1/src/perl-5.16.3.1/perl/bin/)

##############################################################################
##############################################################################
#  OPENSSL
##############################################################################
#Patch for linux archiver
ADD_SUBDIRECTORY(openssl)

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_configure.cmake "

  SET(ENV{PATH} \"\$ENV{PATH};${PERL_PATH}\")
  
  EXECUTE_PROCESS(
    COMMAND perl
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
  SET(ENV{PATH} \"\$ENV{PATH};${PERL_PATH}\")
  EXECUTE_PROCESS(
    COMMAND nmake /f ms/ntdll.mak
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e\"
  )
")
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_install.cmake "
  SET(ENV{PATH} \"\$ENV{PATH};${PERL_PATH}\")
  EXECUTE_PROCESS(
    COMMAND nmake /f ms/ntdll.mak install
    WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e/src/openssl-1.0.1e\"
  )
")


EXTERNALPROJECT_ADD(
  openssl-1.0.1e
  #fixed file
  URL file://${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e.zip
  DEPENDS opensslzip
  PREFIX openssl-1.0.1e
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_nmake.cmake
  INSTALL_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libopenssl_install.cmake
)
SET(OPENSSL_ROOT ${CMAKE_CURRENT_BINARY_DIR}/openssl-1.0.1e)


##############################################################################
##############################################################################
#  LIBCURL
##############################################################################
EXTERNALPROJECT_ADD(
  libcurl-7.29.0
  URL http://curl.haxx.se/download/curl-7.29.0.tar.gz
  URL_MD5 4f57d3b4a3963038bd5e04dbff385390
  PREFIX libcurl-7.29.0
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/libcurl-7.29.0
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
EXTERNALPROJECT_ADD(
  libiconv-1.14
  DEPENDS patch-2.5.9
  URL http://ftp.gnu.org/pub/gnu/libiconv/libiconv-1.14.tar.gz
  URL_MD5 e34509b1623cec449dfeb73d7ce9c6c6
  PREFIX libiconv-1.14
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/libiconv-1.14 -DCMAKE_BUILD_TYPE=RELEASE
  PATCH_COMMAND ${CMAKE_COMMAND} -D PATCH_COMMAND=${PATCH_COMMAND} -D CMAKELISTS_DIR=${CMAKE_CURRENT_SOURCE_DIR}/libiconv -P ${CMAKE_CURRENT_SOURCE_DIR}/libiconv/move.cmake
)

##############################################################################
##############################################################################
#  LIBXML2
##############################################################################
SET(LIBXML2_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/libxml2-2.9.1/src/libxml2-2.9.1/win32)
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxml2_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND assoc .js=JSFile
  )    
  EXECUTE_PROCESS(
    COMMAND cscript configure.js compiler=msvc 
    prefix=..\\\\..\\\\..
    iconv=no
    zlib=yes
    include=${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.8/include
    lib=${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.8/lib
    WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  )"
)
#MAKE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc
    WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  )"
)
#MAKE INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake_install.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc install
    WORKING_DIRECTORY \"${LIBXML2_WIN32_DIR}\"
  )"
)
#CONFIGURE, MAKE AND INSTALL
EXTERNALPROJECT_ADD(
  libxml2-2.9.1
  URL ftp://xmlsoft.org/libxml2/libxml2-2.9.1.tar.gz
  URL_MD5 9c0cfef285d5c4a5c80d00904ddab380
  PREFIX libxml2-2.9.1
  DEPENDS zlib-1.2.8 libiconv-1.14
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxml2_configure.cmake
  BUILD_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxml2_nmake_install.cmake
)


##############################################################################
##############################################################################
#  LIBXSLT
##############################################################################
SET(LIBXSLT_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/libxslt-1.1.28/src/libxslt-1.1.28/win32)
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND cscript configure.js compiler=msvc 
    prefix=..\\\\..\\\\..
    iconv=no
    zlib=yes
    xslt_debug=no
    include=${CMAKE_CURRENT_BINARY_DIR}/libxml2-2.9.1/include/libxml2
    lib=${CMAKE_CURRENT_BINARY_DIR}/libxml2-2.9.1/lib
    WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  ) "
)
#MAKE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc
    WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  ) "
)
#MAKE INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake_install.cmake "
  EXECUTE_PROCESS(
    COMMAND nmake /f Makefile.msvc install
    WORKING_DIRECTORY \"${LIBXSLT_WIN32_DIR}\"
  ) "
)
#MAKE PATCH FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libxslt_patch.cmake 
"
  FILE(READ \"${LIBXSLT_WIN32_DIR}/Makefile.msvc\" LIBXSLT_MAKEFILE)
  STRING(REPLACE \"LDFLAGS = $(LDFLAGS) /OPT:NOWIN98\" \"#LDFLAGS = $(LDFLAGS) /OPT:NOWIN98\" LIBXSLT_MAKEFILE \"\${LIBXSLT_MAKEFILE}\")
  FILE(WRITE \"${LIBXSLT_WIN32_DIR}/Makefile.msvc\" \${LIBXSLT_MAKEFILE})
" 
)
#CONFIGURE, MAKE AND INSTALL
EXTERNALPROJECT_ADD (
  libxslt-1.1.28
  URL ftp://xmlsoft.org/libxslt/libxslt-1.1.28.tar.gz
  URL_MD5 9667bf6f9310b957254fdcf6596600b7
  PREFIX libxslt-1.1.28
  DEPENDS libxml2-2.9.1
  PATCH_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_patch.cmake
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_configure.cmake
  BUILD_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libxslt_nmake_install.cmake
)

##############################################################################
##############################################################################
#  ICU
##############################################################################
SET(LIBICU_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/icu4c-4_8_1_1/src/icu4c-4_8_1_1/source/allinone)
SET(LIBICU_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/icu4c-4_8_1_1 )
SET(LIBICU_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/icu4c-4_8_1_1/src/icu4c-4_8_1_1 )
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libicu_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv /upgrade allinone.sln
    WORKING_DIRECTORY \"${LIBICU_WIN32_DIR}\"
  ) "
)
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libicu_build.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv allinone.sln /build \"Release|Win32\"
    WORKING_DIRECTORY \"${LIBICU_WIN32_DIR}\"
  ) "
)
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libicu_install.cmake "
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
  icu4c-4_8_1_1
  #ICU 5.1
  #URL http://download.icu-project.org/files/icu4c/51.1/icu4c-51_1-src.zip
  #URL_MD5 b4303a43caa79018e3b6ec18148fdb1a
  #ICU 4.8
  URL http://download.icu-project.org/files/icu4c/4.8.1.1/icu4c-4_8_1_1-src.zip
  URL_MD5 890862544bdb9012f5758bd76e82c2b4
  PREFIX icu4c-4_8_1_1
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libicu_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libicu_build.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libicu_install.cmake
)

##############################################################################
##############################################################################
#  XERCES
##############################################################################
SET(XERCES_WIN32_DIR ${CMAKE_CURRENT_BINARY_DIR}/xerces-c-3.1.1/src/xerces-c-3.1.1/projects/Win32/VC10/xerces-all)
SET(XERCES_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/xerces-c-3.1.1 )
SET(XERCES_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/xerces-c-3.1.1/src/xerces-c-3.1.1 )
#CONFIGURE FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_configure.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv /upgrade xerces-all.sln
    WORKING_DIRECTORY \"${XERCES_WIN32_DIR}\"
  ) "
)
#BUILD FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_build.cmake "
  EXECUTE_PROCESS(
    COMMAND devenv xerces-all.sln /build \"Release|Win32\"
    WORKING_DIRECTORY \"${XERCES_WIN32_DIR}\"
  ) "
)
#INSTALL FILE
FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_install.cmake 
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
  xerces-c-3.1.1
  URL http://www.apache.org/dist/xerces/c/3/sources/xerces-c-3.1.1.zip
  URL_MD5 a42e0a35b8be37667bb7df6fb51feded
  PREFIX xerces-c-3.1.1
  #DEPENDS libxml2-2.9.1
  #PATCH_COMMAND echo %cd%
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_configure.cmake
  BUILD_COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_build.cmake
  INSTALL_COMMAND  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/libXERCES_install.cmake
)


##############################################################################
##############################################################################
#  
##############################################################################

MESSAGE(STATUS "Directory to set with ZORBA_THIRD_PARTY_REQUIREMENTS: " ${CMAKE_CURRENT_BINARY_DIR})



