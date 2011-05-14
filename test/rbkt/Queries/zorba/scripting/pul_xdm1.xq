
import module namespace dyn = "http://www.zorba-xquery.com/modules/store/collections";

declare variable $col := xs:QName("myCollection");

declare %updating function local:test3()
{
  for $x in dyn:collection($col)
  return
    (
      delete node $x,
      $x
    )
};


dyn:create-collection($col, (<a></a>,<b></b>));

(
local:test3(),

"
",

dyn:collection($col)
)

