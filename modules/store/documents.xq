xquery version "3.0";

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

(:~
 : This module defines a set of functions which manage documents that
 : are persisted in the store. Specifically, it contains functions
 : to put, remove, list, or retrieve documents.
 : <p/>
 : Please refer to <a href="../zorba/data_lifecycle.html">our documentation</a>
 : for more information about the lifecycle management and manipulation of
 : documents.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see http://zorba.io/errors
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Documents
 :)
module namespace doc = "http://zorba.io/modules/store/documents";

declare namespace zerr = "http://zorba.io/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Retrieves a sequence of URIs of documents bound in the store.
 :
 : @return The list of URIs of the available documents in the store or the
 : empty sequence if none.
 :)
declare function doc:available-documents()
  as xs:string* external;

(:~
 : Gets the document with the given URI from the store.
 :
 : The difference to fn:doc is that this function does not attempt to retrieve
 : the resource from the file system or the web before returning it.
 : Its only responsibility is to return the document from the store that was
 : bound using fn:put or doc:put.
 :
 : @param $uri The URI of the document to retrieve.
 : If a relative URI is given, the URI is made absolute using the static base
 : URI of the module.
 : @return Returns the document bound to the given URI.
 : @error zerr:ZXQD0002 if no document with the given URI exists in the store.
 : @error err:FODC0004 if the given URI is not valid or couldn't be made
 : absolute.
 :)
declare function doc:document( $uri as xs:string )
  as document-node() external;

(:~
 : Returns true if a document with the given URI exists in the store.
 :
 : @param $uri The URI of the document to check for.
 : If a relative URI is given, the URI is made absolute using the static base
 : URI of the module.
 :
 : @return Returns true if a document with the given URI exists in the store or
 : false otherwise.
 : @error err:FODC0004 if the given URI is not valid or couldn't be made
 : absolute.
 :)
declare function doc:is-available-document( $uri as xs:string )
  as xs:boolean external;

(:~
 : Adds a document to the store.
 : The document is bound to the URI given as first parameter.
 : This URI is the name of the document and can be used by the
 : <code>doc:document()</code> function to retrieve the document from the
 : store.
 : <p/>
 : The semantics of the function is similar to the <code>fn:put()</code>
 : function.
 : The difference is that this function accepts only document nodes as
 : parameters.
 : Please note that this function does not try to fetch the document from the
 : external resource identified by the URI.
 : Instead, the file or http-client modules can be used to retrieve the
 : resource as string and <code>fn:parse-xml()</code> can be used to parse the
 : string returning a document.
 :
 : @param $uri The URI of the document.
 : If a relative URI is given, the URI is made absolute using the static base
 : URI of the module.
 : @param $doc The document node to be added to the store.
 : @return An empty XDM instance and a pending update list that, when applied,
 : adds the given document to the store.
 : @error zerr:ZAPI0020 if the store already contains a document for the given
 : URI.
 : @error err:FODC0004 if the given URI is not valid or couldn't be made
 : absolute.
 :)
declare updating function doc:put( $uri as xs:string,
                                   $doc as document-node() )
  external;

(:~
 : Removes the document with the given URI from the store.
 :
 : @param $uri The URI of the document to remove. If a relative URI is given,
 : the URI is made absolute using the static base URI of the module.
 : @return Returns an empty XDM instance and a pending update list that, when
 : applied, removes the document bound to the given URI.
 : @error zerr:ZXQD0002 if no document with the given URI exists in the store.
 : @error err:FODC0004 if the given URI is not valid or couldn't be made
 : absolute.
 :)
declare updating function doc:remove( $uri as xs:string )
  external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
