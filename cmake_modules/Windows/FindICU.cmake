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

# - Find the International Components for Unicode (ICU) Library on Windows
#
# This is a proxy module that calls the FindICU.cmake module. Before
# doing that, we try to guess where ICU might be on the user's machine.
# The user should provide ZORBA_THIRD_PARTY_REQUIREMENTS which is a path where
# a the ICU directory can be found. The ICU directory must have "icu"
# (case insensitive) in its name.
#
# This module helps the Windows user to avoid providing the following two
# variables when building Zorba:
# -D ICU_LIBRARY="path_to_3rd_party_dir\*icu*\lib\icuuc.lib"
# -D ICU_DATA_LIBRARY="path_to_3rd_party_dir\*icu*\lib\icudt.lib"
# -D ICU_I18N_LIBRARY="path_to_3rd_party_dir\*icu*\lib\icuin.lib"
# -D ICU_INCLUDE="path_to_3rd_party_dir\*icu*\include"
#
# See the FindICU.cmake module shipped with Zorba for more information.

FIND_PACKAGE_WIN32(ICU icu)
