import module namespace ft = "http://zorba.io/modules/full-text";

declare ft-option using language "en";

let $synonyms := ft:thesaurus-lookup( "no_such_word" )
return fn:empty( $synonyms )
