(: try-catch with multiple catch clauses showing catch clause precedence :)
try {
    3 + 2 > "30"
} catch(err:XQDY0004) {
    "Some random error that does not occur"
} catch(*, $code) {
    concat("Caught ", $code)
} catch(err:XPTY0004) {
    "This is the error throw. But it should be caught in the catch clause above"
}
