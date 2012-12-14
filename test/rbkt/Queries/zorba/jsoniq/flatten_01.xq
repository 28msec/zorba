import module namespace j = "http://jsoniq.org/functions";

j:flatten(j:parse-json("[1, 2, [ 3 ] ]"))
