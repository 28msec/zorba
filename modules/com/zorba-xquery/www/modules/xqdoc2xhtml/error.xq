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
 : This module defines all errors for the xqdoc2xhtml module.
 :
 : @author Sorin Nasoi
 : @project xqdoc/xqdoc2xhtml
 :
 :)
module namespace err = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/error";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Error namespace URI.
 :)
declare variable $err:errNS as xs:string := "http://www.zorba-xquery.com/modules/xqdoc2xhtml/error";

(:~
 : The XHTML requisites were not copied correctly.
 :)
declare variable $err:UE001 as xs:QName := fn:QName($err:errNS, "err:UE001");

(:~
 : No 'main.html' template was found.
 :)
declare variable $err:UE002 as xs:QName := fn:QName($err:errNS, "err:UE002");

(:~
 : Not all the XQDoc XML's documents were generated.
 :)
declare variable $err:UE003 as xs:QName := fn:QName($err:errNS, "err:UE003");

(:~
 : The generation of the following XQDoc XML failed.
 :)
declare variable $err:UE004 as xs:QName := fn:QName($err:errNS, "err:UE004");

(:~
 : The schema was not copied.
 :)
declare variable $err:UE005 as xs:QName := fn:QName($err:errNS, "err:UE005");

(:~
 : Error encountered while processing a module.
 :)
declare variable $err:UE006 as xs:QName := fn:QName($err:errNS, "err:UE006");

(:~
 : Error encountered while processing a XQDoc XML for generating the XHTML.
 :)
declare variable $err:UE007 as xs:QName := fn:QName($err:errNS, "err:UE007");

(:~
 : The example was not found.
 :)
declare variable $err:UE008 as xs:QName := fn:QName($err:errNS, "err:UE008");

(:~
 : Copying an example source file failed.
 :)
declare variable $err:UE009 as xs:QName := fn:QName($err:errNS, "err:UE009");

(:~
 : A path does not point to an existing directory.
 :)
declare variable $err:UE010 as xs:QName := fn:QName($err:errNS, "err:UE010");
