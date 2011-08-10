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
 : This module provides functions to fetch the contents or the type
 : of the content for a resource identified by a URI.
 : For example, it fetches content for file or http resources if Zorba
 : allows file or http access, respectively.
 :
 : <p>The errors raised by functions of this module have the namespace
 : <tt>http://www.zorba-xquery.com/errors</tt> (associated with prefix zerr).</p>
 :
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Matthias Brantner
 :
 : @project external
 :)
module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : <p>Tries to fetch the resource referred to by the given URI.</p>
 :
 : <p>In order to retrieve the content, the functions uses the
 : URI resolution and URL resolver process as documented at
 : <a href="../../html/uriresolvers.html">
 : URI Resolvers</a>. Therefore, it queries all URI mappers
 : and resolvers with kind <tt>EntityData::SOME_CONTENT</tt>.</p>
 :
 : <p>The function is annotated with the <tt>ann:streamable</tt>
 : annotation, that is it returns a streamable string. A streamable
 : string can only be consumed once. Please see section "Streamable Strings"
 : in the <a href="../../html/options_and_annotations.html">
 : documentation of Zorba's annotations</a>.
 : </p>
 :
 : @param $uri the resource to fetch.
 : @return the resource referred to by the given URI as streamble string.
 :
 : @error zerr:ZXQP0025 if the URI could not be resolved
 :   or did not resolve to a <tt>StreamResource</tt>.
 :
 : @see <a href="../../html/uriresolvers.html">URI Resolvers</a>.
 : @see <a href="../../html/options_and_annotations.html">Documentation of Zorba's annotations</a>.
 :)
declare %ann:streamable function fetch:content($uri as xs:string) as xs:string
{
  fetch:content($uri, "SOME_CONTENT")
};

(:~
 : <p>Tries to fetch the resource referred to by the given URI.</p>
 :
 : <p>In order to retrieve the content, the functions uses the
 : URI resolution and URL resolver process as documented at
 : <a href="../../html/uriresolvers.html">
 : URI Resolvers</a>. Therefore, it queries all URI mappers
 : and resolvers with the specified entity kind.</p>
 :
 : <p>The function is annotated with the <tt>ann:streamable</tt>
 : annotation, that is it returns a streamable string. A streamable
 : string can only be consumed once. Please see section "Streamable Strings"
 : in the <a href="../../html/options_and_annotations.html">
 : documentation of Zorba's annotations</a>.
 : </p>
 :
 : @param $uri the resource to fetch.
 : @param $entityKind the kind of resource to fetch.
 : @return the resource referred to by the given URI as streamble string.
 :
 : @error zerr:ZXQP0025 if the URI could not be resolved
 :   or did not resolve to a <tt>StreamResource</tt>.
 :
 : @see <a href="../../html/uriresolvers.html">URI Resolvers</a>.
 : @see <a href="../../html/options_and_annotations.html">Documentation of Zorba's annotations</a>.
 :)

declare %ann:streamable function fetch:content($uri as xs:string, $entityKind as xs:string) as xs:string external;
