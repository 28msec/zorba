(:
Parse a text with fixed size columns, and then serialize it back with different alignments.
The align attributes are ignored in the parse function.
The data file is taken from http://data.gov.
:)
import schema namespace csv-options="http://www.zorba-xquery.com/modules/csv-options";
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";

let $options :=
validate{
<csv-options:options>
  <column-widths align="right">
    <column-width align="left">20</column-width>
    <column-width>45</column-width>
    <column-width>35</column-width>
    <column-width>17</column-width>
    <column-width align="left">19</column-width>
    <column-width>4</column-width>
    <column-width>2</column-width>
    <column-width>17</column-width>
  </column-widths>
</csv-options:options> }   
return
let $result := 
zorba-csv:serialize(
zorba-csv:parse(file:read-text(fn:resolve-uri("PUAOSL95.TXT")), $options),
                $options)
return 
  $result

  
(:
<b>Input:</b>

501-000             Jefferson County Library System              2100 Park Place                    Birmingham       3523700232052263615HQMJAOJefferson        NAL0089AL0196                                                         
511-000             Pickens County Cooperative Library           Post Office Bldg Highway 17 S      Carrollton       3544704892053678407HQCOAOPickens          YAL0139AL0196                                                         

<b>Intermediate output from parsing</b>

<?xml version="1.0" encoding="UTF-8"?>
<row>
  <column>501-000</column>
  <column>Jefferson County Library System</column>
  <column>2100 Park Place</column>
  <column>Birmingham</column>
  <column>3523700232052263615</column>
  <column>HQMJ</column>
  <column>AO</column>
  <column>Jefferson</column>
</row><row>
  <column>511-000</column>
  <column>Pickens County Cooperative Library</column>
  <column>Post Office Bldg Highway 17 S</column>
  <column>Carrollton</column>
  <column>3544704892053678407</column>
  <column>HQCO</column>
  <column>AO</column>
  <column>Pickens</column>
</row>


<b>Final output from re-serialization:</b>

<?xml version="1.0" encoding="UTF-8"?>
501-000                           Jefferson County Library System                    2100 Park Place       Birmingham3523700232052263615HQMJAO        Jefferson
511-000                        Pickens County Cooperative Library      Post Office Bldg Highway 17 S       Carrollton3544704892053678407HQCOAO          Pickens

:)