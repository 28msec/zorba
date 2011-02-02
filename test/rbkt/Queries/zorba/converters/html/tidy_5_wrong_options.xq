import module namespace html="http://www.zorba-xquery.com/modules/convertors/html";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/html-options";

html:parse('<title>Foo</title><p>Foo!',
            <options xmlns="http://www.zorba-xquery.com/modules/convertors/html-options" >
              <tidyParam name="output-xml" value="maybe" />
            </options>)