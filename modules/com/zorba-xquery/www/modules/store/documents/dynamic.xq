xquery version "1.0";

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
 : This module defines a set of functions which manage documents that
 : are persisted in the store. Specifically, it contains functions
 : to add, remove, list, or retrieve documents.
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 : @project store/documents
 :)
module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

(:~
 : Adds a document to the store. The document is bound to the URI
 : given as first parameter. This URI is the name of the document and
 : can be used by the doc:document() function to retrieve
 : the document from the store.
 :
 : @param $uri The URI of the document. If a relative URI is given, the URI
 :        is made absolute using the static base URI of the module.
 : @param $doc The document node to be added to the store.
 :
 : @return Returns an empty XDM instance and a pending update list which, when
 :         applied, adds the given document to the store.
 :
 : @error ZAPI0020 if the store already contains a document for the given $uri.
 : @error FODC0004 if the given URI is not valid or couldn't be absolutized.
 :)
declare updating function doc:add(
  $uri as xs:string,
  $doc as document-node()) external;

(:~
 : Removes the document with the given URI from the store.
 :
 : @param $uri The URI of the document to remove. If a relative URI is given,
 : the URI is made absolute using the static base URI of the module.

 : @return Returns an empty XDM instance and a pending update list which, when
 :         applied, removes the document bound to the given URI.
 :
 : @error XQD0001 if no document with the given URI exists in the store.
 : @error FODC0004 if the given URI is not valid or couldn't be absolutized.
 :)
declare updating function doc:remove($uri as xs:string) external;

(:~
 : Returns the document with the given URI from the store.
 :
 : @param $uri The URI of the document to retrieve. If a relative URI is given,
 : the URI is made absolute using the static base URI of the module.
 :
 : @return Returns the document bound to the given URI.
 :
 : @error XQD0001 if no document with the given URI exists in the store.
 : @error FODC0004 if the given URI is not valid or couldn't be absolutized.
 :)
declare function doc:document($uri as xs:string) as document-node() external;

(:~
 : Retrieves a sequence of URIs of documents bound in the store.
 :
 : @return The list of URIs of the available documents in the store. The empty
 :         sequence is returned if not document exists in the store.
 :)
declare function doc:available-documents() as xs:string* external;

(:~
 : Returns true if a document with the given URI exists in the store.
 :
 : @param $uri The URI of the document to check for. If a relative URI is given,
 : the URI is made absolute using the static base URI of the module.
 :
 : @return Returns true if a document with the given URI exists in the store or false otherwise.
 :
 : @error FODC0004 if the given URI is not valid or couldn't be absolutized.
 :)
declare function doc:is-available-document($uri as xs:string) as xs:boolean external;
