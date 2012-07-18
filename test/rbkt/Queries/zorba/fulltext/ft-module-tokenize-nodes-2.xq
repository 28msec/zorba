import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";
import schema namespace fts = "http://www.zorba-xquery.com/modules/full-text";

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

let $t1  := validate { $tokens[1] }
let $t2  := validate { $tokens[2] }
let $t3  := validate { $tokens[3] }

let $t10 := validate { $tokens[10] }
let $t11 := validate { $tokens[11] }

return  $t1/@value = "I"        and $t1/@lang = "en"
    and $t2/@value = "love"     and $t2/@lang = "en"
    and $t3/@value = "you"      and $t2/@lang = "en"

    and $t10/@value = "Je"      and $t10/@lang = "fr"
    and $t11/@value = "t'aime"  and $t11/@lang = "fr"

(: vim:set et sw=2 ts=2: :)
