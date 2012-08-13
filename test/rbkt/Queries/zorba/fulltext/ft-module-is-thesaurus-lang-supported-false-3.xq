import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

(: Thesaurus URI that is not statically known. :)
ft:is-thesaurus-lang-supported( "http://www.example.com/", xs:language("en") )
