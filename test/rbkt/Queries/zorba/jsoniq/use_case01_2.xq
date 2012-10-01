import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace j = "http://jsoniq.org/functions";

ddl:create(xs:QName("users"));

dml:insert-last(xs:QName("users"),
  (
    {
      "name" : "Sarah",
      "age" : 13,
      "gender" : "female",
      "friends" : [ "Jim", "Mary", "Jennifer"]
    },
    
    {
      "name" : "Jim",
      "age" : 13,
      "gender" : "male",
      "friends" : [ "Sarah" ]
    }
  )
);



let $sarah := dml:collection(xs:QName("users"))[.("name") = "Sarah"]
for $friend in j:members($sarah("friends"))
return dml:collection(xs:QName("users"))[.("name") = $friend]
