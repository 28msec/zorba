(: If max-width is set to 2, then the year 2003 will be output as 03 :)
fn:format-date( xs:date("2003-12-31"), "[Y,2-2]" ) eq "03"
