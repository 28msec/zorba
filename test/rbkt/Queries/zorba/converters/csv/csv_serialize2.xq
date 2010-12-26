(: Serialize a sequence of two nodes into two lines of csv :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:serialize(
(<row>
    <f1>value1</f1>
    <f2>value2</f2>
    <f3>value3</f3>
    <f4>value4</f4>
  </row>,
  <row>
    <f1>value11</f1>
    <f2>value12</f2>
    <f3>value13</f3>
    <f4>value14</f4>
  </row>), 
  ())

(:
<b>Output:</b>

<?xml version="1.0" encoding="UTF-8"?>
value1,value2,value3,value4
value11,value12,value13,value14

:)