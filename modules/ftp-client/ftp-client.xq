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

declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";

declare option ver:module-version "1.0";

(:~
 : Attempts to connect to an FTP server specified by the given URI.
 :
 : @param $uri The address of the FTP server to connect to.
 : It may either be simple host-name
 : (<code>ftp.example.com</code>)
 : or a URI using the <code>ftp</code> scheme
 : (<code>ftp://ftp.example.com</code>).
 : @param $options The options to use.
 : @return an opaque URI that serves as a connection handle to be used with
 : other functions in this module.
 : @error ftp:ALREADY_CONNECTED if <code>$conn</code> is already a valid handle
 : connected to an FTP server.
 :)
declare %an:sequential function
ftp:connect( $uri as string, $options as object )
  as anyURI external;

(:~
 : Disconnects from an FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : After successful completion of of this function, the handle is no longer
 : valid.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 :)
declare %an:sequential function
ftp:disconnect( $conn as anyURI )
  external;

(:~
 : Gets a binary file from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $file-name The name of the file to get.
 :)
declare %an:sequential function
ftp:get-binary( $conn as anyURI, $file-name as string )
  as base64Binary external;

(:~
 : Gets a text file from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $file-name The name of the file to get.
 : @param $encoding The character encoding of the file.
 :)
declare %an:sequential function
ftp:get-text( $conn as anyURI, $file-name as string, $encoding as string )
  as string external;

(:~
 : Gets a text file, presumed to be encoded in UTF-8, from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $file-name The name of the file to get.
 :)
declare %an:sequential function
ftp:get-text( $conn as anyURI, $file-name as string )
  as string
{
  ftp:get-text( $conn, $file-name, "UTF-8" )
};

declare %an:sequential function
ftp:put-binary( $conn as anyURI, $binary as base64Binary, $file-name as string )
  external;

declare %an:sequential function
ftp:put-text( $conn as anyURI, $text as string, $file-name as string )
  external;

(:===========================================================================:)

(: vim:set syntax=xquery et sw=2 ts=2: :)
