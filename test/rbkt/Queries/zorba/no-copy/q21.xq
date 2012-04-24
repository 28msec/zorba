import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $serialization-params as element():=
<serialization-parameters/>;


declare %ann:sequential function 
local:set-serialization-parameters($params as element()) as empty-sequence()
{
  $serialization-params := $params;
};


declare %ann:sequential function local:set-redirect($url as xs:string) as xs:integer
{
  1
};


declare %ann:sequential function local:save()
{
  variable $tmp := $serialization-params/..;
  local:set-redirect("/wiki");
};


local:save()




(:

module namespace resp = "http://www.28msec.com/modules/response";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable 
$resp:serialization-params as element(serialization-parameters) :=
resp:serializer-defaults-xml();


declare function 
resp:serializer-defaults-xml() as element(serialization-parameters)
{
  <serialization-parameters/>
};


declare %ann:sequential function 
resp:set-serialization-parameters($params as element(serialization-parameters)) as 
empty-sequence()
{
  $resp:serialization-params := $params;
};


declare %ann:sequential function resp:set-redirect($url as xs:string) as xs:integer
{
  1
};


----------------------------------------


import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

import module namespace res = "http://www.28msec.com/modules/response" at "q21.xqlib";

declare namespace ann = "http://www.zorba-xquery.com/annotations";


declare %ann:sequential function local:save()
{
  variable $tmp := refl:eval-s('"blub"');
  res:set-redirect("/wiki");
};


local:save()


:)
