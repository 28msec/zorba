

import module namespace coll = "http://www.zorba-xquery.com/modules/store/collections";

declare variable $col := xs:QName("myCollection");

declare %sequential function local:test()
{
  coll:create-collection($col, (<a><c>1</c></a>,<b>2</b>));

  let $x := coll:collection($col)[1]/c
  return
    block 
    {
      coll:delete-nodes(coll:collection($col)[1]);
      coll:insert-nodes-first($col, <x>{$x}</x>);
    };

  coll:collection($col);
};

local:test()

