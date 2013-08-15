import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

let $xml := '<document xmlns:ns="http://test">
  <element1/>
  <element2>
    <ns:child>
      text
    </ns:child>
  </element2>
  <element3 xmlns:ns="http://test">
    <ns:child>
      content
    </ns:child>
  </element3>
  <element4/>
</document>'
return x:canonicalize($xml, <opt:options><opt:remove-redundant-ns/></opt:options>)
