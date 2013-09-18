import module namespace ft = "http://zorba.io/modules/full-text";

(: Invalid at least/most range. :)
ft:thesaurus-lookup( "http://wordnet.princeton.edu",
                     "affluent",
                     xs:language("en"),
                     "use",
                     -1, 2 )

(: vim:set et sw=2 ts=2: :)
