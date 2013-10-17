import module namespace xqsx = "http://www.zorba-xquery.com/zorba/scripting";

import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare variable $col := xs:QName("myCollection");

declare updating function local:test3()
{
  for $x in dml:collection($col)
  return
    (
      dml:delete($x),
      $x
    )
};


ddl:create($col, (<a></a>,<b></b>));

(
xqsx:apply(local:test3()),

"
",

dml:collection($col)
)
