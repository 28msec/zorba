import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

z:parse("<?xml version='1.0'?>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text
<level1/>
level0 text",
<opt:options>
  <opt:parse-external-parsed-entity/>
</opt:options> 
)
