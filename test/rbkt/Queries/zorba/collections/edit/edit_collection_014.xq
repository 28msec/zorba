import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("dml:collection"));

dml:insert-first(xs:QName("dml:collection"), <foo>1</foo> );

dml:edit(dml:collection(xs:QName("dml:collection")), <foo attr="value">test</foo>);

dml:collection(xs:QName("dml:collection"))
