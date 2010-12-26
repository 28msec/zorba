(:
Serialize xml nodes to fixed size text, 
and then parse it using different parameters, but same column sizes.
:)
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse(
   zorba-csv:serialize(
            (<row><f1>value1</f1><f2>value2</f2><f3>value3</f3><f4>value4</f4></row>,
             <row><f1>value11</f1><f2>value12</f2><f3>value13</f3><f4>value14</f4></row>),
            <options>
              <first-row-is-header/>
              <column-widths>
                <column-width>7</column-width>
                <column-width>7</column-width>
                <column-width>7</column-width>
                <column-width>7</column-width>
              </column-widths>
            </options>   
            ),
    <options>
      <first-row-is-header/>
      <column-positions>
        <column-position>1</column-position>
        <column-position>8</column-position>
        <column-position>15</column-position>
        <column-position>22</column-position>
      </column-positions>
    </options>   )

    
 (:
 <b>Intermediate result from serialization:</b>
 
<?xml version="1.0" encoding="UTF-8"?>
f1     f2     f3     f4     
value1 value2 value3 value4 
value11value12value13value14

<b>Final output from re-parsing:</b>
 
<?xml version="1.0" encoding="UTF-8"?>
<row>
  <f1>value1</f1>
  <f2>value2</f2>
  <f3>value3</f3>
  <f4>value4</f4>
</row><row>
  <f1>value11</f1>
  <f2>value12</f2>
  <f3>value13</f3>
  <f4>value14</f4>
</row>
 :)