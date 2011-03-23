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
 : This library module provides simple string similarity operations.
 : The logic contained in this module is not specific to any particular XQuery implementation, 
 : although it requires the trigonometic functions of XQuery 1.1 or a math extension function for computing sqrt().
 :
 : @author Bruno Martins
 :)

module namespace sim = "http://www.zorba-xquery.com/modules/data-cleaning/string-similarity";

import module namespace set  = "http://www.zorba-xquery.com/modules/data-cleaning/set-similarity";

(:~
 : Edit distance between two strings.
 :
 : <br/>
 : Example usage : <pre> sim:editdistance("FLWOR", "FLOWER") </pre>
 : <br/>
 : Returns : <pre> 2 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @return Edit distance between the two strings.
 :)
declare function sim:editdistance ( $s1 as xs:string, $s2 as xs:string ) as xs:integer {
 if(string-length($s1) = 0) then string-length($s2) else
 if(string-length($s2) = 0) then string-length($s1) else
 min((
  sim:editdistance(substring($s1, 2), $s2) + 1 ,
  sim:editdistance($s1, substring($s2, 2)) + 1 ,
  sim:editdistance(substring($s1, 2), substring($s2, 2)) + ( if(substring($s1, 1, 1) = substring($s2, 1, 1)) then 0 else 1 )
 ))
};

(:~
 : Jaro similarity coefficient between two strings.
 :
 : <br/>
 : Example usage : <pre> sim:jaro("FLWOR Found.", "FLWOR Foundation") </pre>
 : <br/>
 : Returns : <pre> 0.5853174603174603 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @return Jaro similarity coefficient between the two strings.
 :)
declare function sim:jaro ( $s1 as xs:string, $s2 as xs:string ) as xs:double {
 let $s    := for $i in ($s1,$s2) order by string-length($i) return $i
 let $l1   := string-length($s[1])
 let $l2   := string-length($s[2])
 let $mt   := xs:integer((max(($l1,$l2)) div 2.0) - 1)
 let $mc   := for $i in 1 to min( ($l1 , $l2) ) 
              let $auxmatch := substring($s[2], max((1,$i - $mt)), $mt *2 )
              return for $j in 1 to string-length($auxmatch)  
                     where substring($auxmatch, $j, 1) = substring($s[1], $i, 1)
                     return <match char="{substring($s[1], $i, 1)}" pos1="{$i}" pos2="{$j + max((1,$i - $mt)) - 1}" />
 let $m    := count($mc)
 let $t    := count( for $i in $mc, $j in $mc where $i/@pos1>$j/@pos1 and $i/@pos2<$j/@pos2 return $i )
 let $dist := xs:double((($m div $l1) + ($m div $l2) + (($m - $t) div $m)) div 3)
 return $dist
};

(:~
 : Jaro-Winkler similarity coefficient between two strings.
 :
 : <br/>
 : Example usage : <pre> sim:jarowinkler("DWAYNE", "DUANE", 4, 0.1 ) </pre>
 : <br/>
 : Returns : <pre> 0.8577777777777778 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @param $prefix The number of characters to consider when testing for equal prefixes.
 : @param $fact The weighting factor to consider when the input strings have equal prefixes.
 : @return Jaro-Winkler similarity coefficient between the two strings.
 :)
declare function sim:jarowinkler ( $s1 as xs:string, $s2 as xs:string, $prefix as xs:integer, $fact as xs:double ) as xs:double {
 let $jaro := sim:jaro( $s1 , $s2 )
 let $cc   := for $i in 1 to min(($prefix, string-length($s1), string-length($s2))) 
              where substring($s1, 0, $i) = substring($s2, 0, $i) return $i
 return ($jaro + ( $fact * max($cc) * ( 1 - $jaro ) ) )
};

(:~
 : Dice similarity coefficient between sets of character n-grams extracted from two strings.
 :
 : <br/>
 : Example usage : <pre> sim:dice-ngrams("DWAYNE", "DUANE", 2 ) </pre>
 : <br/>
 : Returns : <pre> 0.4615384615384616 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @param $n The number of characters to consider when extracting n-grams.
 : @return Dice similarity coefficient between the sets of character n-grams extracted from the two strings.
 :)
declare function sim:dice-ngrams ( $s1 as xs:string, $s2 as xs:string, $n as xs:integer ) as xs:double {
 set:dice(sim:ngrams($s1,$n),sim:ngrams($s2,$n))
};

(:~
 : Jaccard similarity coefficient between sets of character n-grams extracted from two strings.
 :
 : <br/>
 : Example usage : <pre> sim:jaccard-ngrams("DWAYNE", "DUANE", 2 ) </pre>
 : <br/>
 : Returns : <pre> 0.3 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @param $n The number of characters to consider when extracting n-grams.
 : @return Jaccard similarity coefficient between the sets of character n-grams extracted from the two strings.
 :)
declare function sim:jaccard-ngrams ( $s1 as xs:string, $s2 as xs:string, $n as xs:integer ) as xs:double {
 set:jaccard(sim:ngrams($s1,$n),sim:ngrams($s2,$n))
};

(:~
 : Dice similarity coefficient between sets of tokens extracted from two strings.
 :
 : <br/>
 : Example usage : <pre> sim:dice-tokens("The FLWOR Foundation", "FLWOR Found.", " +" ) </pre>
 : <br/>
 : Returns : <pre> 0.4 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @param $r A regular expression forming the delimiter character(s) which mark the boundaries between adjacent tokens.
 : @return Dice similarity coefficient between the sets tokens extracted from the two strings.
 :)
declare function sim:dice-tokens ( $s1 as xs:string, $s2 as xs:string, $r as xs:string ) as xs:double {
 set:dice( tokenize($s1,$r) , tokenize($s2,$r) )
};

(:~
 : Jaccard similarity coefficient between sets of tokens extracted from two strings.
 :
 : <br/>
 : Example usage : <pre> sim:jaccard-tokens("The FLWOR Foundation", "FLWOR Found.", " +" ) </pre>
 : <br/>
 : Returns : <pre> 0.25 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @param $r A regular expression forming the delimiter character(s) which mark the boundaries between adjacent tokens.
 : @return Jaccard similarity coefficient between the sets tokens extracted from the two strings.
 :)
declare function sim:jaccard-tokens ( $s1 as xs:string, $s2 as xs:string, $r as xs:string ) as xs:double {
 set:jaccard( tokenize($s1,$r) , tokenize($s2,$r) )
};

(:~
 : Cosine similarity coefficient between sets of tokens extracted from two strings. The tokens from each string
 : are weighted according to their occurence frequency (i.e., the term-frequency heuristic from Information Retrieval).
 :
 : <br/>
 : Example usage : <pre> sim:cosine-tokens("The FLWOR Foundation", "FLWOR Found.", " +" ) </pre>
 : <br/>
 : Returns : <pre> 0.408248290463863 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @param $r A regular expression forming the delimiter character(s) which mark the boundaries between adjacent tokens.
 : @return Cosine similarity coefficient between the sets tokens extracted from the two strings.
 :)
declare function sim:cosine-tokens ( $s1 as xs:string, $s2 as xs:string, $r as xs:string ) as xs:double {
 let $tokens1   := tokenize($s1,$r) 
 let $tokens2   := tokenize($s2,$r)
 let $vocab     := distinct-values( ($tokens1, $tokens2) )
 let $freq1     := for $a1 in $vocab return count($tokens1[.=$a1])
 let $freq2     := for $a2 in $vocab return count($tokens2[.=$a2])
 let $freq1pow  := for $aa1 in $freq1 return $aa1 * $aa1
 let $freq2pow  := for $aa2 in $freq2 return $aa2 * $aa2 
 let $mult      := for $freq at $pos in $freq1 return $freq * $freq2[$pos] 
 return sum($mult) div (math:sqrt(sum($freq1pow)) * math:sqrt(sum($freq2pow)))
};

(:~
 : Cosine similarity coefficient between sets of character n-grams extracted extracted from two strings. The n-grams from each string
 : are weighted according to their occurence frequency (i.e., the term-frequency heuristic from Information Retrieval).
 :
 : <br/>
 : Example usage : <pre> sim:cosine-ngrams("DWAYNE", "DUANE", 2 ) </pre>
 : <br/>
 : Returns : <pre> 0.2401922307076307 </pre>
 :
 : @param $s1 The first string.
 : @param $s2 The second string.
 : @param $n The number of characters to consider when extracting n-grams.
 : @return Cosine similarity coefficient between the sets tokens extracted from the two strings.
 :)
declare function sim:cosine-ngrams ( $s1 as xs:string, $s2 as xs:string, $n as xs:integer ) as xs:double {
 let $ngrams1   := sim:ngrams($s1,$n) 
 let $ngrams2   := sim:ngrams($s2,$n)
 let $vocab     := distinct-values( ($ngrams1, $ngrams2) )
 let $freq1     := for $v1 in $vocab return count($ngrams1[.=$v1])
 let $freq2     := for $v2 in $vocab return count($ngrams2[.=$v2])
 let $freq1pow  := for $f1 in $freq1 return $f1 * $f1
 let $freq2pow  := for $f2 in $freq2 return $f2 * $f2 
 let $mult      := for $freq at $pos in $freq1 return $freq * $freq2[$pos] 
 return sum($mult) div (math:sqrt(sum($freq1pow)) * math:sqrt(sum($freq2pow)))
};

(:~
 : Returns the character n-grams from a string
 :
 : <br/>
 : Example usage : <pre> sim:ngrams("FLWOR", 2 ) </pre>
 : <br/>
 : Returns : <pre> ("_F" , "FL" , "LW" , "WO" , "LW" , "WO" , "OR" , "R_") </pre>
 :
 : @param $s The input string.
 : @param $n The number of characters to consider when extracting n-grams.
 : @return A sequence of strings with the extracted n-grams.
 :)
declare function sim:ngrams ( $s as xs:string, $n as xs:integer ) as xs:string* {
 let $pad := '_'
 return
 ( for $a in 1 to $n 
   let $apad := string-join( for $aux in $a + 1 to $n return $pad , '' ) 
   return concat( $apad , substring($s,1,$a) ) ,

   for $b in $n + 2 to string-length($s) return substring($s,$b - $n, $n),

   for $c in string-length($s) - (if ($n = 1) then (-1) else ($n)) - 1 to string-length($s) 
   let $cpad := string-join( for $aux in string-length($s) - $c + 2 to $n return $pad , '' ) 
   return concat(substring($s, $c, $n), $cpad )
 )
};