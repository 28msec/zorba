(:
 : The format is NOT a decimal digit pattern because it does not contain at
 : least one Unicode digit.  Hence, the format is an unknown format and treated
 : as if it were the format "1".
 :)

fn:format-integer( 1234, "#,###" ) eq "1234"
