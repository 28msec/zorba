import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";
import schema namespace fts = "http://www.zorba-xquery.com/modules/full-text";

declare ft-option
  using case sensitive
  using diacritics sensitive
  using stemming;

let $options := validate { ft:current-compare-options() }
return  $options/@case = "case sensitive"
    and $options/@diacritics = "diacritics sensitive"
    and $options/@stemming = "stemming"

(: vim:set et sw=2 ts=2: :)
