import module namespace coll = 
"http://www.28msec.com/rbkt/collections" at "pos_pred14.xqlib";

import module namespace ddl = 
"http://zorba.io/modules/store/static/collections/ddl";

import module namespace dml = 
"http://zorba.io/modules/store/static/collections/dml";

ddl:create($coll:data);

dml:insert($coll:data, <a>b</a> );

let $entries := dml:collection($coll:data)
let $num_entries := fn:count($entries)
return
  if($num_entries = 0)
  then
    <empty/>
  else
    for $entry in $entries[position() gt -4]
    return $entry
