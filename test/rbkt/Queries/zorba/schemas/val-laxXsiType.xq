import module namespace schema = "http://zorba.io/modules/schema";

declare variable $doc :=
<numbers xmlns:xs="http://www.w3.org/2001/XMLSchema"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
<xs_long xsi:type="xs:long">1</xs_long>
<xs_long xsi:type="xs:integer">2</xs_long>
<xs_long>3</xs_long>
</numbers>
;

declare variable $vdoc := validate lax { $doc };

(
schema:schema-type(fn:data(($vdoc//xs_long)[1])),
schema:schema-type(fn:data(($vdoc//xs_long)[2])), 
schema:schema-type(fn:data(($vdoc//xs_long)[3]))
)
