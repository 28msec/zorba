
declare function local:foo() as element()*
{
  for $i in 1 to 10
  return if ($i mod 2 eq 0) then <a id="{$i}"/> else fn:error()
};

declare function local:bar() as element()*
{
  for $i in 1 to 10
  return <b id="{$i}"/>
};


try 
{
  for $i in local:bar()/@id
  for $j in local:foo()/@id
  where xs:string($i) eq xs:string($j)
  return $i
}
catch * 
{
  "caught"
}


(:


:)
