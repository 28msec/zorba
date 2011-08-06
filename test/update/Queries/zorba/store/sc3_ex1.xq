import module namespace f = "http://expath.org/ns/file";
import module namespace c = "http://www.zorba-xquery.com/modules/converters/csv";

import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

declare variable $input-context external;

let $doc := document { <root> { c:parse(f:read-text($input-context), ()) } </root> }
return doc:put("meat_poultry.xml", $doc);
