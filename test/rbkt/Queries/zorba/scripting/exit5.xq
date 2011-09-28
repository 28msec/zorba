declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare function local:searchFor($obj as xs:string) 
{
  $obj
};


declare function local:trick($object as xs:string) 
{
  let $s := local:searchFor($object)
  return
    exit returning ("hat:", $s);

  "THIS IS THE SECRET"
};


declare %ann:sequential function local:magician() 
{
  let $s := local:trick("rabbit")
  return
    exit returning $s;
};


local:magician()
