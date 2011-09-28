(: Simple try-catch example :)

declare namespace err="http://www.w3.org/2005/xqt-errors";

try {
  3 + "2"
} catch err:XPTY0004 {
  "Caught a type error"
}
