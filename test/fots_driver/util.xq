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
 : Zorba FOTS driver util
 : @author Sorin Nasoi
 :)

module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util";

import schema namespace output =
  "http://www.w3.org/2010/xslt-xquery-serialization";

import module namespace file  =
  "http://expath.org/ns/file";

import module namespace fots-err =
  "http://www.zorba-xquery.com/fots-driver/errors" at "errors.xq";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace ann =
  "http://zorba.io/annotations";

declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";
declare option op:disable "f:trace";

(:~
 : The serialization parameters for XML serialization.
 :)
 declare variable $util:serParamXml :=
  <output:serialization-parameters>
    <output:method                value="xml" />
    <output:indent                value="no"  />
    <output:omit-xml-declaration  value="yes" />
  </output:serialization-parameters>;

(:~
 : The serialization parameters for text serialization.
 :)
 declare variable $util:writeText :=
  <output:serialization-parameters>
    <output:method                value="text" />
    <output:indent                value="yes"  />
  </output:serialization-parameters>;

(:~
 : The serialization parameters for text serialization.
 :)
 declare variable $util:writeXML :=
  <output:serialization-parameters>
    <output:method                value="xml" />
    <output:indent                value="yes"  />
  </output:serialization-parameters>;

(:~
 : Search within a given test-case for all element nodes with a given node name.
 : For each such element node return:
 : (a) if the node has a @file attr, the content of that file as unparsed text,
 : or
 : (b) the typed value of the node (assuming it is promotable to string).
 :
 : @param $parentNode
 : @param $baseURI
 : @param $node-name
 : @return the content of the node with name 'node-name'.
 :)
declare %ann:nondeterministic function util:get-value(
  $parentNode as element(),
  $baseURI    as xs:anyURI,
  $node-name  as xs:string
) as xs:string
{
  try
  {
    for $node in $parentNode/descendant-or-self::*
    where (fn:local-name-from-QName(fn:node-name($node)) eq $node-name)
    return
      if ($node/@file)
      then
      {
        if(ends-with($node/@file, ".xml"))
        then fn:serialize(doc(resolve-uri($node/@file, $baseURI)), $util:serParamXml)
        else fn:unparsed-text(resolve-uri($node/@file, $baseURI))
      }
      else fn:string($node)
  }
  catch *
  {
    fn:error($fots-err:errNA, $err:description)
  }
};


(:~
 :  Returns the parent folder of the given file path.
 :  example: util:parent-folder('/home/user/file.ext') returns '/home/user'.
 :
 : @param $path Path.
 : @return the parent folder of the given file.
 :)
declare function util:parent-folder(
  $path as xs:string
) as xs:anyURI
{
  xs:anyURI(fn:substring-before($path, file:base-name($path)))
};


declare %ann:sequential function util:write-query-to-file(
  $query        as xs:string,
  $queryName    as xs:string
) {
  file:write-text(concat("query_", $queryName, ".xq"),
                  $query,
                  $util:writeText);
};
