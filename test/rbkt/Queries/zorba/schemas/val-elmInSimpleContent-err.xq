import schema namespace oa="http://zorba-xquery.org/schemas/test/valError" at
  "valError.xsd";

validate strict { <oa:test><b/>abc</oa:test> }
