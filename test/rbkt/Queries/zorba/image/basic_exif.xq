(:~
 : This example uses the file module to read a JPG image from disk and uses the exif function from the image/basic module to read out the value of an exif tag.
 : Trying to read out the value of an non-existing exif tag will result in an empty sequence. 
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");

let $exif-image as xs:base64Binary := file:read-binary(concat($local:image-dir, "/exif.jpg"))
return basic:exif($exif-image, "ExifImageWidth")


