
variable $doc:=<root>zombie<a>a</a>2<b>b</b>3<c>c</c>4</root>;

variable $debug:=$doc/text()[1];

(
delete node $doc/a,

delete node $doc/text()[1],

replace node $doc/a with ("x")
)
;


(
<delete>{$debug}</delete>,

$doc
)
