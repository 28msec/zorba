(:~
 : XML RPC Client Module
 : This module provides the functions necessary to execute remote call
 : procedures using
 : <a href="http://www.xmlrpc.com/spec" target="_blank">XML-RPC</a>.
 : The application/mashup creator does not need to know the
 : specifics of <a href="http://www.xmlrpc.com/spec" target="_blank">XML-RPC</a> to use this module.
 :
 : Usage:
 : <pre>xmlrpc:invoke("http://www.advogato.org/XMLRPC", "test.sumprod", (5, 7))</pre>
 : <pre>xmlrpc:invoke("http://www.advogato.org/XMLRPC", "test.capitalize", "HelloWorld")</pre>
 : <pre>xmlrpc:invoice("http://www.example.com/XMLRPC", "test.foo", ("some-parameter", 
 :                      &lt;struct&gt;
 :                        &lt;member&gt;
 :                          &lt;name&gt;Foo&lt;/name&gt;
 :                          &lt;value&gt;&lt;string&gt;Bar&lt;/string&gt;&lt;/value&gt;
 :                        &lt;/member&gt;
 :                      &lt;/struct&gt;))</pre>
 :
 : @author William Candillon {william.candillon@28msec.com}
 :
 : @see <a href="http://www.xmlrpc.com/spec" target="_blank">XML-RPC Specification</a>
 : @see <a href="http://en.wikipedia.org/wiki/XML-RPC" target="_blank">XML-RPC Wikipedia article</a> 
 :
 :)
module namespace xmlrpc = "http://www.zorba-xquery.com/modules/xmlrpc";

import module namespace http-client = "http://expath.org/ns/http-client";

import schema namespace http = "http://expath.org/ns/http-client";

(:~
 : XML-RPC serialization error.
 :)
declare variable $xmlrpc:ERR_001 as xs:QName := xs:QName('xmlrpc:ERR_001');

(:~
 :
 : Invoke a remote method with parameters.
 :
 : @param $endpoint-url URL of the XML-RPC server.
 : @param $method Name of the method to invoke.
 : @param $parameters Method parameters. 
 : Struct and Arrays need to follow XML-RPC format.
 : Atomic types will be automatically convert to the
 : proper XML-RPC data format.
 :
 : @see <a href="http://www.xmlrpc.com/spec" target="_blank">http://www.xmlrpc.com/spec</a>
 : 
 : @return Result of the method invocation.
 :)
declare sequential function xmlrpc:invoke(
  $endpoint-url as xs:string,
  $method as xs:string,
  $parameters as item()*)
as item()*
{ 
  declare $request as element(http:request) := <http:request href="{$endpoint-url}" method="POST" />;
  
  xmlrpc:set-method($request);

  xmlrpc:set-content-type($request);
  
  insert node xmlrpc:payload($method, $parameters) into $request/http:body;

  let $response := http-client:send-request($request)
  return
    xmlrpc:result($response[2]);
};


(:~
 : 
 : Invoke a remote method without parameters.
 : Calling this function is equivalent to xmlrpc:invoke($url, $method, ())
 : 
 : @param $endpoint-url URL of the XML-RPC server.
 : @param $method Name of the method to invoke.
 :
 : @see <a href="#invoke-3" target="_blank">xmlrpc:invoke#3</a>
 :
 : @return Result of the method invocation.
 :)
declare sequential function xmlrpc:invoke($endpoint-url as xs:string, $method as xs:string)
{
  xmlrpc:invoke($endpoint-url, $method, ())
};

declare %private updating function xmlrpc:set-method($request as element(http:request))
{
  let $method := attribute method { "POST" }
  return
  if(exists($request/@method)) then
   replace node $request/@method with attribute method { "POST" }
  else
   insert node attribute method { "POST" } into $request
};

declare %private sequential function xmlrpc:set-content-type($request as element(http:request))
{
    if (exists($request/http:body)) then
      delete nodes $request/http:body
    else
      ();

    insert node <http:body media-type="text/xml" method="xml" /> as last into $request;
    $request;
};

declare %private function xmlrpc:payload($method as xs:string, $params as item()*) as element(methodCall)
{
  <methodCall>
    <methodName>{ $method }</methodName>
    {
      if (fn:count($params) gt 0) then
        <params>
        {
          for $param in $params
          return <param>{ xmlrpc:serialize($param) }</param>
        }
        </params>
      else
        ()
    }
  </methodCall>
};

declare %private function xmlrpc:result($body as item()*) as item()*
{
  if (exists($body//fault)) then
      error($xmlrpc:ERR_001, $body//member[/name/text() = "faultString"]//string/text())
    else 
      for $param in $body//param
      return xmlrpc:unserialize($param/value)
};

declare %private function xmlrpc:unserialize($value as element(value)) as item()*
{
  let $child   := $value/*
  let $literal := $value/*/text()
  return
    typeswitch($child)
    case $a as element(int) return xs:integer($literal)
    case $a as element(i4) return xs:integer($literal)
    case $a as element(string) return xs:string($literal)
    case $a as element(boolean) return if($literal = "1") then true() else false()
    case $a as element(double) return xs:double($literal)
    case $a as element(dateTime.iso80601) return xs:dateTime($literal)
    case $a as element(base64) return xs:base64Binary($literal)
    default return $child
};


declare %private function xmlrpc:serialize($value as item())
{
  <value>
  {
    typeswitch($value)
    case $a as element(array) return $value
    case $a as element(struct) return $value
    case $a as element(value) return $value/*
    case $a as xs:integer return <int>{ $value }</int>
    case $a as xs:boolean return <boolean>{ if($value) then 1 else 0 }</boolean>
    case $a as xs:double return <double>{ $value }</double>
    case $a as xs:dateTime return <dateTime.iso8601>{ $value }</dateTime.iso8601>
    case $a as xs:base64Binary return <base64>{ $value }</base64>
    default return <string>{$value}</string>
  }
  </value>
};
