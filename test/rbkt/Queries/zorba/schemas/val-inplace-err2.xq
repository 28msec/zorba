import module namespace schema = "http://zorba.io/modules/schema";
import module namespace doc = "http://zorba.io/modules/store/documents"; 
import schema namespace d="http://www.zorba-xquery.org/schema" at "val-inplace-err2.xsd";

declare revalidation lax;
declare construction strip;

declare variable $doc2:=<root xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns="http://www.zorba-xquery.org/schema">
    <root>
        <a/>
        <b/>
        <c/>
    </root>    
    <a/>
    <b/>
    <c/>
</root>;

schema:validate-in-place($doc2/d:root);


(schema:schema-type($doc2), schema:schema-type($doc2/d:root))
