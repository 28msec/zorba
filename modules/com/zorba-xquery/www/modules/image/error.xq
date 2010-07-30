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
declare variable $err:errImage as xs:string := "http://www.zorba-xquery.com/modules/image/error";


(:~
 : The passed xs:base64Binary is not a valid image type.
 :)
declare variable $err:IM001 as xs:QName := QName($err:errImage, "err:IM001");


(:~
 : A not supported image format was used for conversion.
 :)
declare variable $err:IM002 as xs:QName := QName($err:errImage, "err:IM001");
 
  
