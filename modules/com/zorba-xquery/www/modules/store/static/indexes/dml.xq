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
 : This module defines a set of functions to probe indexes.
 :
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/dml
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project store/indexes/static
 :
 :)
module namespace dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : The probe function retrieves the domain nodes associated with a particular
 : search condition, which is presented as a single key tuple. This function 
 : accept a variable number of arguments.
 : 
 :   dml:probe-index-point($indexUri as xs:QName,
 :                        $key1     as xs:anyAtomictType,
 :                        ...,
 :                        $keyM     as xs:anyAtomicType) as node()*
 :
 : The first argument is always a QName identifying an index. The rest of the 
 : arguments specify the search condition, which is given as a number of 
 : atomic items comprising a key tuple. This number must be equal to the number
 : of indexspecs found in the index declaration [err:XDDY0025]. If the index 
 : contains an entry with the given key tuple, the associated domain nodes are
 : returned. Otherwise, the empty sequence is returned.
 :
 : @param $name The QName of the index.
 : @param $key1 The search condition.
 : @return The sequence of domain nodes or an empty sequence.
 : @error If available indexes does not provide a mapping for
 :        the expanded QName $name.
 :)
declare %ann:variadic function dml:probe-index-point-value(
  $name as xs:QName, 
  $key1 as xs:anyAtomicType*) as node()*  external; 

(:~
 : The probe function retrieves the domain nodes associated with a particular
 : search condition, which is presented as a range of key tuples. This function 
 : accept a variable number of arguments.
 :
 : dml:probe-index-range($indexUri                 as xs:QName,
 :                         $rangeLowerBound1         as xs:anyAtomicType?,
 :                         $rangeUpperBound1         as xs:anyAtomicType?,
 :                         $rangeHaveLowerBound1     as xs:boolean,
 :                         $rangeHaveupperBound1     as xs:boolean,
 :                         $rangeLowerBoundIncluded1 as xs:boolean,
 :                         $rangeupperBoundIncluded1 as xs:boolean,
 :                         ....,
 :                         $rangeLowerBoundM         as xs:anyAtomicType?,
 :                         $rangeUpperBoundM         as xs:anyAtomicType?,
 :                         $rangeHaveLowerBoundM     as xs:boolean,
 :                         $rangeHaveupperBoundM     as xs:boolean,
 :                         $rangeLowerBoundIncludedM as xs:boolean,
 :                         $rangeupperBoundIncludedM as xs:boolean) as node()*
 :
 : To describe the semantics of this function, we start by defining the i-th 
 : key column of an index as the set of key items produced by evaluating the 
 : i-th keyspec of the index for every domain node. Then, the search condition 
 : of a range probe can be defined as a number of rangespecs, where a 
 : rangespec describes a constraint on the values of a key column. The first 
 : rangespec applies to the first key column, the second rangespec to the 
 : second key column, etc. The number of rangespecs must be less or equal to 
 : the number of keyspecs found in the declaration of the given index. 
 : Each rangespec consists of 6 values:
 :
 :   * rangeLowerBound : The lower bound in a range of key values.
 :   * rangeUpperBound : The upper bound in a range of key values.
 :   * rangeHaveLowerBound : If false, then there is no lower bound, or 
 :     equivalently, the lower bound is -INFINITY (the actual rangeLowerBound 
 :     value is ignored). Otherwise, the lower bound is the one given by the 
 :     rangeLowerBound value. The effective lower bound of the range is either 
 :     the rangeLowerBound if rangeHaveLowerBound is true, or -INFINITY if 
 :     rangeHaveLowerBound is false.
 :   * rangeHaveUpperBound : If false, then there is no upper bound, or 
 :     equivalently, the upper bound is +INFINITY (the actual rangeUpperBound 
 :     value is ignored). Otherwise, the upper bound is the one given by the 
 :     rangeUpperBound value. The effective upper bound of the range is either
 :     the rangeUpperBound if rangeHaveUpperBound is true, or +INFINITY if 
 :     rangeHaveUpperBound is false.
 :   * rangeLowerBoundIncluded : If false, then the range is open from below,
 :     i.e., the rangeLowerBound value is not considered part of the range. 
 :     Otherwise, the range is closed from below, i.e., the rangeLowerBound 
 :     value is part of the range.
 :   * rangeUpperBoundIncluded : If false, then the range is open from above,
 :     i.e., the rangeUpperBound value is not considered part of the range. 
 :     Otherwise, the range is closed from above, i.e., the rangeUpperBound 
 :     value is part of the range.
 :
 : @param $name The QName of the index.
 : @param $rangeLowerBound1 The lower bound in a range of key values.
 : @param $rangeUpperBound1 The upper bound in a range of key values.
 : @param $rangeHaveLowerBound If false, then there is no lower bound, or 
 :          equivalently, the lower bound is -INFINITY. Otherwise, the lower 
 :          bound is the one given by the rangeLowerBound value. 
 : @param $rangeHaveUpperBound If false, then there is no upper bound, or 
 :          equivalently, the upper bound is +INFINITY. Otherwise, the upper 
 :          bound is the one given by the rangeUpperBound value. 
 : @param $rangeLowerBoundIncluded If false, then the range is open from below, 
 :          i.e., the rangeLowerBound value is not considered part of the 
 :          range. Otherwise, the range is closed from below, i.e., the 
 :          rangeLowerBound value is part of the range. 
 : @param $rangeUpperBoundIncluded If false, then the range is open from above, 
 :          i.e., the rangeUpperBound value is not considered part of the 
 :          range. Otherwise, the range is closed from above, i.e., the 
 :          rangeUpperBound value is part of the range.  
 : @return The sequence of domain nodes.
 : @error If available indexes does not provide a mapping for
 :        the expanded QName $name.
 :)
declare %ann:variadic function dml:probe-index-range-value($name as xs:QName, 
  $rangeLowerBound1         as xs:anyAtomicType?,
  $rangeUpperBound1         as xs:anyAtomicType?,
  $rangeHaveLowerBound1     as xs:boolean,
  $rangeHaveupperBound1     as xs:boolean,
  $rangeLowerBoundIncluded1 as xs:boolean,
  $rangeupperBoundIncluded1 as xs:boolean) as node()*  external;
