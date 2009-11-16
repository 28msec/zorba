(:~
 : Module Name: File I/O
 : Module Overview: This library module provides simple file system I/O operations.
 : Date: October 23, 2009
 : Copyright: 2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : @author Gabriel Petrovay
 : @version 1.0
 :)
module namespace file = "http://www.zorba-xquery.com/modules/file";


(:~
 : Copies a file given a source and a destination paths/uris. The operation
 : fails if the source path/URI does not point to a file or the destination
 : path/URI is already used.
 :
 : @param sourceFile The path/URI of the file to copy.
 : @param destinationFile The detination path/URI.
 : @return true if the copy operation was successful.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:copy($sourceFile as xs:string, $destinationFile as xs:string) as xs:boolean external;

(:~
 : Copies a file given a source and a destination paths/uris. The operation
 : fails if the source path/URI does not point to a file or the destination
 : path/URI is already used if the overwrite flag is se to false.
 :
 : @param sourceFile The path/URI of the file to copy.
 : @param destinationFile The destination path/URI.
 : @param overwrite Flag to control if the operation should succeed if a the
 :        destination file already exists.
 : @return true if the copy operation was successful
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:copy($sourceFile as xs:string, $destinationFile as xs:string, $overwrite as xs:boolean) as xs:boolean external;

(:~
 : Tests if a path/URI is already used.
 :
 : @param fileOrDir The path/URI to test for existance.
 : @return true if the path/URI points to an existing file system item.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:exists($fileOrDir as xs:string) as xs:boolean external;

(:~
 : Lists the file system items in a certain directory. No assumption should be
 : made on the order of the items. The "." and ".." items are not returned.
 :
 : @param path The path/URI to retrieve the children from.
 : @return The sequence of names of the direct children. 
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:files($path as xs:string) as xs:string external;

(:~
 : Tests if a path/URI points to a directory. On UNIX-based systems, the root
 : and the volumes roots are considered directories.
 :
 : @param dir The path/URI to test.
 : @return true if the path/URI points to a directory.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:is-directory($dir as xs:string) as xs:boolean external;

(:~
 : Tests if a path/URI points to a file.
 :
 : @param dir The path/URI to test.
 : @return true if the path/URI points to a file.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:is-file($file as xs:string) as xs:boolean external;

(:~
 : Retrieves the timestamp of the last modification of the file system item
 : pointed by the path/URI.
 :
 : @param fileOrDir The file system item to read the last modification
 :        timestamp from.
 : @return The date and time of the last modification of the item.
 : @error An error is thrown if the provided path does not point to an existing
 :        item or if IO or Security problems occur.
 :)
declare sequential function file:last-modified($fileOrDir as xs:string) as xs:dateTime external;

(:~
 : Creates a directory. The operation is equivalent to calling:
 : file:mkdir($dir, true()).
 :
 : @param dir The path/URI denoting the directory to be created.
 : @return true if the operation succeeds.
 : @error An error is thrown if a recursive directory creation is attempted,
 :        or if IO or Security problems occur.
 :)
declare sequential function file:mkdir($dir as xs:string) as xs:boolean external;

(:~
 : Creates a directory. This function is not recursive. The $create flag
 : controls the behavior of this function in case the provided path/URI points
 : to an already existing directory.
 :
 : @param dir The path/URI denoting the directory to be created.
 : @param create Flag indicating whether the directory must be created or not.
 : @return When $create is true, this operation returns true only when the
 :         directory is created. If $create is false, this operation succeeds
 :         even if $dir points to an existing directory.
 : @error An error is thrown if a recursive directory creation is attempted,
 :        or if IO or Security problems occur.
 :)
declare sequential function file:mkdir($dir as xs:string, $create as xs:boolean) as xs:boolean external;

(:~
 : Creates directories recursively. All the missing parent directories from the
 : path/URI are created.
 :
 : @param dir The path/URI denoting the directories to be created.
 : @return true if the directory was successfully created.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:mkdirs($dir as xs:string) as xs:boolean external;

(:~
 : Creates directories recursively. The $create flag controls the behavior of
 : this function in case the provided path/URI points to an already existing
 : directory.
 :
 : @param dir The path/URI denoting the directories to be created.
 : @param create Flag indicating whether the directory must be created or not.
 : @return When $create is true, this operation returns true only when the
 :         directory is created. If $create is false, this operation succeeds
 :         even if $dir points to an existing directory.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:mkdirs($dir as xs:string, $create as xs:boolean) as xs:boolean external;

(:~
 : Transforms a file system path into a URI with the file:// scheme. No checks
 : are performed redarding the existence of the provided file system path.
 :
 : @param path The path to transform.
 : @return the file URI corresponding to the provided path.
 :)
declare sequential function file:path-to-uri($file as xs:string) as xs:anyURI external;

(:~
 : Reads the content of a file and returns a Base64 representation of the
 : content.
 :
 : @param file The file to read.
 : @return the content of the file as Base64.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:read($file as xs:string) as xs:base64Binary external;

(:~
 : 
 :
 : @param 
 : @param 
 : @return 
 : @error 
 :)
declare sequential function file:read-html($file as xs:string) as xs:string external;

(:~
 : 
 :
 : @param 
 : @param 
 : @return 
 : @error 
 :)
declare sequential function file:read-html($file as xs:string, $tidyOptions as xs:string) as xs:string external;

(:~
 : Reads the content of a file and returns a string representation of the
 : content.
 :
 : @param file The file to read.
 : @return the content of the file as string.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:read-text($file as xs:string) as xs:string external;

(:~
 : Reads a file as an XML file and returns an XML document. The file content
 : must be a valid XML otherwise an error will be thrown.
 :
 : @param file The file path/URI to be read.
 : @return an XML document containing the content of the file.
 : @error An error is thrown if the does not contain a valid XML, or if IO or
 :        Security problems occur.
 :)
declare sequential function file:read-xml($file as xs:string) as node() external;

(:~
 : Delete a file or a directory from the file system.
 :
 : @param fileOrDir The path/URI of the file or directory to delete.
 : @return true is the operation is succeeds.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:remove($fileOrDir as xs:string) as xs:boolean external;

(:~
 : Write a sequence of items to a file. This operation creates a new file
 : regardless if the given path/URI points to an existing file or not.
 :
 : @param file The file to write the content to.
 : @param content The content to be serialized to the file.
 : @param serializer-params Parameter to control the serialization of the
 :        content. See the description of the module for the accepted values.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:write($file as xs:string, $content as item()*, $serializer-params as item()) external;

(:~
 : Write a sequence of items to a file. This operation creates a new file or
 : appends the serialized content to the file pointed by the given path/URI
 : If the append flag is true and the file does not exist, a new one is
 : created.
 :
 : @param file The file to write the content to.
 : @param content The content to be serialized to the file.
 : @param serializer-params Parameter to control the serialization of the
 :        content. See the description of the module for the accepted values.
 : @param append Flag to specify if this is an append operation or not.
 : @error An error is thrown if IO or Security problems occur.
 :)
declare sequential function file:write($file as xs:string, $content as item()*, $serializer-params as item(), $append as xs:boolean) external;
