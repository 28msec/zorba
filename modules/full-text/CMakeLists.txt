# Copyright 2006-2012 The FLWOR Foundation.
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

IF (NOT ZORBA_NO_FULL_TEXT)
  DECLARE_ZORBA_MODULE(FILE full-text.xq VERSION 1.0
    URI "http://zorba.io/modules/full-text")
ENDIF (NOT ZORBA_NO_FULL_TEXT)

# vim:set et sw=2 ts=2:
