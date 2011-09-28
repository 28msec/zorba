(: testing for potential prefix clashes during automatic schema import :)

import schema namespace xslt-xquery-serialization = "http://www.w3.org/2010/xslt-xquery-serialization";

declare namespace xslt-xquery-serialization_ = "http://www.w3.org/2010/xslt-xquery-serialization";

let $params :=
  <xslt-xquery-serialization:serialization-parameters xmlns:xslt-xquery-serialization="http://www.w3.org/2010/xslt-xquery-serialization">
  </xslt-xquery-serialization:serialization-parameters>
return
  fn:serialize(<a/>, $params)
