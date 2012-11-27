(:
 : Copyright 2006-2011 The FLWOR Foundation.
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
 : Zorba FOTS driver errors
 : @author Sorin Nasoi
 :)

module namespace err =
  "http://www.zorba-xquery.com/fots-driver/errors";

(:~
 : Errors namespace URI.
:)
declare variable $err:errNS as xs:string :=
  "http://www.zorba-xquery.com/fots-driver/errors";

(:~
 : xs:QName with
 : namespace URI = "http://www.w3.org/2010/09/qt-fots-catalog/errors"
 : and local name "err:errNA"
:)
declare variable $err:errNA as xs:QName := fn:QName($err:errNS, "check:errNA");
