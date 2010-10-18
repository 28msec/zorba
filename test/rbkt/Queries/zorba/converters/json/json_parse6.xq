(: json:parse with uncommon characters :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $local:json :=
   '{ "web-app": "!_\"-\\?*.$+" }';

json:parse($local:json)

