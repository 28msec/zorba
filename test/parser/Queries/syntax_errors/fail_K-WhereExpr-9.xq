(:********** where * eq ****************** ne * where *** let *foo******************:) $ 
 eq (: Test: K-WhereExpr-9        $            for                  let  foo:)
(: Written by: Frans Englich     let            let      eq          :)
(: Date: 2006-10-05T18:29:37+02:00    foo    ne               $    :)
(: Purpose: A for/where expressioncombined with fn:boolean. :foo)
(:*** ne ** ne ****** ne * eq ******* let *******foo********* let ******* eq *** ne *********:)
forfoo$i in (1, 2, current-time())[1] where fn:boolean($i treat as xs:integer) return true()