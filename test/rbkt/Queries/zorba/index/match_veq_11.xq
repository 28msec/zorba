
import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace ca = 
'http://www.28msec.com/benchmark/lib/custacc' at 'match_veq_11.xqlib';


ddl:create(xs:QName("ca:custaccs"));

ddl:create(xs:QName("ca:orders"));


iddl:create($ca:index-custaccs-str);

iddl:create($ca:index-custaccs-int);


let $orderprice :=
  for $cust in dml:collection($ca:custaccs)[@id eq 4]
  for $acct-id in $cust/Accounts/Account/@id/fn:string(.)
  for $ord in dml:collection($ca:orders)
  where $ord/@Acct = $acct-id
  return $ord/OrdQty/@Cash
return max($orderprice)

