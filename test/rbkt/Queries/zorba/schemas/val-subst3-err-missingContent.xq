import schema namespace
  s = "http://www.zorba-xquery.com/zorba/test/substitution.xsd"
  at "substitution.xsd";

validate 
{
    <basket xmlns='http://www.zorba-xquery.com/zorba/test/substitution.xsd'>
    	<fruit name="banana" />
        <apple/>
        <berry></berry>
    </basket>
}
