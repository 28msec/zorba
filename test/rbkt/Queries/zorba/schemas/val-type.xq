import module namespace 
    fn-zorba-util="http://www.zorba-xquery.com/modules/schema";

import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";

(:
  let $x := validate type s:ProductType
  {
    <produ xmlns='simple.xsd'>
    	<s:name>p1</s:name>
    	<s:number>1</s:number>
    	<!--this is a comment -->
    </produ>
  }
  return 
    fn-zorba-util:schema-type( $x )
:)

(
  let $x := validate type s:ProductType
  {
    <produ xmlns='http://www.zorba-xquery.com/simple.xsd'>
    	<s:name>p1</s:name>
    	<s:number>1</s:number>
    	<!--this is a comment -->
    </produ>
  }
  return 
    (
     fn-zorba-util:schema-type( $x ),
     fn-zorba-util:schema-type( $x/s:name )
    )
,
  let $x := validate type s:ProductType
  {
    <product xmlns='http://www.zorba-xquery.com/simple.xsd'>
    	<s:name>p1</s:name>
    	<s:number>1</s:number>
    	<!--this is a comment -->
    </product>
  }
  return 
    fn-zorba-util:schema-type( $x )
,
  (: -- regular validate -- :)
  let $x := validate
  {
    <product xmlns='http://www.zorba-xquery.com/simple.xsd'>
    	<s:name>p1</s:name>
    	<s:number>1</s:number>
    	<!--this is a comment -->
    </product>
  }
  return 
    fn-zorba-util:schema-type( $x )
)




(:
    <!--product xmlns='simple.xsd'-->
    	<!--s:name>p1</s:name-->
    	<!--s:number>1</s:number-->
    	<!--this is a comment -->
    <!--/product-->
:)
