import module namespace ddl =
  "http://zorba.io/modules/store/dynamic/collections/w3c/ddl";

import module namespace dml =
  "http://zorba.io/modules/store/dynamic/collections/w3c/dml";

declare variable $coll := "http://zorba.io/collection";
declare variable $doc := doc("uri-collection.xml");    
ddl:create($coll);

dml:apply-insert-nodes-first($coll, $doc);

let $uricoll := uri-collection($coll)
return if( string($uricoll) != "" )
  then true()
  else false()
