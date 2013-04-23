declare default decimal-format infinity = "off-the-scale";

fn:format-number( 1 div 0e0, "###############################" ) eq "off-the-scale"
