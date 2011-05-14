import module namespace dyn = "http://www.zorba-xquery.com/modules/store/collections";


declare variable $coll := xs:QName("dyn:coll1");

declare variable $available-colls := ();
declare variable $is-available := ();
declare variable $content := ();
declare variable $name := ();

dyn:create-collection($coll);
dyn:insert-nodes-first($coll, for $i  in 1 to 10 return <b>{$i}</b>);
dyn:insert-nodes-last($coll, for $i  in 1 to 10 return <c>{$i}</c>);
dyn:insert-nodes-before($coll, dyn:collection($coll)[2], for $i  in 1 to 10 return <d>{$i}</d>);
dyn:insert-nodes-after($coll, dyn:collection($coll)[2], for $i  in 1 to 10 return <e>{$i}</e>);
dyn:delete-nodes(dyn:collection($coll)[last()-2]);
dyn:delete-node-last($coll);
dyn:delete-node-first($coll);
$available-colls := dyn:available-collections();
$is-available := dyn:is-available-collection($coll);
$content := for $i in dyn:collection($coll) return copy $j := $i modify () return $j;
$name := dyn:collection-name(dyn:collection($coll)[1]);
$available-colls, $is-available, $name, $content
