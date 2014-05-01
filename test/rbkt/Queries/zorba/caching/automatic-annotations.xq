declare namespace an = "http://zorba.io/annotations";

declare variable $local:x := ();

declare function local:not-cached-1() 
{
  if ($local:x) then local:not-cached-1() else ()
};

declare function local:not-cached-2($x as node()) as object() 
{
  if ($local:x) then local:not-cached-2($x) else {||}
};

declare function local:not-cached-3($x as xs:integer) as object() 
{
  if ($local:x) then local:not-cached-3($x) else {||}
};

declare function local:not-cached-4($x as object()) as xs:integer 
{
  if ($local:x) then local:not-cached-4($x) else 1
};

declare function local:not-cached-5($x as xs:integer, $y) as xs:integer 
{
  if ($local:x) then local:not-cached-5($x,$y) else 1
};

declare %an:sequential function local:not-cached-6($x as xs:integer) as xs:integer 
{
  delete node <x/>;
  if ($local:x) then local:not-cached-6($x) else 1
};

declare %an:nondeterministic function local:not-cached-7($x as xs:integer) as xs:integer 
{
  if ($local:x) then local:not-cached-7($x) else 1
};

declare %an:deterministic function local:not-cached-8($x as xs:integer) as xs:integer 
{
  if ($local:x) then local:not-cached-8($x) else 1
};

declare updating function local:not-cached-9($x as xs:integer) 
{
  if ($local:x) then local:not-cached-9($x) else delete node <x/>
};

declare updating function local:not-cached-10($x as xs:integer) 
{
  if ($local:x) then local:not-cached-10($x) else ()
};

(: The return type is item :)
declare function local:not-cached-11($v as xs:double*, $stride as xs:integer, $remaining as xs:integer, $offset as xs:integer)
{
  if ($remaining le $stride)
  then <a/>
  else 
    for $x at $p in local:not-cached-11($v, $stride, $remaining - $stride, $offset + $stride)
    return $x + $v[$offset + $p]
};

declare %an:variadic function local:not-cached-12($x as xs:integer) as xs:integer 
{
  if ($local:x) then local:not-cached-12($x) else 1
};

declare function local:cached-1($x as xs:integer) as xs:integer
{
  if ($local:x) then local:cached-1($x) else 1
};

declare function local:cached-2($x as xs:integer?, $y as xs:integer+, $z as xs:integer*) as xs:integer? 
{
  if ($local:x) then local:cached-2($x,$y,$z) else ()
};

declare function local:cached-3($x as empty-sequence()) as empty-sequence()
{
  if ($local:x) then local:cached-3($x) else ()
};

declare %an:strictlydeterministic function local:cached-4($x, $y, $z) 
{
  if ($local:x) then local:cached-4($x,$y,$z) else ()
};

declare %an:cache function local:cached-5($x, $y, $z) 
{
  if ($local:x) then local:cached-5($x,$y,$z) else ()
};

(: The return type can be statically determined as atomic :)
declare function local:cached-6($v as xs:double*, $stride as xs:integer, $remaining as xs:integer, $offset as xs:integer)
{
  if ($remaining le $stride)
  then subsequence($v, $offset + 1)
  else 
    for $x at $p in local:cached-6($v, $stride, $remaining - $stride, $offset + $stride)
    return $x + $v[$offset + $p]
};

local:not-cached-1();
local:not-cached-2(<x/>);
local:not-cached-3(1);
local:not-cached-4({||});
local:not-cached-5(1,1);
local:not-cached-6(1);
local:not-cached-7(1);
local:not-cached-8(1);
local:not-cached-9(1);
local:not-cached-10(1);
local:not-cached-11(xs:double(0), 2, 1, 1);
local:not-cached-12(1);
local:cached-1(1);
local:cached-2(1, 1, 1);
local:cached-3(());
local:cached-4((),(),());
local:cached-5((),(),());
local:cached-6(xs:double(0), 2, 1, 1);

1