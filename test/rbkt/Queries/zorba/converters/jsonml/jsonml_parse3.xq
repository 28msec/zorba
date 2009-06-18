(: jsonml:parse with invalid parameter :)

import module namespace jsonml = "http://www.zorba-xquery.com/zorba/json-ml-functions";

jsonml:parse(('{
     "firstName": "John",
     "lastName": "Smith",
     "address": {
         "streetAddress": "21 2nd Street",
         "city": "New York",
         "state": "NY",
         "postalCode": 10021
     }'))
