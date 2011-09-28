declare context item := fn:doc("document.xml");

fn:matches(xs:string(fn:document-uri()), "document.xml")