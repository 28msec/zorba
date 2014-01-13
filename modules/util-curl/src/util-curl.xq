xquery version "1.0";

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : This module provides common functionality for modules that use libcurl.
 : <p/>
 : Modules using libcurl implementations must import this module 
 : to specify the dependency.
 :
 : @author Paul J. Lucas
 : @library <a href="http://curl.haxx.se/download.html">libcurl</a>
 : @project Zorba/cURL Utility
 :)
module namespace util-curl = "http://zorba.io/modules/util-curl";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(: vim:set et sw=2 ts=2: :)
