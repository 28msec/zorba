(: Test that we can load a module with external functions and link libs :)

import module namespace link = "http://zorba-tests.28.io/modules/link#1.0";

link:xerces-func(), link:our-func()
