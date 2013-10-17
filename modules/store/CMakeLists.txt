# Copyright 2013 The FLWOR Foundation.
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

DECLARE_ZORBA_MODULE(FILE unordered-maps.xq VERSION 1.0
  URI "http://zorba.io/modules/unordered-maps")

DECLARE_ZORBA_MODULE(FILE documents.xq VERSION 2.0
  URI "http://zorba.io/modules/store/documents")

DECLARE_ZORBA_MODULE(FILE dynamic/collections/ddl.xq VERSION 2.0
  URI "http://zorba.io/modules/store/dynamic/collections/ddl")
DECLARE_ZORBA_MODULE(FILE dynamic/collections/dml.xq VERSION 2.0
  URI "http://zorba.io/modules/store/dynamic/collections/dml")
DECLARE_ZORBA_MODULE(FILE dynamic/collections/w3c/ddl.xq VERSION 2.0
  URI "http://zorba.io/modules/store/dynamic/collections/w3c/ddl")
DECLARE_ZORBA_MODULE(FILE dynamic/collections/w3c/dml.xq VERSION 2.0
  URI "http://zorba.io/modules/store/dynamic/collections/w3c/dml")
DECLARE_ZORBA_MODULE(FILE static/collections/ddl.xq VERSION 2.0
  URI "http://zorba.io/modules/store/static/collections/ddl")
DECLARE_ZORBA_MODULE(FILE static/collections/dml.xq VERSION 2.0
  URI "http://zorba.io/modules/store/static/collections/dml")
DECLARE_ZORBA_MODULE(FILE static/indexes/ddl.xq VERSION 2.0
  URI "http://zorba.io/modules/store/static/indexes/ddl")
DECLARE_ZORBA_MODULE(FILE static/indexes/dml.xq VERSION 2.0
  URI "http://zorba.io/modules/store/static/indexes/dml")
DECLARE_ZORBA_MODULE(FILE static/integrity-constraints/ddl.xq VERSION 2.0
  URI "http://zorba.io/modules/store/static/integrity-constraints/ddl")
DECLARE_ZORBA_MODULE(FILE static/integrity-constraints/dml.xq VERSION 2.0
  URI "http://zorba.io/modules/store/static/integrity-constraints/dml")

# vim:set et sw=2 ts=2:
