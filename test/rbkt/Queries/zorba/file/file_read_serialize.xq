import module namespace file = "http://expath.org/ns/file";

variable $local:file-name := fn:resolve-uri("mydata.xml");
variable $local:my-doc := ();

(: read an XML file from the file system and parse it :)
$local:my-doc := fn:parse-xml(file:read-text(fn:resolve-uri("mydata.xml")));

(: double the price of each product :)
for $price in $local:my-doc/products/product/price
return replace value of node $price with xs:double($price) * 2;

(: write the updated data to a new file :)
file:write("new-prices.xml", $local:my-doc, ());

(: return the new data as result of the program :)
$local:my-doc

