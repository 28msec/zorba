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

(:~
 : JSound (JSON schema) validator.
 :
 : @author Paul J. Lucas
 :)

module namespace jsv = "http://jsound.io/modules/validate"; 

import module namespace fetch = "http://zorba.io/modules/fetch";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:===========================================================================:)

(:~ 
 : Validates the given JSON object against the given JSound schema type.
 : 
 : @param $ns The namespace URI of the JSound schema to use.
 : @param $type-name The name of the type in the schema to validate against.
 : @param $item The JSON item to validate.
 : @return the post-validated JSON object.
 : @error jn:JNDY0021 if the loaded schema is invalid JSON.
 : @error jsv:BadJSoundFormat if the loaded schema is invalid JSound.
 : @error zerr:ZXQP0025 if the schema namespace URI cannot be resolved.
 :)
declare function jsv:ns-validate( $ns as string, $type-name as string,
                                  $item as item )
  as boolean
{
  let $schema_doc := fetch:content( $ns, "SCHEMA" )
  let $jsd := jn:parse-json( $schema_doc )
  return jsv:jsd-validate( $jsd, $type-name, $item )
};

(:~
 : Validates the given JSON object against the given JSound schema type.
 :
 : @param $jsd The JSound schema to use.
 : @param $type-name The name of the type in the schema to validate against.
 : @param $item The JSON item to validate.
 : @return the post-validated JSON object.
 : @error jsv:BadJSoundFormat if <code>$jsd</code> is invalid JSound.
 :)
declare function jsv:jsd-validate( $jsd as object, $type-name as string,
                                   $item as item )
 as boolean external;

(:===========================================================================:)

(: vim:set syntax=xquery et sw=2 ts=2: :)
