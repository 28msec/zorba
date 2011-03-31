(: try parsing an empty value :)

import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:parse((<a/>),<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)