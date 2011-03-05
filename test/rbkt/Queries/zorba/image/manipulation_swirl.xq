(:~
 : This example uses the file module read an image from disk, 
 : and rotates the pixels of the image by 90 degrees using the swirl function from the image/manipulation module.
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, 
 : in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $swirled-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read-binary(concat($local:image-dir, "/bird.jpg"))
let $swirled-image := manipulation:swirl($bird, 90)
return not(empty($swirled-image))

