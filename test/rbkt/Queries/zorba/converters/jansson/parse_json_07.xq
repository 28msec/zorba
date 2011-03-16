(: json:parse testing numbers and decimals :)

import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:parse('{ "special-numbers": {
         "decimal": 2.89,
         "e": 2E+6,
         "negative": -1.89
      }
    }',<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)
