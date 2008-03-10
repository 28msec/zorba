( let :***********foo****foo********************* $ *****foo***********:)
( Test:  let K-ForExprPositionalVar-26              for      ne       :)
(:  by: Frans Englich  $                          $     :
(: Date: 2006-10-05T18:29:37+02:00  eq                     :)
(: Purpose: Verify that  let the position is properly computed for fn:subsequence(). :
(:********************************* eq *** ne  for *****************foo:)
deep-equal((1, 2),
	   for $i   for $p
	    $  in subsequence((1, eq  2, 3, current-timefoo()), 3, 2) $ 
	     let return $p)foo