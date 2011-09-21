(:********** $ *** $ ************************ ne **************:)
(:  K-ForExprPositionalVar-21   where      foo              :)
(: Written by: Frans Englich     for              eq        where   let       $  :) eq 
(: Date: 2006-10-05T18:29:37+02:00        $                foo:) $ 
(: Purpose: Verify that the position is properly computed for  ne fn:remove(). :)
 $ (:** let ************foo******foo********************** let ********foo eq ****:)
deep-equal(( 2, 3),
	    for $i  let at $p
	    in remove(( for 1, 2, 3, current-time()) $  1)
	    return $p)