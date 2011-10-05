import module namespace p = "http://www.zorba-xquery.com/modules/xml";
import module namespace f = "http://expath.org/ns/file";

p:parse-xml-fragment("<doc>
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
"er0")
