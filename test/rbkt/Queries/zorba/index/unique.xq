import module namespace u = "http://www.zorba-xquery.com/unique-index" at "unique.xqlib";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace idml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace zerr = "http://zorba.io/modules/zorba-errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

u:create-db();

dml:insert-nodes($u:auctions1, <person id="5"/>);

try
{{
  (dml:insert-nodes($u:auctions1, <person id="1"/>),
   dml:insert-nodes($u:auctions1, <person id="1"/>));
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
   dml:insert-nodes($u:auctions1, <person id="1"/>),
   dml:insert-nodes($u:auctions1, <person id="3"/>),
   dml:delete-nodes-first($u:auctions1, 1),

   dml:insert-nodes($u:auctions2, <person id="1"/>),
   dml:insert-nodes($u:auctions2, <person id="1"/>));
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
