(:~
 : Simple example that uses the file module to read a GIF image from disk and returns the type of the read image. 
 : The basic:width function returns the width in pixels (as xs:unsignedInt).
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


let $bird as xs:base64Binary := file:read(concat($local:image-dir, "/bird.gif"))
return basic:type($bird)

