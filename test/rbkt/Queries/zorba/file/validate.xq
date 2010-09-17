import schema namespace d = "http://www.evaluescience.com/schemas/schema" at "schema.xsd";
import module namespace f = "http://www.zorba-xquery.com/modules/file";

let $d := f:read-xml("$RBKT_SRC_DIR/Queries/zorba/file/validate.xml")
for $i in $d/d:sdds/d:collection/element()
return validate strict { $i }
