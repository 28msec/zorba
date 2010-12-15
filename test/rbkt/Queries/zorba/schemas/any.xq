import schema namespace any = "http://ns.example.com/any-zorba" at "any.xsd";

validate {
  <any:elem>
    <any_elem xmlns:any=""/>
  </any:elem>
}
