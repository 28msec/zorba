import module namespace j = "http://www.jsoniq.org/functions";

j:flatten(j:parse-json("[1, 2, [ 3 ] ]"))
