# Copyright 2006-2010 The FLWOR Foundation.
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

# This directory exists solely as a place for external testsuites to
# be plugged in to the Zorba test system. By default it is empty and
# has no tests. Any subdirectories (or symlinks to subdirectories)
# that are placed here will be added so that they may add tests.
#
# To be picked up, subdirectories must be named "*_testsuite". Tests
# which are added by these suites should have the string "*_testsuite"
# in their name, to facilitate execution with ctest -R.

file (GLOB testsuites "*_testsuite")
foreach (testsuite ${testsuites})
  add_subdirectory("${testsuite}")
endforeach (testsuite)
