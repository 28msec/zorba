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

DECLARE_ZORBA_SCHEMA(FILE xqdoc.xsd URI "http://www.xqdoc.org/1.0")
DECLARE_ZORBA_MODULE(FILE datetime.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/datetime")
DECLARE_ZORBA_MODULE(FILE fetch.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/fetch")
DECLARE_ZORBA_MODULE(FILE node-reference.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/node-reference")
DECLARE_ZORBA_MODULE(FILE reference.xq VERSION 1.0
  URI "http://www.zorba-xquery.com/modules/reference")
DECLARE_ZORBA_MODULE(FILE node.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/node")
DECLARE_ZORBA_MODULE(FILE item.xq VERSION 1.0
  URI "http://www.zorba-xquery.com/modules/item")
DECLARE_ZORBA_MODULE(FILE reflection.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/reflection")
DECLARE_ZORBA_MODULE(FILE schema.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/schema")
DECLARE_ZORBA_MODULE(FILE string.xq VERSION 2.1
  URI "http://www.zorba-xquery.com/modules/string")
DECLARE_ZORBA_SCHEMA(FILE xml-options.xsd 
  URI "http://www.zorba-xquery.com/modules/xml-options")
DECLARE_ZORBA_MODULE(FILE uri.xq VERSION 1.0
  URI "http://www.zorba-xquery.com/modules/uri")
DECLARE_ZORBA_MODULE(FILE xml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xml")
DECLARE_ZORBA_MODULE(FILE xqdoc.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc")
DECLARE_ZORBA_SCHEMA(FILE xqdoc-options.xsd 
  URI "http://www.zorba-xquery.com/modules/xqdoc-options") 

# Subdirectories
DECLARE_ZORBA_MODULE(FILE introspection/sctx.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/introspection/sctx")

DECLARE_ZORBA_MODULE(FILE store/data-structures/unordered-map.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map")
DECLARE_ZORBA_MODULE(FILE store/documents/dynamic.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/documents")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/w3c/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/w3c/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml")
DECLARE_ZORBA_MODULE(FILE store/static/collections/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/collections/ddl")
DECLARE_ZORBA_MODULE(FILE store/static/collections/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/collections/dml")
DECLARE_ZORBA_MODULE(FILE store/static/indexes/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/indexes/ddl")
DECLARE_ZORBA_MODULE(FILE store/static/indexes/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/indexes/dml")
DECLARE_ZORBA_MODULE(FILE store/static/integrity_constraints/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl")
DECLARE_ZORBA_MODULE(FILE store/static/integrity_constraints/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/dml")
DECLARE_ZORBA_MODULE(FILE xqdoc/batch.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc/batch")
DECLARE_ZORBA_MODULE(FILE xqdoc/html.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc/html")
DECLARE_ZORBA_MODULE(FILE xqdoc/menu.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc/menu")

# debugger client DBGP message handler module
IF (ZORBA_WITH_DEBUGGER)
  DECLARE_ZORBA_MODULE (FILE debugger/dbgp-message-handler.xq VERSION 1.0
    URI "http://www.zorba-xquery.com/modules/debugger/dbgp-message-handler")
ENDIF (ZORBA_WITH_DEBUGGER)
