import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0" at "xqdoc-1.0.xsd";

try { 
  xqd:xqdoc("gdata_error.xqlib")
} catch * ($errcode, $errdesc, $errval) {
  $errcode, $errdesc
}
