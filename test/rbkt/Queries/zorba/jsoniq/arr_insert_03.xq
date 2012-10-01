import module namespace j = "http://jsoniq.org/functions";

declare namespace jerr = "http://jsoniq.org/errors";

variable $a1 := [ 1, 2, 3 ];

try 
{
  insert json ( 1 to 2 ) into $a1 at position -2
} 
catch jerr:JNUP0016
{
  fn:true()
}
,
try 
{
  insert json ( 1 to 2 ) into $a1 at position 5
} 
catch jerr:JNUP0016
{
  fn:true()
}
,
try 
{
  insert json ( 1 to 2 ) into $a1 at position -1
} 
catch jerr:JNUP0016 
{
  fn:true()
}
,
try 
{
  insert json ( 1 to 2 ) into $a1 at position 4
}
catch jerr:JNUP0016 
{
  fn:false()
}

