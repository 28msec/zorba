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

for $sarah in dml:collection(xs:QName("users")),
    $friend in dml:collection(xs:QName("users"))
 where $sarah("name") = "Sarah"
  and (some $name in j:members($sarah("friends"))
      satisfies $friend("name") = $name)
return $friend
