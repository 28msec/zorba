import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

doc:put("foo", document { <foo>bar</foo> });

(
doc:remove("foo"),
doc:remove("foo")
);

"OK"