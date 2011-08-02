declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare function local:searchFor($obj as xs:string) 
{
  $obj
};


declare %ann:sequential function local:trick($object as xs:string) as xs:integer
{
  let $s := local:searchFor($object)
  return
    if ($s) 
    then
      exit returning "hat";
    else 
      exit returning 1;
};


local:trick("foo")
