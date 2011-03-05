(:~
 : This example uses the file module read an image from disk and chops away everything that is left of 50px or above 50px 
 : using the chop function from the image/manipulation module.
 : This equivalent to doing sub-image($bird, 50, 50, basic:width($bird), basic:height($bird)).
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, 
 : in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $chopped-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read-binary(concat($local:image-dir, "/bird.jpg"))
let $chopped-image := manipulation:chop($bird, xs:unsignedInt(50), xs:unsignedInt(50))
return not(empty($chopped-image))
