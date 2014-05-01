import module namespace dctx = "http://zorba.io/modules/dctx";

declare function local:foo()
{
  variable $a;
  1
};

dctx:snapshot-id(), local:foo(), dctx:snapshot-id()