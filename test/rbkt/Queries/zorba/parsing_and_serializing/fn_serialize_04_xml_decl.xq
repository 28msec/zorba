(: testing the omit-xml-declaration set to no :)

let $params :=
  <serialization-parameters xmlns="http://www.w3.org/2010/xslt-xquery-serialization">
    <omit-xml-declaration value="no"/>
  </serialization-parameters>
return
  fn:serialize(<a/>, $params)
