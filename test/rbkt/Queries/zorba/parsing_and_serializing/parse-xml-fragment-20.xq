import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

for $i in parse-xml:parse(
    "<root><from1>Jani1</from1><from2>Jani2</from2></root>",
    <opt:options>
      <opt:parse-external-parsed-entity opt:skip-root-nodes="1"/>
    </opt:options>
  )
return $i/parent::node() instance of document-node()
