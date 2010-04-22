import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $str as xs:string := '{"firstName": "John","state": null,"bool": true,"numbers": [1,2,3],"address": {"streetAddress": "21 2nd Street","state": null,"postalCode": 10021,"literals": [true,false,null],"delivery": {"streetAddress": "StreetName","city": "CityName","state": "StateName"}},"strings": ["one","two","three","four"]}';

json:serialize(json:parse($str)) eq $str
