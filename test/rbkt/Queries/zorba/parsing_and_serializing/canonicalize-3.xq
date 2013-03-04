import module namespace x = "http://www.zorba-xquery.com/modules/xml#2.1";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-canonicalize-options";

let $xml := '<document xmlns:ns="http://test">
  <element1>...</element1>
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
</document>'
return x:canonicalize($xml, <opt:options><opt:xml-parse-nsclean/></opt:options>)
