declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $global := 0;

declare %ann:sequential function local:do-seq($num)
{
    $global := $global + 1;
    $num mod 2
};

(
    for $x in 1 to 9
    group by $cat := local:do-seq($x), $cat := $x mod 3
    return <grp cat="{$cat}">{$x}</grp>
,
    $global
)
