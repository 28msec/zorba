(: Default Presentation Modifier for M is 1, so a number should be the result :)
fn:format-date(xs:date("2010-12-31"), "[Y]. this should also come in the output") eq "2010. this should also come in the output"
