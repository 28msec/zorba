(:
 : Copyright 2006-2011 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

import module namespace conf  = "http://www.zorba-xquery.com/modules/conformance" at "conformance_xquts.xqi";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

conf:create-collection-submissions();
conf:test();
dml:delete-nodes(dml:collection(xs:QName("conf:submissionXqueryX")));                           
ddl:delete(xs:QName("conf:submissionXqueryX"));
dml:delete-nodes(dml:collection(xs:QName("conf:submissionXquery")));                           
ddl:delete(xs:QName("conf:submissionXquery"));
dml:delete-nodes(dml:collection(xs:QName("conf:xquery")));                           
ddl:delete(xs:QName("conf:xquery"));
dml:delete-nodes(dml:collection(xs:QName("conf:xqueryx")));                           
ddl:delete(xs:QName("conf:xqueryx"));