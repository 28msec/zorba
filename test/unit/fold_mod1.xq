module namespace mod1 = "http://www.zorba-xquery.com/mod1";

import module namespace mod2 = "http://www.zorba-xquery.com/mod2" at "file:///${CMAKE_CURRENT_BINARY_DIR}/fold_mod2.xq";

declare function mod1:wazaa() as element()?
{
  mod2:foo()
};
