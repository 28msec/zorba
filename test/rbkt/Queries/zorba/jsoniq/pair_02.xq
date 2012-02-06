

import module namespace j = "http://www.jsoniq.org/functions";

variable $j as json-item()* := ( { "foo": "bar" }, { "foo" : 1 });
$j("foo")
