xquery version '1.0';

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : This module contains one variable declaration for each diagnostic of the
 : http://jsoniq.org/errors namespace.
 : The variables serves as documentation for the errors but can also
 : be used in the code. For example, one useful scenario is to compare
 : an error caught in the catch clause of a try-catch expression with one of
 : the variables.
 :
 : @author Carlos Lopez
 : @project JSONiq/Error Codes
 :
 :)

module namespace jerr = 'http://jsoniq.org/errors';

declare variable $jerr:NS := 'http://jsoniq.org/errors';

(:~
 :It is a type error if the right-hand-side expression of a pair constructor does not return exactly one item.
:)
declare variable $jerr:JNTY0002 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0002");

(:~
 :It is a dynamic error if two pairs in an object constructor or in a simple object union have the same name.
:)
declare variable $jerr:JNDY0003 as xs:QName := fn:QName($jerr:NS, "jerr:JNDY0003");

(:~
 :It is a type error to call fn:data on a sequence containing an array or an object.
:)
declare variable $jerr:JNTY0004 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0004");

(:~
 :It is a dynamic error if a pending update list contains two inserting update primitives on the same object and pair name.
:)
declare variable $jerr:JNUP0005 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0005");

(:~
 :It is a dynamic error if upd:applyUpdates causes an object to contain two pairs with the same name.
:)
declare variable $jerr:JNUP0006 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0006");

(:~
 :It is a type error if, in an updating expression, an array selector cannot be cast to xs:integer or if an object selector cannot be cast to xs:string.
:)
declare variable $jerr:JNUP0007 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0007");

(:~
 :It is a dynamic error if the target of a deleting or replacing expression is not an array or an object.
 : It is a dynamic error if the target of a renaming expression is not an object.
 : It is a dynamic error if the target of an appending expression is not an array.
 : It is a dynamic error if the target of a position-inserting expression is not an array.
 : It is a dynamic error if the target of a non-position-inserting expression is not an object.
:)
declare variable $jerr:JNUP0008 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0008");

(:~
 :It is a dynamic error if a pending update list contains two replacing update primitives on the same object or array, and with the same selector.
:)
declare variable $jerr:JNUP0009 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0009");

(:~
 :It is a dynamic error if a pending update list contains two renaming update primitives on the same object and with the same selector.
:)
declare variable $jerr:JNUP0010 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0010");

(:~
 :It is a type error if the content sequence in a node constructor or in an XQUF insert or replace update expression contains an object or an array.
:)
declare variable $jerr:JNTY0011 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0011");

(:~
 :It is a dynamic error to serialize a sequence of less
 : or more than one item with the JSON output method if the
 : jsoniq-serialization-multiple-items is set to no.
 : 
:)
declare variable $jerr:JNSE0012 as xs:QName := fn:QName($jerr:NS, "jerr:JNSE0012");

(:~
 :It is a dynamic error to serialize an atomic value not
 : supported by JSON or a node with the JSON output method and with
 : the jsoniq-serialization-extensions serialization parameter
 : set to false.
:)
declare variable $jerr:JNSE0013 as xs:QName := fn:QName($jerr:NS, "jerr:JNSE0013");

(:~
 :It is a dynamic error to serialize a function or a node with the
 : JSON output method.
:)
declare variable $jerr:JNSE0014 as xs:QName := fn:QName($jerr:NS, "jerr:JNSE0014");

(:~
 :It is a dynamic error to serialize a sequence that does
 : not exist of exactly one document node with XML, HTML, XHTML, Text.
 : 
:)
declare variable $jerr:JNSE0022 as xs:QName := fn:QName($jerr:NS, "jerr:JNSE0022");

(:~
 :It is a dynamic error if it is attempted to create a replace, delete or rename update primitive with a selector that cannot be resolved against the target array or object.
:)
declare variable $jerr:JNUP0016 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0016");

(:~
 : It is a dynamic error if the value in a replace expression is not exactly a single item.
:)
declare variable $jerr:JNUP0017 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0017");

(:~
 :It is a dynamic error if there is not exactly one supplied parameter for an object or array selector.
:)
declare variable $jerr:JNTY0018 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0018");

(:~
 :It is a dynamic error if the content expression, in an object insert expression, does not evaluate to a sequence of objects.
:)
declare variable $jerr:JNUP0019 as xs:QName := fn:QName($jerr:NS, "jerr:JNUP0019");

(:~
 :It is a type error if the prefix is not a string or if the
 : serialization parameters are not an element.
:)
declare variable $jerr:JNTY0023 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0023");

(:~
 :objects or arrays don't have a string value
:)
declare variable $jerr:JNTY0024 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0024");

(:~
 :parser error for invalid option type
:)
declare variable $jerr:JNTY0020 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0020");

(:~
 :array or object selector on heterogeneous sequence
:)
declare variable $jerr:JNTY0021 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0021");

(:~
 :parser error raised by jn:parse-json
:)
declare variable $jerr:JNDY0021 as xs:QName := fn:QName($jerr:NS, "jerr:JNDY0021");