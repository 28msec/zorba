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



