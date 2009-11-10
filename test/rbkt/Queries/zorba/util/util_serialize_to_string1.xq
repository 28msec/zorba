import module namespace zu = "http://www.zorba-xquery.com/zorba/util-functions";
import module namespace ser = "http://www.zorba-xquery.com/modules/serialize";

let $message := zu:parse("<?xml version='1.0'?><a><b>textnode</b></a>")

return ser:serialize($message)
