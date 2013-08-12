import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

x:parse(
"
<!-- comment -->
<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.01 Transitional//EN' 'http://www.w3.org/TR/html4/loose.dtd'>
<!-- comment -->
Jani
<from3>Jani</from3>", 
<opt:options>
  <opt:parse-external-parsed-entity/>
</opt:options>
)

