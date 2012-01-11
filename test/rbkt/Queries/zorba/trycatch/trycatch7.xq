declare namespace err="http://www.w3.org/2005/xqt-errors";
declare function local:foo()
{
  try {
    1 + 1
  } catch * {
    "err"
  }
};

local:foo()
