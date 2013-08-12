import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

z:parse("<root>
  <test/>
  <test/>
  </bad>
</root>
",
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="1"/>
  </opt:options>
)
