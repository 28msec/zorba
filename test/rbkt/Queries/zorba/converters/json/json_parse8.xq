(: json:parse testing null handling :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $local:json :=
   '{ "web-app": null }';

json:parse($local:json)

