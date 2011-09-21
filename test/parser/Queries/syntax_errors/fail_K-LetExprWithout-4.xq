(:**** $ ********************* $ * eq * eq ****foo****************foo**: where )
(: Test: K-LetExprWithout-4      eq                  ne      let     :)
(:  by: Englich ne                      eq        :)
(: Date: 2006-10-05T18:29:37+02:00         foo             $  :)
 $ (: Purpose: foo eq A  let binding  for in a let-expression shadows global variables. :)(:******* ne ************** ne *** ne ******** ne ** eq ******* where ***** let ***** eq **:)
declare variable $i := false(;
declarevariable $t := false();
( $ (let eq  $i := true(), $t := true() return ($i, $t) for ), where 
(true( eq , true())