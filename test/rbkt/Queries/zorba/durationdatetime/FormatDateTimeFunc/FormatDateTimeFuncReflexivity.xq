let $dateTime := xs:dateTime("2010-11-12T13:14:15.167")
let $newDateTime := xs:dateTime(fn:format-dateTime($dateTime, "[Y]-[M01]-[D01]T[H01]:[m01]:[s01].[f001]"))
return $dateTime eq $newDateTime 
