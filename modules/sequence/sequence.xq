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

(:===========================================================================:)

(:~
 : This module provides an XQuery API to perform set operations on sequences.
 :
 : @author Paul J. Lucas
 : @project Zorba/XML and JSON Data Model/Sequence/Sequence
 :)

module namespace seq = "http://zorba.io/modules/sequence";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:===========================================================================:)

(:~
 : Performs a set intersection of two sequences of atomic items based on their
 : values.
 :
 : @param $seq1 The first sequence.
 : @param $seq2 The second sequence.
 : @return a sequence containing only items from <code>$seq1</code> that are
 : also in <code>$seq2</code>.
 :)
declare function seq:value-intersect( $seq1 as xs:anyAtomicType*,
                                      $seq2 as xs:anyAtomicType* )
  as xs:anyAtomicType* external;

(:~
 : Performs a set union of two sequences of atomic items based on their values.
 :
 : @param $seq1 The first sequence.
 : @param $seq2 The second sequence.
 : @return a sequence containing all items from <code>$seq1</code>
 : and <code>seq2$</code> but without duplicates.
 :)
declare function seq:value-union( $seq1 as xs:anyAtomicType*,
                                  $seq2 as xs:anyAtomicType* )
  as xs:anyAtomicType* external;

(:~
 : Filters the first sequence of atomic items such that they are not in the
 : second sequence based on their values.
 :
 : @param $seq1 The first sequence.
 : @param $seq2 The second sequence.
 : @return a sequence only containing items from <code>$seq1</code>
 : that are not in <code>$seq2</code>.
 :)
declare function seq:value-except( $seq1 as xs:anyAtomicType*,
                                   $seq2 as xs:anyAtomicType* )
  as xs:anyAtomicType* external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
