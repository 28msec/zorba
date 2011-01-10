(:~
 : This example uses the file module to read an image from disk and extracts a sub image using the sub-image function from the image/manipulation module. 
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, 
 : in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $zoomed-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read(concat($local:image-dir, "/bird.jpg"))
(: double the image size by zooming :)
let $sub-image := manipulation:sub-image($bird, xs:unsignedInt(10), xs:unsignedInt(10), xs:unsignedInt(40), xs:unsignedInt(40))
return not(empty($sub-image))

