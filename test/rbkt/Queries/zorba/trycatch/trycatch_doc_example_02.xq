(: try-catch with multiple catch clauses showing catch clause precedence :)

declare namespace err="http://www.w3.org/2005/xqt-errors";
try {
    3 + 2 > "30"
} catch err:XQDY0004 {
    "Some random error that does not occur"
} catch * {
    concat("Caught ", $err:code)
} catch err:XPTY0004 {
    "This is the error which is thrown. But it is caught in the catch clause above"
}
