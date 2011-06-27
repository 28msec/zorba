(: Test that we can load a module with external functions and link libs :)

import module namespace link = "http://www.zorba-xquery.com/modules/link#1.0";

link:xerces-func(), link:our-func()
