

declare variable $x external;


declare variable $sales := 
<sales>
<sale pid="3" locid="5" qty="3" date="2013-01-01"/>
<sale pid="3" locid="5" qty="5" date="2013-01-02"/>
<sale pid="2" locid="4" qty="1" date="2013-01-01"/>
<sale pid="2" locid="4" qty="1" date="2014-01-01"/>
<sale pid="2" locid="7" qty="1" date="2014-01-01"/>
</sales>;

declare variable $locations := 
<locations>
<loc id="5" city="paris"/>
<loc id="4" city="san fransisco"/>
<loc id="7" city="chania"/>
</locations>;


try
{
  $x * $x
}
catch *
{
  for $s in $sales/sale
  for $l in $locations/loc
  where $s/@locid eq $l/@id
  return <sale>{$l/@city}</sale> 
}


(:

path-1.1 = 0xbfffeac0 prev = NULL theExpr = NULL

path-2.1 = 0xbfffe9f8 prev = NULL theExpr = NULL

path-2.2 = 0xbfffe8d8 prev = 0xbfffe9f8 theExpr = 0x8125c88


  trycatch_expr (0x8125c88) 
  [
    multiply#2 (0x8125aa8) [
      promote_expr xs:anyAtomicType? (0x8125b68) [
        data#1 (0x8125b08) [
          vref (0x8125a00) [ x (0x81229c4) ]
        ]
      ]
      promote_expr xs:anyAtomicType? (0x8125c28) [
        data#1 (0x8125bc8) [
          vref (0x8125a54) [ x (0x81229c4) ]
        ]
      ]
    ]
    CATCH 
    flwor_expr (0x8134404)
    [
      FOR (0x8126610) s (0x812658c)
      [
        relpath_expr (0x812634c) [
          vref (0x81263a8) [ sales (0x8122a48) ]
            REL STEP child::match_expr [name_test(sale)]
        ]
      ]
      FOR (0x813397c) l (0x81338f8)
      [
        relpath_expr (0x8126650) [
          vref (0x81266ac) [ locations (0x8122acc) ]
            REL STEP child::match_expr [name_test(loc)]
        ]
      ]
      WHERE (0x8134404)
      [
        boolean#1 (0x813401c) [
          value-equal#2 (0x8133e3c) [
            promote_expr xs:anyAtomicType? (0x8133efc) [
              data#1 (0x8133e9c) [
                relpath_expr (0x81339bc) [
                  vref (0x8133a18) [ s (0x812658c) ]
                    REL STEP attribute::match_expr [name_test(locid)]
                ]
              ]
            ]
            promote_expr xs:anyAtomicType? (0x8133fbc) [
              data#1 (0x8133f5c) [
                relpath_expr (0x8133bfc) [
                  vref (0x8133c58) [ l (0x81338f8) ]
                    REL STEP attribute::match_expr [name_test(id)]
                ]
              ]
            ]
          ]
        ]
      ]
      RETURN (0x8134404)
      [
        elem_expr (0x81343a0) [
          copy nodes = 0
          const_expr (0x813434c) [  xs:QName(,,sale) ]
          enclosed-expr#1 (0x81342ec) [
            relpath_expr (0x81340ac) [
              vref (0x8134108) [ l (0x81338f8) ]
                REL STEP attribute::match_expr [name_test(city)]
            ]
          ]
        ]
      ]
    ]
  ]

:)
