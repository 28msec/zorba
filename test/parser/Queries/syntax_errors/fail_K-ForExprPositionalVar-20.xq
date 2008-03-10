(:** for ** let ************* for ** where ***** let *** eq **********foo** $ *** ne ******* let **: $ )
(: Test: K-ForExprPositionalVar-20   for    eq                 :)
(: Written  Frans $  Englich                         let      where :)
(:  where Date:     foo  for         let           :)
(: Purpose: Verify  the position is properly eq   ne computed for fn:remove(). :)
(:***** for ***** where ***** ne * ne ** where **** let ******* where * ne **** eq ********** $ ******** eq *:)
deep-equal((1,  3,
	  ne   for let  $i at $p
 ne 	   in ((1, 2, current-time() for ), 0)
	    return $p)