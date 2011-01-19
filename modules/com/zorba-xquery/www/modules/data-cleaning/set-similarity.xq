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
 : This library module provides simple set similarity operations.
 : The logic contained in this module is not specific to any particular XQuery implementation.
 :
 : @author Bruno Martins
 :)

module namespace set = "http://www.zorba-xquery.com/modules/data-cleaning/set-similarity";

(:~
 : Return the union between two sets, using deep-equal() to remove the duplicates.
 :
 : <br/>
 : Example usage : <pre> set:dup-union ( ( "a", "b", "c") , ( "a", "a", "d") ) </pre>
 : <br/>
 : Returns : <pre> ("a", "b", "c", "d") </pre>
 :
 : @param $s1 The first set.
 : @param $s2 The second set.
 : @return The union of both sets.
 :)
declare function set:dup-union ( $s1 , $s2 ) {
 let $s := ( $s1 , $s2 )
 for $a at $apos in $s
 where every $ba in subsequence($s, 1, $apos - 1) satisfies not(deep-equal($ba,$a))
 return $a
};

(:~
 : Return the intersection between two sets, using deep-equal() to detect the equal set elements.
 :
 : <br/>
 : Example usage : <pre> set:dup-intersect ( ( "a", "b", "c") , ( "a", "a", "d") ) </pre>
 : <br/>
 : Returns : <pre> ("a") </pre>
 :
 : @param $s1 The first set.
 : @param $s2 The second set.
 : @return The intersection of both sets.
 :)
declare function set:dup-intersect ( $s1 , $s2 ) {
 for $a at $apos in $s1
 let $t1 := every $ba in subsequence($s1, 1, $apos - 1) satisfies not(deep-equal($ba,$a))
 let $t2 := some $bb in $s2 satisfies deep-equal($bb,$a)
 where $t1 and $t2
 return $a
};

(:~
 : Remove exact duplicates from a set, using deep-equal() to detect the duplicates.
 :
 : <br/>
 : Example usage : <pre> set:distinct ( ( "a", "a", "b") ) </pre>
 : <br/>
 : Returns : <pre> ("a", "b") </pre>
 :
 : @param $s A set.
 : @return The set without the duplicates.
 :)
declare function set:distinct ( $s ) {
 for $a at $apos in $s
 where every $ba in subsequence($s, 1, $apos - 1) satisfies not(deep-equal($ba,$a))
 return $a
};

(:~
 : Dice similarity coefficient between two sets.
 :
 : <br/>
 : Example usage : <pre> set:dice ( ( "a", "b", "c") , ( "a", "a", "d") ) </pre>
 : <br/>
 : Returns : <pre> 0.4 </pre>
 :
 : @param $s1 The first set.
 : @param $s2 The second set.
 : @return Dice similarity coefficient between the two sets.
 :)
declare function set:dice ( $s1 , $s2 ) as xs:double {
  2 * count( set:dup-intersect($s1,$s2) ) div ( count(set:distinct($s1)) + count(set:distinct($s2)) )
};

(:~
 : Jaccard similarity coefficient between two sets.
 :
 : <br/>
 : Example usage : <pre> set:jaccard ( ( "a", "b", "c") , ( "a", "a", "d") ) </pre>
 : <br/>
 : Returns : <pre> 0.25 </pre>
 :
 : @param $s1 The first set.
 : @param $s2 The second set.
 : @return Jaccard similarity coefficient between the two sets.
 :)
declare function set:jaccard ( $s1 , $s2  ) as xs:double {
 count( set:dup-intersect($s1,$s2) ) div count( set:dup-union($s1,$s2) )
};