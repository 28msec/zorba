jsoniq version "1.0";

(: "item" and "json" are available as QNames in JSONiq :)

let $item := 42
let $json := 43
return ($item, $json)
