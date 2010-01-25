import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

let $xqdoc := xqd:xqdoc("indentation.xq")
return block {
  replace value of node $xqdoc//*:date[1] with "";
  $xqdoc;
}
