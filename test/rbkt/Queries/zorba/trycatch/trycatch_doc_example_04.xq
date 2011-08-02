(: Nested try-catch with the use of the error object :)

declare namespace err="http://www.w3.org/2005/xqt-errors";
try {
    for $x in (1, 2, 3, "4", 5)
    return
        try {
            $x + 4
        } catch err:XPTY0004 {
            fn:error(xs:QName("err:XPTY0004"), "Rethrowing the exception", $x)
        }
} catch * {
    string-join(("An error was caught: ", xs:string($err:code), "Description:", $err:description, " The cause was:", $err:value), " ")
}
