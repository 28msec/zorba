let $dt := xs:dateTime( "1967-11-18T09:14:00-08:00" )
return fn:format-dateTime( $dt, "[Z0]" ) eq "-8"
