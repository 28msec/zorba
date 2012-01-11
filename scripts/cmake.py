"""
# Copyright 2006-2008 The FLWOR Foundation.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

Script to run cmake in the build directory of zorba in a MS Windows
platform.   You may need to change the paths to the external libraries
for this script to work.   Ths paths shown here are the default install
paths for the respective projects.

From the build directory, you can run this script like this

build> python ..\cmake.py


author: Paul F. Kunz <paulfkunz@gmail.com>
"""

s0 ="cmake " 
s1 = '-G "Visual Studio 8 2005" '
s2 = r' -D ICU_LIBRARY="C:\icu\lib\icuuc.lib" '
s3 = r' -D ICU_DATA_LIBRARY="C:\icu\lib\icudt.lib" '
s4 = r' -D ICU_I18N_LIBRARY="C:\icu\lib\icuin.lib" '
s5 = r' -D ICU_INCLUDE="C:\icu\include" '
s6 = r' -D ICONV_INCLUDE_DIR="C:\iconv-1.9.2.win32\include" '
s7 = r' -D ICONV_LIBRARY="C:\iconv-1.9.2.win32\lib\iconv.lib" '
s8 = r' -D LIBXML2_INCLUDE_DIR="C:\libxml2-2.6.32+.win32\include" '
s9 = r' -D LIBXML2_LIBRARIES="C:\libxml2-2.6.32+.win32\lib\libxml2.lib" '
s10 = r' -D BOOST_ROOT="C:\boost" '
s11 = r' -D XERCESC_INCLUDE="C:\xerces-c_2_8_0-x86-windows-vc_8_0\include" '
s12 = r' -D XERCESC_LIBRARY="C:\xerces-c_2_8_0-x86-windows-vc_8_0\lib\xerces-c_2.lib" '
s13 = r' -D LIBTIDY_INCLUDE_DIR="C:\Tidy\include"'
s14 = r' -D LIBTIDY_LIBRARIES="C:\Tidy\build\msvc\releaseDLL\libtidy.lib"'
s15 = r' -D LIBCURL_INCLUDE_DIR="C:\libcurl-7.15.1-msvc-win32-ssl-0.9.8a-zlib-1.2.3\include"'
s16 = r' -D CURL_LIBRARY="C:\libcurl-7.15.1-msvc-win32-ssl-0.9.8a-zlib-1.2.3\libcurl_imp.lib"'
s17 = r" ..\ "

cmd = s0+s1+s2+s3+s4+s5+s6+s7+s8+s9+s10+s11+s12+s13+s14+s15+s16+s17
import os
os.system ( cmd )



