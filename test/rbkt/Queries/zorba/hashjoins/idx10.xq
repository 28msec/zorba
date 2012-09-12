
declare function local:foo() as element()*
{
  for $i in 1 to 10
  return if ($i mod 2 eq 0) then <a id="{$i}"/> else fn:error()
};

declare function local:bar() as element()*
{
  for $i in 1 to 10
  return <b id="{$i}"/>
};


try 
{
  for $i in local:bar()/@id
  for $j in local:foo()/@id
  where xs:string($i) eq xs:string($j)
  return $i
}
catch * 
{
  "caught"
}


(:

Expression tree after optimization for main query
flwor_expr (0x8d66cd0) 
[
  LET (0x8d66c88) $$opt_temp_0 (0x8d66e40)
  [
    hoist/1 (0x8d66c28) [ hoist/1 (0x8d6b298) [ error/0 (0x8d6ae08) [ ] ] ]
  ]
  LET (0x8d66f20) $$opt_temp_1 (0x8d670d8)
  [
    hoist/1 (0x8d66ec0) [
      to/2 (0x8d6afa8) [
        const_expr (0x8d6b008) [ xs:integer [ xs:integer(1) ] ]
        const_expr (0x8d68c48) [ xs:integer [ xs:integer(10) ] ]
      ]
    ]
  ]
  RETURN
    trycatch_expr (0x8d6f258) 
    [
      flwor_expr (0x8d6fca8) 
      [
        FOR (0x8d6b2f8) i (0x8d6e7f8)
        [
          sort-distinct-nodes-asc/1 (0x8d6e690) [
            relpath_expr (0x8d6b238) [
              function_trace_expr (0x8d6f530) [
                flwor_expr (0x8d6b510) 
                [
                  FOR (0x8d6e7b0) i (0x8d6f5f0)
                  [
                    to/2 (0x8d6b578) [
                      const_expr (0x8d6e6f0) [ xs:integer [ xs:integer(1) ] ]
                      const_expr (0x8d6e748) [ xs:integer [ xs:integer(10) ] ]
                    ]
                  ]
                  RETURN
                    elem_expr (0x8d6f4c8) [
                      copy nodes = 1
                      const_expr (0x8d6f690) [ xs:QName [ xs:QName(,,b) ] ]
                      attr_expr (0x8d6f470) [
                        const_expr (0x8d6dd28) [ xs:QName [ xs:QName(,,id) ] ]
                        =
                        enclosed-expr/1 (0x8d6dd80) [
                            var_ref (0x8d6dde0) [ i (0x8d6f5f0) ]
                          ]
                      ]
                    ]
                ]
              ]
                REL STEP attribute::match_expr [name_test(id)]
            ]
          ]
        ]
        LET (0x8d671c8) $$opt_temp_2 (0x8d67030)
        [
          hoist/1 (0x8d67158) [
            cast_expr xs:string? (0x8d6f8a8) [
              data/1 (0x8d6f848) [ var_ref (0x8d6f7b8) [ i (0x8d6e7f8) ] ]
            ]
          ]
        ]
        FOR (0x8d6f770) j (0x8d6f360)
        [
          sort-distinct-nodes-asc/1 (0x8d6f1f8) [
            relpath_expr (0x8d6e8d0) [
              function_trace_expr (0x8d692e0) [
                flwor_expr (0x8d6ada0) 
                [
                  FOR (0x8d69590) $$opt_temp_0 (0x8d69510)
                  [
                    unhoist (0x8d66d90) [ vref(0x8d66d38) [ $$opt_temp_0 (0x8d66e40) ] ]
                  ]
                  FOR (0x8d68d50) i (0x8d68cb0)
                  [
                    unhoist (0x8d66fd0) [ vref (0x8d66f78) [ $$opt_temp_1 (0x8d670d8) ] ]
                  ]
                  RETURN
                    if_expr (0x8d69280) [
                      value-equal-integer/2 (0x8d68d98) [
                        numeric-mod/2 (0x8d68df8) [
                          var_ref (0x8d68e58) [ i (0x8d68cb0) ]
                          const_expr (0x8d68ec0) [ xs:integer [ xs:integer(2) ] ]
                        ]
                        const_expr (0x8d68f28) [ xs:integer [ xs:integer(0) ] ]
                      ]
                      THEN
                        elem_expr (0x8d69150) [
                          copy nodes = 1
                          const_expr (0x8d68f90) [ xs:QName [ xs:QName(,,a) ] ]
                          attr_expr (0x8d690f8) [
                            const_expr (0x8d68fe8) [ xs:QName [ xs:QName(,,id) ] ]
                            =
                              enclosed-expr/1 (0x8d69040) [
                                var_ref (0x8d690a0) [ i (0x8d68cb0) ]
                              ]
                          ]
                        ]
                      ELSE
                        unhoist/1 (0x8d691b8) [
                          var_ref (0x8d69218) [ $$opt_temp_0 (0x8d69510) ]
                        ]
                    ]
                ]
              ]
                REL STEP attribute::match_expr [name_test(id)]
            ]
          ]
        ]
        WHERE
          boolean/1 (0x8d6fbf0) [
            value-equal-string/2 (0x8d6fa10) [
              unhoist/1 (0x8d67268) [
                var_ref (0x8d67210) [ $$opt_temp_2 (0x8d67030) ]
              ]
              cast_expr xs:string? (0x8d6f9b8) [
                data/1 (0x8d6f958) [
                  var_ref (0x8d6f900) [ j (0x8d6f360) ]
                ]
              ]
            ]
          ]
        RETURN
          var_ref (0x8d6fc50) [ i (0x8d6e7f8) ]
      ]
      CATCH 
      const_expr (0x8d6ff10) [ xs:string [ xs:string(caught) ] ]
    ]
]


:)
