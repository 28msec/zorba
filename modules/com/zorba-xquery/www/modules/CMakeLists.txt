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
DECLARE_ZORBA_MODULE(FILE reflection.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/reflection")
DECLARE_ZORBA_MODULE(FILE uri.xq VERSION 1.0
  URI "http://www.zorba-xquery.com/modules/uri")
DECLARE_ZORBA_MODULE(FILE xqdoc.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc")
DECLARE_ZORBA_SCHEMA(FILE xqdoc-options.xsd 
  URI "http://www.zorba-xquery.com/modules/xqdoc-options") 

# Subdirectories

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
