import module namespace ddl = "http://www.zorba-xquery.com/modules/store/jsoniq/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/jsoniq/dynamic/collections/dml";
import module namespace j = "http://www.jsoniq.org/functions";

ddl:create(xs:QName("users"));

dml:insert-nodes-last(xs:QName("users"),
  (
    {
      "name" : "Deadbeat Jim",
      "address" : "1 E 161st St, Bronx, NY 10451",
      "risk tolerance" : "high"
    }
  )
);

let $dbj := dml:collection(xs:QName("users"))[ .("name") = "Deadbeat Jim" ]
return j:insert-into($dbj, pair { "status" : "credit card declined" });

dml:collection(xs:QName("users"))
