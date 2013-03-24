let $old := xs:date( "2010-12-31" )
let $new := xs:date( fn:format-date( $old, "[Y]-[M01]-[D01]" ) )
return $new eq $old
