import module namespace util =
"http://www.zorba-xquery.com/zorba/util-functions";

let $message := util:parse("<?xml version='1.0'?><a><b/></a>")
return $message
