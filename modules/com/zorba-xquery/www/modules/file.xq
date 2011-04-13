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
 :    <p>
 :      <h1>Namespace conventions</h1>
 :      <p>The module defined by this document does define several functions in the namespace
 :          <code>http://www.zorba-xquery.com/modules/file</code>. In this document, the <code>file</code> prefix,
 :        when used, is bound to this namespace URI.</p>
 :    </p>
 :    <p>
 :      <h1>File paths vs. URIs</h1>
 :      <p>In order to make this file API more accessible, the paths of the files are specified as
 :        strings. The syntax of the path strings is operating system dependent. The following forms are accepted
 :        and interpreted as described below.</p>
 :      <ul>
 :        <li>Operating system paths - absolute or relative paths are accepted:
 :          <ul>
 :            <li><code>C:\Test Dir\my file.xml</code>: An absolute path on Windows platforms.</li>
 :            <li><code>C:/Test Dir\my file.xml</code>: An absolute path on Windows platforms that
 :              tollerates slashes instead of backslashes.</li>
 :            <li><code>C:\\\Test Dir//\\my file.xml</code>: An absolute path on Windows platforms
 :              that tollerates an arbitrary number of slashes and backslashes.</li>
 :            <li><code>/Test Dir/my file.xml</code>: An absolute path on UNIX-based platforms
 :              that tollerates an arbitrary number of slashes.</li>
 :            <li><code>//Test Dir////my file.xml</code>: An absolute path on UNIX-based
 :              platforms.</li>
 :            <li><code>my file.xml</code>: A relative path. The file should be searched for 
 :              starting with the location pointed by the base URI of the current module.</li>
 :          </ul>
 :        </li>
 :        <li>File URIs - only absolute paths are accepted:
 :          <ul>
 :            <li><code>file:///C:/Test%20Dir/my%20file.xml</code>: An absolute path on Windows
 :              platforms.</li>
 :            <li><code>file:///C:/Test Dir/my file.xml</code>: An absolute path on Windows
 :              platforms. The URI tolerates spaces.</li>
 :            <li><code>file:///C:/Test%20Dir///my%20file.xml</code>: An absolute path on Windows
 :              platforms. The URI tolerates an arbitrary number of slashes.</li>
 :            <li><code>file:///Test%20Dir/my%20file.xml</code>: An absolute path on UNIX-based
 :              platforms.</li>
 :            <li><code>file://localhost/Test%20Dir/my%20file.xml</code>: A URI that accepts
 :              <code>localhost</code> as the autority of the URI.</li>
 :          </ul>
 :        </li>
 :      </ul>
 :    </p>
 :
 : @author Gabriel Petrovay, Matthias Brantner, Markus Pilman
 :)
module namespace file = "http://www.zorba-xquery.com/modules/file";

import schema namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

(:~
 : Appends a sequence of items to a file. If the file pointed by <pre>$file</pre>
 : does not exist, a new file will be created. Before writing to the file, the items
 : are serialized according to the <pre>$serializer-params</pre>.
 :
 : The semantics of <pre>$serializer-params</pre> is the same as for the
 : <pre>$params</pre> parameter of the <a target="_blank"
 : href="http://www.w3.org/TR/xpath-functions-11/#func-serialize">fn:serialize</a>
 : function.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @param $serializer-params Parameter to control the serialization of the
 :    content.
 : @return The empty sequence.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:append(
  $file as xs:string,
  $content as item()*,
  $serializer-params as element(output:serialization-parameters)?
) as empty-sequence()
{
  file:append-text(
    $file,
    fn:serialize($content, $serializer-params))
};

(:~
 : Appends a sequence of Base64 items as binary to a file. If the file pointed
 : by <pre>$file</pre> does not exist, a new file will be created.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @return The empty sequence.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:append-binary(
  $file as xs:string,
  $content as xs:base64Binary*
) as empty-sequence() external;

(:~
 : Appends a sequence of string items to a file.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @return The empty sequence.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %private %sequential function file:append-text(
  $file as xs:string,
  $content as xs:string*
) as empty-sequence() external;

(:~
 : Copies a file or a directory given a source and a destination path/URI.
 :
 : The operation is equivalent to calling:
 : <pre>file:copy($source, $destination, fn:true())</pre>.
 :
 : @param $source The path/URI of the file to copy.
 : @param $destination The detination path/URI.
 : @return The empty sequence.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0002 If <pre>$source</pre> points to a directory and
 :    <pre>$destination</pre> points to an existing file.
 : @error FOFL0003 If <pre>$destination</pre> does not exist and it's
 :    parent directory does not exist either.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:copy(
  $source as xs:string,
  $destination as xs:string
) as empty-sequence()
{
  file:copy($source, $destination, fn:true())
};

(:~
 : Copies a file or a directory given a source and a destination path/URI.
 : 
 : @param $source The path/URI of the file to copy.
 : @param $destination The destination path/URI.
 : @param $overwrite Flag to control if the operation should overwrite the
 :    destination file.
 : @return The empty sequence.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0002 If:
 :    <ul>
 :      <li><pre>$source</pre> points to a directory and
 :        <pre>$destination</pre> points to an existing file.</li>
 :      <li>the <pre>$overwrite</pre> parameter evaluates to
 :        <pre>fn:false()</pre>, and <pre>$destination</pre> points to an
 :        existing file;</li>
 :    </ul>
 : @error FOFL0003 If <pre>$destination</pre> does not exist and it's
 :    parent directory does not exist either.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:copy(
  $source as xs:string,
  $destination as xs:string,
  $overwrite as xs:boolean
) as empty-sequence() external;

(:~
 : Creates a directory.
 :
 : The operation is will create all the missing parent directories from the
 : given path.
 :
 : @param $dir The path/URI denoting the directory to be created.
 : @return The empty sequence.
 : @error FOFL0002 If the directory cannot be created because of an already
 :    existing file.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:create-directory(
  $dir as xs:string
) as empty-sequence() external;

(:~
 : Deletes a file or a directory from the file system.
 :
 : If <pre>$path</pre> points to a directory the directory will be deleted
 : recursively.
 :
 : @param $path The path/URI of the file or directory to delete.
 : @return The empty sequence.
 : @error FOFL0001 If the <pre>$path</pre> path does not exist.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:delete(
  $path as xs:string
) as empty-sequence()
{
  if (file:exists($path)) then
    if (file:is-directory($path)) then
      file:delete-directory-impl($path)
    else
      file:delete-file-impl($path)
  else
    fn:error(xs:QName("err:FOFL0001"), fn:concat("The path does not exists: ", $path))
};

(:~
 : Deletes a file from the file system.
 :
 : @param $file The path/URI of the file to delete.
 : @return The empty sequence.
 : @error FOFL0001 If the <pre>$file</pre> path does not exist.
 : @error FOFL0000 If any other error occurs.
 :)
declare %private %sequential function file:delete-file-impl(
  $file as xs:string
) as empty-sequence() external;

(:~
 : Deletes a directory from the file system.
 :
 : @param $dir The path/URI of the directory to delete.
 : @return The empty sequence.
 : @error FOFL0001 If the <pre>$dir</pre> path does not exist.
 : @error FOFL0003 If <pre>$dir</pre> does not point to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %private %sequential function file:delete-directory-impl(
  $dir as xs:string
) as empty-sequence()
{
  for $item in file:list($dir)
  let $fullPath := fn:concat($dir, file:directory-separator(), $item)
  return
    if (file:is-directory($fullPath)) then
      file:delete-directory-impl($fullPath)
    else
      file:delete-file-impl($fullPath);
    
  file:delete-file-impl($dir);
};

(:~
 : Tests if a path/URI is already used in the file system.
 :
 : @param $path The path/URI to test for existance.
 : @return true if the path/URI points to an existing file system item.
 :)
declare %nondeterministic function file:exists(
  $path as xs:string
) as xs:boolean external;

(:~
 : Tests if a path/URI points to a directory. On UNIX-based systems, the root
 : and the volume roots are considered directories.
 :
 : @param $dir The path/URI to test.
 : @return true if the path/URI points to a directory.
 :)
declare %nondeterministic function file:is-directory(
  $dir as xs:string
) as xs:boolean external;

(:~
 : Tests if a path/URI points to a file.
 :
 : @param $dir The path/URI to test.
 : @return true if the path/URI points to a file.
 :)
declare %nondeterministic function file:is-file(
  $file as xs:string
) as xs:boolean external;

(:~
 : Moves a file or directory given a source and a destination paths/URIs.
 :
 : The operation is equivalent to calling:
 : <pre>file:move($sourceFile, $destination, fn:true())</pre>.
 :
 : @param $sourceFile The path/URI of the file to move.
 : @param $destination The detination path/URI.
 : @return The empty sequence.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0002 If <pre>$source</pre> points to a directory and
 :    <pre>$destination</pre> points to an existing file.
 : @error FOFL0003 If <pre>$destination</pre> does not exist and it's parent
 :    directory does not exist either.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:move(
  $sourceFile as xs:string,
  $destination as xs:string
) as empty-sequence()
{
  file:move($sourceFile, $destination, fn:true())
};

(:~
 : Moves a file or directory given a source and a destination paths/URIs.
 :
 : @param $source The path/URI of the file or directory to move.
 : @param $destination The destination path/URI.
 : @param $overwrite Flag to control if the operation should overwrite the
 :    destination file.
 : @return The empty sequence.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0002 If:
 :    <ul>
 :      <li><pre>$source</pre> points to a directory, <pre>$destination</pre> points to an existing file</li>
 :      <li><pre>$source</pre> points to a file, <pre>$destination</pre> points to an existing file, and
 :        the <pre>$overwrite</pre> evaluates to <pre>fn:false()</pre></li>
 :    </ul>
 : @error FOFL0003 If <pre>$destination</pre> does not exist and it's parent
 :    directory does not exist either.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:move(
  $source as xs:string,
  $destination as xs:string,
  $overwrite as xs:boolean
) as empty-sequence()
{
  file:copy($source, $destination, $overwrite);
  file:delete($source);
};

(:~
 : Reads the content of a file and returns a Base64 representation of the
 : content.
 :
 : @param $file The file to read.
 : @return The content of the file as Base64.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0004 If <pre>$source</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %nondeterministic function file:read-binary(
  $file as xs:string
) as xs:base64Binary external;

(:~
 : Reads the content of a file and returns a string representation of the
 : content.
 :
 : The operation is equivalent to calling:
 : <pre>file:read-text($file, "UTF-8")</pre>.
 :
 : @param $file The file to read.
 : @return The content of the file as string.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0004 If <pre>$source</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare function file:read-text(
  $file as xs:string
) as xs:string
{
  file:read-text($file, "UTF-8")
};

(:~
 : Reads the content of a file using the specified encoding and returns a
 : string representation of the content.
 :
 : In Zorba only the following encodings are currently supported: "UTF-8",
 : "UTF8". The encoding parameter is case insensitive.
 :
 : @param $file The file to read.
 : @param $encoding The encoding used when reading the file.
 : @return The content of the file as string.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0004 If <pre>$source</pre> points to a directory.
 : @error FOFL0006 If <pre>$encoding</pre> is not supported.
 : @error FOFL0000 If any other error occurs.
 :)
declare %nondeterministic function file:read-text(
  $file as xs:string,
  $encoding as xs:string
) as xs:string external;

(:~
 : Reads the content of a file and returns a sequence of strings representing
 : the lines in the content of the file.
 :
 : The operation is equivalent to calling:
 : <pre>file:read-text-lines($file, "UTF-8")</pre>.
 :
 : @param $file The file to read.
 : @return The content of the file as a sequence of strings.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0004 If <pre>$source</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare function file:read-text-lines(
  $file as xs:string
) as xs:string*
{
  file:read-text-lines($file, "UTF-8")
};

(:~
 : Reads the content of a file using the specified encoding and returns a
 : sequence of strings representing the lines in the content of the file.
 :
 : This implementation considers the LF (&#xA;) character as the line
 : separator. If a resulting line ends with the CR (&#xD;) character, this is
 : trimmed as well. This implementation will uniformly treat LF and CRLF as
 : line separators.
 :
 : In Zorba only the following encodings are currently supported: "UTF-8",
 : "UTF8". The encoding parameter is case insensitive.
 :
 : @param $file The file to read.
 : @param $encoding The encoding used when reading the file.
 : @return The content of the file as a sequence of strings.
 : @error FOFL0001 If the <pre>$source</pre> path does not exist.
 : @error FOFL0004 If <pre>$source</pre> points to a directory.
 : @error FOFL0006 If <pre>$encoding</pre> is not supported.
 : @error FOFL0000 If any other error occurs.
 :)
declare function file:read-text-lines(
  $file as xs:string,
  $encoding as xs:string
) as xs:string*
{
  let $content := file:read-text($file, $encoding)
  return fn:tokenize($content, "\n")
};

(:~
 : This is an internal function that copies an entire source directory to an
 : destination directory. The caller to this function must make sure that both
 : the source and destination point to existing directories.
 :
 : @param $sourceDir The existing source directory.
 : @param $destinationDir The existing destination directory.
 : @param $overwrite Flag to control if the operation should overwrite any
 :        files that already exist at destination.
 : @return The empty sequence.
 :)
declare %private %sequential function file:copy-directory(
  $sourceDir as xs:string,
  $destinationDir as xs:string,
  $overwrite as xs:boolean
) as empty-sequence()
{
  let $name := file:base-name($sourceDir)
  let $destDir := fn:concat($destinationDir, file:directory-separator(), $name)
  return
    block {
      file:create-directory($destDir);

      for $item in file:list($sourceDir)
      let $fullSrcPath := fn:concat($sourceDir, file:directory-separator(), $item)
      let $fullDestPath := fn:concat($destDir, file:directory-separator(), $item)
      return
        if (file:is-directory($fullSrcPath)) then
          file:copy-directory($fullSrcPath, $fullDestPath, $overwrite)
        else
          file:copy($fullSrcPath, $fullDestPath, $overwrite);
    }
};

(:~
 : Writes a sequence of items to a file.
 :
 : The operation is equivalent to calling:
 : <pre>file:write($file, $content, $serializer-params, fn:true())</pre>.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @param $serializer-params Parameter to control the serialization of the
 :        content.
 : @return The empty sequence.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:write(
  $file as xs:string,
  $content as item()*,
  $serializer-params as element(output:serialization-parameters)?
) as empty-sequence()
{
  file:write($file, $content, $serializer-params, fn:true())
};

(:~
 : Writes a sequence of items to a file. Before writing to the file, the items
 : are serialized according to the <pre>$serializer-params</pre>.
 :
 : The semantics of <pre>$serializer-params</pre> is the same as for the
 : <pre>$params</pre> parameter of the <a target="_blank"
 : href="http://www.w3.org/TR/xpath-functions-11/#func-serialize">fn:serialize</a>
 : function.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @param $serializer-params Parameter to control the serialization of the
 :        content.
 : @param $overwrite Flag to specify if an existing file should be overwritten.
 : @return The empty sequence.
 : @error FOFL0002 If <pre>$overwrite</pre> evaluates to <pre>fn:false()</pre>
 :    and <pre>$file</pre> already exists.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:write(
  $file as xs:string,
  $content as item()*,
  $serializer-params as element(output:serialization-parameters)?,
  $overwrite as xs:boolean
) as empty-sequence()
{
  file:write-text($file, fn:serialize($content, $serializer-params), $overwrite)
};

(:~
 : Writes a sequence of Base64 items as binary to a file.
 :
 : The operation is equivalent to calling:
 : <pre>file:write-binary($file, $content, fn:true())</pre>.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @return The empty sequence.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:write-binary(
  $file as xs:string,
  $content as xs:base64Binary*
) as empty-sequence()
{
  file:write-binary($file, $content, fn:true())
};

(:~
 : Writes a sequence of Base64 items as binary to a file.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @param $overwrite Flag to specify if an existing file should be overwritten.
 : @return The empty sequence.
 : @error FOFL0002 If <pre>$overwrite</pre> evaluates to <pre>fn:false()</pre>
 :    and <pre>$file</pre> already exists.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %sequential function file:write-binary(
  $file as xs:string,
  $content as xs:base64Binary*,
  $overwrite as xs:boolean
) as empty-sequence() external;

(:~
 : Writes a sequence of string items to a file.
 :
 : The operation is equivalent to calling:
 : <pre>file:write-text($file, $content, fn:true())</pre>.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @param $overwrite Flag to specify if an existing file should be overwritten.
 : @return The empty sequence.
 : @error FOFL0002 If <pre>$overwrite</pre> evaluates to <pre>fn:false()</pre>
 :    and <pre>$file</pre> already exists.
 : @error FOFL0004 If <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %private %sequential function file:write-text(
  $file as xs:string,
  $content as xs:string*,
  $overwrite as xs:boolean
) as empty-sequence() external;

(:~
 : Lists the file system items in a certain directory.
 :
 : The operation is equivalent to calling:
 : <pre>file:list($dir, fn:false())</pre>.
 :
 : @param $dir The path/URI of the directory to retrieve the children from.
 : @return The sequence of names of the direct children.
 : @error FOFL0003 If <pre>$dir</pre> does not point to an existing directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %nondeterministic function file:list(
  $dir as xs:string
) as xs:string* external;

(:~
 : Lists the file system items in a certain directory. The order of the items
 : in the resulting sequence is not defined. The "." and ".." items are not
 : returned. The returned paths are relative to the provided <pre>$path</pre>.
 :
 : If <pre>$recursive</pre> evaluates to <pre>fn:true()</pre>, the operation
 : will recurse in the subdirectories.
 : 
 : @param $dir The path/URI to retrieve the children from.
 : @param $recursive A boolean flag indicating whether the operation should be
 :    performed recursively.
 : @return A sequence of relative paths.
 : @error FOFL0003 If <pre>$dir</pre> does not point to an existing directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare function file:list(
  $path as xs:string,
  $recursive as xs:boolean
) as xs:string*
{
  for $f in file:list($path)
  let $full := fn:concat($path, file:directory-separator(), $f)
  return (
    $f,
    if ($recursive and file:is-directory($full)) then
      for $child in file:list($full, $recursive)
      return fn:concat($f, file:directory-separator(), $child)
    else
      ()
  )
};

(:~
 : Lists all files matching the given pattern in a given directory.
 : The order of the items in the result is not defined.
 : The "." and ".." items are not considered for the match.
 : The file paths are relative to the provided $path.
 :
 : The pattern is a glob expression supporting:
 : <ul>
 :   <li><pre>*</pre> for matching any number of unknown characters</li>
 :   <li><pre>?</pre> for matching one unknown character</li>
 : </ul>
 : 
 : @param $path The path/URI to retrieve the children from.
 : @param $recursive A boolean flag indicating whether the operation should be
 :    performed recursively.
 : @param $pattern The file name pattern.
 : @return A sequence of file names matching the pattern.
 : @error FOFL0003 If <pre>$dir</pre> does not point to an existing directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare function file:list(
  $path as xs:string,
  $recursive as xs:boolean,
  $pattern as xs:string
) as xs:string* {
  for $file in file:list($path, $recursive)
  let $name := fn:tokenize($file, fn:concat("\", file:directory-separator()))[fn:last()]
  return
    if (fn:matches($name, file:glob-to-regex($pattern))) then
      $file
    else
      ()
};

(:~
 : A helper function that performs a trivial (not complete) glob to regex
 : pattern translation.
 : 
 : @param $pattern The glob pattern.
 : @return A regex pattern coresponding to the glob pattern provided.
 :)
declare function file:glob-to-regex(
  $pattern as xs:string
) {
  fn:codepoints-to-string(
    (
      94                          (: prepend ^ :)
      ,
      for $char in fn:string-to-codepoints($pattern)
      return
        switch ($char)
        case 63 return 46         (: ? -> . :)
        case 46 return (92, 46)   (: . -> \. :)
        case 42 return (46, 42)   (: * -> .* :)
        default return $char
      ,
      36)                         (: append $ :)
  )
};

(:~
 : Retrieves the timestamp of the last modification of the file system item
 : pointed by the path/URI.
 :
 : @param $path The file system item to read the last modification
 :    timestamp from.
 : @return The date and time of the last modification of the item.
 : @error FOFL0001 If the <pre>$path</pre> does not exist.
 : @error FOFL0000 If any other error occurs.
 :)
declare %nondeterministic function file:last-modified(
  $path as xs:string
) as xs:dateTime external;

(:~
 : Retrieves the size of a file.
 :
 : @param $file The file get the size.
 : @return An integer representing the size in bytes of the file.
 : @error FOFL0001 If the <pre>$file</pre> does not exist.
 : @error FOFL0001 If the <pre>$file</pre> points to a directory.
 : @error FOFL0000 If any other error occurs.
 :)
declare %nondeterministic function file:size(
  $file as xs:string
) as xs:integer external;

(:~
 : This function returns the value of the operating system specific directory
 : separator. For example, <pre>/</pre> on UNIX-based systems and <pre>\</pre>
 : on Windows systems.
 :
 : @return The operating system specific directory separator.
 :)
declare function file:directory-separator() as xs:string external;

(:~
 : This function returns the value of the operating system specific path
 : separator. For example, <pre>:</pre> on UNIX-based systems and <pre>;</pre>
 : on Windows systems.
 :
 : @return The operating system specific path separator.
 :)
declare function file:path-separator() as xs:string external;

(:~
 : Transforms a relative path/URI into an absolute operating system path by
 : resolving it against the current working directory.
 :
 : No path existence check is made.
 :
 : @param $path The path/URI to transform.
 : @return The operating system file path.
 :)
declare function file:resolve-path(
  $path as xs:string
) as xs:string external;

(:~
 : Transforms a file system path into a URI with the file:// scheme. If the
 : path is relative, it is first resolved against the current working
 : directory.
 :
 : No path existence check is made.
 :
 : @param $path The path to transform.
 : @return The file URI corresponding to <pre>path</pre>.
 :)
declare function file:path-to-uri(
  $path as xs:string
) as xs:anyURI external;

(:~
 : Transforms a URI, an absolute path, or relative path to a native path on the
 : running platform.
 :
 : No path existence check is made.
 :
 : @param $path The uri or path to normalize.
 : @return The native path corresponding to <pre>$path</pre>.
 :)
declare function file:path-to-native($path as xs:string) as xs:string external;

(:~
 : Returns the last component from the <pre>$path</pre>, deleting any
 : trailing directory-separator characters. If <pre>$path</pre> consists
 : entirely directory-separator characters, the empty string is returned. If
 : <pre>$path</pre> is the empty string, the string <pre>"."</pre> is returned,
 : signifying the current directory.
 :
 : No path existence check is made.
 :
 : @param $path A file path/URI.
 : @return The base name of this file.
 :)
declare function file:base-name($path as xs:string) as xs:string
{
  let $delim := file:directory-separator()
  let $delim-escaped := replace($delim, '(\.|\[|\]|\\|\||\-|\^|\$|\?|\*|\+|\{|\}|\(|\))','\\$1')
  let $normalized-file := 
    let $n := file:prepare-for-dirname-and-base-name($path)
		return if ($delim eq "\" and matches($n, "^[a-zA-Z]:$")) then
			concat($n, "\")
		else $n
  return
    if (matches($path, concat("^", $delim-escaped, "+$"))) then
      ""
    else if (file:directory-separator() eq '\' and matches($path, "^[a-zA-Z]:\\?$")) then
      ""
    else if ($path eq "") then
      "."
    else
      replace($normalized-file, concat("^.*", $delim-escaped), '')
};

(:~
 : Returns the last component from the <pre>$path</pre>, deleting any
 : trailing directory-separator characters and the <pre>$suffix</pre>. If path
 : consists entirely directory-separator characters, the empty string is
 : returned. If path is the empty string, the string <pre>"."</pre> is
 : returned, signifying the current directory.
 :
 : No path existence check is made.
 :
 : The <pre>$suffix</pre> can be used for example to eliminate file extensions.
 :
 : @param $path A file path/URI.
 : @param $suffix A suffix which should get deleted from the result.
 : @return The base-name of $path with a deleted $suffix.
 :)
declare function file:base-name($path as xs:string, $suffix as xs:string) as xs:string
{
  let $res := file:base-name($path)
  return
    if (fn:ends-with($res, $suffix) and $res ne ".") then
      fn:substring($res, 1, fn:string-length($suffix))
    else
      $res
};

(:~
 : This function is the converse of <pre>file:base-name</pre>. It returns a
 : string denoting the parent directory of the <pre>$path</pre>. Any trailing
 : directory-separator characters are not counted as part of the directory
 : name. If path is the empty string or contains no directory-separator string,
 : <pre>"."</pre> is returned, signifying the current directory.
 :
 : No path existence check is made.
 :
 : @param $path The filename, of which the dirname should be get.
 : @return The name of the directory the file is in.
 :)
declare function file:dir-name($path as xs:string) as xs:string
{
  let $delim := file:directory-separator()
  let $delim-escaped := replace($delim, '(\.|\[|\]|\\|\||\-|\^|\$|\?|\*|\+|\{|\}|\(|\))','\\$1')
  let $normalized-file := file:prepare-for-dirname-and-base-name($path)
  return
    if (matches($path, concat("^", $delim-escaped, "+$"))) then
      $delim
    else if ($normalized-file eq $delim) then
      $delim
    else if (file:directory-separator() eq '\' and matches($path, "^[a-zA-Z]:\\$")) then
      $path
    else if (file:directory-separator() eq '\' and matches($normalized-file, "^[a-zA-Z]:$")) then
      concat($normalized-file, '\')
    else if ($path eq "") then
      "."
    else if (matches($normalized-file, $delim-escaped)) then
      replace($normalized-file, concat('^(.*)', $delim-escaped,'.*'),
                         '$1')
    else "."
};

(:~
 : This is a helper function used by dirname and base-name. This function takes a path as
 : input and normalizes it according to the rules states in dirname/base-name documentation
 : and normalizes it to a system specific path.
 :)
declare %private function file:prepare-for-dirname-and-base-name($path as xs:string) as xs:string
{
  let $delim := file:directory-separator()
  let $delim-escaped := replace($delim, '(\.|\[|\]|\\|\||\-|\^|\$|\?|\*|\+|\{|\}|\(|\))','\\$1')
  let $normalize-path := file:path-to-native($path)
  let $normalized :=
    if ($normalize-path eq $delim) then
      $normalize-path
    else
      replace($normalize-path, concat($delim-escaped, '+$'), '')
  return $normalized
};
