declare namespace zann = "http://www.zorba-xquery.com/annotations";
declare namespace zwarn = "http://www.zorba-xquery.com/options/warnings";
declare option zwarn:enable "all";
declare option zwarn:error "ZWST0003";

declare %zann:sequential function local:foo()
{
  1
};

local:foo()

