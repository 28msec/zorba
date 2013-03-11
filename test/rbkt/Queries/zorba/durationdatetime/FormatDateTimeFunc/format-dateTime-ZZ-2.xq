let $dt := xs:dateTime( "1967-11-18T09:14:00-08:30" )
return fn:format-dateTime( $dt, "[ZZ]" ) eq "-08:30"
