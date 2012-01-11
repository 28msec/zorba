(:********************** for * where **********foo******** ne **********:)
(: Test: ne  K-ForExprWithout-46            let   eq            $       :)
(:  let Written by: Frans Englich         eq     foo              eq    $  :)
(: Date: 2006-10-05T18:29:37+02:00               where          :)
(:Purpose: Type check: $foo is of type xs:string,  $ which cannot be ne  added to xs:integer 1. :)
(** for **************** ne ***** where ************* let ********* let ****:)
for $foo in"foo" return  eq 1 + $foo