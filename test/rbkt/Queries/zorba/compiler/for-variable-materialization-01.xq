jsoniq version "1.0";

declare function local:x()
{
  (current-dateTime())
};

let $do-not-evaluate := local:x() (:current-dateTime():) (:"x":) (:error(QName("local:EVALUATED"), "evaluated"):)
return
    for $inner in ("a", "b", "b")[$$ eq "c"]
    return $do-not-evaluate