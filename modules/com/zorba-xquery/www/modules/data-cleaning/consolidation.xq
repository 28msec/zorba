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
 : This library module provides simple consolidation operations.
 : The logic contained in this module is not specific to any particular XQuery implementation.
 :
 : @author Bruno Martins
 :)

module namespace con = "http://www.zorba-xquery.com/modules/data-cleaning/consolidation";

import module namespace set  = "http://www.zorba-xquery.com/modules/data-cleaning/set-similarity";

import module namespace sim  = "http://www.zorba-xquery.com/modules/data-cleaning/string-similarity";

(:~
 : Return the single the most frequent node in a sequence of nodes provided as input.
 :
 : <br/>
 : Example usage : <pre> con:mostfrequent( ( "a", "a", "b") ) </pre>
 : <br/>
 : Returns : <pre> ("a") </pre>
 :
 : @param $s A sequence of nodes.
 : @return The most frequent node in the input sequence.
 :)
declare function con:mostfrequent ( $s ) {
 (for $str in set:distinct($s) order by count($s[deep-equal(.,$str)]) descending return $str)[1]
};

(:~
 : Return the single the less frequent node in a sequence of nodes provided as input.
 :
 : <br/>
 : Example usage : <pre> con:leastfrequent( ( "a", "a", "b") ) </pre>
 : <br/>
 : Returns : <pre> ("b") </pre>
 :
 : @param $s A sequence of nodes.
 : @return The less frequent node in the input sequence.
 :)
declare function con:leastfrequent ( $s ) {
 let $aux := for $str in set:distinct($s) order by count($s[deep-equal(.,$str)]) return $str
 return if (count($aux) = 0) then () else ($aux[1])
};

(:~
 : Return the single longest string, in terms of the number of characters, in a sequence of strings provided as input.
 :
 : <br/>
 : Example usage : <pre> con:longest( ( "a", "aa", "aaa") ) </pre>
 : <br/>
 : Returns : <pre> ("aaa") </pre>
 :
 : @param $s A sequence of strings.
 : @return The longest string in the input sequence.
 :)
declare function con:longest ( $s as xs:string* ) as xs:string? {
 let $aux := for $str in $s order by string-length($str) descending return $str
 return if (count($aux) = 0) then () else ($aux[1])
};

(:~
 : Return the single shortest string, in terms of the number of characters, in a sequence of strings provided as input.
 :
 : <br/>
 : Example usage : <pre> con:shortest( ( "a", "aa", "aaa") ) </pre>
 : <br/>
 : Returns : <pre> ("a") </pre>
 :
 : @param $s A sequence of strings.
 : @return The shortest string in the input sequence.
 :)
declare function con:shortest( $s as xs:string* ) as xs:string? {
 let $aux := for $str in $s order by string-length($str) return $str
 return if (count($aux) = 0) then () else ($aux[1])
};

(:~
 : Return the single longest string, in terms of the number of tokens, in a sequence of strings provided as input.
 :
 : <br/>
 : Example usage : <pre> con:moretokens( ( "a b c", "a b", "a"), " +" ) </pre>
 : <br/>
 : Returns : <pre> ("a b c") </pre>
 :
 : @param $s A sequence of strings.
 : @param $r A regular expression forming the delimiter character(s) which mark the boundaries between adjacent tokens.
 : @return The longest string in the input sequence, in terms of the number of tokens.
 :)
declare function con:moretokens ( $s as xs:string*, $r as xs:string ) as xs:string? {
 let $aux := for $str in $s order by count(tokenize($str,$r)) descending return $str
 return if (count($aux) = 0) then () else ($aux[1])
};

(:~
 : Return the single shortest string, in terms of the number of tokens, in a sequence of strings provided as input.
 :
 : <br/>
 : Example usage : <pre> con:lesstokens( ( "a b c", "a b", "a"), " +" ) </pre>
 : <br/>
 : Returns : <pre> ("a") </pre>
 :
 : @param $s A sequence of strings.
 : @param $r A regular expression forming the delimiter character(s) which mark the boundaries between adjacent tokens.
 : @return The shortest string in the input sequence, in terms of the number of tokens.
 :)
declare function con:lesstokens ( $s as xs:string*, $r as xs:string ) as xs:string? {
 let $aux := for $str in $s order by count(tokenize($str,$r)) return $str
 return if (count($aux) = 0) then () else ($aux[1])
};

(:~
 : Return the strings from an input sequence of strings that match a particular regular expression.
 :
 : <br/>
 : Example usage : <pre> con:matching( ( "a A b", "c AAA d", "e BB f"), "A+" ) </pre>
 : <br/>
 : Returns : <pre> ( "a A b", "c AAA d") </pre>
 :
 : @param $s A sequence of strings.
 : @param $r The regular expression to be used in the matching.
 : @return The strings in the input sequence that match the input regular expression.
 :)
declare function con:matching ( $s as xs:string*, $r as xs:string ) as xs:string* {
 for $str in $s where matches($str,$r) return $str
};

(:~
 : Return the single string, from an input sequence of strings, that appears more frequently as part
 : of the other strings in the sequence. If no such string exists, then this function returns an empty sequence.
 :
 : <br/>
 : Example usage : <pre> con:superstring( ( "aaa bbb ccc", "aaa bbb", "aaa ddd", "eee fff" ) ) </pre>
 : <br/>
 : Returns : <pre> ( "aaa bbb" ) </pre>
 :
 : @param $s A sequence of strings.
 : @return The string that appears more frequently as part of the other strings in the sequence.
 :)
declare function con:superstring ( $s as xs:string* ) as xs:string? {
  let $aux :=
  for $str in $s 
  let $cnt := count ( for $str2 in $s return if(contains($str2,$str)) then $str else () )
  where $cnt > 1
  order by $cnt descending
  return $str
  return if (count($aux) = 0) then () else ($aux[1])
};

(:~
 : Return the single more similar string, in terms of the edit distance towards an input string, 
 : in a sequence of strings provided as input.
 :
 : <br/>
 : Example usage : <pre> con:moresimilar-editdistance( ( "aaabbbccc", "aaabbb", "eeefff" ), "aaab" ) </pre>
 : <br/>
 : Returns : <pre> ( "aaabbb" ) </pre>
 :
 : @param $s A sequence of strings.
 : @param $m The string towards which we want to measure the edit distance.
 : @return The more similar string in the input sequence.
 :)
declare function con:moresimilar-editdistance ( $s as xs:string*, $m as xs:string ) as xs:string? {
 let $aux := for $str in $s order by sim:editdistance($str,$m) return $str
 return if (count($aux) = 0) then () else ($aux[1])
};

(:~
 : Return the single less similar string, in terms of the edit distance towards an input string, 
 : in a sequence of strings provided as input.
 :
 : <br/>
 : Example usage : <pre> con:lesssimilar-editdistance( ( "aaabbbccc", "aaabbb", "eeefff" ), "aaab" ) </pre>
 : <br/>
 : Returns : <pre> ( "eeefff" ) </pre>
 :
 : @param $s A sequence of strings.
 : @param $m The string towards which we want to measure the edit distance.
 : @return The less similar string in the input sequence.
 :)
declare function con:lesssimilar-editdistance ( $s as xs:string*, $m as xs:string ) as xs:string? {
 let $aux := for $str in $s order by sim:editdistance($str,$m) descending return $str
 return if (count($aux) = 0) then () else ($aux[1])
};