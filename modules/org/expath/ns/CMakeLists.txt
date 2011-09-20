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

# Nothing to do in this directory.

IF(ZORBA_WITH_FILE_ACCESS)
  DECLARE_ZORBA_MODULE(FILE file.xq VERSION 2.0
    URI "http://expath.org/ns/file")
ENDIF(ZORBA_WITH_FILE_ACCESS)
