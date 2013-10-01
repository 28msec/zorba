import module namespace sctx = "http://zorba.io/modules/sctx";

declare %private function local:private-function()
{
  1
};

sctx:function-annotations(xs:QName("local:private-function"), 0) eq fn:QName("http://www.w3.org/2012/xquery", "private")
