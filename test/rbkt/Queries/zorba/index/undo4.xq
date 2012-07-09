
import module namespace u = "http://www.zorba-xquery.com/unique-index" at "undo4.xqlib";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace idml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

u:create-db();


dml:insert-nodes($u:c1, 
<person id="1">
<car make="honda"/><car make="vw"/>
</person>);

dml:insert-nodes($u:c1,
<person id="2">
<car make="vw"/>
</person>);


dml:insert-nodes($u:c2, 
<person id="1">
<car make="honda"/><car make="vw"/>
</person>);


idml:probe-index-point-general($u:PersonCars, "vw")
,
"

TEST 0:

"
,
try
{
  idml:probe-index-point-value($u:PersonCars, "vw")
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
"

TEST 1:

"
,
try
{{
  (
    dml:insert-nodes($u:c1, <person id="3"><car make="vw"/></person>),

    dml:insert-nodes($u:c2, <person id="1"/>)
  );
  ()
}}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
"
"
,
idml:probe-index-point-general($u:PersonCars, "vw")
,
"

TEST 2:

"
,
try
{{
  (
    dml:insert-nodes($u:c1, <person id="3"><car make="vw"/></person>),

    dml:delete-node-first($u:c1),

    dml:insert-nodes($u:c2, <person id="1"/>)
  );
  ()
}}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
"
"
,
idml:probe-index-point-general($u:PersonCars, "vw")
,
"

TEST 3:

"
,
try
{{
  (
    insert node <car make="BMW"/> into dml:collection($u:c1)[1],

    dml:insert-nodes($u:c1, <person id="3"><car make="vw"/></person>),

    dml:delete-node-first($u:c1),

    delete nodes dml:collection($u:c1)[2]/car,

    dml:insert-nodes($u:c2, <person id="1"/>)
  );
  ()
}}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
"
"
,
idml:probe-index-point-general($u:PersonCars, ("vw", "BMW"))
,
"

TEST 4:

"
,
{
delete nodes dml:collection($u:c1)[1]/car[1];

idml:probe-index-point-value($u:PersonCars, "vw")
}
,
"
"


