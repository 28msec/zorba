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
 : This module describes the errors for the image modules.
 :
 : @author Daniel Thomas
 :)
module namespace err = 'http://www.zorba-xquery.com/modules/image/error';


(:~
 : The error namespace URI.
 :)
declare variable $err:errorNS as xs:string := 'http://www.zorba-xquery.com/modules/image/error';


(:~
 : One of the passed xs:base64Binary is not a valid image or of an unsupported image type.
 :)
declare variable $err:IM001 as xs:QName := fn:QName($err:errorNS, 'err:IM001');


(:~
 : If the xs:base64Binary passed to convert-svg is not a valid SVG image.
 :)
declare variable $err:IM002 as xs:QName := fn:QName($err:errorNS, 'err:IM002');

