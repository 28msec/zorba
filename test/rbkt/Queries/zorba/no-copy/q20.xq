declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

let $auction := doc($input-context) 
return
 <result>
 <preferred>
 { count($auction/site/people/person/profile[@income >= 100000]) }
 </preferred>
 <standard>
 {
  count(
      $auction/site/people/person/
      profile[@income < 100000 and @income >= 30000]
      )
 }
 </standard>
 <challenge>
 { count($auction/site/people/person/profile[@income < 30000]) }
 </challenge>
 <na>
 {
  count(
      for $p in $auction/site/people/person
      where empty($p/profile/@income)
      return $p
      )
 }
 </na>
 </result>

