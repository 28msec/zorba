xquery version "3.0";

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
 : <p>This module provides functions to fetch the content of a resource identified
 : by a URI. For example, it fetches the content of file or http resources.</p>
 :
 : <p>In order to retrieve such content, the functions use the
 : URI resolution and URL resolver process as documented at
 : <a href="../zorba/uriresolvers.html">
 : URI Resolvers</a>.</p>
 :
 : @author Matthias Brantner
 :
 : @project Zorba/Input Output/Fetch
 :)
module namespace fetch = "http://zorba.io/modules/fetch";

declare namespace an = "http://zorba.io/annotations";

declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : <p>Tries to fetch the resource referred to by the given URI.</p>
 :
 : <p>It queries all URI mappers and resolvers with kind
 : <tt>EntityData::SOME_CONTENT</tt>.</p>
 :
 : <p>The content is assumed to be UTF-8 encoded.</p>
 :
 : @param $uri the resource to fetch.
 : @return the resource referred to by the given URI as streamble string.
 :
 : @error uri:URI_UNRESOLVED_OR_NOSTREAM if the URI could not be resolved
 :   or did not resolve to a <tt>StreamResource</tt>.
 :
 : @see <a href="../zorba/uriresolvers.html">URI Resolvers</a>.
 : @see <a href="../zorba/options_and_annotations.html">Documentation of Zorba's annotations</a>.
 :)
declare %an:streamable function fetch:content($uri as xs:string) as xs:string
{
  fetch:content($uri, "SOME_CONTENT")
};

(:~
 : <p>Tries to fetch the resource referred to by the given URI.</p>
 :
 : <p>It queries all URI mappers and resolvers with kind the specified
 : entity kind.</p>
 :
 : <p>The content is assumed to be UTF-8 encoded.</p>
 :
 : @param $uri the resource to fetch.
 : @param $entity-kind the kind of resource to fetch.
 : @return the resource referred to by the given URI as streamble string.
 :
 : @error uri:URI_NOT_RESOLVED_OR_NOSTREAM if the URI could not be resolved
 :   or did not resolve to a <tt>StreamResource</tt>.
 :
 : @see <a href="../zorba/uriresolvers.html">URI Resolvers</a>.
 : @see <a href="../zorba/options_and_annotations.html">Documentation of Zorba's annotations</a>.
 :)
declare %an:streamable function fetch:content($uri as xs:string, $entity-kind as xs:string)
as xs:string
{
  fetch:content($uri, $entity-kind, "UTF-8")
};

(:~
 : <p>Tries to fetch the resource referred to by the given URI.</p>
 :
 : <p>It queries all URI mappers and resolvers with kind the specified
 : entity kind.</p>
 :
 : @param $uri the resource to fetch.
 : @param $entity-kind the kind of resource to fetch.
 : @param $encoding the encoding of the content
 : @return the resource referred to by the given URI as streamble string.
 :
 : @error uri:URI_UNRESOLVED_OR_NOSTREAM if the URI could not be resolved
 :   or did not resolve to a <tt>StreamResource</tt>.
 : @error uri:CHARSET_UNKNOWN if the given encoding is invalid or not supported.
 :
 : @see <a href="../zorba/uriresolvers.html">URI Resolvers</a>.
 : @see <a href="../zorba/options_and_annotations.html">Documentation of Zorba's annotations</a>.
 :)
declare %an:streamable function fetch:content(
  $uri as xs:string,
  $entity-kind as xs:string,
  $encoding as xs:string)
as xs:string external;

(:~
 : <p>Tries to fetch the resource referred to by the given URI and
 : returning it as base64Binary.</p>
 :
 : <p>It queries all URI mappers and resolvers with kind
 : <tt>EntityData::SOME_CONTENT</tt>.</p>

 : @param $uri the resource to fetch.
 : @return the resource referred to by the given URI as streamble base64Binary.
 :
 : @error uri:URI_UNRESOLVED_OR_NOSTREAM if the URI could not be resolved
 :   or did not resolve to a <tt>StreamResource</tt>.
 :)
declare %an:streamable function fetch:content-binary($uri as xs:string)
as xs:base64Binary
{
  fetch:content-binary($uri, "SOME_CONTENT")
};

(:~
 : <p>Tries to fetch the resource referred to by the given URI and
 : returning it as base64Binary.</p>
 :
 : <p>It queries all URI mappers and resolvers with kind the specified
 : entity kind.</p>
 :
 : @param $uri the resource to fetch.
 : @param $entity-kind the kind of resource to fetch.
 : @return the resource referred to by the given URI as streamble base64Binary.
 :
 : @error uri:URI_UNRESOLVED_OR_NOSTREAM if the URI could not be resolved
 :   or did not resolve to a <tt>StreamResource</tt>.
 :)
declare %an:streamable function fetch:content-binary(
  $uri as xs:string,
  $entity-kind as xs:string)
as xs:base64Binary external;
