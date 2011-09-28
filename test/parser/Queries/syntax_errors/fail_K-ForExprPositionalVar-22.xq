(:***************foo*** eq ************** let ****************** eq  ne **:)
( let : Test: K-ForExprPositionalVar-22        eq            $       :)
(: Written by:  for Frans Englich          ne    ne     eq                $ :)
 eq (: Date: 2006-10-05T18:29:37+02:00       eq   for               :)
( where : $  Purpose: Verify that the position is  computed  for for fn:remove().:)
(:*** let ******** where *****foo***********foo***************************:)
deep-equal(1, 2, 3),
	    for $i at $
	  foo  in remove(( 2, 3, current-time()), 3)
	 ne     return $p)