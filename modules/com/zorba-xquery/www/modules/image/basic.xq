module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';

(:~
 : Contains the definitions of the possible image types.
 :)
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';




(:~
 : Returns the width (in pixels) of the passed image.
 : 
 : @param $image is the image for which we want to know the width.
 : @return The width of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function basic:width($image as xs:base64Binary) as xs:unsignedInt external;

(:~
 : Returns the height (in pixels) of the passed image.
 : 
 : @param $image is the image for which we want to know the width.
 : @return The height of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function basic:height($image as xs:base64Binary) as xs:unsignedInt external;


(:~
 : Converts an image to another format.
 : If the image already has the specified format, then this function just returns the image without modifying it.
 :
 : @param $image is the image to convert.
 : @param $type is the type in which to convert the image (an imageType as defined in 'http://www.zorba-xquery.com/modules/image/image')
 : @return A new image with the same content as the passed image but with the specified file format.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function basic:convert($image as xs:base64Binary, $type as image:imageType) as xs:base64Binary external;



(:~
 : Returns the image type that is stored in the given xs:base64Binary or an empty sequence if the passed xs:base64Binary is not a valid image type.
 :
 : @param $image is the image for which the type is requested.
 : @return The type of the passed image (an imageType as defined in 'http://www.zorba-xquery.com/modules/image/image') or an empty sequence if the passed xs:base64Binary is not a valid image type.
 :)
declare function basic:type($image as xs:base64Binary) as image:imageType external; 
  
 
(:~
 : Creates a new and empty image with white background color.
 : 
 : @param $width is the width of the new image.
 : @param $height is the height of the new image.
 : @param $format is the format of the new image.
 : @return A new and empty image with the specified type.
 :)
declare function basic:create($width as xs:unsignedInt, $height as xs:unsignedInt, $format as image:imageType) as xs:base64Binary external;
 

 
(:~
 : Creates an animated GIF image from the passed $images. The width and height of the first passed image will be used.
 :
 : @param $images are the images with which the animated GIF shall be created (in the right order).
 : @param $delay specifies how long a given image shows in the animated GIF in 1/100 of a second.
 : @param $iterations specifies how many times the animation loop should be executed (0 for endless loop).
 : @return A new image that is an animated GIF composed out of the passed images.
 : @error If any of the passed xs:base64Binary is not a valid image type.
 :)
declare function basic:create-animated-gif($images as xs:base64Binary+, $delay as xs:unsignedInt, $iterations as xs:unsignedInt) as xs:base64Binary external; 









