
import module namespace foaf = "http://www.w3.org/TestModules/foaf" at
                                   "foaf_module-with-index.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

foaf:create-db();

dml:delete(dml:collection($foaf:network)[. ("name") eq "James T. Kirk"]);

dml:insert($foaf:network,
    {
      "name" : "Wesley Crusher",
      "age" : 20,
      "gender" : "male",
      "friends" : [ "Beverly Crusher" ]
    }
);

(replace json value of dml:collection($foaf:network)[.("name") eq "Beverly Crusher"]("name") with "Beverly Picard",

for $person in dml:collection($foaf:network)
let $friends := $person("friends")
for $i in 1 to jn:size($friends)
where $friends($i) eq "Beverly Crusher"
return
replace json value of $friends($i) with "Beverly Picard")
;

foaf:probe-point-id($foaf:person, "Beverly Picard")
