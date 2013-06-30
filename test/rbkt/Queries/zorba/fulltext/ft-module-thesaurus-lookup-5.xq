import module namespace ft = "http://zorba.io/modules/full-text";

let $synonyms := ft:thesaurus-lookup( "http://wordnet.princeton.edu",
                                      "breakfast",
                                      xs:language("en"),
                                      "USE",
                                      2, 2 )
return $synonyms = "nourishment"
