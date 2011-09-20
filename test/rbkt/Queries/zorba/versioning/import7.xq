(: Test importing a module with an invalid version specification :)

import module namespace bad = "http://www.zorba-xquery.com/modules/bad-ver#1.0";

bad:version()
