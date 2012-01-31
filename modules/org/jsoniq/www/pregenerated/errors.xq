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
:)
declare variable $jerr:JSDY0001 as xs:QName := fn:QName($jerr:NS, "jerr:JSDY0001");

(:~
:)
declare variable $jerr:JSDY0002 as xs:QName := fn:QName($jerr:NS, "jerr:JSDY0002");


declare variable $jerr:JSDY0020 as xs:QName := fn:QName($jerr:NS, "jerr:JSDY0020");

(:~
 :parser errors raised by the JSONIQLoader
:)
declare variable $jerr:JSDY0040 as xs:QName := fn:QName($jerr:NS, "jerr:JSDY0040");

(:~
 :error raised by insert-into
:)
declare variable $jerr:JSDY0060 as xs:QName := fn:QName($jerr:NS, "jerr:JSDY0060");