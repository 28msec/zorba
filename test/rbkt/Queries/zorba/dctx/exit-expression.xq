import module namespace dctx = "http://zorba.io/modules/dctx";
declare namespace an = "http://zorba.io/annotations";

declare %an:sequential function local:test()
{
    exit returning dctx:snapshot-id();
};

dctx:snapshot-id(), local:test(), dctx:snapshot-id()