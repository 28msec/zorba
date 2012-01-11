(:
  HashJoin
:)

let $auction := doc("auction.xml") return

for $p in $auction/site/people/person
for $a in $auction/site/closed_auctions
for $t in $a/closed_auction
where $t/buyer/@person eq $p/@id
return <item person="{$p/name/text()}">{$t}</item>


(:

-----------------------------

HOIST --> HASHJOIN


flwor_expr (0x80d2e90) [
  LET (0x80d2ef8) [
    var kind=LET (0x80c6118) name=auction 
    :=
    fn:doc/1 (0x80c6210) [
      const_expr (0x80b6388) [AtomicXQType XS_STRING] [ auction.xml ]
    ]
  ]
  LET (0x80ae288) [
    var kind=LET (0x80c95d8) name=$$opt_temp_0
    :=
    fn::hoist/1 (0x80ae220) [
      relpath_expr (0x80cb6d8) [
        var kind=LET (0x80c6118) name=auction 
        REL STEP child::match_expr [name_test(site)]
        REL STEP child::match_expr [name_test(closed_auctions)]
      ]
    ]
  ]
RETURN
  sequential_expr (0x80aec00) 
  [
    op-extensions:create/1 (0x80aeae8) 
    [
      const_expr (0x80ae790) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
    ]

    sequential_expr (0x80af1e8) 
    [
      fn::index-session-opener/1 (0x80d06e0) 
      [
        const_expr (0x80aec70) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
      ]
      flwor_expr (0x80af0c0) 
      [
        FOR (0x80aea68) 
        [
          var kind=FOR (0x80ae998) name=$$opt_temp_3
          IN
          relpath_expr (0x80b1050) [
            fn::unhoist/1 (0x80ad930) [
              var kind=LET (0x80c95d8) name=$$opt_temp_0
            ]
            REL STEP child::match_expr [name_test(closed_auction)]
          ]
        ]
      RETURN
        fn::index-builder/3 (0x80af058) 
        [
          const_expr (0x80aed48) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
          var kind=FOR (0x80ae998) name=$$opt_temp_3
          cast_expr [AtomicXQType XS_STRING?] (0x80aefa0) 
          [
            relpath_expr (0x80aee18) [
              var kind=FOR (0x80ae998) name=$$opt_temp_3
              REL STEP child::match_expr [name_test(buyer)]
              REL STEP attribute::match_expr [name_test(person)]
            ]
          ]
        ]
      ]
      fn::index-session-closer/1 (0x80af180) 
      [
        const_expr (0x80af128) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
      ]
    ]

    flwor_expr (0x80d2cc8) 
    [
      FOR (0x80d2e38) 
      [
        var kind=FOR (0x80c94d8) name=p 
        IN
        relpath_expr (0x80c9148) [
          var kind=LET (0x80c6118) name=auction 
          REL STEP child::match_expr [name_test(site)]
          REL STEP child::match_expr [name_test(people)]
          REL STEP child::match_expr [name_test(person)]
        ]
      ]
      LET (0x80ae660) 
      [
        var kind=LET (0x80ae4d0) name=$$opt_temp_2
        :=
        fn::hoist/1 (0x80ae5e8) [
          fn:data/1 (0x80b0f80) [
            relpath_expr (0x80d0678) [
              var kind=FOR (0x80c94d8) name=p 
              REL STEP child::match_expr [name_test(name)]
              REL STEP child::match_expr [text()]
            ]
          ]
        ]
      ]
      LET (0x80ae3e0) 
      [
        var kind=LET (0x80ae580) name=$$opt_temp_1
        :=
        fn::hoist/1 (0x80ae368) [
          cast_expr [AtomicXQType XS_STRING?] (0x80d0618) [
            relpath_expr (0x80d03d8) [
              var kind=FOR (0x80c94d8) name=p 
              REL STEP attribute::match_expr [name_test(id)]
            ]
          ]
        ]
      ]
      FOR (0x80d2de0) 
      [
        var kind=FOR (0x80cb930) name=a 
        IN
        fn::unhoist/1 (0x80ae300) [
          var kind=LET (0x80c95d8) name=$$opt_temp_0
        ]
      ]
      FOR (0x80d2d78) 
      [
        var kind=FOR (0x80cdcc0) name=t 
        IN
        op-extensions:probe-index-point/2 (0x80aece0) [
          const_expr (0x80ae790) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
          fn::unhoist/1 (0x80ae458) [
            var kind=LET (0x80ae580) name=$$opt_temp_1
          ]
        ]
      ]
    RETURN
      elem_expr (0x80d2c60) [
        const_expr (0x80d2c08) [AtomicXQType XS_QNAME] [ item ]
        attr_expr (0x80d2a48) [
          const_expr (0x80d2958) [AtomicXQType XS_QNAME] [ person ]
        =
          fn::enclosed-expr/1 (0x80d2ae0) [
            fn::unhoist/1 (0x80ae6b0) [
              var kind=LET (0x80ae4d0) name=$$opt_temp_2
            ]
          ]
        ]
        fn::enclosed-expr/1 (0x80d2ba0) [
          var kind=FOR (0x80cdcc0) name=t 
        ]
      ]
    ]
  ]
]


-----------------------------

HASHJOIN --> HOIST


Expression tree after optimization for query
flwor_expr (0x80c9cb0) 
[
  forlet (0x80c9d48) 
  [
    var kind=LET (0x80bcfc8) name=auction type=[documentNode? content=[EMPTY_KIND?]]
    :=
    fn:doc/1 (0x80bd0c0) [ const_expr (0x80ad228) [XS_STRING] [ auction.xml ] ]
  ]
  forlet (0x80a5e40) 
  [
    var kind=LET (0x80a5ff0) name=$$opt_temp_2
    :=
    fn::hoist/1 (0x80a5dd8) 
    [
      relpath_expr (0x80c2550) 
     [
        var kind=LET (0x80bcfc8) name=auction type=[documentNode? content=[EMPTY_KIND?]]
        REL STEP child::match_expr [name_test(site)]
        REL STEP child::match_expr [name_test(closed_auctions)]
      ]
    ]
  ]
RETURN
  fn::concatenate/3 (0x80acac8) 
  [
    op-extensions:create/1 (0x80ac910) [
      const_expr (0x80ac8b8) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
    ]

    sequential_expr (0x80a6d20) 
    [
      fn::index-session-opener/1 (0x80a64b0) [
        const_expr (0x80a6458) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
      ]

      flwor_expr (0x80a6bc8) 
      [
        forlet (0x80a6180) 
        [
          var kind=FOR (0x80a67c0) name=$$opt_temp_0 AT
          var kind=POS (0x80a6828) name=$$opt_temp_1
          IN
          relpath_expr (0x80a6518) 
          [
            relpath_expr (0x80a6578) 
            [
              var kind=LET (0x80bcfc8) name=auction type=[documentNode? content=[EMPTY_KIND?]]
              REL STEP child::match_expr [name_test(site)]
              REL STEP child::match_expr [name_test(closed_auctions)]
            ]
            REL STEP child::match_expr [name_test(closed_auction)]
          ]
        ]
      RETURN
        fn::index-builder/3 (0x80a6b60) 
        [
          const_expr (0x80a6890) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
          var kind=FOR (0x80a67c0) name=$$opt_temp_0
          cast_expr [AtomicXQType XS_STRING?] (0x80a6ac8) 
          [
            relpath_expr (0x80a6940) 
            [
              var kind=FOR (0x80a67c0) name=$$opt_temp_0
              REL STEP child::match_expr [name_test(buyer)]
              REL STEP attribute::match_expr [name_test(person)]
            ]
          ]
        ]
      ]

      fn::index-session-closer/1 (0x80a6cb8) [
        const_expr (0x80a6c60) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
      ]
    ]

    flwor_expr (0x80c9b40) 
    [
      forlet (0x80c9c78) 
      [
        var kind=FOR (0x80c0358) name=p type=[anyNode content=[XQType EMPTY_KIND?]]
        IN
        relpath_expr (0x80bffb0) 
        [
          var kind=LET (0x80bcfc8) name=auction type=[documentNode? content=[EMPTY_KIND?]]
          REL STEP child::match_expr [name_test(site)]
          REL STEP child::match_expr [name_test(people)]
          REL STEP child::match_expr [name_test(person)]
        ]
      ]
      forlet (0x80a6148) 
      [
        var kind=LET (0x80a62e8) name=$$opt_temp_4
        :=
        fn::hoist/1 (0x80a60d0) 
        [
          fn:data/1 (0x80a7fe8) 
          [
            relpath_expr (0x80c73f8) 
            [
              var kind=FOR (0x80c0358) name=p type=[anyNode content=[EMPTY_KIND?]]
              REL STEP child::match_expr [name_test(name)]
              REL STEP child::match_expr [text()]
            ]
          ]
        ]
      ]
      forlet (0x80a3de0)
      [
        var kind=LET (0x80a5e78) name=$$opt_temp_3
        :=
        fn::hoist/1 (0x80a5f60) 
        [
          op-extensions:probe-index-point/2 (0x80a5948) 
          [
            const_expr (0x80ac8b8) [AtomicXQType XS_ANY_URI] [ tempIndex0 ]
            promote_expr [AtomicXQType XS_ANY_ATOMIC?] (0x80a7e80) 
            [
              fn:data/1 (0x80a7e18) 
              [
                relpath_expr (0x80c71f0) 
                [
                  var kind=FOR (0x80c0358) name=p type=[anyNode content=[EMPTY_KIND?]]
                  REL STEP attribute::match_expr [name_test(id)]
                ]
              ]
            ]
          ]
        ]
      ]
      forlet (0x80c9c30) 
      [
        var kind=FOR (0x80c27b8) name=a type=[anyNode content=[XQType EMPTY_KIND?]]
        IN
        fn::unhoist/1 (0x80a5ef8) [var kind=LET (0x80a5ff0) name=$$opt_temp_2]
      ]
      forlet (0x80c9be8) 
      [
        var kind=FOR (0x80c4b48) name=t type=[anyNode content=[XQType EMPTY_KIND?]]
      IN
        fn::unhoist/1 (0x80a6058) [var kind=LET (0x80a5e78) name=$$opt_temp_3]
      ]
    RETURN
      elem_expr (0x80c9ad8) [
        const_expr (0x80c9a60) [AtomicXQType XS_QNAME] [ item ]
        attr_expr (0x80c98d0) [
          const_expr (0x80c9760) [AtomicXQType XS_QNAME] [ person ]
        =
          fn::enclosed-expr/1 (0x80c9850) [
            fn::unhoist/1 (0x80a6228) [
              var kind=LET (0x80a62e8) name=$$opt_temp_4
            ]
          ]
        ]
        fn::enclosed-expr/1 (0x80c99f8) [
          var kind=FOR (0x80c4b48) name=t type=[NodeXQType anyNode content=[XQType EMPTY_KIND?]]
        ]
      ]
    ]
  ]
]

:)


