import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json := '
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
  }
  '
return json:parse( $json )

(: vim:set et sw=2 ts=2: :)
