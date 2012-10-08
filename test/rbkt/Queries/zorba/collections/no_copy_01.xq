import module namespace db = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

declare namespace ext = "http://www.zorba-xquery.com/extensions";

ddl:create(xs:QName("local:bar"));

(: needs to copy because $n is used twice and the constructor is not inlined => false:)
let $n := <a/>
return $n is db:apply-insert-last(xs:QName("local:bar"), $n),

(: doesn't need to copy because the pragma is used => true :)
let $n := <a/>
return (# ext:no-copy #) { $n is  db:apply-insert-last(xs:QName("local:bar"), $n) }
