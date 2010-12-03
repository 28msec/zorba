import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse(
'f1, f2, f3, f4
f5, f6, "f7", "f8
""f9"', 
<options>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
  <xml-nodes>
    <row>
      <column/>
    </row>
  </xml-nodes>
</options>
)

