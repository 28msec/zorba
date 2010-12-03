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
