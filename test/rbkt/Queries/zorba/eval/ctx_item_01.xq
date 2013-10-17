import module namespace refl = "http://zorba.io/modules/reflection";

declare context item := <doc><a/></doc>;

refl:eval("./a")
