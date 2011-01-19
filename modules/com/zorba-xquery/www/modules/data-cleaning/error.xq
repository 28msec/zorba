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
 : This module defines all errors for the data-cleaning modules.
 :
 : @author Bruno Martins
 :
 :)
module namespace err = "http://www.zorba-xquery.com/modules/data-cleaning/error";

(:~
 : Error namespace URI.
 :)
declare variable $err:errNS as xs:string := "http://www.zorba-xquery.com/modules/data-cleaning/error";

(:~
 : notsupported if the type of metric, the source unit or the target unit are not known to the service.
 :)
declare variable $err:notsupported as xs:QName := fn:QName($err:errNS, "err:notsupported");

