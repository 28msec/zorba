# Copyright 2010 The FLWOR Foundation.
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

# - Try to find the SWIG library on Windows
#
# This is a proxy module that calls the FindSWIG.cmake module.
# But before we try to guess where SWIG might be on the user's machine.
# The user should provide ZORBA_THIRD_PARTY_REQUIREMENTS which is a path where
# the SWIG directory can be found. The SWIG directory must have "swig"
# (case insensitive) in its name.
#
# This module helps the Windows user to avoid providing the following two
# variables when building Zorba:
# -D SWIG_EXECUTABLE="path_to_3rd_party_dir\*swig*\include"
#
# See the FindSWIG.cmake module shipped with Zorba for more information.

FIND_PACKAGE_WIN32(NAME SWIG FOUND_VAR SWIG_FOUND SEARCH_NAMES swig)
