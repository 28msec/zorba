
variable $test:=<root><child><childchild/></child></root>;

(
replace value of node $test/child with "x",

delete node $test/child/childchild
);

$test

