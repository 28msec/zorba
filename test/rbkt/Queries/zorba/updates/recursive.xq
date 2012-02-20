variable $x:=<y><a/></y>;

insert node <b/> into $x/a;

rename node $x/a/b as "a";

<first>
{
$x//a
}
</first>
