import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace j = "http://www.jsoniq.org/functions";

ddl:create(xs:QName("users"));

dml:insert-last(xs:QName("users"),
  (
    {
      "name" : "Deadbeat Jim",
      "address" : "1 E 161st St, Bronx, NY 10451",
      "risk tolerance" : "high"
    }
  )
);

let $dbj := dml:collection(xs:QName("users"))[ .("name") = "Deadbeat Jim" ]
return insert json { "status" : "credit card declined" } into $dbj;

dml:collection(xs:QName("users"))
