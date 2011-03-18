declare base-uri "http://example.org/";

fn:base-uri(fn:parse-xml("<a xml:base='foo'/>")/a)
