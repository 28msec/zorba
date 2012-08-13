import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

declare ft-option using language "en";

let $synonyms := ft:thesaurus-lookup( "http://wordnet.princeton.edu",
                                      "marmite" )
return $synonyms = "pot"
