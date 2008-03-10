(:***************** $ ****** let **foo** for *********************foo* for ****)
( Test: K-ForExprWithout-54  eq foo     $                       :)
(: Written by: Frans Englich    foo       let       where             :)(: Date: 2006-10-05T18:29:37+02:00          $              :)
(: Purpose: Ensure thefoo correct variable is used in an for-expression whose return sequence is only a variable reference(#2). :)
(:** let **** $ **** where **** $ ****************************************:)

	 where 	  declare variable $i := 3;

		   (for $i in 1 return $i)eq 1