
declare namespace ann = "http://zorba.io/annotations";

declare variable $glob as element():= <glob/>;


declare %ann:sequential function
local:set-global-var($param as element()) as empty-sequence()
{
  $glob := $param;
};


declare %ann:sequential function local:dummy($url as xs:string) as xs:integer
{
  1
};


declare %ann:sequential function local:save()
{
  variable $tmp := $glob/..;
  local:dummy("/wiki");
};


local:save()



