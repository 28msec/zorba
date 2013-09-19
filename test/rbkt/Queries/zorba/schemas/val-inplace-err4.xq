import schema namespace d="http://www.zorba-xquery.org/schema" at "extracontent.xsd";
import module namespace schema = "http://zorba.io/modules/schema";

declare revalidation lax;

declare variable $doc:=<root xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns="http://www.zorba-xquery.org/schema" xx="xx">

</root>;

schema:validate-in-place($doc);