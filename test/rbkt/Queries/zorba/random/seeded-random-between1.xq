import module namespace r = "http://zorba.io/modules/random";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

count(r:seeded-random-between(1, 1, 1000, 100)) eq 100,

every $i as xs:integer in r:seeded-random-between(1, 1, 1000, 500) 
satisfies ($i ge 1 and $i le 1000),

try
{
  r:seeded-random-between(1, 4, 1, 100)
} catch r:INVALID_ARGUMENT
{
  $err:description, $err:value
}


