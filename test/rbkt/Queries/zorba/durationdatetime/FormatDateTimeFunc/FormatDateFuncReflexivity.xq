let $date := xs:date("2010-12-31")
let $newDate := xs:date(fn:format-date($date, "[Y]-[M01]-[D01]"))
return $date eq $newDate
