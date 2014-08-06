import module namespace u = "http://zorba.io/unique-index" at "undo2.xqlib";

import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

declare namespace zerr = "http://zorba.io/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

u:create-db();

dml:insert($u:auctions1, <person id="1" key="5"/>);
dml:insert($u:auctions1, <person id="2" key="5"/>);

try
{{
  (
   dml:insert($u:auctions1, <person id="3" key="1"/>),

   insert node <foo/> into dml:collection($u:auctions1)[1],

   dml:insert($u:auctions1, <person id="4" key="5"/>),

   replace value of node dml:collection($u:auctions1)[1]/@key with "1",

   dml:insert($u:auctions2, <person id="1"/>),
   dml:insert($u:auctions2, <person id="1"/>));
  ()
}}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,

dml:collection($u:auctions1)
,
idml:probe-index-point-value($u:PersonId1, "1")/.
,
idml:probe-index-point-value($u:PersonId1, "3")/.
,
idml:probe-index-point-value($u:PersonId1, "5")/.
,
dml:collection($u:auctions2)
