import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare variable $col := xs:QName("myCollection");

declare updating function local:test3()
{
  for $x in dml:collection($col)
  return
    (
      delete node $x,
      $x
    )
};


ddl:create($col, (<a></a>,<b></b>));

(
local:test3(),

"
",

dml:collection($col)
)

