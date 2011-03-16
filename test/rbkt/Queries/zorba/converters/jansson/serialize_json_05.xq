(: json:serialize some pitfall characters :)

import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:serialize((<json type="object">
      <pair name="name" type="string">\"\\\/\b\f\n\r\t</pair>
  </json>),<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)
