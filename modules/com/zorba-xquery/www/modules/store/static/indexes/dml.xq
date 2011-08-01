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
 : This module defines a set of functions to probe and refresh indexes.
 :
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/dml
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann,
 :   Markos Zaharioudakis
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
 : is variadic and accepts a variable number of key arguments.
 : 
 : The first argument is the QName identifying the index to probe. The remaining 
 : arguments specify the search condition, which is given as a number of 
 : (optional) atomic items comprising a key tuple. The number of key tuples
 : given must be equal to the number of keys declared for the index.
 :
 : @param $name The QName of the index to probe
 : @param $key_i any number of key used to probe the index (i.e. the search condition).
 :
 : @return If the index contains an entry with the given key tuple,
 :   the associated domain nodes are
 : returned. Otherwise, the empty sequence is returned.
 :
 : @error zerr::ZDDY0021 if the index with name $name is not declared.
 : @error zerr::ZDDY0023 if the index with name $name does not exist.
 : @error zerr::ZDDY0025 if the number of keys passed as arguments
 :    does not match the number of keys declared for the index.
 :)
declare %ann:variadic function dml:probe-index-point-value(
  $name as xs:QName, 
  $key_i as xs:anyAtomicType?) as node()*  external; 


(:~
 : The probe function retrieves the domain nodes associated with a particular
 : search condition, which is presented as a range of key tuples.
 : This function accept a variable number of arguments.
 :
 : To describe the semantics of this function, we start by defining the i-th 
 : key column of an index as the set of key items produced by evaluating the 
 : i-th keyspec of the index for every domain node. Then, the search condition 
 : of a range probe can be defined as a number of rangespecs, where a 
 : rangespec describes a constraint on the values of a key column. The first 
 : rangespec applies to the first key column, the second rangespec to the 
 : second key column, etc. The number of rangespecs must be less or equal to 
 : the number of keyspecs found in the declaration of the given index. 
 : Each rangespec consists of six values (i.e. rangeLowerBound_i,
 : rangeUpperBound_i, rangeHaveLowerBound_i, rangeHaveUpperBound_i,
 : rangeLowerBoundIncluded_i, rangeUpperBoundIncluded_i). Because the
 : function is declared as variadic, several rangespecs can be passed
 : as arguments to the function.
 :
 : @param $name The QName of the index to probe
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
 : @return The sequence of domain nodes matching this range probe.
 :
 : @error zerr::ZDDY0021 if the index with name $name is not declared.
 : @error zerr::ZDDY0023 if the index with name $name does not exist.
 : @error zerr::ZDDY0025 if the number of rangespecs passed as arguments
 :    does not match the number of keys declared for the index.
 :)
declare %ann:variadic function dml:probe-index-range-value($name as xs:QName, 
  $rangeLowerBound1         as xs:anyAtomicType?,
  $rangeUpperBound1         as xs:anyAtomicType?,
  $rangeHaveLowerBound1     as xs:boolean,
  $rangeHaveupperBound1     as xs:boolean,
  $rangeLowerBoundIncluded1 as xs:boolean,
  $rangeupperBoundIncluded1 as xs:boolean) as node()*  external;

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
 : @error zerr::ZDDY0021 if the index with name $name is not declared.
 : @error zerr::ZDDY0023 if the index with name $name does not exist.
 :)
declare updating function dml:refresh-index($name as xs:QName) external;

