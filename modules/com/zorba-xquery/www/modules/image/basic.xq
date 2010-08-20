(:~
 : This module provides basic functions for handling images including conversion between different formats.
 : Supported image formats are:
 : 
 : GIF
 : JPEG
 : PNG
 : TIFF
 : SVG
 :
 : 
 : @author Daniel Thomas
 : @version 0.1
 :)
module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';


(:~
 : Internal module.
 :)
import module namespace basicschema = 'http://www.zorba-xquery.com/modules/image/basicschema';

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
declare function basic:width($image as xs:base64Binary) as xs:unsignedInt {
  basicschema:width($image)
};

(:~
 : Returns the height (in pixels) of the passed image.
 : 
 : @param $image is the image for which we want to know the width.
 : @return The height of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function basic:height($image as xs:base64Binary) as xs:unsignedInt {
  basicschema:height($image)
};


(:~
 : Set quality (compression) for JPEG, GIF and PNG image formats.
 : Lowering the quality of an image can reduce image size.
 :
 : @param $image is the image for which we want to set the quality.
 : @param $quality is the new quality for the image (a value from 0 to 100 with default 75)
 : @return A new image with the quality set accordingly. 
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function basic:compress($image as xs:base64Binary, $quality as xs:unsignedInt) as xs:base64Binary {
  basicschema:compress($image, $quality)
};



(:~
 : Converts an image to another format.
 : If the image already has the specified format, then this function just returns the image without modifying it.
 : Accepted image formats are:
 :
 : GIF
 : PNG
 : TIFF
 : JPEG
 :
 : @param $image is the image to convert.
 : @param $format is the format in which to convert the image.
 : @return A new image with the same content as the passed image but with the specified file format.
 : @error If the passed xs:base64Binary is not a valid image.
 : @error If an unsupported image format was passed. 
 : @error If the passed format is SVG (as it is nearly impossible to convert images to SVG) 
 :)
declare function basic:convert($image as xs:base64Binary, $format as xs:string) as xs:base64Binary {
  basicschema:convert($image, image:imageType($format))
};



(:~
 : Returns the image type that is stored in the given xs:base64Binary.
 :
 : @param $image is the image for which the type is requested.
 : @return The type of the passed image. 
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function basic:type($image as xs:base64Binary) as xs:string {
  basicschema:type($image)
};
 
(:~
 : Creates a new and empty image with white background color and the specified format.
 : Allowed image formats are:
 : 
 : GIF
 : PNG
 : JPEG
 : TIFF
 : SVG
 : 
 : @param $width is the width of the new image.
 : @param $height is the height of the new image.
 : @param $format is the format of the new image.
 : @return A new and empty image with the specified type.
 : @error If an unsupported image format was passed. 
 :)
declare function basic:create($width as xs:unsignedInt, $height as xs:unsignedInt, $format as xs:string) as xs:base64Binary {
    basicschema:create($width, $height, image:imageType($format))
};


