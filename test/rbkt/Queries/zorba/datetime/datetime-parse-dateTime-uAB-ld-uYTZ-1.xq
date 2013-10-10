import module namespace dt = "http://zorba.io/modules/datetime";

let $buf := "Friday, December 28, 2012, 08:00:00 PST"
return dt:parse-dateTime( $buf, "%A, %B %d, %Y, %T %Z", "en-US" )
