(:Parse a text file with fixed size columns
The text file is taken from http://data.gov.
:)

import schema namespace csv-options="http://www.zorba-xquery.com/modules/csv-options";
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";

zorba-csv:parse(file:read-text(fn:resolve-uri("pusum02a.txt")), 
                    
validate{
<csv-options:options>
  <column-positions>
     <column-position>                 1 </column-position>
     <column-position>               3</column-position>
     <column-position>               13 </column-position>
     <column-position>               23 </column-position>
     <column-position>               33 </column-position>
     <column-position>               38 </column-position>
     <column-position>               43 </column-position>
     <column-position>               48 </column-position>
     <column-position>               59 </column-position>
     <column-position>               70 </column-position>
     <column-position>               81 </column-position>
     <column-position>               93</column-position>
     <column-position>               104 </column-position>
     <column-position>               115 </column-position>
     <column-position>               126 </column-position>
     <column-position>               137 </column-position>
     <column-position>               149 </column-position>
     <column-position>               160 </column-position>
     <column-position>               171 </column-position>
     <column-position>               182 </column-position>
     <column-position>               193 </column-position>
     <column-position>               204 </column-position>
     <column-position>               216 </column-position>
     <column-position>               227 </column-position>
      <column-position>              238 </column-position>
     <column-position>               249 </column-position>
     <column-position>               260 </column-position>
     <column-position>               271 </column-position>
     <column-position>               282 </column-position>
     <column-position>               293 </column-position>
     <column-position>               304 </column-position>
     <column-position>               315 </column-position>
     <column-position>               323 </column-position>
     <column-position>               331 </column-position>
     <column-position>               340 </column-position>
     <column-position>               349 </column-position>
      <column-position>              360 </column-position>
     <column-position>               371 </column-position>
     <column-position>               382 </column-position>
     <column-position>               388 </column-position>
     <column-position>               394 </column-position>
     <column-position>               403 </column-position>
     <column-position>               410 </column-position>
     <column-position>               417 </column-position>
     <column-position>               426 </column-position>
     <column-position>               428 </column-position>
     <column-position>               430 </column-position>
     <column-position>               432 </column-position>
     <column-position>               434 </column-position>
     <column-position>               436 </column-position>
     <column-position>               438 </column-position>
     <column-position>               440 </column-position>
     <column-position>               442 </column-position>
     <column-position>               444 </column-position>
     <column-position>               446 </column-position>
     <column-position>               448 </column-position>
     <column-position>               450 </column-position>
     <column-position>               452 </column-position>
     <column-position>               454 </column-position>
     <column-position>               456 </column-position>
     <column-position>               458 </column-position>
     <column-position>               460 </column-position>
     <column-position>               462 </column-position>
     <column-position>               464 </column-position>
     <column-position>               466 </column-position>
     <column-position>               468 </column-position>
     <column-position>               470 </column-position>
     <column-position>               472 </column-position>
     <column-position>               474 </column-position>
     <column-position>               476 </column-position>
     <column-position>               478 </column-position>
     <column-position>               480 </column-position>
     <column-position>               482 </column-position>
     <column-position>               484 </column-position>
     <column-position>               486 </column-position>
     <column-position>               488 </column-position>
     <column-position>               490 </column-position>
     <column-position>               492 </column-position>
     <column-position>               494 </column-position>
     <column-position>               496 </column-position>
     <column-position>               498 </column-position>
     <column-position>               500 </column-position>
     <column-position>               502 </column-position>
     <column-position>               504 </column-position>
     <column-position>               506 </column-position>
     <column-position>              508</column-position>
  </column-positions>
</csv-options:options> }

)                 
         
		 
		 
(:
<b>Input</b>:

AK    643786    643786    643786   85   17    2      69.20     116.76     203.55      320.31   21262139     909265     917565    1049824    24138793   11073742    3840140   14913882    2862282    5624872    23401036    1639283    2272159      87252     111849       7013     144446    2823241     351481    3726988   24945   29966  1294603   130525     223785     706700       5615   329   459    1395707/200106/200202200308 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 0 1 1 1 0 0 1 0 0 0 
AL   4447100   4447100   4447100  206   76   17     247.72     654.64     940.98     1595.62   60530598    4240026     465982    5822386    71058992   37040130    8116560   45156690   10066006   14525722    69748418   17136487    8913046     300832     272135      15666     582025   13226499    3219055   17049279   33696   44092  5710811   639360     258283    1315744      10105  1344  1704    4894910/200109/200201200305 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 1 1 1 1 0 0 1 0 0 0 1 0 0 0 


<b>Output:</b>

<row>
  <column>AK</column>
  <column>643786</column>
  <column>643786</column>
  <column>643786</column>
  <column>85</column>
  <column>17</column>
  <column>2</column>
  <column>69.20</column>
  <column>116.76</column>
  <column>203.55</column>
  <column>320.31</column>
  <column>21262139</column>
  <column>909265</column>
  <column>917565</column>
  <column>1049824</column>
  <column>24138793</column>
  <column>11073742</column>
  <column>3840140</column>
  <column>14913882</column>
  <column>2862282</column>
  <column>5624872</column>
  <column>23401036</column>
  <column>1639283</column>
  <column>2272159</column>
  <column>87252</column>
  <column>111849</column>
  <column>7013</column>
  <column>144446</column>
  <column>2823241</column>
  <column>351481</column>
  <column>3726988</column>
  <column>24945</column>
  <column>29966</column>
  <column>1294603</column>
  <column>130525</column>
  <column>223785</column>
  <column>706700</column>
  <column>5615</column>
  <column>329</column>
  <column>459</column>
  <column>13957</column>
  <column>07/2001</column>
  <column>06/2002</column>
  <column>02200308</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>0</column>
  <column>0</column>
  <column>1</column>
  <column>1</column>
  <column>0</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>0</column>
  <column>0</column>
  <column>1</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
</row><row>
  <column>AL</column>
  <column>4447100</column>
  <column>4447100</column>
  <column>4447100</column>
  <column>206</column>
  <column>76</column>
  <column>17</column>
  <column>247.72</column>
  <column>654.64</column>
  <column>940.98</column>
  <column>1595.62</column>
  <column>60530598</column>
  <column>4240026</column>
  <column>465982</column>
  <column>5822386</column>
  <column>71058992</column>
  <column>37040130</column>
  <column>8116560</column>
  <column>45156690</column>
  <column>10066006</column>
  <column>14525722</column>
  <column>69748418</column>
  <column>17136487</column>
  <column>8913046</column>
  <column>300832</column>
  <column>272135</column>
  <column>15666</column>
  <column>582025</column>
  <column>13226499</column>
  <column>3219055</column>
  <column>17049279</column>
  <column>33696</column>
  <column>44092</column>
  <column>5710811</column>
  <column>639360</column>
  <column>258283</column>
  <column>1315744</column>
  <column>10105</column>
  <column>1344</column>
  <column>1704</column>
  <column>48949</column>
  <column>10/2001</column>
  <column>09/2002</column>
  <column>01200305</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>1</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>1</column>
  <column>1</column>
  <column>0</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>1</column>
  <column>0</column>
  <column>0</column>
  <column>1</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
  <column>1</column>
  <column>0</column>
  <column>0</column>
  <column>0</column>
</row>

:)           