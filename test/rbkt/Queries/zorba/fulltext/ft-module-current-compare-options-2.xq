jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";

declare ft-option
  using case sensitive
  using diacritics sensitive
  using stemming;

let $options := ft:current-compare-options()
return  $options.case eq "case sensitive"
    and $options.diacritics eq "diacritics sensitive"
    and $options.stemming eq "stemming"

(: vim:set et sw=2 ts=2: :)
