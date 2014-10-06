let $f := function($nums as xs:integer*, $f1 as function(*)) as xs:integer
          {
            if (empty($nums))
            then 0
            else head($nums) + $f1(tail($nums), $f1)
          }
let $F := $f(?, $f)
return $F(1 to 200)