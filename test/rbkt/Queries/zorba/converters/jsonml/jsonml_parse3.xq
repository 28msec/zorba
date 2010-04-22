(: jsonml:parse with invalid parameter :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

json:parseML(('{
     "firstName": "John",
     "lastName": "Smith",
     "address": {
         "streetAddress": "21 2nd Street",
         "city": "New York",
         "state": "NY",
         "postalCode": 10021
     }'))
