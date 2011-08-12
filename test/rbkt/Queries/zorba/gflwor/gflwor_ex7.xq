import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

import module namespace data = "http://www.28msec.com/WindyCityDBDemo/lib/data" at "data.xqlib";

declare namespace err = "http://www.w3.org/2005/xqt-errors";


declare variable $local:error := xs:QName('data:error');


declare function local:get($collection as xs:QName, $query as xs:string?) 
{
  let $expr   := concat('dml:collection($collection)',
                         if($query) then $query else "[position() lt 50]",
                         ""
                        )
  return
    try
    {
      util:eval
      (
        concat(
          'import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";',
          $expr
        )
      )
    } 
    catch * 
    {
      error($local:error, concat("Invalid Query: ", $expr, ". ", $err:description))
    }
};


ddl:create($data:users);
local:get($data:users, ", 1+1")

