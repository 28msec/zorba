
import module namespace accounts="www.accounts.com" at "match_veq_01.xqlib";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";


declare variable $doc := 
<accounts>
<account name="John" email="john@yahoo.com"/>
<account name="George" email="george@gmail.com"/>
</accounts>;


declare function local:account($email as xs:string?) as element(account)?
{
  dml:collection(xs:QName('accounts:accounts'))[xs:string(@email) eq lower-case($email)]
};


ddl:create(xs:QName("accounts:accounts"));

iddl:create(xs:QName("accounts:accounts-index"));

for $acc in $doc/account
return dml:insert(xs:QName('accounts:accounts'), $acc);

local:account("George@gmail.com")
,
"
"


