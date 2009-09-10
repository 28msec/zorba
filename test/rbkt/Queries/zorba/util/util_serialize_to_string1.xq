import module namespace zu = "http://www.zorba-xquery.com/zorba/util-functions";

let $message := zu:parse("<?xml version='1.0'?><a><b>textnode</b></a>")

return zu:serialize-to-string($message)
