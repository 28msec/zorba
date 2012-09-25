import module namespace j = "http://jsoniq.org/functions";

let $users :=
  [
    { "userid" : "W0342", "firstname" : "Walter", "lastname" : "Denisovich" },
    { "userid" : "M0535", "firstname" : "Mick", "lastname" : "Goulish" }
  ]
let $holdings :=
  [
    { "userid" : "W0342", "ticker" : "DIS", "shares" : 153212312 },
    { "userid" : "M0535", "ticker" : "DIS", "shares" : 10 },
    { "userid" : "M0535", "ticker" : "AIG", "shares" : 23412 }
  ]
return
  [
    for $u in j:members($users)
    order by $u("userid")
    return {
      "userid" : $u("userid"),
      "first" :  $u("firstname"),
      "last" :   $u("lastname"),
      "holdings" : [
           for $h in j:members($holdings)
           where $h("userid") = $u("userid")
           order by $h("ticker")
           return {
              "ticker" : $h("ticker"),
              "share" : $h("shares")
           }
      ]
    }
  ]

