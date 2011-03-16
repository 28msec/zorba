import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";


declare variable $tmp := <json type="object"><pair name="phoneNumbers" type="array"><item type="string">212 732-1234</item><item type="string">646 123-4567</item></pair><pair name="firstName" type="string">John</pair><pair name="lastName" type="string">Smith</pair><pair name="address" type="object"><pair name="postalCode" type="number">10021</pair><pair name="city" type="string">New York</pair><pair name="streetAddress" type="string">21 2nd Street</pair><pair name="state" type="string">NY</pair></pair></json>;

json:serialize($tmp,<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)