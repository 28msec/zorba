(: check for invalid URI (FODC0007) :)
fn:parse-xml("<a xml:base='foo'/>", "http://")
