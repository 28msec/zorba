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

# - Try to find the Python include files and libraries on Windows
#
# This is a proxy module that calls the FindPythonLibs.cmake module shipped with
# CMake. But before we try to guess where the Python libraries might be on the
# user's machine, the user should provide ZORBA_THIRD_PARTY_REQUIREMENTS which
# is a list of paths where the Python directory can be found. The Python
# directory must have "python" (case insensitive) in its name.
#
# This module helps the Windows user to avoid providing the following two
# variables when building Zorba:
# -D PYTHON_LIBRARIES="path_to_3rd_party_dir\*python*\lib"
# -D PYTHON_INCLUDE_DIRS="path_to_3rd_party_dir\*python*\include"
#
# See the FindPythonLibs.cmake module shipped with CMake for more information.

FIND_PACKAGE_WIN32 (PythonLibs PYTHONLIBS_FOUND python)
