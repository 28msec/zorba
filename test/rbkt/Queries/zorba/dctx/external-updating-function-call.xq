import module namespace dctx = "http://zorba.io/modules/dctx";
import module namespace doc = "http://zorba.io/modules/store/documents";

variable $y := dctx:snapshot-id();
doc:put("foo", document { <foo>bar</foo> });
$y, dctx:snapshot-id()