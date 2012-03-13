(:~
 : This module provides the functions defined by the JSONiq specification,
 : sections 1.7 (Functions) and 1.10 (Update Primitives). JSONiq extends
 : the XQuery specification to also deal with JSON data natively. See
 :
 :     http://www.jsoniq.org/
 :
 : for details.
 :
 : This module depends on having the JSONiq feature enabled in Zorba,
 : ie, Zorba must be compiled with ZORBA_WITH_JSON.
 :)
module namespace jn = "http://www.jsoniq.org/functions";

import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

declare namespace jdm = "http://www.jsoniq.org/";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";


(:~
 : This function has the same semantics as fn:parse-xml(), except that
 : it parses the string as JSON (not XML), and returns an Object or
 : Array rather than an XML document.
 :
 : @param $j A string containing a valid JSON text.
 : @return a JSON Object or Array item.
 :)
declare function jn:parse-json($j as xs:string) as json-item()? external;


(:~
 : Returns the names used in the Pairs of the object. This function is
 : equivalent to
 :
 :    for $p in jn:pairs($arg) return jn:name($p)
 :
 : The names will be returned in an implementation-defined order
 :
 : @param $o A JSON Object.
 : @return The names of pairs in the object.
 :)
declare function jn:names($o as object()) as xs:string* external;


(:~
 : Returns the value of a JSON Pair with a given name within a given JSON object.
 : If no such pair exists in the object, returns the empty sequence.
 :
 : @param $o A JSON Object.
 : @param $name The name of the pair whose value is to be retrieved
 : @return the value of specified pair within the given object, or the empty sequence.
 :)
declare function jn:value($o as object(), $name as xs:string) as item()? external;


(:~
 : Returns the size of a JSON Object or JSON Array. The size of an Object
 : is the number of Pairs contained within it; the size of an Array is
 : the number of members contained within it.
 :
 : @param $j A JSON Object or JSON Array.
 : @return The number of items in $j.
 : @error jn:JUDY0060 if $j is a JSON Pair.
 :)
declare function jn:size($j as json-item()) as xs:integer external;


(:~
 : Returns the member of an Array at the specified position (starting from 1).
 : If the position is out of bounds of the array, returns the empty sequence.
 :
 : @param $a A JSON Array.
 : @param $p The position in the array.
 : @return The member at the specified position, or empty sequence.
 :)
declare function jn:member($o as array(), $p as xs:integer) as item()? external;


(:~
 : Returns the members of an Array.
 :
 : @param $a A JSON Array.
 : @return The members of the specified array.
 :)
declare function jn:members($o as array()) as item()* external;


(:~
 : Recursively "flatten" a JSON Array, by replacing any arrays with their
 : members. Equivalent to
 :
 :   define function jn:flatten($arg as array()) {
 :     for $value in jn:values($arg)
 :     return
 :       if ($value instance of array())
 :       then jn:flatten($value)
 :       else $value
 :   };
 :
 : @param $a A JSON Array.
 : @return The flattened version of $a.
 :)
declare function jn:flatten($a as array()) as item()* external;


(:~
 : Returns the jdm:null value null.
 :
 : @return the said value
 :)
declare function jn:null() as jdm:null external;

(:~
 : Insert one or more pairs into an object. Recall that a JSON Object
 : may not contain two pairs with the same name. This function will not
 : replace a pair in an object.
 :
 : @param $o A JSON Object.
 : @param $p A sequence of Pairs to insert.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, inserts the pairs into the object.
 : @error jn:JUDY0060 if pair with the given name already exists.
declare updating function jn:insert-into(
  $o as object(),
  $p as pair()*) external;
:)

(:~
 : Insert one or more items into a JSON Array. The items will be inserted
 : at the beginning of the array.
 :
 : @param $a A JSON Array.
 : @param $i A sequence of items to insert.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, inserts the items into the array.
 :)
declare updating function jn:insert-as-first(
  $a as array(),
  $i as item()*) external;

(:~
 : Insert one or more items into a JSON Array. The items will be inserted
 : after the specified position in the array.
 :
 : The position must exist in the array. You cannot specify an position of 0
 : to insert at the beginning of the array (use jn:insert-as-first($a, ...) or
 : jn:insert-before($a, 1, ...)).
 :
 : @param $a A JSON Array.
 : @param $pos The position.
 : @param $i A sequence of items to insert.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, inserts the items into the array.
 : @error jn:JUDY0061 if the position doesn't select an existing array member
 :)
declare updating function jn:insert-after(
  $a as array(),
  $pos as xs:integer,
  $i as item()*) external;

(:~
 : Insert one or more items into a JSON Array. The items will be inserted
 : before the specified position in the array.
 :
 : The position must exist in the array.
 :
 : @param $a A JSON Array.
 : @param $pos The position.
 : @param $i A sequence of items to insert.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, inserts the items into the array.
 : @error jn:JUDY0061 if the position doesn't select an existing array member
 :)
declare updating function jn:insert-before(
  $a as array(),
  $pos as xs:integer,
  $i as item()*) external;

(:~
 : Insert one or more items into a JSON Array. The items will be inserted
 : at the end of the array.
 :
 : @param $a A JSON Array.
 : @param $i A sequence of items to insert.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, inserts the items into the array.
 :)
declare updating function jn:insert-as-last(
  $a as array(),
  $i as item()*) external;

(:~
 : Delete an item from a JSON Array or a Pair from a JSON Object.
 : 
 : If $j is an Object and $selector is an xs:string, deletes the Pair
 : $i($selector) if it exists, raising an error if it does not exist.
 :
 : If $j is an Array and $selector is an xs:integer, deletes the member
 : $i($selector) if it exists, raising an error if it does not exist.
 :
 : In any other case, a type error is raised.
 : @param $j A JSON Array or JSON Object.
 : @param $select An xs:string (if $j is an Object) or xs:integer
 :   (if $j is an array).
 : @return An empty XDM instance and a pending update list which, once
 :   applied, deletes the item from the array or object.
 : @error jn:JUDY0061 if the selector doesn't select an existing pair or
 :   array member
 : @error jn:JUDY0062 if the first argument is a pair
 : @error jn:JUDY0063 invalid type for second argument (must be xs:integer
 :   if first argument is an array or xs:string if first argument is an object)
 :)
declare updating function jn:delete(
  $j as json-item(),
  $selector as xs:anyAtomicType)
{
  try {
    typeswitch ($j)
    case $o as object()
      return jn:delete-pair($o, $selector treat as xs:string)
    case $a as array()
      return jn:delete-member($a, $selector treat as xs:integer)
    default return
      fn:error(
        fn:QName("http://www.jsoniq.org/errors", "JUDY0062"),
        "first argument to delete function is pair() but must be array() or object()",
        $j)
   } catch err:XPDY0050 {
     fn:error(
       fn:QName("http://www.jsoniq.org/errors", "JUDY0063"),
       concat(
         schema:schema-type($selector),
         ": invalid type for second argument; should be ",
         typeswitch ($j)
         case object() return "xs:string"
         default return "xs:integer"
       ),
       $selector
     )
   }
};

(:~
 : Delete a pair from a JSON Object by name.
 :
 : @param $o A JSON Object.
 : @param $n The name of the Pair to delete.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, deletes the pair from the object.
 : @error jn:JUDY0061 if the key doesn't select an existing pair.
 :)
declare updating function jn:delete-pair(
  $o as object(),
  $key as xs:string) external;

(:~
 : Delete an item from a JSON Array.
 :
 : @param $a A JSON Array.
 : @param $pos The position in the array to delete.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, deletes the item from the array.
 : @error jn:JUDY0061 if the position doesn't select an existing member 
 :)
declare updating function jn:delete-member(
  $a as array(),
  $pos as xs:integer) external;

(:~
 : Assigns a new name to a JSON Pair in an Object.
 :
 : @param $o A JSON Object.
 : @param $old-name The current name of a Pair in the Object.
 : @param $new-name The new name for the Pair.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, renames the pair.
 : @error jn:JUDY0061 if $old-name doesn't select an existing pair.
 :)
declare updating function jn:rename(
  $o as object(),
  $old-name as xs:string,
  $new-name as xs:string) external;

(:~
 : Replace an item in an Array, or the value of a Pair in an Object.
 :
 : If $j is an Object and $selector is an xs:string, replaces the value
 : of the Pair $i($selector) if it exists, raising an error if it does
 : not exist.
 :
 : If $j is an Array and $selector is an xs:integer, replaces the member
 : $i($selector) if it exists, raising an error if it does not exist.
 :
 : In any other case, a type error is raised.
 :
 : @param $j A JSON Object or Array.
 : @param $select An xs:string (if $j is an Object) or xs:integer
 :   (if $j is an array).
 : @param $new-val The new item to insert into the Object or Array in
 :   place of the old value.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, replaces the selected item in the object or array.
 : @error jn:JUDY0061 if $selector is wrong. (QQQ needs testing)
 :)
declare updating function jn:replace-value(
  $j as json-item(),
  $selector as xs:anyAtomicType,
  $new-val as item()) 
{
  try {
    typeswitch ($j)
    case $o as object()
      return jn:replace-value-in-object($o, $selector treat as xs:string, $new-val)
    case $a as array()
      return jn:replace-value-in-array($a, $selector treat as xs:integer, $new-val)
    default return
      fn:error(
        fn:QName("http://www.jsoniq.org/errors", "JUDY0062"),
        "first argument to replace-value function is pair() but must be array() or object()",
        $j)
   } catch err:XPDY0050 {
     fn:error(
       fn:QName("http://www.jsoniq.org/errors", "JUDY0063"),
       concat(
         schema:schema-type($selector),
         ": invalid type for second argument; should be ",
         typeswitch ($j)
         case object() return "xs:string"
         default return "xs:integer"
       ),
       $selector
     )
   }
};

(:~
 : Replace the value of a Pair in an Object.
 :
 : @param $o A JSON Object.
 : @param $n The name of a Pair in $o.
 : @param $new-val The new value for the Pair.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, replaces the value of the selected pair in the object.
 : @error jn:JUDY0061 if the position doesn't select an existing member 
 :)
declare updating function jn:replace-value-in-object(
  $o as object(),
  $n as xs:string,
  $new-val as item()) external;

(:~
 : Replace an item in a JSON Array.
 : @param $a A JSON Array.
 : @param $pos The position in the array to replace.
 : @param $new-valu The new item to put in the array in place of the
 : existing item.
 : @return An empty XDM instance and a pending update list which, once
 :   applied, replaces the selected item in the array.
 : @error jn:JUDY0061 if the position doesn't select an existing member 
 :)
declare updating function jn:replace-value-in-array(
  $a as array(),
  $pos as xs:integer,
  $new-val as item()) external;
