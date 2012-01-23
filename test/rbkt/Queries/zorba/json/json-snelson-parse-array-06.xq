(: parse an JSON array composed of 2 JSON objects :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse('[
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
 }]')
