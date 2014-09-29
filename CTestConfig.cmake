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
SET (CTEST_DROP_METHOD http) 
SET (CTEST_PROJECT_NAME "Zorba") 
SET (CTEST_NIGHTLY_START_TIME "00:00:00 GMT") 
SET (CTEST_DROP_SITE "zorbatest.28.io:8080") 
SET (CTEST_DROP_LOCATION "/cdash/submit.php?project=Zorba") 
SET (CTEST_DROP_SITE_CDASH TRUE)
SET (CTEST_CUSTOM_WARNING_EXCEPTION
    ${CTEST_CUSTOM_WARNING_EXCEPTION}
    "Warning: GNU Bison.*"
    "Warning: using repository file.*"
    "Warning: urning: GNU Flex.*")
SET (CTEST_COMPRESS_SUBMISSION ON)
SET (VALGRIND_COMMAND_OPTIONS "--tool=memcheck --leak-check=full --track-fds=yes --num-callers=50 --track-origins=yes")
