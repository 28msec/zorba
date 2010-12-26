(:
Parse a csv with header and subheaders, starting from line 5.
Data continues after subheaders.
The csv file is taken from http://data.gov.
:)
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";

zorba-csv:parse(file:read-text(fn:resolve-uri("Hospital Outpatient Payments for 61 Commonly Performed Procedures, CY 2008 Data.csv")), 
<options>
  <first-row-is-header line="5-8"/>
  <start-from-row line="9"/>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
</options>
)

(:
<b>Input:</b>
OUTPATIENT HOSPITAL PAYMENTS FOR 61 COMMONLY PERFORMED PROCEDURES,,,,,,
2008 CALENDAR YEAR CLAIMS PROCESSED THROUGH JUNE 2009,,,,,,
SOURCE:  NATIONAL CLAIMS HISTORY,,,,,,
14-Oct-09,,,,,,
 STATE,COUNTY,HOSPITAL NAME,Removal of damaged skin and underlying tissue,,Breast biopsy through skin with sampling device,,
,,,CPT 11042,,CPT 19103,
,,,,,,
,,,Allowed Services+,Range of Payment Rates by County+,Allowed Services+,Range of Payment Rates by County+
NATIONAL,,,"622,289",102 - 228,"60,717"
California,Los Angeles, ,"12,831",187,"1,037",955
California,Los Angeles,ALHAMBRA HOSPITAL MEDICAL CENTER,0,,0,

<b>Output:</b>
<row>
  <_STATE>NATIONAL</_STATE>
  <COUNTY/>
  <HOSPITAL_NAME/>
  <Removal_of_damaged_skin_and_underlying_tissue>
    <CPT_11042>
      <Allowed_Services_>622,289</Allowed_Services_>
      <Range_of_Payment_Rates_by_County_>102 - 228</Range_of_Payment_Rates_by_County_>
    </CPT_11042>
  </Removal_of_damaged_skin_and_underlying_tissue>
  <Breast_biopsy_through_skin_with_sampling_device>
    <CPT_19103>
      <Allowed_Services_>60,717</Allowed_Services_>
      <Range_of_Payment_Rates_by_County_>536 - 1147</Range_of_Payment_Rates_by_County_>
    </CPT_19103>
  </Breast_biopsy_through_skin_with_sampling_device>
</row><row>
  <_STATE>California</_STATE>
  <COUNTY>Los Angeles</COUNTY>
  <HOSPITAL_NAME> </HOSPITAL_NAME>
  <Removal_of_damaged_skin_and_underlying_tissue>
    <CPT_11042>
      <Allowed_Services_>12,831</Allowed_Services_>
      <Range_of_Payment_Rates_by_County_>187</Range_of_Payment_Rates_by_County_>
    </CPT_11042>
  </Removal_of_damaged_skin_and_underlying_tissue>
  <Breast_biopsy_through_skin_with_sampling_device>
    <CPT_19103>
      <Allowed_Services_>1,037</Allowed_Services_>
      <Range_of_Payment_Rates_by_County_>955</Range_of_Payment_Rates_by_County_>
    </CPT_19103>
  </Breast_biopsy_through_skin_with_sampling_device>
</row><row>
  <_STATE>California</_STATE>
  <COUNTY>Los Angeles</COUNTY>
  <HOSPITAL_NAME>ALHAMBRA HOSPITAL MEDICAL CENTER</HOSPITAL_NAME>
  <Removal_of_damaged_skin_and_underlying_tissue>
    <CPT_11042>
      <Allowed_Services_>0</Allowed_Services_>
      <Range_of_Payment_Rates_by_County_/>
    </CPT_11042>
  </Removal_of_damaged_skin_and_underlying_tissue>
  <Breast_biopsy_through_skin_with_sampling_device>
    <CPT_19103>
      <Allowed_Services_>0</Allowed_Services_>
      <Range_of_Payment_Rates_by_County_/>
    </CPT_19103>
  </Breast_biopsy_through_skin_with_sampling_device>
</row>
:)