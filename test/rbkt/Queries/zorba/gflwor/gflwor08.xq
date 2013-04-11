
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";


ddl:create(xs:QName("captains"), (
{ "name" : "Jean-Luc Picard", "series" : [ "The next generation" ], "century" : 24 }
));


ddl:create(xs:QName("movies"),(
{ "id" : "I", "name" : "The Motion Picture", "captain" : "James T. Kirk" },
{ "id" : "II", "name" : "The Wrath of Kahn", "captain" : "James T. Kirk" })
);


for $captain in dml:collection(xs:QName("captains"))

for $movie allowing empty in 
    dml:collection(xs:QName("movies"))[ try { .("captain") eq $captain("name") } catch * { false } ]

return { "captain" : $captain("name"), "movie" : $movie }
