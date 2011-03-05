(:~
 : This example uses the file module read an image from disk and crops away everything that is right of 50px or under 50px 
 : using the crop function from the image/manipulation module.
 : This equivalent to doing sub-image($bird, 0, 0, 50, 50).
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, 
 : in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $cropped-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read-binary(concat($local:image-dir, "/bird.jpg"))
let $cropped-image := manipulation:crop($bird, xs:unsignedInt(50), xs:unsignedInt(50))
return not(empty($cropped-image))
