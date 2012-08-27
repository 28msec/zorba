
import module namespace foaf = "http://www.w3.org/TestModules/foaf" at
                                   "foaf_module-with-index-and-xml.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

foaf:create-db();

dml:delete(dml:collection($foaf:network)[. ("name")/first eq "James"]);

dml:insert($foaf:network,
    {
      "name" : <name><first>Wesley</first><last>Crusher</last></name>,
      "age" : 20,
      "gender" : "male",
      "friends" : [ "Beverly Crusher" ]
    }
);

(replace value of node dml:collection($foaf:network)[.("name")/first eq "Beverly"]("name")/first with "Bev",
replace value of node dml:collection($foaf:network)[.("name")/first eq "Beverly"]("name")/last with "Picard",

for $person in dml:collection($foaf:network)
let $friends := $person("friends")
for $i in 1 to jn:size($friends)
where $friends($i) eq "Beverly Crusher"
return
replace json value of $friends($i) with "Bev Picard")
;

foaf:probe-point-id($foaf:person, "Bev")
