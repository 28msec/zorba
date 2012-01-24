
declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";


declare function local:dummy($x as xs:integer) as xs:integer
{
  $x
};


declare function local:parent($n as node()) as node()
{
  local:dummy(2);

  $n/..
};


declare function local:foo($n as node()) as node()
{
  for $child in $n/b
  return local:parent($child)
};


variable $d1 := <a><b><c/></b></a>;

variable $d2 := <a><b><c/></b></a>;

local:foo($d1),
local:foo($d2)



(:


Optimizing main program
After MarkExprs :
block_expr (0x82f4c08) 
[
  var_decl_expr (0x82f39f0) 
  [
    var kind=LOCAL (0x82f3970) name=d1
    elem_expr (0x82f3af8) 
    [
      copy nodes = 0
      const_expr (0x82f3e98) [ xs:QName [ xs:QName(,,a) ] ]
      elem_expr (0x82f3e30) [
        copy nodes = 0
        const_expr (0x82f3c20) [ xs:QName [ xs:QName(,,b) ] ]
        elem_expr (0x82f3fb0) [
          copy nodes = 0
          const_expr (0x82f3f58) [ xs:QName [ xs:QName(,,c) ] ]
        ]
      ]
    ]
  ]

  var_decl_expr (0x82f4018) 
  [
    var kind=LOCAL (0x82f3a58) name=d2
    elem_expr (0x82f47a0) [
      copy nodes = 0
      const_expr (0x82f4748) [ xs:QName [ xs:QName(,,a) ] ]
      elem_expr (0x82f48a8) [
        copy nodes = 0
        const_expr (0x82f4850) [ xs:QName [ xs:QName(,,b) ] ]
        elem_expr (0x82f4958) [
          copy nodes = 0
          const_expr (0x82f4120) [ xs:QName [ xs:QName(,,c) ] ]
        ]
      ]
    ]
  ]

  concatenate/2 (0x82f4ba8) 
  [
    local:foo/1 (0x82f4ae0) 
    [
      treat_expr [NodeXQType anyNode content=[XQType ANY_TYPE_KIND*]] (0x82f4b40) [
        var_ref (0x82f4a88) [ d1 (0x82f3970) ]
      ]
    ]
    local:foo/1 (0x82f49c0) 
    [
      treat_expr [NodeXQType anyNode content=[XQType ANY_TYPE_KIND*]] (0x82f4a20) [
        var_ref (0x82f40c0) [ d2 (0x82f3a58) ]
      ]
    ]
  ]
]


--------------------------------------------

Expression tree after optimization for local:foo
treat_expr [NodeXQType anyNode content=[XQType ANY_TYPE_KIND*]] (0x82f3cc8) 
[
  flwor_expr (0x82f43a8) 
  [
    FOR (0x82f41c0) child (0x82f3db0)
    [
      relpath_expr (0x82f3200) [
        var_ref (0x82f3260) [ n (0x82f2f40) ]
          REL STEP child::match_expr [name_test(b)]
      ]
    ]
    RETURN
      local:parent/1 (0x82f42e0) [ var_ref (0x82f4288) [ child (0x82f3db0) ] ]
  ]
]


------------------------------------------------

Expression tree after optimization for local:parent
treat_expr [NodeXQType anyNode content=[XQType ANY_TYPE_KIND*]] (0x82f2e70) 
[
  block_expr (0x82f3910) 
  [
    apply_expr (0x82f3648) 
    [
      const_expr (0x82f4530) [ xs:integer [ xs:integer(2) ] ]
    ]
    relpath_expr (0x82f36a0) 
    [
      var_ref (0x82f3700) [ n (0x82f2d08) ]
        REL STEP parent::match_expr [node()]
    ]
  ]
]


------------------------------------------------

mark sources of expr 0x82f3200 ($n/b in local:foo())
source: 0x82f3af8


mark sources of expr 0x82f36a0 ($n/.. in local:parent)
source; 0x82f3af8


mark sources of expr 0x82f3200 ($n/b in local:foo())
source: 0x82f47a0


:)
