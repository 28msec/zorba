import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

import module namespace data = "http://www.28msec.com/WindyCityDBDemo/lib/data" at "data.xqlib";


declare variable $local:error := xs:QName('data:error');


declare function local:get($collection as xs:QName, $query as xs:string?) 
{
  let $expr   := concat('manip:collection($collection)',
                         if($query) then $query else "[position() lt 50]",
                         ""
                        )
  return
    try
    {
      util:eval-simple 
      (
        concat(
          'import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";',
          $expr
        )
      )
    } 
    catch * ($ecode, $desc)
    {
      error($local:error, concat("Invalid Query: ", $expr, ". ", $desc))
    }
};


init:create-collection($data:users);
local:get($data:users, ", 1+1");

