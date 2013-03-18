
import module namespace x="www.xmark.com" at "match_veq_07.xqlib";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";


ddl:create($x:auctions);

iddl:create($x:idx);

dml:insert($x:auctions, doc("auction.xml"));

let $auctions := dml:collection($x:auctions) 
return
  for $p in $auctions/site/people/person
  let $a :=
    for $t in $auctions/site/closed_auctions/closed_auction
    where $t/buyer/@person eq $p/@id
    return $t
  return <item person="{$p/name/text()}">{count($a)}</item>
