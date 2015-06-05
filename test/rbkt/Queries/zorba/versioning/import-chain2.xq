(: Test that importing a version in the main module and a library module :)
(: raises an error when the versions conflict. :)
import module namespace modA = "http://zorba-tests.28.io/modules/A";
import module namespace vm = "http://zorba-tests.28.io/modules/ver#2.3";

modA:hello()
