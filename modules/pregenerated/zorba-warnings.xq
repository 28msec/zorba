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
 : http://zorba.io/warnings namespace.
 : The variables serves as documentation for the errors but can also
 : be used in the code. For example, one useful scenario is to compare
 : an error caught in the catch clause of a try-catch expression with one of
 : the variables.
 :
 : @author Carlos Lopez
 : @project Zorba/Zorba Warning Codes
 :
 :)

module namespace zwarn = 'http://zorba.io/warnings';

declare variable $zwarn:NS := 'http://zorba.io/warnings';

(:~
 :
 : This warning is reported if the declaration of a function, variable,
 : collection, or index contains an annotation that is not in the
 : http://zorba.io/annotations namespace and Zorba doesn't know how to
 : handle.
 : 
:)
declare variable $zwarn:ZWST0002 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0002");

(:~
:)
declare variable $zwarn:ZWST0003 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0003");

(:~
:)
declare variable $zwarn:ZWST0004 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0004");

(:~
 :
 : This warning is raised if the user explicitly enables caching
 : of function results (using the %an:cache annotation) but the function
 : is updating or its parameter and return types are not subtypes of
 : xs:anyAtomicType.
 : 
:)
declare variable $zwarn:ZWST0005 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0005");

(:~
 :
 : This warning is raised if the user explicitly enables caching
 : of function results (using the %an:cache annotation) and the function
 : is annotated as sequential or nondeterministic.
 : 
:)
declare variable $zwarn:ZWST0006 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0006");

(:~
:)
declare variable $zwarn:ZWST0007 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0007");

(:~
:)
declare variable $zwarn:ZWST0008 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0008");

(:~
 :
 : This warning is enabled when the "common-language" option is employed. It will raise warnings
 : for language features that are not supported by both XQuery and JSONiq grammars.
 : 
:)
declare variable $zwarn:ZWST0009 as xs:QName := fn:QName($zwarn:NS, "zwarn:ZWST0009");