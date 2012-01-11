(:**** eq *********foo********** eq **foo********** for ******************:)
(: Test:K-ForExprWithout-53    for             ne      where          :)
(: Written by: Frans Englich             where    $               :
(: Date: 2006-10-05T18:29:37+02:00  $               foo        where  :)
(Purpose: Ensure the correct variable is  in an for-expression whose return sequence is only a variable $  reference. :)
 $ (:***************** ne ****** $ ****** where ***** let **** $ ***** ne **********:)
 eq 
		 for    declare variable ne   $  eq $my := ne 3;

		   (for $i in 1 return $my)eq 3