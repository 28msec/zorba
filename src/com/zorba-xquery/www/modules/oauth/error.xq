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
module namespace  err = "http://www.zorba-xquery.com/modules/oauth/error";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Errors namespace URI.
 :)
declare variable $err:errNS as xs:string := "http://www.zorba-xquery.com/modules/oauth/errors";

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'err:OC001'. This signing method is not implemented yet.
:)
declare variable $err:OC001 as xs:QName := fn:QName($err:errNS, "err:OC001");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'err:OC002'. This signing method is not supported.
:)
declare variable $err:OC002 as xs:QName := fn:QName($err:errNS, "err:OC002");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'err:OC003'. Http 401 error.
:)
declare variable $err:OC003 as xs:QName := fn:QName($err:errNS, "err:OC003");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/oauth/errors" and local name 'err:OC004'. Http 500 error.
:)
declare variable $err:OC004 as xs:QName := fn:QName($err:errNS, "err:OC004");
