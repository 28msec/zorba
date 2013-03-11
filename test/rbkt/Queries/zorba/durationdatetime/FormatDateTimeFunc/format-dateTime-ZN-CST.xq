let $dt := xs:dateTime( "1967-11-18T09:14:00-06:00" )
return fn:format-dateTime( $dt, "[ZN]" ) eq "CST"
