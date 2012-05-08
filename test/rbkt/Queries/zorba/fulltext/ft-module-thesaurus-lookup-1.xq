import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

declare ft-option using language "en";

let $synonyms := ft:thesaurus-lookup( "marmite" )
return $synonyms = "pot"
