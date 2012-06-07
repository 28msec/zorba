for $x in 1 to 9
let $kind := $x
group by $kind := $kind mod 3, $even := $kind * ($x mod 2)
return <numbers kind="{$kind}" even="{$even}">{$x}</numbers>


(:

for $x in (1,2,3,4,5,6,7,8,9)
let $kind := $x
let $kind := $kind mode 3,
let $even := $kind * ($x mod 2)
group by $kind := $kind mod 3, $even := $kind * ($x mod 2)
return <numbers kind="{$kind}" even="{$even}">{$x}</numbers>


1,
2,
3,
4,
5,
6,
7,
8,
9,

1, 1
2, 2
3, 3
4, 4
5, 5
6, 6
7, 7
8, 8
9, 9

1, 1,  1, 1
2, 2,  2, 0
3, 3,  0, 0
4, 4,  1, 0
5, 5,  2, 2
6, 6,  0, 0
7, 7,  1, 1
8, 8,  2, 0
9, 9,  0, 0

1, 1 --> 1, 7

2, 0 --> 2, 8

0, 0 --> 3, 6, 9

1, 0 --> 4

2, 2 --> 5

:)
