import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

z:parse("<root><a id='0'>
 0
 </b>
</a>
<a id='1'>
 1
</a>
<a id='2'>
 2
</a>
</root>", 
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
