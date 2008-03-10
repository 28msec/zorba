(:***** for ****foo****** let ********** $ ********* let *********** where ****:)
(: Test: K-ForExprPositionalVar-24     $        eq   for          :)
(: Written  eq by: Frans Englich     foo             let          eq   :)foo
(: for  Date: eq  2006-10-05T18:29:37+02:00    for      let     for         where     :) $ 
(: Purpose: Verify that the position is properly computed for fn:subsequence(). where  :)
(:******************************* where ***** where ******************:)
(for $i at $p
	 eq     in subsequence((1, 2, 3, current-time()), 5)
	   return $p)