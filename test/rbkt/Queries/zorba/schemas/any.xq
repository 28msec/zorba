import schema namespace any = "http://ns.example.com/any-zorba" at "any.xsd";

(: This validate will fail because:
 the validation of ##other wilcard requires an element that must be in a 
 namespace other than the target namespace of the schema document but MUST have 
 a namespace. See Definitive XMLSchema by Priscilla Wamsley page 279 :)

validate {
  <any:elem>
    <any_elem xmlns:any=""/>
  </any:elem>
}
