import schema namespace d = "http://www.evaluescience.com/schemas/schema" at "schema.xsd";
import module namespace file = "http://expath.org/ns/file";

let $d := fn:parse-xml(file:read-text("$RBKT_SRC_DIR/Queries/zorba/file/validate.xml"))
for $i in $d/d:sdds/d:collection/element()
return validate strict { $i }
