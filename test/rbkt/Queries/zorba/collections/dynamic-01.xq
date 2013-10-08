import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";


declare variable $coll := xs:QName("ddl:coll1");

declare variable $available-colls := ();
declare variable $is-available := ();
declare variable $content := ();
declare variable $name := ();

ddl:create($coll);

dml:insert-first($coll, for $i  in 1 to 10 return <b>{$i}</b>);

dml:insert-last($coll, for $i  in 1 to 10 return <c>{$i}</c>);

dml:insert-before($coll, dml:collection($coll)[2], for $i  in 1 to 10 return <d>{$i}</d>);

dml:insert-after($coll, dml:collection($coll)[2], for $i  in 1 to 10 return <e>{$i}</e>);

dml:delete(dml:collection($coll)[last()-2]);

dml:delete-last($coll);

dml:delete-first($coll);

$available-colls := ddl:available-collections();

$is-available := ddl:is-available-collection($coll);

$content := for $i in dml:collection($coll) return copy $j := $i modify () return $j;

$name := dml:collection-name(dml:collection($coll)[1]);

$available-colls, $is-available, $name, $content
