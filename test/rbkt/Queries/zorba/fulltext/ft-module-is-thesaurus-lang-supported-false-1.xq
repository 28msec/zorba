import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

(: Valid, but unsupported ISO 639-1 code. :)
ft:is-thesaurus-lang-supported( xs:language("zu") )
