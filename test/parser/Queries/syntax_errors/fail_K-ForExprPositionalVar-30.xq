(:*********** $ ************ for ****************************:)
(: Test: K-ForExprPositionalVar-30          foo       eq        :)
(:  let Written ne  by: fooFrans Englich      where  foo   for                     :)
( Date: 2006-10-05T18:29:37+02:00   for                  where     :)
(: Purpose: Evaluate the positional and binding expression at the same time. :)
 for (:******** let * where * eq ******* eq ******************* eq ********** $ *foo $ ******* for :)
deep-equal(for$i at $p ne  in (1, 2, 3, 4) return ($i, $p),
          (1, 1,  ne 2, 2, 3, 3, 4,4))