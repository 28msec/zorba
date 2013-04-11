declare decimal-format local:th zero-digit = "๐";

fn:format-number( 1234.567, "#,###.##", "local:th" ) eq "๑,๒๓๔.๕๗"
