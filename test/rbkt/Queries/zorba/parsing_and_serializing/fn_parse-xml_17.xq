declare base-uri "http://example.org/";

(: check for base-uri of document node returned by fn:parse :)
fn:base-uri(fn:parse-xml("<a xml:base='foo'/>"))
