import module namespace ft = "http://zorba.io/modules/full-text";

(: Thesaurus URI that is not statically known. :)
ft:is-thesaurus-lang-supported( "http://www.example.com/", xs:language("en") )
