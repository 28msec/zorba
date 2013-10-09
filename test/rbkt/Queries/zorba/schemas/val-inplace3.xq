import module namespace schema = "http://zorba.io/modules/schema";
import schema namespace d="http://www.example.com/doc" at "val-inplace3.xsd";
import module namespace file = "http://expath.org/ns/file";
declare revalidation lax;

variable $doc:=<item xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns="http://www.zorba-xquery.org/schema">
    <a>old</a>
</item>;

(
  schema:validate-in-place($doc),
  replace value of node $doc//*:a with "new"
);

variable $res1:=string($doc//*:a);

(
  replace value of node $doc//*:a with "new"
);

($res1,string($doc//*:a))