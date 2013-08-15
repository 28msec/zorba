declare namespace zann = "http://zorba.io/annotations";
declare namespace zwarn = "http://zorba.io/options/warnings";
declare option zwarn:enable "all";
declare option zwarn:error "ZWST0003";

declare %zann:sequential function local:foo()
{
  1
};

local:foo()

