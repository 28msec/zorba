declare namespace err="http://www.w3.org/2005/xqt-errors";
try {
 "a" cast as xs:integer
}
catch * {
  0
}
