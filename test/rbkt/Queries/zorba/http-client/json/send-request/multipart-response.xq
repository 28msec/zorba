jsoniq version "1.0";
import module namespace http = "http://zorba.io/modules/http-client";
import schema namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

variable $req := http:get("http://zorbatest.28.io:8080/http-test-data/multipart.php");

for $key in keys($req.headers)
where not(starts-with($key, "Content"))
return delete json $req.headers($key);

serialize($req,
  <output:serialization-parameters>
    <output:method value="json"/>
    <output:indent value="yes"/>
  </output:serialization-parameters>
)