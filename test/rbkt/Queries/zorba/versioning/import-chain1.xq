(: Test that importing a version in the main module and a library module :)
(: is OK, so long as the versions don't conflict. :)
import module namespace vm = "http://www.flworfound.org/modules/ver#2.3";
import module namespace modB = "http://www.zorba-xquery.com/modules/B";

modB:hello()
