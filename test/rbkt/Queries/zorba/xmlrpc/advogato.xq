import module namespace xmlrpc = "http://www.zorba-xquery.com/modules/xmlrpc";

let $sumprod    := xmlrpc:invoke("http://www.advogato.org/XMLRPC", "test.sumprod", (5, 7))
let $capitalize := xmlrpc:invoke("http://www.advogato.org/XMLRPC", "test.capitalize", "HelloWorld")
let $strlen     := xmlrpc:invoke("http://www.advogato.org/XMLRPC", "test.strlen", "HelloWorld")
let $guess      := xmlrpc:invoke("http://www.advogato.org/XMLRPC", "test.guess")
return
<results>
  <result id="sumprod">
{$sumprod}
  </result>
  <result id="capitalize">
{$capitalize}
  </result>
  <result id="strlen">
{$strlen}
  </result>
  <result id="guess">
{$guess}
  </result>
</results>
