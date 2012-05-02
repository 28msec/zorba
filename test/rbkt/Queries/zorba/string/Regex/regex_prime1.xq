
declare function local:string-1-n($nr as xs:integer) as xs:string
{
  if($nr eq 0) then
    ""
  else 
    concat("1", local:string-1-n($nr - 1))
};

declare function local:is-prime($nr as xs:integer) as xs:boolean
{
  let $str1 := local:string-1-n($nr)
  return
    fn:not(fn:matches($str1, "^(11+)\1+$"))
};

(local:is-prime(13), local:is-prime(24))
