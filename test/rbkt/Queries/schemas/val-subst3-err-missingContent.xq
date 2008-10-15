import schema namespace
  s = "zorba/test/substitution.xsd"
  at "substitution.xsd";

validate 
{
    <basket xmlns='zorba/test/substitution.xsd'>
    	<fruit name="banana" />
        <apple/>
        <berry></berry>
    </basket>
}
