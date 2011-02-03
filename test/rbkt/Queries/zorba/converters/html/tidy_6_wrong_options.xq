(: tidy a html using correct tidy options/values but wrongly formated as html-options :)

import module namespace html="http://www.zorba-xquery.com/modules/convertors/html";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/html-options";

html:parse('<title>Foo</title><p>Foo!',
            <option xmlns="http://www.zorba-xquery.com/modules/convertors/html-options" >
              <tidyParam name="output-xml" value="yes" />
              <tidyParam name="doctype" value="omit" />
              <tidyParam name="quote-nbsp" value="no" />
              <tidyParam name="char-encoding" value="utf8" />
              <tidyParam name="newline" value="LF" />
              <tidyParam name="tidy-mark" value="no" />
            </option>)