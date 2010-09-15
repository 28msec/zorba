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
 : This is the zorba-specific implementation of the http-client.
 : Do not call functions from this module directly but use the
 : module http://www.expath.org/mod/http-client instead.
 :
 : @see http://www.expath.org/mod/http-client
 : @author Markus Pilman
 :)
module namespace httpclientimpl = 'http://expath.org/ns/httpclientimpl';

import schema namespace http = "http://expath.org/ns/http-client";

(:~
 : Helper function
 :
 : Do not use this function directly but use http://www.expath.org/mod/http-client;send-request
 : instead since this function does not all the error checking. So
 : calling this function directly can make zorba crash!!
 :
 : @param $request @see http://www.expath.org/mod/http-client;send-request
 : @param $href @see http://www.expath.org/mod/http-client;send-request
 : @param $bodies @see http://www.expath.org/mod/http-client;send-request
 :
 : @return @see http://www.expath.org/mod/http-client;send-request
 :)
declare sequential function httpclientimpl:http-send-request-impl (
  $request as element(http:request)?,
  $href as xs:string?,
  $bodies as item()*
) as item()+ external;

(:~
 : Helper function
 :
 : Do not use this function directly but use http://www.expath.org/mod/http-client;read
 : instead since this function does not all the error checking.
 :
 : @param $request @see http://www.expath.org/mod/http-client;send-request
 : @param $href @see http://www.expath.org/mod/http-client;send-request
 : @param $bodies @see http://www.expath.org/mod/http-client;send-request
 :
 : @return @see http://www.expath.org/mod/http-client;read
 :)
declare %nondeterministic function httpclientimpl:http-read-impl (
  $request as element(http:request)?,
  $href as xs:string?,
  $bodies as item()*
) as item()+ external;
