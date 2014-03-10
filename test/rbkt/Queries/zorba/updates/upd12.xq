import module namespace doc = "http://zorba.io/modules/store/documents";

doc:put("foo", document { <foo>bar</foo> });

(
doc:remove("foo"),
doc:remove("foo")
);

"OK"
