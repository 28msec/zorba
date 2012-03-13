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
 :objects or arrays don't have a string value
:)
declare variable $jerr:JNTY0003 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0003");

(:~
 :objects or arrays don't have a typed value
:)
declare variable $jerr:JNTY0004 as xs:QName := fn:QName($jerr:NS, "jerr:JNTY0004");

(:~
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
 :error raised by insert-into
:)
declare variable $jerr:JUDY0060 as xs:QName := fn:QName($jerr:NS, "jerr:JUDY0060");

(:~
 :error raised by upd:delete, upd:insert-before/after
:)
declare variable $jerr:JUDY0061 as xs:QName := fn:QName($jerr:NS, "jerr:JUDY0061");

(:~
 :error raised by upd:delete if the argument is not an object or array
:)
declare variable $jerr:JUDY0062 as xs:QName := fn:QName($jerr:NS, "jerr:JUDY0062");

(:~
 :error raised by upd:delete if the first argument is an
 : object/array but second argument is not of type xs:string/xs:integer,
 : respectively
 : 
:)
declare variable $jerr:JUDY0063 as xs:QName := fn:QName($jerr:NS, "jerr:JUDY0063");

(:~
 :error raised by mergeUpdates. An insert-before or insert-last
 : UP must not have the same target as any other insert-before, -last, -as-first, or -as-last UP
 : 
:)
declare variable $jerr:JUDY0064 as xs:QName := fn:QName($jerr:NS, "jerr:JUDY0064");

(:~
 :error raised by upd:rename
:)
declare variable $jerr:JUDY0065 as xs:QName := fn:QName($jerr:NS, "jerr:JUDY0065");