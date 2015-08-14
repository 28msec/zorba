jsoniq version "1.0";
let $do-not-evaluate := error(QName("local:EVALUATED"), "evaluated")
return
    for $inner in ("a", "b")[$$ eq "c"]
    return $do-not-evaluate