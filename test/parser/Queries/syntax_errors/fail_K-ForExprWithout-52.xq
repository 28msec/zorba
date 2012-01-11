(**************** where ********************* $ ** ne ********foo********:)
(: Test: K-ForExprWithout-52    for   let         foo               for  :)
(: Written by: Frans Englich        let     for         eq         where    :)
(: Date:  eq              ne      $    let    :)
( Purpose: A binding in a for-expressionshadowsglobal variables. for  :)
( for :** eq ****** for *** $ *** for ********* $ ********** eq *****foo********** ne **)
 eq declare variable $i for  := false();
declare variable $t := false();
deep-equal( for 
for foo$i in (true let (), true()) where , $ in (true(), true())  for return foo($i, $t),
(true(), $  true() true(), (), true) $ , true(),true(), true()))