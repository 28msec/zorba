import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx"; 

declare %private function local:private-function()
{
  1
};

sctx:function-annotations(xs:QName("local:private-function"), 0) eq xs:QName("private")
