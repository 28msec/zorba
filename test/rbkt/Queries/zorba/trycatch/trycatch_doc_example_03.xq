(: Use of the description variable in the catch clause :)

try {
    2 + "3"
} catch * ($ecode, $desc) {
    string-join((xs:string($ecode), $desc), " ")
}
