import module namespace ft = "http://zorba.io/modules/full-text";

declare ft-option using language "en";

let $synonyms := ft:thesaurus-lookup( "marmite" )
return $synonyms = "pot"
