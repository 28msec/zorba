(: the comparison method for this test is set to Ignore because the order in which the children
are returned in jansson 1.2, 1.3, 2.0 is different:)

import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:parse(('[
{
  "firstName": "John",
  "lastName": "Smith",
  "address": {
      "streetAddress": "21 2nd Street",
      "city": "New York",
      "state": "NY",
      "postalCode": 10021
  },
  "phoneNumbers": [
      "212 732-1234",
      "646 123-4567"
  ]
},
{
  "firstName": "John",
  "lastName": "Smith",
  "address": {
      "streetAddress": "21 2nd Street",
      "city": "New York",
      "state": "NY",
      "postalCode": 10021
  },
  "phoneNumbers": [
      "212 732-1234",
      "646 123-4567"
  ]
 }]'),<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)
