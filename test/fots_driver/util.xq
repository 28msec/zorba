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
  "http://www.zorba-xquery.com/annotations";


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
 : The serialization parameters for XML serialization.
 :)
 declare variable $util:writeXML :=
  <output:serialization-parameters>
    <output:method                value="xml" />
    <output:indent                value="yes"  />
    <output:omit-xml-declaration  value="no" />
  </output:serialization-parameters>;
  
(:~
 : Retrieve the value of from the given node that is either given as text node
 : or in a file attribute.
 :
 : @param $case test-case element.
 : @param $path the path of the test-set.
 : @return the query text.
 :)
declare %ann:nondeterministic function util:get-value(
  $case       as element(fots:test-case),
  $envBaseURI as xs:anyURI,
  $node-name  as xs:string
) as xs:string {
  try {
    for $node in $case/descendant-or-self::*
    where (fn:local-name-from-QName(fn:node-name($node)) = $node-name)
    return
      if(exists($node/@file))
      then fn:unparsed-text(resolve-uri($node/@file, $envBaseURI))
      else fn:data($node)
  } catch * {
    fn:error($fots-err:errNA, $err:description)
  }
};

(:~
 :  returns the parent folder of the given file path.
 :   example: util:parent-folder('/home/user/file.ext') returns '/home/user'.
 : @param $path Path.
 : @return the parent folder of the given file.
 :)

declare function util:parent-folder(
  $path   as xs:string
) as xs:anyURI {
  xs:anyURI(fn:substring-before($path,
                                file:base-name($path)))
};

declare function util:serialize-result(
  $result    as item()*
) as xs:string* {
util:serialize-result($result,
                      $util:serParamXml)
};

declare function util:serialize-result(
  $result    as item()*,
  $SerParams
) as xs:string* {
  for $res in $result
  return
   if($res instance of node())
   then fn:serialize($res,
                     $SerParams)
   else fn:string($res)
};
