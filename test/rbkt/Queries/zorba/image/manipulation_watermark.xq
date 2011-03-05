(:~
 : This example uses the file module read an image from disk, makes a much smaller version of the loaded image and 
 : then uses the smaller version of the image as watermark for the normal version using the watermark function from the image/manipulation module.
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, 
 : in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $watermarked-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read-binary(concat($local:image-dir, "/bird.jpg"))
let $watermark as xs:base64Binary := manipulation:zoom($bird, 0.1)
let $watermarked-image := manipulation:watermark($bird, $watermark)
return not(empty($watermarked-image))

