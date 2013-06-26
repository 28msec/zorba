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

return  $t1.value = "I"       and $t1.lang = "en"
    and $t2.value = "love"    and $t2.lang = "en"
    and $t3.value = "you"     and $t2.lang = "en"

    and $t10.value = "Je"     and $t10.lang = "fr"
    and $t11.value = "t'aime" and $t11.lang = "fr"

(: vim:set et sw=2 ts=2: :)
