import module namespace np = "http://zorba.io/modules/node-position";

declare namespace err="http://www.w3.org/2005/xqt-errors";

declare namespace zerr = "http://zorba.io/errors";

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
},

"

",

try
{
np:in-same-tree-of(xs:anyURI("zorba:0.3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333.1.50"),xs:anyURI("zorba:0.0.1.50"))
}
catch * 
{
<err>
<err-code>{$err:code}</err-code>
<err-description>{$err:description}</err-description>
<err-value>{$err:value}</err-value>
<err-line>{$err:line-number}</err-line>
</err>
},

"

",

try
{
np:in-same-tree-of(xs:anyURI("zorba:0..1.50"),xs:anyURI("zorba:0.0.1.50"))
}
catch * 
{
<err>
<err-code>{$err:code}</err-code>
<err-description>{$err:description}</err-description>
<err-value>{$err:value}</err-value>
<err-line>{$err:line-number}</err-line>
</err>
},

"

"

