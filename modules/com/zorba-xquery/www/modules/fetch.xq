xquery version "3.0";

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
 : This module provides functions to fetch the contents or the type
 : of the content for a resource identified by a URI.
 : For example, it fetches content for file or http resources if Zorba
 : allows file or http access, respectively.
 :
 : @author Matthias Brantner
 : @project external
 :)
module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";
declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : fetch:ErrRetrievingResource
 :)
declare variable $fetch:ErrRetrievingResource as xs:QName :=
  fn:QName("http://www.zorba-xquery.com/modules/fetch",
           "fetch:ErrRetrievingResource");


(:~
 : fetch:ResourceDoesNotExist
 :)
declare variable $fetch:ResourceDoesNotExist as xs:QName :=
  fn:QName("http://www.zorba-xquery.com/modules/fetch",
           "fetch:ResourceDoesNotExist");

(:~
 : Tries to fetch the resource referred to by the given URI.
 : 
 : @param $uri the resource to fetch to
 : @return the resource referred to by the given URI
 : @error fetch:ErrRetrievingResource if an error occurred
 :        retrieving the resource.
 : @error fetch:ResourceDoesNotExist if no resource could be found at
 :        the given location.
 :)
declare %ann:streamable function fetch:content($uri as xs:string) as xs:string external;
