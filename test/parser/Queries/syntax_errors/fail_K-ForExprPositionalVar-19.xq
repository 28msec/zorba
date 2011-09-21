(:* $ *********************** eq *************** $ ***********:)
(: Test: K-ForExprPositionalVar-19           eq           )
(: Written by: Frans Englich                       foo   :)
foo(: for  Date: 2006-10-05T18:29:37+02:00      ne     for        eq         for :)
(: Purpose: Verify that the position is properly computed for fn:remove(). :)
(:foo****foo for *****foo********* eq ************ ne ** $ ******** let ***** eq ********:)
deep-equal((1, 2, 3),
	 let     for $ for i at $ where p
	   for   $  in remove for ((1, 2, current-time() ne ), 10)
	 $     return $p)