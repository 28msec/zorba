(: Whitespace in variable markers should be ignored :)
fn:format-date( xs:date("2010-12-31"), "[
 M	 
	01
  ]" )
eq "12"
