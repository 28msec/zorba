(:~
 : Module Name: eXcel-err
 : Module Version: 0.1
 : Date: August 1, 2009
 : Copyright:  2006-2008 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : Proprietary XQuery Extensions Used: None
 : XQuery Specification: January 2007
 : Module Overview: This is a library module containing the error messages
 : @author  Sorin Nasoi
 :)

module namespace  excel-err = "http://www.zorba-xquery.com/modules/excel/errors" ;

(:~
errors namespace URI
:)
declare variable $excel-err:errNS as xs:string := "http://www.zorba-xquery.com/modules/excel/errors";

(:~
xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Value" 
:)
declare variable $excel-err:errValue as xs:QName := fn:QName($excel-err:errNS, "excel-err:Value");

(:~
xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Num"
:)
declare variable $excel-err:errNum as xs:QName := fn:QName($excel-err:errNS, "excel-err:Num");

(:~
xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Div0"
:)
declare variable $excel-err:errDiv0 as xs:QName := fn:QName($excel-err:errNS, "excel-err:Div0");

(:~
xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:NA"
:)
declare variable $excel-err:errNA as xs:QName := fn:QName($excel-err:errNS, "excel-err:NA");

(:~
xs:QName with namespace URI="http://www.zorba-xquery.com/modules/excel/errors" and local name 'excel-err:Ref"
:)
declare variable $excel-err:errRef as xs:QName := fn:QName($excel-err:errNS, "excel-err:Ref");
