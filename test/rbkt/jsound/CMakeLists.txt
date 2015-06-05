# Copyright 2006-2013 The FLWOR Foundation.
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

DECLARE_ZORBA_SCHEMA(FILE sample.jsd
  URI http://zorba-tests.28.io/jsound-schema TEST_ONLY)

DECLARE_ZORBA_SCHEMA(FILE invalid.jsd
  URI http://zorba-tests.28.io/invalid-jsound-schema TEST_ONLY)
