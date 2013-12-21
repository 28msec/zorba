jsoniq version "1.0";

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

(:===========================================================================:)

(:~
 : This module provides functions for performing FTP commands.
 : <p/>
 : @author Paul J. Lucas
 : @library <a href="http://curl.haxx.se/">cURL Library</a>
 : @project Zorba/Input Output/FTP Client
 :)
module namespace ftp = "http://zorba.io/modules/ftp-client";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

declare function ftp:connect( $uri as string, $options as object )
  as anyURI() external;

declare function ftp:connect( $uri as string )
  as anyURI()
{
  ftp:connect( $uri, { } )
};

declare function ftp:get-binary( $conn as anyURI, $file-name as string )
  as base64Binary external;

declare function ftp:get-text( $conn as anyURI, $file-name as string )
  as string external;

declare function ftp:put-binary( $conn as anyURI, $binary as base64Binary,
                                 $file-name as string )
  external;

declare function ftp:put-text( $conn as anyURI, $text as string,
                               $file-name as string )
  external;

(:===========================================================================:)

(: vim:set syntax=xquery et sw=2 ts=2: :)
