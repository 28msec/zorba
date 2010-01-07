(:
 : Copyright 2006-2009 The FLWOR Foundation.
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

(:~
 : Intospection Module for the Dynamic Context
 :
 : @version 1.0
 :)
module namespace dctx = "http://www.zorba-xquery.com/modules/introspection/dctx";


(:~
 :)
declare function dctx:is-available-collection($name as xs:QName) as xs:boolean external;

(:~
 :)
declare function dctx:available-collections() as xs:QName* external;

(:~
 :)
declare function dctx:is-available-index($name as xs:QName) as xs:boolean external;

(:~
 :)
declare function dctx:available-indexes() as xs:QName* external;

(:~
 :)
declare function dctx:is-activated-integrity-constraint($name as xs:QName) as xs:boolean external;

(:~
 :)
declare function dctx:activated-integrity-constraints() as xs:QName* external;
