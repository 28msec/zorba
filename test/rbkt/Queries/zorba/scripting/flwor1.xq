
import module namespace dyn = "http://www.zorba-xquery.com/modules/store/collections";

declare variable $col := xs:QName("myCollection");

declare %sequential function local:test3()
{
  dyn:create-collection($col, (<a></a>,<b></b>));

  for $x in dyn:collection($col)
  return
    {
      dyn:insert-nodes-last($col, <c></c>);
    }

  dyn:collection($col)
};

local:test3()

