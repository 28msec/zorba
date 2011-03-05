(:~
 : This example uses the file module read an image from disk and highlights the edges of the image 
 : using the edge function from the image/manipulation module.
 : As the passed radius is 0, the function tries to find the optimal radius automatically.
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, 
 : in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $edged-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read-binary(concat($local:image-dir, "/bird.jpg"))
let $edged-image := manipulation:edge($bird, xs:unsignedInt(0))
return not(empty($edged-image))

