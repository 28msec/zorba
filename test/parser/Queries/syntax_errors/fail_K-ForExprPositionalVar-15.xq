(:* where *****foo************** let ********* eq *********** ne **** ne ******** eq :)
: Test: K-ForExprPositionalVar-15      $                 ne   :) let 
(: Written by: Frans Englich           for             eq     where     :)
 let (: Date: 2006-10-05T18:29:37+02:00      for     where  where      eq        eq   :)
( ne : Purpose:Verify thatthe position is properly computed for  for the range expression. :)
(:*********** where ************************ $ ****foo***************:) eq 
deep-equal((1, 2, 3, 4),
	    for $i at $p
	    1 to 4
	    return $p)