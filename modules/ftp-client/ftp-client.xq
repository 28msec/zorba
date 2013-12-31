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
 : @param $options The options to use:
 :  <dl>
 :    <dt><code>user</code></dt>
 :      <dd>
 :        The user to log in as;
 :        default: <code>ftp</code> (for anonymous FTP).
 :      </dd>
 :    <dt><code>password</code></dt>
 :      <dd>
 :        The password to use to log in;
 :        default: <code>ftp</code> (for anonymous FTP).
 :      </dd>
 :    <dt><code>trace</code></dt>
 :      <dd>
 :        Whether to emit information to standard error
 :        tracing the communication between the FTP client and server;
 :        default: <code>false</code>.
 :      </dd>
 :  </dl>
 : @return an opaque URI that serves as a connection handle to be used with
 : other functions in this module.
 : @error ftp:ALREADY_CONNECTED if <code>$conn</code> is already a valid handle
 : connected to an FTP server.
 : @error ftp:INVALID_ARGUMENT if any option is invalid.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:connect( $uri as string, $options as object )
  as anyURI external;

(:~
 : Deletes a file from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-path The path of the file to delete.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:delete( $conn as string, $remote-path as string )
  external;

(:~
 : Disconnects from an FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : After successful completion of of this function, the handle is no longer
 : valid.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:disconnect( $conn as anyURI )
  external;

(:~
 : Gets a binary file from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-path The path of the file to get.
 : @return the binary content of <code>$remote-path</code>.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:get-binary( $conn as anyURI, $remote-path as string )
  as base64Binary external;

(:~
 : Gets a text file from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-path The path of the file to get.  It must not be empty.
 : @param $encoding The character encoding of the file.
 : @return the text content of <code>$remote-path</code>.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty
 : or <code>$encoding</code> is either an invalid or unsupported encoding.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:get-text( $conn as anyURI, $remote-path as string, $encoding as string )
  as string external;

(:~
 : Gets a text file, presumed to be encoded in UTF-8, from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-path The path of the file to get.  It must not be empty.
 : @return the text content of <code>$remote-path</code>.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:get-text( $conn as anyURI, $remote-path as string )
  as string
{
  ftp:get-text( $conn, $remote-path, "UTF-8" )
};

(:~
 : Gets a listing for a directory on an FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-path The full path of the directory on the FTP server to get
 : the directory listing for.
 : An empty path is equivalent to <code>/</code>.
 : @return Returns a sequence of JSON objects, one per file or subdirectory in
 : the listing.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:list( $conn as anyURI, $remote-path as string )
  as object* external;

(:~
 : Creates a directory on the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-path The path of the new directory to create.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:mkdir( $conn as string, $remote-path as string )
  external;

(:~
 : Uploads binary data to a file to the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $binary The binary data to upload.
 : @param $remote-path The path of the file to upload to. It must not be empty.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:put-binary( $conn as anyURI, $binary as base64Binary,
                $remote-path as string )
  external;

(:~
 : Uploads text to a file to the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $text The text to upload.
 : @param $remote-path The path of the file to upload to. It must not be empty.
 : @param $encoding The character encoding of the file.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty
 : or <code>$encoding</code> is either an invalid or unsupported encoding.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:put-text( $conn as anyURI, $text as string, $remote-path as string,
              $encoding as string )
  external;

(:~
 : Uploads text to a UTF-8 encoded file on the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $text The text to upload.
 : @param $remote-path The path of the file to upload to. It must not be empty.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:put-text( $conn as anyURI, $text as string, $remote-path as string )
{
  ftp:put-text( $conn, $text, $remote-path, "UTF-8" )
};

(:~
 : Renames a file or directory on an FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-from-path The path of the file or directory to rename.
 : @param $remote-to-path The new name.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-from-path</code> or
 : <code>$remote-to-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:rename( $conn as string, $remote-from-path as string,
            $remote-to-path as string )
  external;

(:~
 : Removes a directory from the FTP server.
 :
 : @param $conn The opaque URI connection handle previously returned by
 : <code>ftp:connect()</code>.
 : @param $remote-path The path of the directory to remove.
 : @error ftp:INVALID_ARGUMENT if <code>$remote-path</code> is empty.
 : @error ftp:NOT_CONNECTED if <code>$conn</code> is either an invalid handle
 : or is no longer a valid handle.
 : @error ftp:FTP_ERROR if there was some other FTP error.
 :)
declare %an:sequential function
ftp:rmdir( $conn as string, $remote-path as string )
  external;

(:===========================================================================:)

(: vim:set syntax=xquery et sw=2 ts=2: :)
