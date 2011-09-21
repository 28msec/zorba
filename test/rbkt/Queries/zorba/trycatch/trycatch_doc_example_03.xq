(: Use of the description variable in the catch clause :)

declare namespace err="http://www.w3.org/2005/xqt-errors";
try {
    2 + "3"
} catch * {
    string-join((xs:string($err:code), $err:description), " ")
}
