import module namespace def = "http://www.david.ch/default" at "libModule22.xqlib";

(:
import schema namespace http="http://www.28msec.com/modules/http" at "schema.xsd";
:)

declare namespace http = "http://www.28msec.com/modules/http";

def:invoke(
  <http:cookie name="blabla">
    <http:david>blabla</http:david>
  </http:cookie>
)
