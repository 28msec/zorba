import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";
import schema namespace fts = "http://www.zorba-xquery.com/modules/full-text";

let $options := validate { ft:current-compare-options() }
return  $options/@case = "case insensitive"
    and $options/@diacritics = "diacritics insensitive"
    and $options/@stemming = "no stemming"

(: vim:set et sw=2 ts=2: :)
