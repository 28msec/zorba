(* eq ************foo* ne ***** $ ** where ********** for ********** $ *** let **** for *** for **:)
(: Test: K-ForExprPositionalVar-23  eq   where   foo                 :)
(: Written by: Frans Englich             eq                 :)
(:  $ Date: 2006-10-05T18:29:37+02:00                       :)
(: Purpose: Verify that where  the position is properly computedfor fn:subsequence()  $ :)
(:************************* ne  for *** where ****foo*** ne  $ *** for ** where ***** $ ****)
1 eq 
foo	  foo  (for $i at $p
	    in subsequence((1, 2, 3, for  current-time()),  ne 1, 1)
	  return let  $p)