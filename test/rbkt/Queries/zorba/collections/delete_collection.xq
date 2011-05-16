import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";


declare %sequential function local:create() 
{
  ddl:create-collection(xs:QName("ns:test1"));
  ddl:create-collection(xs:QName("ns:test2"), for $i in 1 to 10 return <a> { $i } </a> );
  exit returning ddl:is-available-collection(xs:QName("ns:test1")) and ddl:is-available-collection(xs:QName("ns:test2"));
};


declare %sequential function local:delete() 
{
  ddl:delete-collection(xs:QName("ns:test1"));
  ddl:delete-collection(xs:QName("ns:test2"));
  exit returning fn:not(ddl:is-available-collection(xs:QName("ns:test1")) or ddl:is-available-collection(xs:QName("ns:test2")));
};


{
  variable $create := local:create();
  variable $delete := local:delete();

  if (fn:not($create or $delete)) 
  then
    fn:false()
  else
    {
      variable $create := local:create();

      $create
    }
}

