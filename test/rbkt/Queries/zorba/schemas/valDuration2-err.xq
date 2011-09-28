import schema namespace simple="http://zorba-xquery.com/test/vsimple.xsd" at "vsimple.xsd"; 

validate strict 
{
  <simple:dd><simple:duration>sorry, no duration here</simple:duration></simple:dd>
}

