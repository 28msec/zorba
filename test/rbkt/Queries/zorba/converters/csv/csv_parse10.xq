import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";

zorba-csv:parse(file:read-text(fn:resolve-uri("NAWQA.swmaster.CROSSTAB_COUNT.1260179451247.csv")), 
                    <options>
                      <first-row-is-header/>
                      <csv separator=","
                           quote-char=""
                           quote-escape=""/>
                      <xml-nodes>
                        <row>
                          <column/>
                        </row>
                      </xml-nodes>
                    </options>                    
                    )
