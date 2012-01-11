import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

try { 
  xqd:xqdoc("gdata_error.xqlib")
} catch *  {
  $err:code, $err:description
}
