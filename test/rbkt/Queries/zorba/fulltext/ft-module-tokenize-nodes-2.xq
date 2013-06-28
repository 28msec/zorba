jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";

let $x :=
  <quotes>
    <quote xml:lang="en">
      I love you more than yesterday, less than tomorrow.
    </quote>
    <quote xml:lang="fr">
      Je t'aime plus qu'hier, moins que demain.
    </quote>
  </quotes>

let $includes := $x//quote
let $excludes := ()

let $tokens := ft:tokenize-nodes( $includes, $excludes )

let $t1  := $tokens[1]
let $t2  := $tokens[2]
let $t3  := $tokens[3]

let $t10 := $tokens[10]
let $t11 := $tokens[11]

return  $t1.value eq "I"       and $t1.lang eq "en"
    and $t2.value eq "love"    and $t2.lang eq "en"
    and $t3.value eq "you"     and $t2.lang eq "en"

    and $t10.value eq "Je"     and $t10.lang eq "fr"
    and $t11.value eq "t'aime" and $t11.lang eq "fr"

(: vim:set et sw=2 ts=2: :)
