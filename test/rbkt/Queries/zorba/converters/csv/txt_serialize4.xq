(: xml-to-txt example with 2 rows :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:serialize(
(<row1>
  <f1>value1</f1>
  <f2>"value2"</f2>
  <f3>value3&amp;,value33</f3>
  <f4>value4</f4>
</row1>,
<row2>
  <f1>value11</f1>
  <f2>value12</f2>
  <f3>value13</f3>
  <f33>value13</f33>
  <f4>value14</f4>
</row2>,
<row3>
  <f11>value21</f11>
  <f22>value22</f22>
  <f33>value23</f33>
  <f44>value24</f44>
</row3>), 

<options>
  <first-row-is-header/>
  <column-widths>
    <column-width>10</column-width>
    <column-width>7</column-width>
    <column-width>10</column-width>
    <column-width>7</column-width>
  </column-widths>
</options>   
)
  