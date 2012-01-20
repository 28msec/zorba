module namespace j = "http://www.jsoniq.org/functions";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

(:~
 :
 : @param $a
 : @return
 :)
declare function j:flatten($a as array()) as item()* external;

(:~
 :
 : @param $j
 : @return
 :)
declare function j:parse-json($j as xs:string) as json-item()? external;

(:~
 :
 : @param $o
 : @return
 :)
declare function j:names($o as object()) as xs:string* external;

(:~
 :
 : @param $p
 : @return
 :)
declare function j:name($p as pair()) as xs:string external;

(:~
 :
 : @param $o
 : @return
 :)
declare function j:pairs($o as object()) as pair()* external;

(:~
 :
 : @param $o
 : @param $n
 : @return
 :)
declare function j:pair($o as object(), $n as xs:string) as pair()? external;

(:~
 :
 : @param $o
 : @param $n
 : @return
 :)
declare function j:member($o as array(), $p as xs:integer) as item()? external;

(:~
 :
 : @param $j
 : @return
 :)
declare function j:size($j as json-item()) as item()* external;

(:~
 :
 : @param $j
 : @return
 :)
declare function j:values($j as json-item()) as item()* external;

(:~
 :
 : @param $p
 : @return
 :)
declare function j:value($p as pair()) as item() external;
