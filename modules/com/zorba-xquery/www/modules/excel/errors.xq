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
 : Module that defines the errors raised in the excel modules.
 :
 : @author Sorin Nasoi, Daniel Turcanu
 :)
module namespace  excel-err = "http://www.zorba-xquery.com/modules/excel/errors" ;

(:~
 : Errors namespace URI.
:)
declare variable $excel-err:errNS as xs:string := "http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Value" 
:)
declare variable $excel-err:errValue as xs:QName := fn:QName($excel-err:errNS, "excel-err:Value");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Num"
:)
declare variable $excel-err:errNum as xs:QName := fn:QName($excel-err:errNS, "excel-err:Num");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Div0"
:)
declare variable $excel-err:errDiv0 as xs:QName := fn:QName($excel-err:errNS, "excel-err:Div0");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:NA"
:)
declare variable $excel-err:errNA as xs:QName := fn:QName($excel-err:errNS, "excel-err:NA");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Ref"
:)
declare variable $excel-err:errRef as xs:QName := fn:QName($excel-err:errNS, "excel-err:Ref");
