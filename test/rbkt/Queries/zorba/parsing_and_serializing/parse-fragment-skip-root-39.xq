import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

z:parse-xml("<doc>
  <foo>0</foo>
  <foo>1</foo>
  <foo>2</foo>
  <foo>3</foo>
  <foo>4</foo>
  <foo>5</foo>
  <foo>6</foo>
  <foo>7</foo>
  <foo>8</foo>
  <foo>9</foo>
  <foo>10</foo>
</doc>", 
  <opt:options>
    <opt:parseExternalParsedEntity opt:skipRootNodes="2"/>
  </opt:options>
)
