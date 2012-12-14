import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

x:parse(
"
<from1>Jani</from1>
<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.01 Transitional//EN' 'http://www.w3.org/TR/html4/loose.dtd'>
<from2>Jani</from2>
<from3>Jani</from3>",
<opt:options>
  <opt:parse-external-parsed-entity/>
</opt:options>
)
