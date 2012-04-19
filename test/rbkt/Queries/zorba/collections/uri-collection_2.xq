import module namespace ddl =
    "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl";
import module namespace dml =
    "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml";


declare variable $coll := "http://www.zorba-xquery.com/collection";
declare variable $doc := doc("uri-collection.xml");    
ddl:create($coll);

dml:apply-insert-nodes-first($coll, $doc);

let $uricoll := uri-collection("")
return if( string($uricoll) != "" )
  then true()
  else false()