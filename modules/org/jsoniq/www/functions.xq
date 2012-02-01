module namespace j = "http://www.jsoniq.org/functions";

declare namespace jdm = "http://www.jsoniq.org/";

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

(:~
 : Returns the jdm:null value null.
 :
 : @return the said value
 :)
declare function j:null() as jdm:null external;

(:~
 :
 : @param $p
 :
 : @return
 :
 : @error j:JUDY0060 if pair with the given name already exists
 :)
declare updating function j:insert-into(
  $o as object(),
  $p as pair()*) external;

(:~
 :
 : @param $p
 : @return
 :)
declare updating function j:insert-as-first(
  $a as array(),
  $i as item()*) external;

(:~
 :
 : @param $p
 : @return
 : @error j:JUDY0061 if the position doesn't select an existing array member
 :)
declare updating function j:insert-after(
  $a as array(),
  $pos as xs:integer,
  $i as item()*) external;

(:~
 :
 : @param $p
 : @return
 : @error j:JUDY0061 if the position doesn't select an existing array member
 :)
declare updating function j:insert-before(
  $a as array(),
  $pos as xs:integer,
  $i as item()*) external;

(:~
 :
 : @param $p
 : @return
 :)
declare updating function j:insert-as-last(
  $a as array(),
  $i as item()*) external;

(:~
 :
 : @param $p
 : @return
 :
 : @error j:JUDY0061 if the selector doesn't select an existing pair or
 :   array member
 : @error j:JUDY0062 if the first argument is a pair
 : @error j:JUDY0063 invalid type for second argument (must be xs:integer
 :   if first argument is an array or xs:string if first argument is an object)
 :)
declare updating function j:delete(
  $i as json-item(),
  $selector as xs:anyAtomicType) external;

(:~
 :
 : @param $p
 : @return
 :)
declare updating function j:rename(
  $p as pair(),
  $name as xs:string) external;

(:~
 :
 : @param $p
 : @return
 :)
declare updating function j:replace-value(
  $p as pair(),
  $i as item()) external;

(:~
 :
 : @param $p
 : @return
 :)
declare updating function j:replace-value(
  $a as array(),
  $pos as xs:integer,
  $i as item()) external;
