import module namespace file = "http://expath.org/ns/file";
declare namespace ann = "http://zorba.io/annotations";
declare namespace notice = "http://zorba.io/notice";

declare variable $local:path-to-zorba := "/home/federico/zorba/zorba"; 
declare variable $local:zorba-version := "3.1.0";

declare %ann:nondeterministic function local:read-notice-file($dirname as xs:string) as node()?
{
  let $ftxt := fn:concat($dirname, "/NOTICE.xml")
  return
    if(file:is-file($ftxt)) then
      fn:parse-xml(file:read-text($ftxt))
    else
      ()
};

local:read-notice-file("/home/federico/zorba/zorba")