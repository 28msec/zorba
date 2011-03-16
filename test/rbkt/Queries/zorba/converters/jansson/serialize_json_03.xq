(: json:serialize called with wrong parameter: comment node:)

import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:serialize((<!--comment-->),<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)
