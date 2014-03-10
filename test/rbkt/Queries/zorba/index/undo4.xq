import module namespace u = "http://zorba.io/unique-index" at "undo4.xqlib";

import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

declare namespace zerr = "http://zorba.io/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

u:create-db();


dml:insert($u:c1, 
<person id="1">
<car make="honda"/><car make="vw"/>
</person>);

dml:insert($u:c1,
<person id="2">
<car make="vw"/>
</person>);


dml:insert($u:c2, 
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
  idml:probe-index-point-value($u:PersonCars, "vw")/.
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
    dml:insert($u:c1, <person id="3"><car make="vw"/></person>),

    dml:insert($u:c2, <person id="1"/>)
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
    dml:insert($u:c1, <person id="3"><car make="vw"/></person>),

    dml:delete-first($u:c1),

    dml:insert($u:c2, <person id="1"/>)
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

    dml:insert($u:c1, <person id="3"><car make="vw"/></person>),

    dml:delete-first($u:c1),

    delete nodes dml:collection($u:c1)[2]/car,

    dml:insert($u:c2, <person id="1"/>)
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

idml:probe-index-point-value($u:PersonCars, "vw")/.
}
,
"
"


