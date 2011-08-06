import module namespace cddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

declare variable $coll-name := xs:QName("earthquakes");

cddl:create-collection($coll-name);
cddl:is-available-collection($coll-name)
