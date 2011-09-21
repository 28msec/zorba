(: Test that importing a versioned module gets the right version. :)
import module namespace vm = "http://www.zorba-xquery.com/modules/ver#1.3";

vm:version()
