import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

z:parse("<doc>
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
    <opt:parse-external-parsed-entity opt:skip-root-nodes="0"/>
  </opt:options>
)
