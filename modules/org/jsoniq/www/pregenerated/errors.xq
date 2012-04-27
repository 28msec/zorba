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
 
 (:
  : THIS FILE IS GENERATED.
  : PLEASE DO NOT EDIT.
  :)
 (:~
 : This module contains one declaration of a variable for each
 : error of the http://www.jsoniq.org/errors namespace.
 : The variables serves as documentation for the errors but can also
 : be used in the code. For example, one useful scenario is to compare
 : an error caught in the catch clause of a try-catch expression with one of
 : the variables.
 :
 : @author Carlos Lopez
 :
 : @project error
 :)

xquery version '1.0';

module namespace jerr = 'http://www.jsoniq.org/errors';

declare variable $jerr:NS := 'http://www.jsoniq.org/errors';

(:~
 :It is a dynamic error to serialize a sequence of less
 : or more than one item with the JSON output method if the
 : cloudscript-serialization-multiple-items is set to no.
 : 
:)
declare variable $jerr:JNSE0012 as xs:QName := fn:QName($jerr:NS, "jerr:JNSE0012");

(:~
 :It is a dynamic error to serialize an atomic value not
 : supported by JSON or a node with the JSON output method and with
 : the cloudscript-serialization-extensions serialization parameter
 : set to false.
:)
declare variable $jerr:JNSE0013 as xs:QName := fn:QName($jerr:NS, "jerr:JNSE0013");

(:~
 :It is a dynamic error to serialize a function with the
 : JSON output method.
:)
declare variable $jerr:JNSE0014 as xs:QName := fn:QName($jerr:NS, "jerr:JNSE0014");

(:~
 :Expression computing the value of a pair does not return exactly
 : one item.
:)
declare variable $jerr:JNTY0002 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0002");

(:~
 :objects or arrays don't have a string value
:)
declare variable $jerr:JNTY0003 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0003");

(:~
 :objects or arrays don't have a typed value
:)
declare variable $jerr:JNTY0004 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0004");

(:~
 :wrong type for object/array selector in update expr
:)
declare variable $jerr:JNTY0007 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0007");

(:~
 :error raised by node constructor or updating expression indicating that a JSON item cannot appear in the corresponding content sequence
:)
declare variable $jerr:JNTY0011 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0011");

(:~
 :error raised by object constructor
:)
declare variable $jerr:JNDY0003 as xs:QName := fn:QName($jerr:NS, "jerr:JNDY0003");

(:~
 :parser errors raised by the JSONIQLoader
:)
declare variable $jerr:JSDY0040 as xs:QName := fn:QName($jerr:NS, "jerr:JSDY0040");

(:~
 :duplicate pair to insert
:)
declare variable $jerr:JNUP0005 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0005");

(:~
 :pair to insert already in object
:)
declare variable $jerr:JNUP0006 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0006");

(:~
 :pair to delete not in object
:)
declare variable $jerr:JNUP0007 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0007");

(:~
 :duplicate pair to replace
:)
declare variable $jerr:JNUP0008 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0008");

(:~
 :pair to replace not in object
:)
declare variable $jerr:JNUP0009 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0009");

(:~
 :duplicate pair to rename
:)
declare variable $jerr:JNUP0010 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0010");

(:~
 :pair to rename not in object
:)
declare variable $jerr:JNUP0011 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0011");

(:~
 :pair to rename already in object
:)
declare variable $jerr:JNUP0012 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0012");

(:~
 :position to insert not in array
:)
declare variable $jerr:JNUP0018 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0018");

(:~
 :position to delete not in array
:)
declare variable $jerr:JNUP0020 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0020");

(:~
 :position to replace not in array
:)
declare variable $jerr:JNUP0021 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0021");

(:~
 :duplicate position to replace
:)
declare variable $jerr:JNUP0022 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0022");