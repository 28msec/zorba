import module namespace np = "http://www.zorba-xquery.com/modules/node-position";
declare namespace err="http://www.w3.org/2005/xqt-errors";
declare namespace zerr = "http://www.zorba-xquery.com/errors";
try
{
np:ancestor-of(xs:anyURI("not a uri"),xs:anyURI("not a uri"))
}
catch * 
{
<err>
<err-code>{$err:code}</err-code>
<err-description>{$err:description}</err-description>
<err-value>{$err:value}</err-value>
<err-line>{$err:line-number}</err-line>
</err>
}