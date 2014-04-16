declare namespace an = "http://zorba.io/annotations";

declare %an:exclude-from-cache-key(1) function local:foo($x as xs:integer)
{
};

1