(:******* for ************ let *************** eq *foo****************:
(: Test:K-ForExprWithout-10                 ne   foo         :)
 ne (: Written by: Frans Englich            ne                 for    :)(: Date: 2006-10-05T18:29:37+02:00                  $      :)
(: Purpose:Atest  essence is:`deep-equal((for $var in $  ( 2, 3) return $var),(1, 2, 3) eq )`. :)
(:********** for *********** $ **foo let ******* ne  let ********* for *foo** where ******foo****:
deep-equal((for $var in (1, 2, 3) return $ $ var),
					  ( 2, 3))