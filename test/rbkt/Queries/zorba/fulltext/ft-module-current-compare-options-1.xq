jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";

let $options := ft:current-compare-options()
return $options.case eq "case insensitive"
    and $options.diacritics eq "diacritics insensitive"
    and $options.stemming eq "no stemming"

(: vim:set et sw=2 ts=2: :)
