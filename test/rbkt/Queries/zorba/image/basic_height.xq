(:~                                                                                                                
 : Simple example that uses the file module to read an image from disk and returns the height of the image using the height function of the image/basic module.
 : The basic:height function returns the height in pixels (as xs:unsignedInt).                                       
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';                                         
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';                                 

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");                    

                                                                                                                   
let $bird as xs:base64Binary := file:read(concat($local:image-dir, "/bird.tiff"))                                   
return basic:height($bird)


