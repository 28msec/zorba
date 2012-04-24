xquery version "1.0";

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
 : Module that defines the errors raised in Oauth modules.
 :
 : @author Stephanie Russell
 : @project OAuth
 :
 :)
module namespace  oerr = "http://www.zorba-xquery.com/modules/oauth/error";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Errors namespace URI.
 :)
declare variable $oerr:errNS as xs:string := "http://www.zorba-xquery.com/modules/oauth/errors";

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'OC001'. This signing method is not implemented yet.
:)
declare variable $oerr:OC001 as xs:QName := xs:QName("oerr:OC001");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'OC002'. This signing method is not supported.
:)
declare variable $oerr:OC002 as xs:QName := xs:QName("oerr:OC002");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'OC003'. Http 401 error.
:)
declare variable $oerr:OC003 as xs:QName := xs:QName("oerr:OC003");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'OC004'. Http 500 error.
:)
declare variable $oerr:OC004 as xs:QName := xs:QName("oerr:OC004");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'OC004'. Http 500 error.
:)
declare variable $oerr:OC005 as xs:QName := xs:QName("oerr:OC005");