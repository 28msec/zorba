(: Nested try-catch with the use of the error object :)
try {
    for $x in (1, 2, 3, "4", 5)
    return
        try {
            $x + 4
        } catch(err:XPTY0004) {
            fn:error(xs:QName("err:XPTY0004"), "Rethrowing the exception", $x)
        }
} catch(*, $code, $desc, $obj) {
    string-join(("An error was caught: ", $code, "Description:", $desc, " The cause was:", $obj), " ")
}
