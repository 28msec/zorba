import module namespace json="http://www.zorba-xquery.com/modules/converters/json";

declare variable $json-value := '{"html":"<b>bold</b>"}';

json:serialize(json:parse($json-value))
