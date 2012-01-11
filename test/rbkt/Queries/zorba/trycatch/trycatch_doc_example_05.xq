(: try-catch catching error happening inside functions :)

declare namespace err="http://www.w3.org/2005/xqt-errors";
declare function local:squares() {
    for $x in (1, 2, 3, 4, "5", 6, 7)
    return $x * $x
};

try {
    local:squares()
} catch err:XPTY0004 {
    "Caught a type error"
}
