(: wrong value for array :)

import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:serialize((<json type="object">
      <pair name="name" type="array">
          <pair name="wrong" type="string">value</pair>
      </pair>
  </json>),<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)
