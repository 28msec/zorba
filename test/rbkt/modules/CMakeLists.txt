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

# Build and install any test modules
DECLARE_ZORBA_MODULE("http://www.zorba-xquery.com/modules/ver" 2.3
  "ver2")
DECLARE_ZORBA_MODULE("http://www.zorba-xquery.com/modules/ver" 1.4
  "ver")

DECLARE_ZORBA_MODULE("http://www.zorba-xquery.com/modules/bad-ver" 1.4
  "bad-ver")

DECLARE_ZORBA_MODULE("http://www.zorba-xquery.com/modules/A" 1.0
  "module-A")
DECLARE_ZORBA_MODULE("http://www.zorba-xquery.com/modules/B" 1.0
  "module-B")

DECLARE_ZORBA_MODULE("http://www.zorba-xquery.com/modules/ext" 2.0 "ext2")
DECLARE_ZORBA_MODULE("http://www.zorba-xquery.com/modules/ext" 1.0 "ext")