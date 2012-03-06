import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

schema:schema-type(
  data(
    validate lax { 
      <a 
        xmlns:xs="http://www.w3.org/2001/XMLSchema"
        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xsi:type="xs:integer">2</a> }
  )
)
