
variable $doc:=<root>root-a<a/>a-b<b/>b-c<c/>c-d<d/>d-root</root>;

variable $a:=();

variable $b:=();

$a := count($doc/text());

replace node $doc/b with ();

$b := count($doc/text());

<result>rep-empty: before: {$a}, after: {$b}, expected {$a - 1}</result>
