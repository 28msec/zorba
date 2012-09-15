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
 : This module defines a set of functions to probe and refresh indexes which are
 : declared in the prolog of a module.
 :
 : <p>This module is part of <a href="../../html/xqddf.html">Zorba's XQuery Data
 : Definition Facility</a>. All the indexes managed by this module
 : have to be pre-declared in the prolog of a library module. Please refer to the
 : <a href="../../html/data_lifecycle.html">general documentation</a>
 : for more information and examples.</p>
 :
 : @see <a href="../../html/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../../html/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/collections/dml
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/integrity_constraints/dml
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Zorba Team
 :
 : @project store/indexes/static
 :
 :)
module namespace idml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace an = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";

declare option ver:module-version "2.0";

(:~
 : <p>The probe-index-point-value function retrieves from an index the domain 
 : nodes associated by value equality with a given <strong>search tuple</strong>.
 : The search tuple consists of a number of <strong>search keys</strong>, where
 : each search key is either an atomic item or the empty sequence.  The number
 : of search keys given must be equal to the number of keys declared for the 
 : index. Since the number of keys differs from one index to another, this 
 : function is variadic.</p>
 :
 : <p>The result of the function is either an error or the set of domain nodes for 
 : which the following xquery expression returns true:</p>
 :
 : <pre>
 : $key1 eq $node/keyExpr1 and ... and $keyM eq $node/keyExprM
 : </pre>
 : where keyExpr<sub>i</sub> is the expression specified in the i-th keyspec 
 : of the index.
 :
 : @param $name The QName of the index to probe
 : @param $key_i the search keys used to probe the index with. The i-th search
 :        key corresponds to the i-th key expression in the index declaration.
 : @return The set of domain nodes that satisfy the search condition.
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0025 if the number of search keys passed as arguments is not
 :        the same as the number of keys declared for the index.
 : @error err:XPTY0004 if a non-empty seach key is given, whose type does not match 
 :        the sequence type specified in the corresponding keyspec.
 :
 :)
declare %an:variadic function idml:probe-index-point-value(
  $name as xs:QName, 
  $key_i as xs:anyAtomicType?) as node()*  external; 


(:~
 : <p>The probe-index-point-value-skip function is an extension of the
 : probe-index-point-value function. Additionally, it allows to skip index
 : items. 
 :
 : @param $name The QName of the index to probe
 : @param $skip The number of index items to skip.
 : @param $key_i the search keys used to probe the index with. The i-th search
 :        key corresponds to the i-th key expression in the index declaration.
 : @return The set of domain nodes that satisfy the search condition.
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0025 if the number of search keys passed as arguments is not
 :        the same as the number of keys declared for the index.
 : @error err:XPTY0004 if a non-empty seach key is given, whose type does not match 
 :        the sequence type specified in the corresponding keyspec.
 :
 :)
declare %an:variadic function idml:probe-index-point-value-skip(
  $name as xs:QName, 
  $skip as xs:integer,
  $key_i as xs:anyAtomicType?) as node()*  external; 


(:~
 : <p>The probe-index-point-general function retrieves from an index the domain
 : nodes associated by general equality with a given <strong>search sequence
 : </strong>. The search sequence consists of an arbitrary number of <strong>
 : search keys</strong>, where each search key is an atomic item. The function
 : is supported by general indexes only. Its result is either an error or the
 : set of domain nodes for which the following xquery expression returns true:</p>
 : <pre>
 : $keys = $node/keyExpr
 : </pre>
 : where keyExpr is the expression specified in the keyspec of the index (remember
 : that for general indexes, there can be only one keyspec).
 :
 : @param $name The QName of the index to probe.
 : @param $key The search sequence.
 : @return The set of domain nodes that satisfy the search condition.
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0029 if the index is not general.
 : @error err:XPTY0004  if the search sequence contains a search key, whose 
 :        type does not match the sequence type specified in the keyspec of
 :        the index.
 :)
declare function idml:probe-index-point-general(
  $name as xs:QName, 
  $key  as xs:anyAtomicType*) as node()*  external; 


(:~
 : <p>The probe-index-range-value function retrieves the domain nodes associated
 : by value order-comparison (operators le, lt, ge, gt) with a given <strong>search 
 : box</strong>. The search box is specified as a number M of <strong>rangespecs
 : </strong>, where each rangespec consists of six values. The number M must be 
 : greater than 0 and less than or equal to the number N of keyspecs found in the 
 : index declaration. If M is less than N, then the "missing" rangespecs are 
 : assumed to have the following value: [(), (), false, false, false, false]. 
 : As a result, we can assume that M is equal to N (Remember that for general 
 : indexes, there can be only one IndexKeySpec, and as a result, for general 
 : indexes, M = N = 1). Since the number of keys differs from one index to 
 : another, this function is variadic.</p>
 :
 : <p>The i<sup>th</sup> rangespec corresponds to the i<sup>th</sup> keyspec, and 
 : specifies a search condition on the key values that are produced by evaluating
 : that keyspec for every domain node. Specifically, we define the i<sup>th</sup>
 : <strong>rangespec result</strong> as the set of domain nodes for which the 
 : following xquery expression returns true:</p>
 :
 :<pre>
 : if ($haveLowerBound-i and $haveUpperBound-i) then
 :   $lowerBound-i lop $node/keyExpr-i and $node/keyExpr-i uop $upperBound-i
 : else if ($haveLowerBound-i) then
 :   $lowerBound-i lop $node/keyExpr-i
 : else if ($haveUpperBound-i) then
 :   $node/keyExpr-i uop $upperBound-i
 : else
 :   fn:true()
 :</pre>
 :
 : <p>where keyExpr-i is the expression specified by the i<sup>th</sup> keyspec 
 : of the index, lop is either the le or the lt operator depending on whether 
 : $lowerBoundsIncluded-i is true or false, and uop is either the le or the 
 : lt operator depending on whether $upperBoundsIncluded-i is true or false.</p>
 :
 : <p>The result of the probe-index-range-value function is either an error,
 : or the intersection of all the rangespec results.</p>
 :
 : @param $name The QName of the index to probe
 : @param $lowerBound-i The lower bound in a range of key values.
 : @param $upperBound-i The upper bound in a range of key values.
 : @param $haveLowerBound-i If false, then there is no lower bound, or 
 :        equivalently, the lower bound is -INFINITY. Otherwise, the lower 
 :        bound is the one given by the lowerBound-i value. 
 : @param $haveUpperBound-i If false, then there is no upper bound, or 
 :        equivalently, the upper bound is +INFINITY. Otherwise, the upper 
 :        bound is the one given by the upperBound-i value. 
 : @param $lowerBoundIncluded-i If false, then the range is open from below, 
 :        i.e., the lowerBound-i value is not considered part of the 
 :        range. Otherwise, the range is closed from below, i.e., the 
 :        lowerBound-i value is part of the range. 
 : @param $upperBoundIncluded-i If false, then the range is open from above, 
 :        i.e., the upperBound-i value is not considered part of the 
 :        range. Otherwise, the range is closed from above, i.e., the 
 :        upperBound-i value is part of the range.
 : @return The set of domain nodes that satisfy the search condition.
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0025 if the number of rangespecs passed as arguments
 :        is zero or greater than the number of keys declared for the index.
 : @error zerr:ZDDY0026 if the index is not a range index.
 : @error err:XPTY0004  if $haveLowerBound-i is true and $lowerBound-i is an
 :        atomic item whose type does not match the sequence type specified
 :        by the i<sup>th</sup> keyspec, or $haveUpperBound-i is true and 
 :        $upperBound-i is an atomic item whose type does not match the 
 :        sequence type specified by the i<sup>th</sup> keyspec.
 : @error zerr:ZDDY0034 if (a) the index is general (in which case there is 
 :        only one rangespac), (b) the index is untyped, (c) there is both a
 :        lower and an upper bound, and (d) if T1 and T2 are the types of the 
 :        lower and upper bound, neither T1 is a subtype of T2 nor T2 is a 
 :        subtype of T1.   
 :)
declare %an:variadic function idml:probe-index-range-value(
  $name                 as xs:QName, 
  $lowerBound-i         as xs:anyAtomicType?,
  $upperBound-i         as xs:anyAtomicType?,
  $haveLowerBound-i     as xs:boolean,
  $haveUpperBound-i     as xs:boolean,
  $lowerBoundIncluded-i as xs:boolean,
  $upperBoundIncluded-i as xs:boolean) as node()*  external;


(:~
 : <p>The probe-index-range-value-skip function is an extension of the
 : probe-index-range-value function. Additionally, it allows to skip index
 : items. 
 :
 : @param $name The QName of the index to probe
 : @param $skip The number of index items to skip.
 : @param $lowerBound-i The lower bound in a range of key values.
 : @param $upperBound-i The upper bound in a range of key values.
 : @param $haveLowerBound-i If false, then there is no lower bound, or 
 :        equivalently, the lower bound is -INFINITY. Otherwise, the lower 
 :        bound is the one given by the lowerBound-i value. 
 : @param $haveUpperBound-i If false, then there is no upper bound, or 
 :        equivalently, the upper bound is +INFINITY. Otherwise, the upper 
 :        bound is the one given by the upperBound-i value. 
 : @param $lowerBoundIncluded-i If false, then the range is open from below, 
 :        i.e., the lowerBound-i value is not considered part of the 
 :        range. Otherwise, the range is closed from below, i.e., the 
 :        lowerBound-i value is part of the range. 
 : @param $upperBoundIncluded-i If false, then the range is open from above, 
 :        i.e., the upperBound-i value is not considered part of the 
 :        range. Otherwise, the range is closed from above, i.e., the 
 :        upperBound-i value is part of the range.
 : @return The set of domain nodes that satisfy the search condition.
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0025 if the number of rangespecs passed as arguments
 :        is zero or greater than the number of keys declared for the index.
 : @error zerr:ZDDY0026 if the index is not a range index.
 : @error err:XPTY0004  if $haveLowerBound-i is true and $lowerBound-i is an
 :        atomic item whose type does not match the sequence type specified
 :        by the i<sup>th</sup> keyspec, or $haveUpperBound-i is true and 
 :        $upperBound-i is an atomic item whose type does not match the 
 :        sequence type specified by the i<sup>th</sup> keyspec.
 : @error zerr:ZDDY0034 if (a) the index is general (in which case there is 
 :        only one rangespac), (b) the index is untyped, (c) there is both a
 :        lower and an upper bound, and (d) if T1 and T2 are the types of the 
 :        lower and upper bound, neither T1 is a subtype of T2 nor T2 is a 
 :        subtype of T1.   
 :)
declare %an:variadic function idml:probe-index-range-value-skip(
  $name                 as xs:QName, 
  $skip                 as xs:integer,
  $lowerBound-i         as xs:anyAtomicType?,
  $upperBound-i         as xs:anyAtomicType?,
  $haveLowerBound-i     as xs:boolean,
  $haveUpperBound-i     as xs:boolean,
  $lowerBoundIncluded-i as xs:boolean,
  $upperBoundIncluded-i as xs:boolean) as node()*  external;


(:~
 : <p>The probe-index-range-general function retrieves the domain nodes associated
 : by general order-comparison (operators &lt;=, &lt;, &gt;=, &gt;) with one or two
 : <strong>search sequences</strong>. Each search sequence consists of an 
 : arbitrary number of <strong>search keys</strong>, where each search key is 
 : an atomic item. This method is supported by general range indexes only. Its
 : result is either an error or the set of domain nodes for which the following
 : xquery expression returns true:</p>
 :
 : <pre>
 : if ($haveLowerBound and $haveUpperBound) then
 :   $lowerBoundKeys lop $node/keyExpr and $node/keyExpr uop $upperBoundKeys
 : else if ($haveLowerBound) then
 :   $lowerBoundKeys lop $node/keyExpr
 : else if ($haveUpperBound) then
 :   $node/keyExpr uop $upperBoundKeys
 : else
 :   fn:true()
 : </pre>
 : 
 : <p>where keyExpr is the expression specified in the keyspec of the index,
 : lop is either the &lt;= or the &lt; operator depending on whether 
 : $lowerBoundsIncluded is true or false, and uop is either the &lt;= or the 
 : &lt; operator depending on whether $upperBoundsIncluded is true or false</p>.
 :
 : @param $name The QName of the index to probe.
 : @param $lowerBound The lower bound search sequence.
 : @param $upperBound The upper bound search sequence.
 : @param $haveLowerBound Whether a lower bound search sequence exists or not.
 : @param $haveUpperBound Whether an upper bound search sequence exists or not.
 : @param $lowerBoundIncluded Whether to use the &lt;= or the &lt; operator when
 :        comparing a search key from $lowerBound with an index key.
 : @param $upperBoundIncluded Whether to use the &lt;= or the &lt; operator when
 :        comparing an index key with a search key from $upperBound.
 : @return The set of domain nodes that satisfy the search condition
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 : @error zerr:ZDDY0030 if the index is not a general range index.
 : @error err:XPTY0004  if $haveLowerBound is true and $lowerBoundKeys constains
 : an atomic item whose type does not match the sequence type specified by the 
 : index keyspec, or $haveUpperBound is true and $upperBoundKeys contains an 
 : atomic item whose type does not match the sequence type specified by the 
 : index keyspec.
 :)
declare function idml:probe-index-range-general(
  $name               as xs:QName, 
  $lowerBound         as xs:anyAtomicType*,
  $upperBound         as xs:anyAtomicType*,
  $haveLowerBound     as xs:boolean,
  $haveUpperBound     as xs:boolean,
  $lowerBoundIncluded as xs:boolean,
  $upperBoundIncluded as xs:boolean) as node()*  external;


(:~
 : The refresh-index function is an updating function which updates
 : the index with the given name.
 : Note that if the maintenance property of the index is automatic,
 : this function is a NOP.
 :
 : @param $name The QName of the index to refresh.
 : @return The result of the function is an empty XDM instance and a
 :         pending update list which, when applied, refreshes the contents
 :         of the index.that consists of a
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 :)
declare updating function idml:refresh-index($name as xs:QName) external;

(:~
 : The keys function returns a sequence of all keys contained in the
 : index with the given name. Each element has the following structure:
 :   <pre class="brush: xml;">
 :   &lt;key xmlns="http://www.zorba-xquery.com/modules/store/static/indexes/dml"&gt;
 :     &lt;attribute value="key1_value"/&gt;
 :     &lt;attribute value="key2_value"/&gt;
 :     &lt;attribute value="key3_value"/&gt;
 :   &lt;/key&gt;
 :   </pre>
 :
 : @param $name The QName of the index
 : @return The result of the function is sequence of elements each representing
 :         one key contained in the index.
 : 
 : Note that the order of the attribute elements reflects the order of
 : the keys in the index specification. Also note that the values in
 : these attributes have the type that is declared in the corresponding
 : index specification. 
 :
 : @error zerr:ZDDY0021 if the index with name $name is not declared.
 : @error zerr:ZDDY0023 if the index with name $name does not exist.
 :)
declare function idml:keys($name as xs:QName) as node()* external;
