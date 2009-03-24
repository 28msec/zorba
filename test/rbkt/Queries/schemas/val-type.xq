import module namespace 
    fn-zorba-util="http://www.zorba-xquery.com/zorba/util-functions";

import schema namespace 
  s = "simple.xsd" 
  at "simple.xsd";

let $x := validate as s:ProductType
{
    <product xmlns='simple.xsd'>
    	<s:name>p1</s:name>
    	<s:number>1</s:number>
    	<!--this is a comment -->
    </product>
}

return 
   fn-zorba-util:schema-type( $x )

(:
    <!--product xmlns='simple.xsd'-->
    	<!--s:name>p1</s:name-->
    	<!--s:number>1</s:number-->
    	<!--this is a comment -->
    <!--/product-->
:)