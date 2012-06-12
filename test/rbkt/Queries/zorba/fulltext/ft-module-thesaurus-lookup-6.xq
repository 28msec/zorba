import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

declare ft-option using language "en";

let $synonyms := ft:thesaurus-lookup( "no_such_word" )
return fn:empty( $synonyms )
