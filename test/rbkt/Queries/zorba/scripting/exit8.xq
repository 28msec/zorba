declare namespace an = "http://zorba.io/annotations";

declare %an:sequential function local:test($string as xs:string, $match as xs:string) as xs:boolean
{
  if (fn:contains($string, $match))
  then exit returning true();
  else ();
  
  false()
};

for $project in ("package", "something")
return local:test($project, "package")
