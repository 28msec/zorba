import module namespace cddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace cdml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

variable $coll-name := xs:QName("local:mycol");

cddl:create-collection($coll-name);

for $i in 1 to 10
return
    cdml:insert-nodes-last(
      $coll-name, 
      <mynode id="{$i}"/>
    );

cdml:collection($coll-name)
