import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

declare variable $tmp :=<ul>
  <li style="color:red">First Item</li>
  <li title="Some hover text." style="color:green">Second Item</li>
  <li><span class="code-example-third">Third</span>Item</li>
</ul>;

json:serialize($tmp,<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="json-ml" />
            </options>)