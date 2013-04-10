let $old := xs:dateTime( "2010-11-12T13:14:15.167" )
let $new := xs:dateTime( fn:format-dateTime( $old, "[Y]-[M01]-[D01]T[H01]:[m01]:[s01].[f001]" ) )
return $new eq $old 
