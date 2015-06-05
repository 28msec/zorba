(: Test importing a module with an invalid version specification :)

import module namespace bad = "http://zorba-tests.28.io/modules/bad-ver#1.0";

bad:version()
