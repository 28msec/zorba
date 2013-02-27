import module namespace foaf = "http://www.w3.org/TestModules/foaf" at
                                   "foaf_module-with-index-and-xml.xqlib";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

foaf:create-db();

dml:insert($foaf:network, {
    "first-name" : "William",
    "last-name" : "Riker",
    "age" : 30,
    "gender" : "male"
  });

let $riker := dml:collection($foaf:network)[ .("last-name") eq "Riker" ]
return {
  insert json { "name" : <name><first>William</first><last>Riker</last></name> } into $riker;
  delete json $riker("first-name");
  delete json $riker("last-name");
}

for $x in foaf:probe-point-id($foaf:person, "William")
return $x
