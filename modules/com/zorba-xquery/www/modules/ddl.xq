(:~
 : Module Name: DDL Module defined in the XQuery Data Definition Facility
 : Copyright: 2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
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
declare updating function ddl:drop-collection($name as xs:QName) external;

(:~
 :)
declare updating function ddl:drop-all-collections() external;

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
