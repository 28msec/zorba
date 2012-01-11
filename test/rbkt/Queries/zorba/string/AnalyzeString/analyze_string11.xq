(:
  A previous implementation was importing the "xpath-functions" schema
  as the default element namespace and therefore this query was failing.
:)
declare default element namespace "dummy";

fn:analyze-string("", ".")
