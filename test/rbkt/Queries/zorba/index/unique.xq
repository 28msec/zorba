import module namespace u = "http://zorba.io/unique-index" at "unique.xqlib";

import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

declare namespace zerr = "http://zorba.io/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

u:create-db();

dml:insert($u:auctions1, <person id="5"/>);

try
{{
  (dml:insert($u:auctions1, <person id="1"/>),
   dml:insert($u:auctions1, <person id="1"/>));
  ()
}}
catch * 
{
  $err:code
}
,

try
{{
  (
   dml:insert($u:auctions1, <person id="1"/>),
   dml:insert($u:auctions1, <person id="3"/>),
   dml:delete-first($u:auctions1, 1),

   dml:insert($u:auctions2, <person id="1"/>),
   dml:insert($u:auctions2, <person id="1"/>));
  ()
}}
catch * 
{
  $err:code
}
,

dml:collection($u:auctions1)
,
idml:probe-index-point-value($u:PersonId1, "1")
,
idml:probe-index-point-value($u:PersonId1, "3")
,
idml:probe-index-point-value($u:PersonId1, "5")
,
dml:collection($u:auctions2)
