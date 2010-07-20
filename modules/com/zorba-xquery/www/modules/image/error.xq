(:~
 : This module defines all errors for the image modules.
 :
 : @version 0.1
 : @author Daniel Thomas
 :)
module namespace err = "http://www.zorba-xquery.com/modules/image/error";


(:~
 : Error namespace URI.
 :)
declare variable $err:errImage as xs:string := "http://expath.org/ns/error";


(:~
 : The passed xs:base64Binary can not be used as image type.
 :)
declare variable $err:XPST0083 as xs:QName := QName($err:errImage, "err:XPST0083"); 
