import schema namespace
  s = "zorba/test/substitution.xsd"
  at "substitution.xsd";

validate 
{
    <basket xmlns='zorba/test/substitution.xsd'>
    	<fruit name="banana" />
        <apple/>
        <berry><wild>true</wild></berry>
	<cherry/>
    </basket>
}
