declare namespace an = "http://www.zorba-xquery.com/annotations";


declare variable $input:=
  for $i in 1 to 1000
  return ({"a":3, "b" : "foo"}, {"a": { "d" : 4}, "c":[1,2,3]});


declare %an:sequential function local:collapse-general($x)
{
   variable $val := [], $obj := [], $arr := [];

   $x ! (typeswitch (.)
         case object() return  { append json . into $obj; }
         case array() return { append json . into $arr; }
         default return { append json . into $val; });

   if (size($val) eq 0)
   then ()
   else ["_VAL", members($val)],

   if (size($obj) eq 0)
   then ()
   else ["_OBJ", local:collapse-objects(members($obj))],

   if (size($arr) eq 0)
   then ()
   else  ["_ARR", local:collapse-general(members($arr) ! members(.)) ]
};


declare %an:sequential function local:collapse-objects($x as object()*)
{
  {| for $y in distinct-values($x ! (keys(.)))
         let $z := $x($y)
         return {$y : local:collapse-general($z)} |}
};

 local:collapse-objects($input),
"
"

