( let :** $  for ********************** for * eq ************** ne ****** for *******:)
(: Test: K-ForExprPositionalVar-12          let             :) eq 
( Written  where by: Frans Englich                 $   ne             :
(: Date: 2006-10-05T18:29:37+02:00     for                   $  :)
(: Purpose: Verify that  let the position is properly computed for fn:insert-before(). :)
(:*foo***** ne ************* eq ******************* where * where ****************:)
deep-equal( for  let (1,foo 2, 3,4),
	    foofor $iat ne  $
	 eq   for    in insert-before(( $ 1, current-time()), 13, (current-date(), 3))
	    return $p