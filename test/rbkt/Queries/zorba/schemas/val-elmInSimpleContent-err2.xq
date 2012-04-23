import schema namespace d="http://www.zorba-xquery.org/schema" at "extracontent.xsd";
import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

declare revalidation lax;

declare variable $x:=validate lax {<root xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns="http://www.zorba-xquery.org/schema">
<a/>aa
</root>};
$x/text()
