

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

flwor_expr (0x812cda0)
[
  FOR (0x812bad8) a (0x812ba54)
  [
    concatenate/2 (0x812b9f4) [ 1, 2 ]
  ]
  FOR (0x812c028) x (0x812bfa4)
  [
    concatenate/3 (0x812bf44) [
      elem_expr (0x812bee0) [
        const_expr (0x812be8c) [  xs:QName(,,a) ]
        text_expr (0x812be34) [ const_expr (0x812bde0) [  xs:string(1) ] ]
      ]
      elem_expr (0x812bd7c) [
        const_expr (0x812bd28) [  xs:QName(,,a) ]
        text_expr (0x812bcd0) [ const_expr (0x812bc7c) [  xs:string(2) ] ]
      ]
      elem_expr (0x812bc18) [
        const_expr (0x812bbc4) [  xs:QName(,,a) ]
        text_expr (0x812bb6c) [ const_expr (0x812bb18) [  xs:string(3) ] ]
      ]
    ]
  ]
  COUNT  (0x812c0ec) w (0x812c068)
  LET (0x812c864) y (0x812c7e0)
  [
    flwor_expr (0x812c77c)
    [
      FOR (0x812c314) z (0x812c290)
      [
        local:foo/1 (0x812c170) [ vref (0x812c11c) [ a (0x812ba54) ] ]
      ]
      WHERE (0x812c77c)
      [
        boolean/1 (0x812c698) [
          value-equal-integer/2 (0x812c4b8) [
            cast_expr xs:integer? (0x812c408) [
              data/1 (0x812c3a8) [ vref (0x812c354) [ x (0x812bfa4) ] ]
            ]
            vref (0x812c464) [ z (0x812c290) ]
          ]
        ]
      ]
      RETURN (0x812c77c)
      [
        vref (0x812c728) [ z (0x812c290) ]
      ]
    ]
  ]
  RETURN (0x812cda0)
  [
    concatenate/2 (0x812cd40) [
      elem_expr (0x812ccdc) [
        copy nodes = 0
        const_expr (0x812cc88) [  xs:QName(,,res) ]
        enclosed-expr/1 (0x812cc28) [
          concatenate/4 (0x812cbc8) [
            vref (0x812cb74) [ x (0x812bfa4) ]
            vref (0x812cb20) [ w (0x812c068) ]
            count/1 (0x812cac0) [
              vref (0x812ca6c) [ y (0x812c7e0) ]
            ]
            sum_integer/1 (0x812c94c) [
              vref (0x812c8f8) [ y (0x812c7e0) ]
            ]
          ]
        ]
      ]
      const_expr (0x812c8a4) [  xs:string(
) ]
    ]
  ]
]

:)
