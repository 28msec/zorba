import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse(
'f1, f2, f3, f4, f10, f11
f5, f6, "f7", "f8
""f9",f8', 
<options>
  <first-row-is-header/>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
</options>
)

(:
<b>Output:</b>

<?xml version="1.0" encoding="UTF-8"?>
<row>
  <f1>f5</f1>
  <_f2> f6</_f2>
  <_f3> f7</_f3>
  <_f4> f8
"f9</_f4>
  <_f10>f8</_f10>
</row>
:)