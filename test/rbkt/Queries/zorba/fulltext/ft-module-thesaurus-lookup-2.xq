import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

let $synonyms := ft:thesaurus-lookup( "http://wordnet.princeton.edu",
                                      "marmite",
                                      xs:language("en") )
return $synonyms = "pot"
