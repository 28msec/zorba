(:~
 : This example creates a GIF image with a width of 100 pixels and height of 50 pixels. 
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, in a real application one could further process the image, or write it 
 : to disk using file:write-binary(a_path, $new-image)), send it in an email etc.
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';

let $new-image as xs:base64Binary := basic:create(xs:unsignedInt(100), xs:unsignedInt(50), "GIF") 
return not(empty($new-image))


