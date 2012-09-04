import module namespace foaf = "http://www.w3.org/TestModules/foaf" at
                                   "foaf_module-with-index-and-xml.xqlib";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

foaf:create-db();

dml:insert($foaf:network, {
    "name" : <name>William Riker</name>,
(:    "name" : "William Riker", :)
    "age" : 30,
    "gender" : "male"
  });

let $riker := dml:collection($foaf:network)[ .("name") eq "William Riker" ]
return
  replace json value of $riker("name") with <name><first>William</first><last>Riker</last></name>;

for $x in foaf:probe-point-id($foaf:person, "William")
return $x
