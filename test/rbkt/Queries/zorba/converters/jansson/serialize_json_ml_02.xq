import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

declare variable $tmp :=<table class="MyTable" style="background-color:yellow">
<tr>
<td class="MyTD" style="border:1px solid black">#5D28D1</td>
<td class="MyTD" style="background-color:red">Example text here</td>
</tr>
<tr>
<td class="MyTD" style="border:1px solid black">#AF44EF</td>
<td class="MyTD" style="background-color:green">127310656</td>
</tr>
<tr>
<td class="MyTD" style="border:1px solid black">#AAD034</td>
<td class="MyTD" style="background-color:blue">\u00A0<span style="background-color:maroon">\u00A9</span>\u00A0</td>
</tr>
</table>;

json:serialize($tmp,<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="json-ml" />
            </options>)