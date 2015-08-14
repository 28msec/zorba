jsoniq version "1.0";
for $outer in ("a", "b")
let $do-not-evaluate := error(QName("local:EVALUATED"), "evaluated")
return
    for $inner in ("2001-01-01", "2001-01-01" )[current-date() eq ($$)]
    return $do-not-evaluate