import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0";

try { 
  xqd:xqdoc("gdata_error.xqlib")
} catch * ($errcode, $errdesc, $errval) {
  $errcode, $errdesc
}
