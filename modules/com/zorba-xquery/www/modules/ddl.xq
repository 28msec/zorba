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
 : DDL Module defined in the XQuery Data Definition Facility
 :
 : @version 1.0 
 :)
module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";

(:~
 :)
declare updating function ddl:create-collection($name as xs:QName) external;

(:~
 :)
declare updating function ddl:create-collection($name as xs:QName,
                                                $content as node()*) external;

(:~
 :)
declare updating function ddl:delete-collection($name as xs:QName) external;

(:~
 :)
declare updating function ddl:insert-nodes-first($name as xs:QName,
                                                 $content as node()*) external;

(:~
 :)
declare updating function ddl:insert-nodes-last($name as xs:QName,
                                                $content as node()*) external;

(:~
 :)
declare updating function ddl:insert-nodes-at($name as xs:QName,
                                              $pos as xs:integer,
                                              $content as node()*) external;

(:~
 :)
declare updating function ddl:insert-nodes-before($name as xs:QName,
                                                  $pos as node()+,
                                                  $content as node()*) external;

(:~
 :)
declare updating function ddl:insert-nodes-after($name as xs:QName,
                                                  $pos as node()+,
                                                  $content as node()*) external;

(:~
 :)
declare updating function ddl:remove-nodes($name as xs:QName,
                                           $target as node()*) external;

(:~
 :)
declare updating function ddl:remove-node-at($name as xs:QName,
                                             $pos as xs:integer) external;

(:~
 :)
declare updating function ddl:create-index($name as xs:QName) external;

(:~
 :)
declare updating function ddl:delete-index($name as xs:QName) external;
