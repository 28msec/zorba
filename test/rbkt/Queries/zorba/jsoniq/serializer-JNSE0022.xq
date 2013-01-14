(: make sure jerr:JNSE0022 is raised if trying to serialize a non-document node with methods html, text, xml, or xhtml :)
declare namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace jerr = "http://jsoniq.org/errors";

let $obj := { "message": "test" }
return
  (
    try
    {
      serialize($obj, <output:serialization-parameters><output:method value="html"/></output:serialization-parameters>)
    } catch jerr:JNSE0022
    {
      $err:description
    },
    try
    {
      serialize($obj, <output:serialization-parameters><output:method value="text"/></output:serialization-parameters>)
    } catch jerr:JNSE0022
    {
      $err:description
    },
    try
    {
      serialize($obj, <output:serialization-parameters><output:method value="xml"/></output:serialization-parameters>)
    } catch jerr:JNSE0022
    {
      $err:description
    },
    try
    {
      serialize($obj, <output:serialization-parameters><output:method value="xhtml"/></output:serialization-parameters>)
    } catch jerr:JNSE0022
    {
      $err:description
    }
  )
