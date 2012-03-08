declare namespace http = "http://www.28msec.com/modules/http";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $http:var := "";

declare %ann:sequential function http:set-header(
    $name as xs:string,
    $value as xs:string)
as xs:string?
{
  let $lc-name := fn:lower-case($name)
  return
    if ($lc-name eq "status" or
        $lc-name eq "set-cookie" or
        $lc-name eq "content-type")
    then
      fn:error(
        xs:QName("http:invalid-header-name"),
        concat($name, ": invalid header name")
      )
    else
      http:set-header-impl($name, $value)
};

(:~
 : <p>Set a HTTP header in the response.</p>
 :
 : <p>
 :`
 : @return The empty-sequence is returned.
 :)
declare %fn:private %ann:sequential function http:set-header-impl(
    $name as xs:string,
    $value as xs:string)
as xs:string? { 
  $http:var := "val"; 
};

http:set-header("foo", "bar")
