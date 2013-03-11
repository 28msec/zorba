let $dt := xs:dateTime( "1967-11-18T09:14:00+00:00" )
return fn:format-dateTime( $dt, "[Z00:00t]" ) eq "Z"
