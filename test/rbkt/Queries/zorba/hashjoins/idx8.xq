declare namespace xqdoc = "http://www.xqdoc.org/1.0";

let $fs := doc("xqdoc.xml")/xqdoc:xqdoc/xqdoc:functions/xqdoc:function

for $function in ($fs[1],$fs[8])

for $furi in ("http://www.w3.org/2005/xpath-functions",())

let $invokedFunctions := $function/xqdoc:invoked[string(xqdoc:uri)=$furi]

return ($function/xqdoc:name/text(),":",$invokedFunctions) 


(:

flwor_expr (0x97ef1f0) 
[
  LET (0x97f1dc8) $$opt_temp_0 (0x97f1d58) 
  [
    op:concatenate/2 (0x97f12e0) [
      const_expr (0x97f1250) [ string [ http://www.w3.org/2005/xpath-functions ] ]
      op:concatenate/0 (0x97f11f0) [ ]
    ]
  ]
  RETURN
  flwor_expr (0x97f4530) 
  [
    LET (0x97ecb48) fs (0x97ec748) 
    [
      path_expr(0x97ec0a8)[fn:doc[xqdoc.xml]/xqdoc:xqdoc/xqdoc:functions/xqdoc:function]
    ]
    FOR (0x97f11a8) function (0x97f0da8)
    [
      op:concatenate/2 (0x97f0c68) [
          fn-zorba:sequence-point-access/2 [ $fs ,  1 ]
          fn-zorba:sequence-point-access/2 [ $fs ,  8 ]
      ]
    ]
    LET (0x97f15e8) $$opt_temp_2 (0x97f1508) 
    [
      relpath_expr (0x97f2350) [
        wrapper_expr (0x97f23b0) [var_ref[(0x97f18f0) function (0x97f0da8)]]/xqdoc:invoked
      ]
    ]
    LET (0x97f2158) $$opt_temp_1 (0x97f09d8) 
    [
      path_expr (0x97f4150) [
        var_ref [ (0x97f41b0) function (0x97f0da8) ]/xqdoc:name/text()
      ]
    ]
    FOR (0x97f1848) furi (0x97f1448)
    [
      op:unhoist/1 (0x97f0968) [ var_ref [ (0x97f0910) $$opt_temp_0 (0x97f1d58) ] ]
    ]
    RETURN
    op:concatenate/3 (0x97f44d0) 
    [
      op:unhoist/1 (0x97f21f8) [ var_ref [ (0x97f21a0) $$opt_temp_1 (0x97f09d8) ] ]

      const_expr (0x97f40d8) [ string [ : ] ]

      wrapper_expr (0x97f4080) [
        flwor_expr (0x97f25d8) 
        [
          FOR (0x97f2ca8) $$dot (0x97f2c38)
          [
            op:unhoist(0x97ecf78) [ var_ref [ (0x97ecf20) $$opt_temp_2 (0x97f1508) ] ]
          ]
          WHERE
          op:value-equal-string/2 (0x97f3150)
          [
             fn:string/1 (0x97f3028) 
             [
               treat_expr [XQType ITEM_KIND?] (0x97f3098) [
                 path_expr (0x97f2d38)[ var_ref[(0x97f2d98) $$dot(0x97f2c38) ]/xqdoc:uri]
               ]
             ]
             var_ref [ (0x97f30f8) furi (0x97f1448) ]
           ]
           RETURN
             var_ref [ (0x97f39c8) $$dot (0x97f2c38) ]
         ]
       ]
     ]
   ]
]


*******************************************************************************


flwor_expr (0x8e7f500) 
[
  LET (0x8e86698) $$opt_temp_0 (0x8e863e8) 
  [
    op:concatenate/2 (0x8e83a48) [
      const_expr (0x8e839b8) [ string [ http://www.w3.org/2005/xpath-functions ] ]
      op:concatenate/0 (0x8e83958) [ ]
    ]
  ]
  RETURN
  flwor_expr (0x8e86c98) 
  [
    LET (0x8e7f370) fs (0x8e7ef70) 
    [
      path_expr(0x97ec0a8)[fn:doc[xqdoc.xml]/xqdoc:xqdoc/xqdoc:functions/xqdoc:function]
    ]
    FOR (0x8e83910) function (0x8e83510)
    [
      op:concatenate/2 (0x8e833d0) [
          fn-zorba:sequence-point-access/2 [ $fs ,  1 ]
          fn-zorba:sequence-point-access/2 [ $fs ,  8 ]
      ]
    ]
    LET (0x8e85358) $$opt_temp_2 (0x8e852e8) 
    [
      path_expr (0x8e84ab8) [
        wrapper (0x8e84b18) [ var_ref[ (0x8e84058) function(0x8e83510)]]/xqdoc:invoked ]
    ]
    RETURN
        sequential_expr (0x8e830b0) 
        [
          op:create-internal-index/2 (0x8e85cc0) [
            const_expr (0x8e844f0) [ QName [ tempIndex0 ] ]
            flwor_expr (0x8e7f748) 
            [
              FOR (0x8e82e10) $$opt_temp_3 (0x8e7f5d8) AT $$opt_temp_4 (0x8e7f648)
              [
                op:unhoist(0x8e82050) [ var_ref [(0x8e820b0) $$opt_temp_2 (0x8e852e8) ] ]
              ]
              RETURN
                op:value-index-entry-builder/2 (0x8e82628) [
                  var_ref [ (0x8e825d0) $$opt_temp_3 (0x8e7f5d8) ]
                  fn:string/1 (0x8e82e78) [
                    treat_expr [XQType ITEM_KIND?] (0x8e82570) [
                      relpath_expr (0x8e85f18) [
                        var_ref [ (0x8e82ed8) $$opt_temp_3 (0x8e7f5d8) ]/xqdoc:uri
                      ]
                    ]
                  ]
                ]
            ]
          ]
          flwor_expr (0x8e85d20) 
          [
            LET (0x8e85a18) $$opt_temp_1 (0x8e84ee8) 
            [
              op:hoist/1 (0x8e86368) [
                relpath_expr (0x8e868b8) [
                  var_ref [ (0x8e86918) function (0x8e83510) ]
                    REL STEP child::match_expr [name_test(xqdoc[=http://www.xqdoc.org/1.0]:name)]
                    REL STEP child::match_expr [text()]
                ]
              ]
            ]
            FOR (0x8e83fb0) furi (0x8e83bb0)
            [
              op:unhoist/1 (0x8e84fd0) [
                var_ref [ (0x8e7f2a0) $$opt_temp_0 (0x8e863e8) ]
              ]
            ]
            RETURN
              op:concatenate/3 (0x8e86c38) [
                op:unhoist/1 (0x8e82438) [
                  var_ref [ (0x8e84180) $$opt_temp_1 (0x8e84ee8) ]
                ]
                const_expr (0x8e86840) [ string [ : ] ]
                wrapper_expr (0x8e867e8) [
                  flwor_expr (0x8e84d40) [
                    FOR (0x8e85410) $$dot (0x8e853a0)
                      [
                      fn-zorba-ddl:probe-index-point-value/2 (0x8e83120) [
                        const_expr (0x8e844f0) [ QName [ tempIndex0 ] ]
                        var_ref [ (0x8e85860) furi (0x8e83bb0) ]
                      ]
                    ]
                    RETURN
                      var_ref [ (0x8e86130) $$dot (0x8e853a0) ]
                  ]
                ]
              ]
          ]
        ]
    ]
]


<root>
insert :
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">QName</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">concat</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-date</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-time</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">empty</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">error</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">normalize-space</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">string-length</xqdoc:name>
</xqdoc:invoked>

logout :
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">QName</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">concat</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-date</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-time</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">empty</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">error</xqdoc:name></xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">normalize-space</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">string-length</xqdoc:name>
</xqdoc:invoked>
</root>

:)
