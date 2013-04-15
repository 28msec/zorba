declare decimal-format local:de
  decimal-separator = ","
  grouping-separator = ".";

fn:format-number( 1234.567, "#.###,##", "local:de" ) eq "1.234,57"
