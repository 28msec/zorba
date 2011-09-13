

variable $y:=<a>c</a>;

(
insert node "a" as first into $y,
insert node "b" before $y/node()[1]
);

$y
