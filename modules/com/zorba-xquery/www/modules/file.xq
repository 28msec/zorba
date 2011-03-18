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
 : Creates a directory.
 :
 : The operation is equivalent to calling:
 : <pre>file:create-directory($dir, fn:true(), fn:false())</pre>.
 :
 : @param $dir The path/URI denoting the directory to be created.
 : @return The empty sequence.
 :)
declare sequential function file:create-directory(
  $dir as xs:string) as empty-sequence()
{
  file:create-directory($dir, fn:true(), fn:false())
};

(:~
 : Creates a directory. If the $recursive argument evaluates to
 : <pre>fn:true()</pre> all the missing parent directories from the path are
 : also created.
 :
 : The operation is equivalent to calling:
 : <pre>file:create-directory($dir, $recursive, fn:false())</pre>.
 :
 : @param $dir The path/URI denoting the directory to be created.
 : @param $recursive If the operation should create all the missing parrent
 :	      directories.
 : @return The empty sequence.
 :)
declare sequential function file:create-directory(
  $dir as xs:string,
  $recursive as xs:boolean) as empty-sequence()
{
  file:create-directory($dir, $recursive, fn:false())
};

(:~
 : Creates a directory. If the $failIfExists argument  evaluates to
 : <pre>fn:true()</pre> the operation will fail if the firectory already
 : exists.
 :
 : @param $dir The path/URI denoting the directory to be created.
 : @param $recursive If the operation should create all the missing parrent
 :        directories.
 : @param $failIfExists Flag indicating whether the directory must be created or not.
 : @return The empty sequence.
 :)
declare sequential function file:create-directory(
  $dir as xs:string,
  $recursive as xs:boolean,
  $failIfExists as xs:boolean
) as empty-sequence() external;

(:~
 : Deletes a file or an empty directory from the file system.
 :
 : @param $fileOrDir The path/URI of the file or directory to delete.
 : @return The empty sequence.
 :)
declare sequential function file:delete(
  $fileOrDir as xs:string
) as empty-sequence() external;

(:~
 : Deletes a file or a directory from the file system. If $fileOrDir denotes a
 : directory and $recursive evaluates to <pre>fn:true()</pre>, the directory
 : will be deleted recursively.
 :
 : @param $fileOrDir The path/URI of the file or directory to delete.
 : @param $recursive If the operation should recursively delete the given
 :	      directory.
 : @return The empty sequence.
 :)
declare sequential function file:delete(
  $fileOrDir as xs:string,
  $recursive as xs:boolean
) as empty-sequence()
{
  if ($recursive) then
    for $item in file:files($fileOrDir)
    let $fullPath := fn:concat($fileOrDir, file:path-separator(), $item)
    return
      if (file:is-directory($fullPath)) then
        file:delete($fullPath, fn:true())
      else
        file:delete($fullPath)
  else
    ();
    
  file:delete($fileOrDir);
};

(:~
 : Reads the content of a file and returns a Base64 representation of the
 : content.
 :
 : @param $file The file to read.
 : @return The content of the file as Base64.
 :)
declare %nondeterministic function file:read-binary(
  $file as xs:string
) as xs:base64Binary external;

(:~
 : Reads the content of a file and returns a sequence of strings representing
 : the lines in the content of the file.
 :
 : The operation is equivalent to calling:
 : <pre>file:read-text-lines($file, "UTF-8")</pre>.
 :
 : @param $file The file to read.
 : @return The content of the file as a sequence of strings.
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
 : Reads the content of a file and returns a string representation of the
 : content.
 :
 : The operation is equivalent to calling:
 : <pre>file:read-text($file, "UTF-8")</pre>.
 :
 : @param $file The file to read.
 : @return The content of the file as string.
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
 :)
declare function file:read-text(
  $file as xs:string,
  $encoding as xs:string
) as xs:string external;

(:~
 : Reads a file as an XML file and returns an XML document. The file content
 : must be a valid XML otherwise an error will be thrown.
 :
 : The operation is equivalent to calling:
 : <pre>file:read-xml($file, "UTF-8")</pre>.
 :
 : @param $file The file to read.
 : @return An XML document containing the content of the file.
 :)
declare function file:read-xml(
  $file as xs:string
) as node()
{
  file:read-xml($file, "UTF-8")
};

(:~
 : Reads a file as an XML file using the specified encoding and returns an XML
 : document. The file content must be a valid XML otherwise an error will be
 : thrown.
 :
 : In Zorba only the following encodings are currently supported: "UTF-8",
 : "UTF8". The encoding parameter is case insensitive.
 :
 : @param $file The file to read.
 : @param $encoding The encoding used when reading the file.
 : @return An XML document containing the content of the file.
 :)
declare %nondeterministic function file:read-xml(
  $file as xs:string,
  $encoding as xs:string
) as node() external;

(:~
 : Tests if a path/URI is already used in the file system.
 :
 : @param $fileOrDir The path/URI to test for existance.
 : @return true if the path/URI points to an existing file system item.
 :)
declare %nondeterministic function file:exists(
  $fileOrDir as xs:string
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
 : Copies a file given a source and a destination paths/URIs. The operation
 : fails if the source path/URI does not point to a file or the destination
 : path/URI is already used by a file.
 :
 : The operation is equivalent to calling:
 : <pre>file:copy($sourceFile, $destination, fn:false())</pre>.
 :
 : @param $sourceFile The path/URI of the file to copy.
 : @param $destination The detination path/URI.
 : @return The empty sequence.
 :)
declare sequential function file:copy(
  $sourceFile as xs:string,
  $destination as xs:string
) as empty-sequence()
{
  file:copy($sourceFile, $destination, fn:false())
};

(:~
 : Copies a file given a source and a destination paths/URIs. The operation
 : fails if the source path/URI does not point to a file or the destination
 : path/URI is already used by a file and the overwrite flag evaluates to
 : <pre>fn:false()</pre>.
 :
 : @param $sourceFile The path/URI of the file to copy.
 : @param $destination The destination path/URI.
 : @param $overwrite Flag to control if the operation should overwrite the
 :        destination file.
 : @return The empty sequence.
 :)
declare sequential function file:copy(
  $sourceFile as xs:string,
  $destination as xs:string,
  $overwrite as xs:boolean
) as empty-sequence() external;

(:~
 : Copies a file or directory given a source and a destination paths/URIs.
 : The operation fails if the source path/URI does not point to a file and the
 : recursive flag evaluates to <pre>fn:false()</pre>. The operation also fails
 : if in at any time one destination file already exists and the overwrite flag
 : evaluates to <pre>fn:false()</pre>.
 :
 : @param $source The path/URI of the file or directory to copy.
 : @param $destination The destination path/URI.
 : @param $overwrite Flag to control if the operation should overwrite any
 :        files that already exist at destination.
 : @param $recursive If the operation should recursively copy a directory.
 : @return The empty sequence.
 :)
declare sequential function file:copy(
  $source as xs:string,
  $destination as xs:string,
  $overwrite as xs:boolean,
  $recursive as xs:boolean
) as empty-sequence()
{
  (: for non-recursive and file copy use the external implementation :)
  if (fn:not($recursive) or fn:not(file:is-directory($source))) then
    file:copy($source, $destination, $overwrite)

  (: we are sure we want to copy a directory :)
  else
    (: we copy it into an existing directory :)
    if (file:exists($destination)) then
      if (file:is-directory($destination)) then
        file:copy-directory($source, $destination, $overwrite)
      else
        (: the destination is a file :)
        fn:error()

    (: the destination does not exist, that means the copied directory is renamed :)
    else
      (: but only if it's parent directory exists :)
      let $dir := file:dirname($destination)
      return
        if (file:is-directory($dir)) then
          block {
            file:create-directory($destination, fn:true());
          
            for $item in file:files($source)
            let $fullSrcPath := fn:concat($source, file:path-separator(), $item)
            let $fullDestPath := fn:concat($destination, file:path-separator(), $item)
            return
              if (file:is-directory($fullSrcPath)) then
                file:copy-directory($fullSrcPath, $fullDestPath, $overwrite)
              else
                file:copy($fullSrcPath, $fullDestPath, $overwrite);
          }
        else
          fn:error()
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
declare %private sequential function file:copy-directory(
  $sourceDir as xs:string,
  $destinationDir as xs:string,
  $overwrite as xs:boolean
) as empty-sequence()
{
  let $name := file:basename($sourceDir)
  let $destDir := fn:concat($destinationDir, file:path-separator(), $name)
  return
    block {
      file:create-directory($destDir);

      for $item in file:files($sourceDir)
      let $fullSrcPath := fn:concat($sourceDir, file:path-separator(), $item)
      let $fullDestPath := fn:concat($destDir, file:path-separator(), $item)
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
 :)
declare sequential function file:write(
  $file as xs:string,
  $content as item()*,
  $serializer-params as item()*
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
 :)
declare sequential function file:write(
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
 :)
declare sequential function file:write-binary(
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
 :)
declare sequential function file:write-binary(
  $file as xs:string,
  $content as xs:base64Binary*,
  $overwrite as xs:boolean
) as empty-sequence() external;

(:~
 : Writes a sequence of string items to a file.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @return The empty sequence.
 :)
declare sequential function file:write-text(
  $file as xs:string,
  $content as xs:string*
) as empty-sequence()
{
  file:write-text($file, $content, fn:true())
};

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
 :)
declare sequential function file:write-text(
  $file as xs:string,
  $content as xs:string*,
  $overwrite as xs:boolean
) as empty-sequence() external;

(:~
 : Appends a sequence of items to a file. Before writing to the file, the items
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
 : @return The empty sequence.
 :)
declare sequential function file:append(
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
 : Appends a sequence of Base64 items as binary to a file.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @return The empty sequence.
 :)
declare sequential function file:append-binary(
  $file as xs:string,
  $content as xs:base64Binary*
) as empty-sequence() external;

(:~
 : Appends a sequence of string items to a file.
 :
 : The operation is equivalent to calling:
 : <pre>file:append-text($file, $content, fn:true())</pre>.
 :
 : @param $file The path/URI of the file to write the content to.
 : @param $content The content to be serialized to the file.
 : @return The empty sequence.
 :)
declare sequential function file:append-text(
  $file as xs:string,
  $content as xs:string*
) as empty-sequence() external;




(: ********************************************************************** :)

(:~
 : Lists the file system items in a certain directory.
 : The order of the items in the result is not defined.
 : The "." and ".." items are not returned.
 : The file paths are relative to the provided $path.
 :
 : @param $path The path/URI to retrieve the children from.
 : @return The sequence of names of the direct children.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare %nondeterministic function file:files(
  $path as xs:string
) as xs:string* external;

(:~
 : Lists all files matching the given pattern in a given directory.
 : The order of the items in the result is not defined.
 : The "." and ".." items are not considered for the match.
 : The result of this function is equivalent to the following call:
 : file:files($path, $pattern, fn:false())
 : The file paths are relative to the provided $path.
 : 
 : @param $path The path/URI to retrieve the children from.
 : @param $pattern The file name condition to be checked.
 : @return A sequence of file names matching the pattern.
 :)
declare function file:files(
  $path as xs:string,
  $pattern as xs:string
) as xs:string* {
  file:files($path, $pattern, fn:false())
};

(:~
 : Lists all files matching the given pattern in a given directory.
 : The order of the items in the result is not defined.
 : The "." and ".." items are not considered for the match.
 : The file paths are relative to the provided $path.
 : 
 : @param $path The path/URI to retrieve the children from.
 : @param $pattern The file name condition to be checked.
 : @param $recursive A boolean flag indicating whether directories
 :        should be searched recursively.
 : @return A sequence of file names matching the pattern.
 : @example rbkt/Queries/zorba/file/files_pattern1.xq
 : @example rbkt/Queries/zorba/file/files_pattern2.xq
 : @example rbkt/Queries/zorba/file/files_pattern_rec1.xq
 : @example rbkt/Queries/zorba/file/files_pattern_rec2.xq
 :)
declare function file:files(
  $path as xs:string,
  $pattern as xs:string,
  $recursive as xs:boolean
) as xs:string* {
  for $f in file:files($path)
  let $full := fn:concat($path, file:path-separator(), $f)
  let $is_directory := file:is-directory($full)
  let $result :=
    (
      if (fn:matches($f, $pattern))
      then $f
      else ()
      ,
      if ($recursive and $is_directory)
      then
        for $child in file:files($full, $pattern, $recursive)
        return fn:concat($f, file:path-separator(), $child)
      else ()
  )
  return $result
};

(:~
 : Retrieves the timestamp of the last modification of the file system item
 : pointed by the path/URI.
 :
 : @param $fileOrDir The file system item to read the last modification
 :        timestamp from.
 : @return The date and time of the last modification of the item.
 : @error An error is thrown if the provided path does not point to an existing
 :        item or if IO or Security problems occur.
 :)
declare %nondeterministic function file:last-modified(
  $fileOrDir as xs:string
) as xs:dateTime external;

(:~
 : This function returns the file path separator used by this operating system.
 :
 : @return The operating system file path separator.
 :)
declare function file:path-separator() as xs:string external;

(:~
 : Transforms a path/URI into a full operating system path. The URI must have
 : the file:// scheme. The operation is performed redardless the existence
 : of the provided path.
 :
 : @param $path The path/URI to transform.
 : @return The operating system file path.
 :)
declare function file:path-to-full-path(
  $path as xs:string
) as xs:string external;

(:~
 : Transforms a file system path into a URI with the file:// scheme. No checks
 : are performed redardless of the existence of the provided file system path.
 :
 : @param $path The path to transform.
 : @return The file URI corresponding to the provided path.
 :)
declare function file:path-to-uri(
  $path as xs:string
) as xs:anyURI external;

(:~
 : file:normalize-path takes a path as a uri, a absolute path or relative path
 : and normalizes it to the form used on the running platform.
 :
 : @param $path The uri or path to normalize.
 : @return The normalization of $path.
 :)
declare function file:normalize-path($path as xs:string) as xs:string external;

(:~
 : The dirname function is the converse of basename; it returns a string of
 : the parent directory of the pathname pointed to by path. Any
 : trailing '/' and '\' characters - depending on the operating system - are
 : not counted as part of the directory name. If path is the empty string or contains no `/'
 : characters, dirname returns the string ".", signifying the current directory.
 :
 : @param $file The filename, of which the dirname should be get.
 : @return The name of the directory the file is in.
 :)
declare function file:dirname($file as xs:string) as xs:string
{
  let $delim := file:path-separator()
  let $delim-escaped := replace($delim, '(\.|\[|\]|\\|\||\-|\^|\$|\?|\*|\+|\{|\}|\(|\))','\\$1')
  let $normalized-file := file:prepare-for-dirname-and-basename($file)
  return
    if (matches($file, concat("^", $delim-escaped, "+$"))) then
      $delim
    else if ($normalized-file eq $delim) then
      $delim
    else if (file:path-separator() eq '\' and matches($file, "^[a-zA-Z]:\\$")) then
      $file
    else if (file:path-separator() eq '\' and matches($normalized-file, "^[a-zA-Z]:$")) then
      concat($normalized-file, '\')
    else if ($file eq "") then
      "."
    else if (matches($normalized-file, $delim-escaped)) then
      replace($normalized-file, concat('^(.*)', $delim-escaped,'.*'),
                         '$1')
    else "."
};

(:~
 : The basename function returns the last component from the pathname pointed to by path,
 : deleting any trailing '/' or '\' characters. If path consists entirely of '/' or '\' characters,
 : the empty string is returned. If path is the empty string, the
 : string "." is returned.
 : 
 :
 : @param $file A file URI/path.
 : @return The base name of this file.
 :)
declare function file:basename($file as xs:string) as xs:string
{
  let $delim := file:path-separator()
  let $delim-escaped := replace($delim, '(\.|\[|\]|\\|\||\-|\^|\$|\?|\*|\+|\{|\}|\(|\))','\\$1')
  let $normalized-file := 
    let $n := file:prepare-for-dirname-and-basename($file)
		return if ($delim eq "\" and matches($n, "^[a-zA-Z]:$")) then
			concat($n, "\")
		else $n
  return
    if (matches($file, concat("^", $delim-escaped, "+$"))) then
      ""
    else if (file:path-separator() eq '\' and matches($file, "^[a-zA-Z]:\\?$")) then
      ""
    else if ($file eq "") then
      "."
    else
      replace($normalized-file, concat("^.*", $delim-escaped), '')
};

(:~
 : The basename#2 function first gets the basename of the given path and then deletes the
 : suffix $suffix, if it is the suffix of the basename of the basename of $file.
 :
 : @param $file A file URI/path.
 : @param $suffix A suffix which should get deleted from the result.
 : @return The basename of $file with a deleted $suffix.
 :)
declare function file:basename($file as xs:string, $suffix as xs:string) as xs:string
{
  let $res := file:basename($file)
  return
    if (fn:ends-with($res, $suffix)) then
      fn:substring($res, 1, fn:string-length($suffix))
    else
      $res
};

(:~
 : This is a helper function used by dirname and basename. This function takes a path as
 : input and normalizes it according to the rules states in dirname/basename documentation
 : and normalizes it to a system specific path.
 :)
declare %private function file:prepare-for-dirname-and-basename($path as xs:string) as xs:string
{
  let $delim := file:path-separator()
  let $delim-escaped := replace($delim, '(\.|\[|\]|\\|\||\-|\^|\$|\?|\*|\+|\{|\}|\(|\))','\\$1')
  let $normalize-path := file:normalize-path($path)
  let $normalized :=
    if ($normalize-path eq $delim) then
      $normalize-path
    else
      replace($normalize-path, concat($delim-escaped, '+$'), '')
  return $normalized
};
