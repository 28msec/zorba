(:Serialize a sequence of constructed nodes in csv lines, without header:)
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
declare namespace data="http://www.zorba-xquery/data";

zorba-csv:serialize(
for $person in fn:doc("data.xml")/data:root/data:person
return <row>{$person/data:name}
            {$person/data:address}
            {$person/data:address2}
        </row>, 
<options>
  <first-row-is-header/>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
</options>)

(:
<b>Input:</b>
  <?xml version="1.0" encoding="utf-8" ?> 
  <data:root xmlns:data="http://www.zorba-xquery/data">
   <data:person>
   <data:name>N1</data:name> 
   <data:address>A1</data:address> 
   <data:address2>A12</data:address2> 
   </data:person>
   <data:person>
   <data:name>N2</data:name> 
   <data:address>A2</data:address> 
   <data:address2>A22</data:address2> 
   </data:person>
   <data:person>
   <data:name>N3</data:name> 
   <data:address>A3</data:address> 
   <data:address2>A32</data:address2> 
   </data:person>
   <data:person>
   <data:name>N4</data:name> 
   <data:address>A4</data:address> 
   <data:address2>A42</data:address2> 
   </data:person>
   <data:person>
   <data:name>N5</data:name> 
   <data:address>A5</data:address> 
   <data:address2>A52</data:address2> 
   </data:person>
   <data:person>
   <data:name>N6</data:name> 
   <data:address2>A62</data:address2> 
   </data:person>
   <data:person>
   <data:name>N7</data:name> 
   <data:address>A7</data:address> 
   <data:address2>A72</data:address2> 
   </data:person>
   <data:person>
   <data:name>N8</data:name> 
   <data:address>A8</data:address> 
   <data:address2>A82</data:address2> 
   </data:person>
  </data:root>
   
  
<b>Output:</b>

name,address,address2
N1,A1,A12
N2,A2,A22
N3,A3,A32
N4,A4,A42
N5,A5,A52
N6,,A62
N7,A7,A72
N8,A8,A82

:)