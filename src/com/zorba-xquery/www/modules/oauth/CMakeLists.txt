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

DECLARE_ZORBA_MODULE (URI "http://www.zorba-xquery.com/modules/oauth/client" VERSION 1.0 FILE "client.xq")
# This test is introduced by DECLARE_ZORBA_MODULE(), so this is the
# best place for the EXPECTED_FAILURE() (especially because we're
# cheating and using the undocumented ${num_zorba_modules}).
EXPECTED_FAILURE("check_mod_${num_zorba_modules}_client.xq" 3389465)

DECLARE_ZORBA_MODULE (URI "http://www.zorba-xquery.com/modules/oauth/error" VERSION 1.0 FILE "error.xq")
