# Copyright 2006-2011 The FLWOR Foundation.
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

DECLARE_ZORBA_SCHEMA (FILE xpath-functions.xsd
  URI "http://www.w3.org/2005/xpath-functions")

# Unversioned modules (not owned by Zorba team)
DECLARE_ZORBA_MODULE (FILE xpath_functions.xq
  URI "http://www.w3.org/2005/xpath-functions")
  
DECLARE_ZORBA_MODULE (FILE xpath_functions_math.xq
  URI "http://www.w3.org/2005/xpath-functions/math")

DECLARE_ZORBA_MODULE (FILE pregenerated/xqt-errors.xq
  URI "http://www.w3.org/2005/xqt-errors")
