(:~
 : Module Name: File I/O
 : Module Version: 0.1
 : Date: October 23, 2009
 : Copyright:  2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : Proprietary XQuery Extensions Used: None
 : XQuery Specification: January 2007
 : Module Overview: This library module provides simple file system I/O operations.
 : @author Gabriel Petrovay
 :)

module namespace file = "http://www.zorba-xquery.com/modules/file";


declare sequential function file:exists($fileOrDir as xs:string) as xs:boolean external;

declare sequential function file:files($path as xs:string) as xs:anyURI* external;

declare sequential function file:is-directory($dir as xs:string) as xs:boolean external;

declare sequential function file:is-file($file as xs:string) as xs:boolean external;

declare sequential function file:last-modified($fileOrDir as xs:string) as xs:dateTime external;

declare sequential function file:mkdir($dir as xs:string) as xs:boolean external;

declare sequential function file:mkdirs($dir as xs:string) as xs:boolean external;

declare sequential function file:read($file as xs:string) as xs:base64Binary external;

declare sequential function file:read-html($file as xs:string) as xs:string external;

declare sequential function file:read-html($file as xs:string, $tidyOptions as xs:string) as xs:string external;

declare sequential function file:read-text($file as xs:string) as xs:string external;

declare sequential function file:read-xml($uri as xs:string) as node() external;

declare sequential function file:remove($fileOrDir as xs:string) as xs:boolean external;


(: the functios below still need to be implemented :)

declare sequential function file:write($uri as xs:string) as xs:integer {1};

declare sequential function file:write($uri as xs:string,
                            $serializer-params) as xs:integer {1};

declare sequential function file:copy($source as xs:string,
                           $target as xs:string) {1};

declare sequential function file:copy($source as xs:string,
                           $target as xs:string, 
                           $overwrite as xs:boolean) {1};

declare sequential function file:createTempFile() as xs:anyURI {1};

declare sequential function file:createTempFile($path as xs:string) as xs:anyURI {1};

declare sequential function file:createTempFile($path as xs:string,
                                     $pattern as xs:string) as xs:anyURI {1};
