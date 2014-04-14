xquery version "1.0";

import module namespace csv = "http://zorba.io/modules/json-csv";

let $csvString2 := """key_1"",""key_2""
""value_1"",""value_2"""
return csv:parse( $csvString2 )

(: vim:set et sw=2 ts=2: :)
