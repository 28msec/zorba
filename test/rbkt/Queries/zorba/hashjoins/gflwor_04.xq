

declare function local:dummy($x as xs:integer)
{
 $x
};


declare function local:foo($x as xs:integer) as xs:integer+
{
  $x * $x,
  local:dummy($x)
};


for $a in (1, 2)
for $x in (<a>1</a>, <a>2</a>, <a>3</a>)
count $w
let $y := 
  for $z in local:foo($a)
  where xs:integer($x) eq $z
  return $z
return (<res>{$x, $w, count($y), sum($y)}</res>, "&#xA;")

(:

Expression tree after optimization for main query
flwor_expr (0x8c202b8)
[
  FOR (0x8c1f0c4) a (0x8c1f044)
  [
    concatenate#2 (0x8c1efe8) [ xs:integer(1)  xs:integer(2) ]
  ]
  LET (0x8c20474) $$opt_temp_0 (0x8c20398)
  [
    hoist#1 (0x8c20418) [ local:foo#1(0x8c1f710) [ vref(0x8c1f6c0) [ a (0x8c1f044) ] ] ]
  ]
  LET (0x8c20ccc) $$opt_temp_4 (0x8c20c4c)
  [
    create-internal-index#2 (0x8c20bf0) [
      const_expr (0x8c2085c) [  xs:QName(,,tempIndex0) ]
      flwor_expr (0x8c20b90)
      [
        FOR (0x8c20a58) $$opt_temp_2 (0x8c20958) AT $$opt_temp_3 (0x8c209d8)
        [
          unhoist#1 (0x8c208ac) [ vref (0x8c20908) [ $$opt_temp_0 (0x8c20398) ] ]
        ]
        RETURN (0x8c20b90)
        [
          value-index-entry-builder#2 (0x8c20b34) [
            vref (0x8c20ae4) [ $$opt_temp_2 (0x8c20958) ]
            vref (0x8c20a94) [ $$opt_temp_2 (0x8c20958) ]
          ]
        ]
      ]
    ]
  ]
  FOR (0x8c1f5d8) x (0x8c1f558)
  [
    concatenate#3 (0x8c1f4fc) [ <a>1</a>, <a>2</a>, <a>3</a> ]
  ]
  LET (0x8c20638) $$opt_temp_1 (0x8c2055c)
  [
    hoist#1 (0x8c205dc) [
      cast_expr xs:integer? (0x8c1f98c) [
        data#1 (0x8c1f930) [ vref (0x8c1f8e0) [ x (0x8c1f558) ] ]
      ]
    ]
  ]
  COUNT  (0x8c1f694) w (0x8c1f614)
  LET (0x8c1fdb8) y (0x8c1fd38)
  [
    flwor_expr (0x8c1fcd8)
    [
      FOR (0x8c1f8a4) z (0x8c1f824)
      [
        probe-index-point-value#2 (0x8c20d08) [
          const_expr (0x8c2085c) [  xs:QName(,,tempIndex0) ]
          unhoist#1 (0x8c206c4) [ vref (0x8c20674) [ $$opt_temp_1 (0x8c2055c) ] ]
        ]
      ]
      RETURN (0x8c1fcd8)
      [
        vref (0x8c1fc88) [ z (0x8c1f824) ]
      ]
    ]
  ]
  RETURN (0x8c202b8)
  [
    concatenate#2 (0x8c2025c) [
      elem_expr (0x8c201fc) [
        copy nodes = 1
        const_expr (0x8c201ac) [  xs:QName(,,res) ]
        enclosed-expr#1 (0x8c20150) [
          concatenate#4 (0x8c200f4) [
            vref (0x8c200a4) [ x (0x8c1f558) ]
            vref (0x8c20054) [ w (0x8c1f614) ]
            count#1 (0x8c1fff8) [ vref (0x8c1ffa8) [ y (0x8c1fd38) ] ]
            sum_integer#1 (0x8c1fe94) [ vref (0x8c1fe44) [ y (0x8c1fd38) ] ]
          ]
        ]
      ]
      const_expr (0x8c1fdf4) [  xs:string(
) ]
    ]
  ]
]


:)
