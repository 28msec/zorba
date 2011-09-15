
variable $test:=<root><child><childchild><childchildchild/></childchild></child></root>;

(
replace value of node $test/child with "x",
delete node $test//childchildchild
);

$test

