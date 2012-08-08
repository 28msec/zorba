
variable $doc := <foo a="1"/>;

variable $a := [ 1, 2, 3, 4 ];

try
{
(
insert json [4, 5] into $a at position 3,
delete json $a(3),
insert json [10, 15] into $a at position 4,

insert node $doc/@a into $doc
);
}
catch *
{
}

$a
