(:*********** ne ***** let ******foo* where *******foo* where * eq **** for ***************:)
(: Test:  let K-ForExprPositionalVar-14        for                 :)
(: Written by: Frans Englichfoo    eq       for   foo                 let    :) where 
(: Date: 2006-10-05T18:29:37+02:00  ne                 let        :)
(: Purpose: Verify that the  where position is properly  where computed for  let fn:insert-before()(#3 eq ) :)
(:**** let ***** eq ****************************foo*********** ne ******:)
deep-equal((1,2,3, 4),
	    for $i at $p $    in insert-before((1, (), 2, (current-date), ) where )
	   let   return foo$p)