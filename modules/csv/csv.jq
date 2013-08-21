xquery version "3.0";

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

(:===========================================================================:)

(:~
 : This module provides an API for reading and serializing CSV (comma-separated
 : values) files.
 : See RFC 4180,
 : "Common Format and MIME Type for Comma-Separated Values (CSV) Files."
 : @project Zorba/CSV
 :)

module namespace csv = "http://zorba.io/modules/csv";

declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:===========================================================================:)

(:~
 : TODO
 :
 : @param $csv TODO
 : @param $options TODO
 : @return TODO
 : @error zerr:ZCSV0001 if the \c separator option is given and it's not a
 : single ASCII character.
 :)
declare function csv:parse( $csv as string, $options as object() )
  as object()* external;

(:~
 : TODO
 :
 : @param $csv TODO
 : @return TODO
 :)
declare function csv:parse( $csv as string )
  as object()*
{
  csv:parse( $csv, {} )
};

(:~
 : TODO
 :
 : @param $obj TODO
 : @param $options TODO
 : @return TODO
 :)
declare function csv:serialize( $obj as object()*, $options as object() )
  as string* external;

(:~
 : TODO
 :
 : @param $obj TODO
 : @return TODO
 :)
declare function csv:serialize( $obj as object()* )
  as string*
{
  csv:serialize( $obj, {} )
};

(:===========================================================================:)

(: vim:set syntax=xquery et sw=2 ts=2: :)
