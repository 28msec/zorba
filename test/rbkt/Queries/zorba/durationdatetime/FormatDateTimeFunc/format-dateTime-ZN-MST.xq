let $dt := xs:dateTime( "1967-11-18T09:14:00-07:00" )
return fn:format-dateTime( $dt, "[ZN]" ) eq "MST"
