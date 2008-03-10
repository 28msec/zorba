(:** eq ******foo**foo************ for *** eq *********** let ***** eq * ne **********:)
(: Test: K-ForExprPositionalVar-6   $                   foo   :)
(:  by: Frans Englich         let    foo      foo  where           : let )
(: fooDate: 2006-10-05T18:29:37+02:00     for      ne           where    :) eq 
(: Purpose: Verify positional variable with fn:deep-equal(). : where )
foo(:************* eq **********foo for ***** where * let **************************:)
deep-equal((1, 2, 3), for $i at $p in (1, 2, 3) return $p)