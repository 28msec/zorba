import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare context item := <doc><a/></doc>;

refl:eval("./a")
