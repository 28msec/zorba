import module namespace r = "http://zorba.io/modules/random";

declare namespace zerr = "http://zorba.io/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

count(r:seeded-random(1, 2)) eq 2,

try
{
  r:seeded-random(-1, 1)
} catch zerr:ZXQD0004
{
  $err:description
},

r:seeded-random(1, -1)
