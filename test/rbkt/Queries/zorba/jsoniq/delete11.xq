import module namespace j = "http://www.jsoniq.org/functions";

variable $o := 
{
  "foo1" : "bar1",
  "foo2" : "bar2",
  "foo3" : "bar3"
};

delete json $o("foo1");

$o("foo2")
