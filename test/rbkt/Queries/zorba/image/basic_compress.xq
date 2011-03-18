(:~
 : This example uses the file module to read an image from disk and compresses the image to a quality of 2 (with 1 being the lowest and 10 being the heighest possible value). 
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, in a real application one could further process the image, or write it 
 : to disk using file:write-binary(a_path, basic:compress($compressed-bird, xs:unsignedInt(2))), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';                                         
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';                                 

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");                    

                                                                                                                   
let $bird as xs:base64Binary := file:read-binary(concat($local:image-dir, "/bird.jpg")) 
let $compressed-bird := basic:compress($bird, xs:unsignedInt(2))
return not(empty($compressed-bird))
