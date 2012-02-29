(: Test that importing a version in the main module and a library module :)
(: raises an error when the versions conflict. :)
import module namespace modA = "http://www.zorba-xquery.com/modules/A";
import module namespace vm = "http://www.flworfound.org/modules/ver#2.3";

modA:hello()
