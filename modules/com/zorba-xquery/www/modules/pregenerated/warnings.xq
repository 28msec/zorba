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
 : error of the http://www.zorba-xquery.com/warnings namespace.
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

module namespace zwarn = 'http://www.zorba-xquery.com/warnings';

declare variable $zwarn:NS := 'http://www.zorba-xquery.com/warnings';

(:~
 :
 : This warning is reported if the declaration of a function, variable,
 : collection, or index contains an annotation that is not in the
 : http://www.zorba-xquery.com/annotations namespace and Zorba doesn't know
 : how to handle.
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