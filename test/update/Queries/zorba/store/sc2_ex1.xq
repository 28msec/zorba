import module namespace cddl = "http://zorba.io/modules/store/dynamic/collections/ddl";

declare variable $coll-name := xs:QName("earthquakes");

cddl:create($coll-name);
cddl:is-available-collection($coll-name)
