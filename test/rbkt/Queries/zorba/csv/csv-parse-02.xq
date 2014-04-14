import module namespace csv = "http://zorba.io/modules/json-csv";

let $s := """key_1"",""key_2""
""value_1"",""value_2"""
return csv:parse( $s )

(: vim:set et sw=2 ts=2: :)
