(:
  HashJoin
:)

let $auction := doc("auction.xml") return

for $p in $auction/site/people/person
let $a :=
  for $t in $auction/site/closed_auctions/closed_auction
  where xs:string($t/buyer/@person) eq xs:string($p/@id)
  return $t
return <item person="{$p/name/text()}">{count($a)}</item>

(:

HOIST --> HASHJOIN

flwor_expr 
[
  LET  auction (0x80c6318) 
  [
    fn:doc/1 [ const_expr [ auction.xml ] ]
  ]
  LET $$opt_temp_0 (0x80cbd38)
  [
    fn::hoist/1 [ relpath_expr [ auction / site/closes_auctions/closed_auction ] ]
  ]
RETURN
  sequential_expr 
  [
    op-extensions:create/1 
    [
      const_expr [ tempIndex0 ]
    ]
    sequential_expr 
    [
      fn::index-session-opener/1 
      [
        const_expr [ tempIndex0 ]
      ]
      flwor_expr (0x80aef90) 
      [
        FOR $$opt_temp_2 (0x80ae220) AT $$opt_temp_3 (0x80ce608) 
        [
          fn::unhoist/1 [ (0x80cbd38) $$opt_temp_0 ]
        ]
      RETURN
        fn::index-builder/3 (0x80aef28) 
        [
          const_expr (0x80ce670) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
          var kind=FOR (0x80ae220) name=$$opt_temp_2
          cast_expr [AtomicXQType XS_STRING?] (0x80aee88) [
            relpath_expr (0x80aea60) [
              var kind=FOR (0x80ae220) name=$$opt_temp_2
              REL STEP child::match_expr [name_test(buyer)]
              REL STEP attribute::match_expr [name_test(person)]
            ]
          ]
        ]
      ]
      fn::index-session-closer/1 (0x80af050) [
        const_expr (0x80aeff8) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
      ]
    ]
    flwor_expr (0x80d3020) [
      FOR (0x80d30d8) [
        var kind=FOR (0x80c96d8) name=p type=[NodeXQType anyNode content=[XQType UNTYPED_KIND*]]
      IN
        relpath_expr (0x80c9348) [
          var kind=LET (0x80c6318) name=auction type=[NodeXQType documentNode? content=[XQType UNTYPED_KIND*]]
          REL STEP child::match_expr [name_test(site)]
          REL STEP child::match_expr [name_test(people)]
          REL STEP child::match_expr [name_test(person)]
        ]
      ]
      LET (0x80ae5e8) [
        var kind=LET (0x80ae788) name=$$opt_temp_1
      :=
        fn::hoist/1 (0x80ae570) [
          cast_expr [AtomicXQType XS_STRING?] (0x80ce588) [
            relpath_expr (0x80ce358) [
              var kind=FOR (0x80c96d8) name=p type=[NodeXQType anyNode content=[XQType UNTYPED_KIND*]]
              REL STEP attribute::match_expr [name_test(id)]
            ]
          ]
        ]
      ]
    RETURN
      elem_expr (0x80d2d18) [
        const_expr (0x80d2ec8) [AtomicXQType XS_QNAME] [ item ]
        attr_expr (0x80d2cb8) [
          const_expr (0x80d2b48) [AtomicXQType XS_QNAME] [ person ]
        =
          fn::enclosed-expr/1 (0x80d2c50) [
            fn:data/1 (0x80b0fe8) [
              relpath_expr (0x80ce1d0) [
                var kind=FOR (0x80c96d8) name=p type=[NodeXQType anyNode content=[XQType UNTYPED_KIND*]]
                REL STEP child::match_expr [name_test(name)]
                REL STEP child::match_expr [text()]
              ]
            ]
          ]
        ]
        fn::enclosed-expr/1 (0x80d2fb8) [
          fn:count/1 (0x80d2f50) [
            flwor_expr (0x80ce720) [
              FOR (0x80ce7b8) [
                var kind=FOR (0x80cbc30) name=t type=[NodeXQType anyNode content=[XQType UNTYPED_KIND*]]
              IN
                op-extensions:probe-index-point/2 (0x80aee20) [
                  const_expr (0x80ae1c8) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
                  fn::unhoist/1 (0x80ae638) [
                    var kind=LET (0x80ae788) name=$$opt_temp_1
                  ]
                ]
              ]
            RETURN
              var kind=FOR (0x80cbc30) name=t type=[NodeXQType anyNode content=[XQType UNTYPED_KIND*]]
            ]
          ]
        ]
      ]
    ]
  ]
]



HASHJOIN --> HOIST


flwor_expr (0x80c9f18) 
[
  forlet (0x80c9fb0) 
  [
    var kind=LET (0x80bd1d0) name=auction type=[documentNode? content=[EMPTY_KIND?]]
    :=
    fn:doc/1 (0x80bd2c8) [ const_expr (0x80ad410) [XS_STRING] [ auction.xml ] ]
  ]
RETURN
  fn::concatenate/3 (0x80a6460) 
  [
    op-extensions:create/1 (0x80a3fe8) [
      const_expr (0x80a5a20) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
    ]

    sequential_expr (0x80a70e8) 
    [
      fn::index-session-opener/1 (0x80a6930) [
        const_expr (0x80a68d8) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
      ]

      flwor_expr (0x80a6f90) 
      [
        forlet (0x80c9b88) 
        [
          var kind=FOR (0x80a6b88) name=$$opt_temp_0 AT
          var kind=POS (0x80a6bf0) name=$$opt_temp_1
          IN
          relpath_expr (0x80a6998) 
          [
            var kind=LET (0x80bd1d0) name=auction type=[documentNode? ]
            REL STEP child::match_expr [name_test(site)]
            REL STEP child::match_expr [name_test(closed_auctions)]
            REL STEP child::match_expr [name_test(closed_auction)]
          ]
        ]
      RETURN
        fn::index-builder/3 (0x80a6f28) 
        [
          const_expr (0x80a6c58) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
          var kind=FOR (0x80a6b88) name=$$opt_temp_0
          cast_expr [AtomicXQType XS_STRING?] (0x80a6e90) 
          [
            relpath_expr (0x80a6d08) 
            [
              var kind=FOR (0x80a6b88) name=$$opt_temp_0
              REL STEP child::match_expr [name_test(buyer)]
              REL STEP attribute::match_expr [name_test(person)]
            ]
          ]
        ]
      ]

      fn::index-session-closer/1 (0x80a7080) [
        const_expr (0x80a7028) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
      ]
    ]

    flwor_expr (0x80c9e48) 
    [
      forlet (0x80c9ee0) 
      [
        var kind=FOR (0x80c0560) name=p type=[anyNode content=[EMPTY_KIND?]]
        IN
        relpath_expr (0x80c01b8) 
        [
          var kind=LET (0x80bd1d0) name=auction type=[documentNode? content=[EMPTY_KIND?]]
          REL STEP child::match_expr [name_test(site)]
          REL STEP child::match_expr [name_test(people)]
          REL STEP child::match_expr [name_test(person)]
        ]
      ]
    RETURN
      elem_expr (0x80c9b20) 
      [
        const_expr (0x80c9cf0) [AtomicXQType XS_QNAME] [ item ]
        attr_expr (0x80c9ac0) 
        [
          const_expr (0x80c9950) [AtomicXQType XS_QNAME] [ person ]
          =
          fn::enclosed-expr/1 (0x80c9a40) 
          [
            fn:data/1 (0x80abdb0) 
            [
              relpath_expr (0x80c9648) 
              [
                var kind=FOR (0x80c0560) name=p type=[anyNode content=[EMPTY_KIND?]]
                REL STEP child::match_expr [name_test(name)]
                REL STEP child::match_expr [text()]
              ]
            ]
          ]
        ]
        fn::enclosed-expr/1 (0x80c9de0) 
        [
          fn:count/1 (0x80c9d78) 
          [
            flwor_expr (0x80c5470) 
            [
              forlet (0x80c4d10) 
              [
                var kind=FOR (0x80c2ac8) name=t type=[anyNode content=[EMPTY_KIND?]]
                IN
                op-extensions:probe-index-point/2 (0x80a6510) 
                [
                  const_expr (0x80a5a20) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
                  promote_expr [AtomicXQType XS_ANY_ATOMIC?] (0x8098800) 
                  [
                    fn:data/1 (0x8098798) 
                    [
                      relpath_expr (0x80c5180) 
                      [
                        var kind=FOR (0x80c0560) name=p type=[anyNode content=[EMPTY_KIND?]]
                        REL STEP attribute::match_expr [name_test(id)]
                      ]
                    ]
                  ]
                ]
              ]
            RETURN
              var kind=FOR (0x80c2ac8) name=t type=[anyNode content=[EMPTY_KIND?]]
            ]
          ]
        ]
      ]
    ]
  ]
]



:)
