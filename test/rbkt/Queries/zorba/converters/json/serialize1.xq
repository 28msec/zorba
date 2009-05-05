import module namespace json = "http://www.zorba-xquery.com/zorba/json-functions";

declare variable $str as xs:string := '{"firstName": "John","lastName": "Smith","address": {"streetAddress": "21 2nd Street","city": "New York","state": "NY","postalCode": 10021},"phoneNumbers": ["212 732-1234","646 123-4567"]}';

json:serialize(json:parse($str)) eq $str
