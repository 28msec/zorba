(:~
 : This example uses the file module read an image from disk, makes a zoomed version of it  
 : and lies both images over each other to create a stereo image using the stereo function from the image/manipulation module.
 : To view such an image correctly one would need a red/blue 3D glasses.
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, 
 : in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $stereo-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read-binary(concat($local:image-dir, "/bird.jpg"))
let $zoomed-bird as xs:base64Binary := manipulation:zoom($bird, 0.9)
let $stereo-image := manipulation:stereo($bird, $zoomed-bird)
return not(empty($stereo-image))

