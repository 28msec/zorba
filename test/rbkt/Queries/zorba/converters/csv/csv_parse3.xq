(:Parse csv with different parameters.
The csv file is taken from http://data.gov.
:)

import schema namespace csv-options="http://www.zorba-xquery.com/modules/csv-options";
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";
zorba-csv:parse(file:read-text(fn:resolve-uri("tri_2008_NH_v08.txt")), 

validate{
<csv-options:options>
  <first-row-is-header/>
  <csv separator="&#009;"
       quote-char=""
       quote-escape=""/>
  <xml-nodes>
    <row>
      <column/>
    </row>
  </xml-nodes>
</csv-options:options>
}
)


(:
<b>Input:</b>
Year	TRI Facility ID	Facility Name	Street Address	
2008	03840NVLRNOCEAN	NOVEL IRON WORKS INC	250 OCEAN RD
2008	03055SNTGB47POW	SAINT-GOBAIN CERAMICS- IGNITER PRODUCTS	47 POWERS ST

<b>Output:</b>
<row>
  <Year>2008</Year>
  <TRI_Facility_ID>03840NVLRNOCEAN</TRI_Facility_ID>
  <Facility_Name>NOVEL IRON WORKS INC</Facility_Name>
  <Street_Address>250 OCEAN RD</Street_Address>
</row><row>
  <Year>2008</Year>
  <TRI_Facility_ID>03055SNTGB47POW</TRI_Facility_ID>
  <Facility_Name>SAINT-GOBAIN CERAMICS- IGNITER PRODUCTS</Facility_Name>
  <Street_Address>47 POWERS ST</Street_Address>
</row>
:)