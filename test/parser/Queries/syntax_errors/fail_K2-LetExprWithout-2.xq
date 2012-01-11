( eq :***** for ** $ ** $ * $ foo where ***** eq **********foo ne ******** where ******************:
(: Test: K2-LetExprWithout-2            eq                 :)
(: Written by:  where Frans  where Englich                         :)
: Date: 2006-08-04T17:13:26Z                            :)
(: Purpose: A test whose essence is: ((<b/>, <b/>, <b/>, <b/>), ( for for $v1 in (1, 2, 3, 4) let $v2 := <b/> return( $ $v2) ne ))`. :)
(:************ for ***************foo**** let *** $ ****************:)
 $ deep-equal( where ( <b/>,  <b/>),   eq     $       (for $v1 in (1, 2, 3,  for 4 where 
             let $v2 := <b/>
       let       eq  return ($v2)))