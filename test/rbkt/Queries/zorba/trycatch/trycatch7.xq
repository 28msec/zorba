declare function local:foo()
{
  try {
    1 + 1
  } catch * {
    "err"
  }
};

local:foo()
