import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace data = "http://www.28msec.com/WindyCityDBDemo/lib/data" at "data.xqlib";

declare variable $local:error := xs:QName('data:error');

declare function local:get($collection as xs:QName, $query as xs:string?) 
{
  let $expr   := concat('xqddf:collection($collection)',
                         if($query) then $query else "[position() lt 50]",
                         ""
                        )
  return
    try{
      using $collection eval {
        concat(
          'import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";',
          $expr
        )
      }
  } catch * ($ecode, $desc){
    error($local:error, concat("Invalid Query: ", $expr, ". ", $desc))
  }
};


xqddf:create-collection($data:users);
local:get($data:users, ", 1+1");

