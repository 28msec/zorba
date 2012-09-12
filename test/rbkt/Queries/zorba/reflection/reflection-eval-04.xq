import module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";
import module namespace client = "http://pilman.ch/ns/blubb" at "client.xqlib";

for $i in (1 to 2)
return reflection:eval-s("$i, $client:oauth-token1")
