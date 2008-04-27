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
IF (NOT WIN32 OR UNIX)
FILE (GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.iter)

FOREACH (TESTFILE ${TESTFILES})
STRING (REPLACE w3c_testsuite official_ts TESTNAME "${TESTFILE}")
ADD_TEST ("iterplans/${TESTNAME}" "${CMAKE_CURRENT_SOURCE_DIR}/../../itertest" "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" "${TESTFILE}")
ENDFOREACH(TESTFILE)
ENDIF (NOT WIN32 OR UNIX)
