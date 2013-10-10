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
 : This module defines a set of functions to probe and refresh indexes which are
 : declared in the prolog of a module.
 : <p/>
 : This module is part of
 : <a href="../zorba/xqddf.html">Zorba's XQuery Data Definition Facility</a>.
 : All the indexes managed by this module have to be pre-declared in the prolog
 : of a library module.
 : Please refer to the
 : <a href="../zorba/data_lifecycle.html">general documentation</a>
 : for more information and examples.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../zorba/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://zorba.io/modules/store/static/indexes/ddl
 : @see http://zorba.io/modules/store/static/collections/dml
 : @see http://zorba.io/modules/store/static/collections/ddl
 : @see http://zorba.io/modules/store/static/integrity-constraints/ddl
 : @see http://zorba.io/modules/store/static/integrity-constraints/dml
 : @see http://zorba.io/errors
 :
 : @author Zorba Team
 : @project Zorba/Data Store/Indexes/Static Data Manipulation
 :)
module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

declare namespace an = "http://zorba.io/annotations";
declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Gets the domain nodes from an index associated by value equality with a
 : given <em>search tuple</em>.
 : <p/>
 : The search tuple consists of a number of <em>search keys</em> where each
 : search key is either an atomic item or the empty sequence.  The number of
 : search keys given must be equal to the number of keys declared for the
 : index. Since the number of keys differs from one index to another, this
 : function is variadic.
 : @param $name The of the index to probe.
 : @param $key_i A search key used to probe the index with. The i-th search key
 : corresponds to the i-th key expression in the index declaration.
 : @return The set of domain nodes for which the following XQuery expression
 : returns true:
 :  <pre>
 :    $key1 eq $node/keyExpr1 and ... and $keyM eq $node/keyExprM
 :  </pre>
 : where <i>keyExpr<sub>i</sub></i> is the expression specified in the i-th
 : keyspec of the index.
 : @error zerr:ZDDY0021 if the index is not declared.
 : @error zerr:ZDDY0023 if the index does not exist.
 : @error zerr:ZDDY0025 if the number of search keys passed as arguments is not
 : the same as the number of keys declared for the index.
 : @error err:XPTY0004 if a non-empty seach key is given whose type does not
 : match the sequence type specified in the corresponding keyspec.
 :)
declare %an:variadic function
idml:probe-index-point-value( $name as xs:QName, $key_i as xs:anyAtomicType? )
  as node()* external;

(:~
 : This is an extension of the <code>probe-index-point-value()</code> function
 : in that it allows index items to be skipped.
 :
 : @param $name The name of the index to probe.
 : @param $skip The number of index items to skip.
 : @param $key_i The search keys used to probe the index with. The i-th search
 : key corresponds to the i-th key expression in the index declaration.
 : @return The set of domain nodes that satisfy the search condition.
 : @error zerr:ZDDY0021 if the index is not declared.
 : @error zerr:ZDDY0023 if the index does not exist.
 : @error zerr:ZDDY0025 if the number of search keys passed as arguments is not
 : the same as the number of keys declared for the index.
 : @error err:XPTY0004 if a non-empty seach key is given whose type does not
 : match the sequence type specified in the corresponding keyspec.
 :)
declare %an:variadic function
idml:probe-index-point-value-skip( $name as xs:QName,
                                   $skip as xs:integer,
                                   $key_i as xs:anyAtomicType? )
  as node()* external;

(:~
 : Gets from an index the domain nodes associated by general equality with a
 : given <em>search sequence </em>.
 : The search sequence consists of an arbitrary number of <em>search keys</em>
 : where each search key is an atomic item.
 : The function is supported by general indexes only.
 :
 : @param $name The name of the index to probe.
 : @param $key The search sequence.
 : @return The set of domain nodes for which the following XQuery expression
 : returns true:
 :  <pre>
 :    $keys = $node/keyExpr
 :  </pre>
 : where keyExpr is the expression specified in the keyspec of the index
 : (remember that for general indexes, there can be only one keyspec).
 : @error err:XPTY0004 if the search sequence contains a search key whose type
 : does not match the sequence type specified in the keyspec of the index.
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0029 if the index is not general.
 :)
declare function idml:probe-index-point-general( $name as xs:QName,
                                                 $key  as xs:anyAtomicType* )
  as node()* external;

(:~
 : Gets the domain nodes associated by value order-comparison (operators
 : <code>le</code>, <code>lt</code>, <code>ge</code>, <code>gt</code>) with a
 : given <em>search box</em>.
 : <p/>
 : The search box is specified as a number <i>M</i> of <em>rangespecs</em>
 : where each rangespec consists of six values.
 : The number <i>M</i> must be greater than 0 and less than or equal to the
 : number <i>N</i> of keyspecs found in the index declaration.
 : If <i>M</i> &lt; <i>N</i>, then the "missing" rangespecs are assumed to have
 : the following value: [(), (), false, false, false, false].
 : As a result, we can assume that <i>M</i> = <i>N</i>.
 : Remember that for general indexes, there can be only one IndexKeySpec and,
 : as a result for general indexes, <i>M</i> = <i>N</i> = 1.
 : Since the number of keys differs from one index to another,
 : this function is variadic.
 : <p/>
 : The i<sup>th</sup> rangespec corresponds to the i<sup>th</sup> keyspec, and
 : specifies a search condition on the key values that are produced by
 : evaluating that keyspec for every domain node.
 : Specifically, we define the i<sup>th</sup> <em>rangespec result</em> as the
 : set of domain nodes for which the following XQuery expression returns
 : true:
 :  <pre>
 :    if ( $haveLowerBound-i and $haveUpperBound-i ) then
 :      $lowerBound-i lop $node/keyExpr-i and $node/keyExpr-i uop $upperBound-i
 :    else if ( $haveLowerBound-i ) then
 :      $lowerBound-i lop $node/keyExpr-i
 :    else if ( $haveUpperBound-i ) then
 :      $node/keyExpr-i uop $upperBound-i
 :    else
 :      fn:true()
 :  </pre>
 : where <i>keyExpr-i</i> is the expression specified by the i<sup>th</sup>
 : keyspec of the index, <i>lop</i> is either the <code>le</code> or the
 : <code>lt</code> operator depending on whether
 : <code>$lowerBoundsIncluded-i</code> is true or false, and <i>uop</i> is
 : either the <i>le</i> or the <i>lt</i> operator depending on whether
 : <code>$upperBoundsIncluded-i</code> is true or false.
 :
 : @param $name The name of the index to probe.
 : @param $lowerBound-i The lower bound in a range of key values.
 : @param $upperBound-i The upper bound in a range of key values.
 : @param $haveLowerBound-i If false, then there is no lower bound, or
 : equivalently, the lower bound is -INFINITY. Otherwise, the lower bound is
 : the one given by the <code>$lowerBound-i</code> value.
 : @param $haveUpperBound-i If false, then there is no upper bound, or
 : equivalently, the upper bound is +INFINITY. Otherwise, the upper bound is
 : the one given by the <code>$upperBound-i</code> value.
 : @param $lowerBoundIncluded-i If false, then the range is open from below,
 : i.e., the <code>$lowerBound-i</code> value is not considered part of the
 : range. Otherwise, the range is closed from below, i.e., the
 : <code>$lowerBound-i</code> value is part of the range.
 : @param $upperBoundIncluded-i If false, then the range is open from above,
 : i.e., the <code>$upperBound-i</code> value is not considered part of the
 : range. Otherwise, the range is closed from above, i.e., the
 : <code>$upperBound-i</code> value is part of the range.
 : @return The intersection of all the rangespec results.
 : @error zerr:ZDDY0021 if the index is not declared.
 : @error zerr:ZDDY0023 if the index does not exist.
 : @error zerr:ZDDY0025 if the number of rangespecs passed as arguments is zero
 : or greater than the number of keys declared for the index.
 : @error zerr:ZDDY0026 if the index is not a range index.
 : @error err:XPTY0004 if <code>$haveLowerBound-i</code> is true and
 : <code>$lowerBound-i</code> is an atomic item whose type does not match the
 : sequence type specified by the i<sup>th</sup> keyspec, or
 : <code>$haveUpperBound-i</code> is true and <code>$upperBound-i</code> is an
 : atomic item whose type does not match the sequence type specified by the
 : i<sup>th</sup> keyspec.
 : @error zerr:ZDDY0034 if (a) the index is general (in which case there is
 : only one rangespac), (b) the index is untyped, (c) there is both a lower and
 : an upper bound, and (d) if T1 and T2 are the types of the lower and upper
 : bound, neither T1 is a subtype of T2 nor T2 is a subtype of T1.
 :)
declare %an:variadic function
idml:probe-index-range-value( $name                 as xs:QName,
                              $lowerBound-i         as xs:anyAtomicType?,
                              $upperBound-i         as xs:anyAtomicType?,
                              $haveLowerBound-i     as xs:boolean,
                              $haveUpperBound-i     as xs:boolean,
                              $lowerBoundIncluded-i as xs:boolean,
                              $upperBoundIncluded-i as xs:boolean )
  as node()* external;

(:~
 : This function is an extension of the <code>probe-index-range-value()</code>
 : function that index items to be skipped.
 :
 : @param $name The QName of the index to probe
 : @param $skip The number of index items to skip.
 : @param $lowerBound-i The lower bound in a range of key values.
 : @param $upperBound-i The upper bound in a range of key values.
 : @param $haveLowerBound-i If false, then there is no lower bound, or
 : equivalently, the lower bound is -INFINITY. Otherwise, the lower bound is
 : the one given by the <code>$lowerBound-i</code> value.
 : @param $haveUpperBound-i If false, then there is no upper bound, or
 : equivalently, the upper bound is +INFINITY. Otherwise, the upper bound is
 : the one given by the <code>$upperBound-i</code> value.
 : @param $lowerBoundIncluded-i If false, then the range is open from below,
 : i.e., the lowerBound-i value is not considered part of the range. Otherwise,
 : the range is closed from below, i.e., the <code>$lowerBound-i</code> value
 : is part of the range.
 : @param $upperBoundIncluded-i If false, then the range is open from above,
 : i.e., the upperBound-i value is not considered part of the range. Otherwise,
 : the range is closed from above, i.e., the <code>$upperBound-i</code> value
 : is part of the range.
 : @return The set of domain nodes that satisfy the search condition.
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0025 if the number of rangespecs passed as arguments is zero
 : or greater than the number of keys declared for the index.
 : @error zerr:ZDDY0026 if the index is not a range index.
 : @error err:XPTY0004 if <code>$haveLowerBound-i</code> is true and
 : <code>$lowerBound-i</code> is an atomic item whose type does not match the
 : sequence type specified by the i<sup>th</sup> keyspec, or
 : <code>$haveUpperBound-i</code> is true and <code>$upperBound-i</code> is an
 : atomic item whose type does not match the sequence type specified by the
 : i<sup>th</sup> keyspec.
 : @error zerr:ZDDY0034 if (a) the index is general (in which case there is
 : only one rangespac), (b) the index is untyped, (c) there is both a lower and
 : an upper bound, and (d) if T1 and T2 are the types of the lower and upper
 : bound, neither T1 is a subtype of T2 nor T2 is a subtype of T1.
 :)
declare %an:variadic function
idml:probe-index-range-value-skip( $name                 as xs:QName,
                                   $skip                 as xs:integer,
                                   $lowerBound-i         as xs:anyAtomicType?,
                                   $upperBound-i         as xs:anyAtomicType?,
                                   $haveLowerBound-i     as xs:boolean,
                                   $haveUpperBound-i     as xs:boolean,
                                   $lowerBoundIncluded-i as xs:boolean,
                                   $upperBoundIncluded-i as xs:boolean )
  as node()* external;

(:~
 : Gets the domain nodes associated by general order-comparison (operators
 : <code>&lt;=</code>, <code>&lt;</code>, <code>&gt;=</code>,
 : <code>&gt;</code>) with one or two <em>search sequences</em>.
 : <p/>
 : Each search sequence consists of an arbitrary number of
 : <em>search keys</em> where each search key is an atomic item.
 : This method is supported by general range indexes only.
 : Its result is either an error or the set of domain nodes for which the
 : following XQuery expression returns true:
 :  <pre>
 :    if ( $haveLowerBound and $haveUpperBound ) then
 :      $lowerBoundKeys lop $node/keyExpr and $node/keyExpr uop $upperBoundKeys
 :    else if ( $haveLowerBound ) then
 :      $lowerBoundKeys lop $node/keyExpr
 :    else if ( $haveUpperBound ) then
 :      $node/keyExpr uop $upperBoundKeys
 :    else
 :      fn:true()
 :  </pre>
 : where <i>keyExpr</i> is the expression specified in the keyspec of the
 : index, <i>lop</i> is either the <code>&lt;=</code> or the <code>&lt;</code>
 : operator depending on whether <code>$lowerBoundsIncluded</code> is true or
 : false, and <i>uop</i> is either the <code>&lt;=</code> or the
 : <code>&lt;</code> operator depending on whether
 : <code>$upperBoundsIncluded</code> is true or false.
 :
 : @param $name The of the index to probe.
 : @param $lowerBound The lower bound search sequence.
 : @param $upperBound The upper bound search sequence.
 : @param $haveLowerBound Whether a lower bound search sequence exists or not.
 : @param $haveUpperBound Whether an upper bound search sequence exists or not.
 : @param $lowerBoundIncluded Whether to use the <code>&lt;=</code> or the
 : <code>&lt;</code> operator when comparing a search key from
 : <code>$lowerBound</code> with an index key.
 : @param $upperBoundIncluded Whether to use the <code>&lt;=</code> or the
 : <code>&lt;</code> operator when comparing an index key with a search key
 : from <code>$upperBound</code>.
 : @return The set of domain nodes that satisfy the search condition.
 : @error zerr:ZDDY0021 if the index was not declared.
 : @error zerr:ZDDY0023 if the index does not exist.
 : @error zerr:ZDDY0030 if the index is not a general range index.
 : @error err:XPTY0004 if <code>$haveLowerBound</code> is true and
 : <code>$lowerBoundKeys</code> contains an atomic item whose type does not
 : match the sequence type specified by the index keyspec, or
 : <code>$haveUpperBound</code> is true and <code>$upperBoundKeys</code>
 : contains an atomic item whose type does not match the sequence type
 : specified by the index keyspec.
 :)
declare function
idml:probe-index-range-general( $name               as xs:QName,
                                $lowerBound         as xs:anyAtomicType*,
                                $upperBound         as xs:anyAtomicType*,
                                $haveLowerBound     as xs:boolean,
                                $haveUpperBound     as xs:boolean,
                                $lowerBoundIncluded as xs:boolean,
                                $upperBoundIncluded as xs:boolean )
  as node()* external;

(:~
 : Updates the index with the given name.  Note that if the maintenance
 : property of the index is automatic, this function does nothing.
 :
 : @param $name The name of the index to refresh.
 : @return An empty XDM instance and a pending update list that, when applied,
 : refreshes the contents of the index.
 : @error zerr:ZDDY0021 if the index is not declared.
 : @error zerr:ZDDY0023 if the index does not exist.
 :)
declare updating function idml:refresh-index( $name as xs:QName )
  external;

(:~
 : Gets a sequence of all keys contained in the index with the given name.
 : Each element has the following structure:
 :  <pre class="brush: xml;">
 :   &lt;key xmlns="http://zorba.io/modules/store/static/indexes/dml"&gt;
 :     &lt;attribute value="key1_value"/&gt;
 :     &lt;attribute value="key2_value"/&gt;
 :     &lt;attribute value="key3_value"/&gt;
 :   &lt;/key&gt;
 :  </pre>
 : Note that the order of the attribute elements reflects the order of
 : the keys in the index specification. Also note that the values in
 : these attributes have the type that is declared in the corresponding
 : index specification.
 :
 : @param $name The name of the index to get the keys for.
 : @return A sequence of elements comprising the keys in the index.
 : @error zerr:ZDDY0021 if the index was not declared.
 : @error zerr:ZDDY0023 if the index does not exist.
 :)
declare function idml:keys( $name as xs:QName )
  as node()* external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
