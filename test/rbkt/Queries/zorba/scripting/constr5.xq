import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

(: test call to a side-effecting function in an element constructor :)
element book {
   element title { ddl:create(fn:QName("foo:bar", "blub")) ; "Harold and the Purple Crayon" },
   element blub { dml:apply-insert-nodes-last(fn:QName("foo:bar", "blub"), <blub2/>) }
}
