module namespace foo = "http://www.28msec.com/foo";

declare function foo:test() {
  if (fn:true())
  then 1
  else $a
};
