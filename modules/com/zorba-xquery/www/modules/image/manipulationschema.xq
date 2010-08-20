(:~
 : For Internal use only.
 :
 : @author Daniel Thomas
 : @version 0.1
 : @see http://www.zorba-xquery.com/modules/image/image
 : @see http://www.imagemagick.org/Magick++/
 :)
module namespace man = 'http://www.zorba-xquery.com/modules/image/manipulationschema';


(:~
 : Contains the definitions for color and noise types.
 :)
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';



(:~
 : Returns the passed image with the specified width and height. 
 : If the new dimensions are greater than the current dimensions, then the new image will have the passed image in the upper left corner and the rest will be filled with the current background color.
 : If the passed dimenstions are less then the current dimensions, the new image will contain the specified rectangle of the passed image beginning at the upper left corner.
 : To change the size of the actual contents of an image, see the zoom function.
 :
 : @param $image is the image to resize.
 : @param $width is the new width for the image.
 : @param $height is the new height for the image.
 : @return A new image with the specified width and height.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:resize($image as xs:base64Binary, $width as xs:unsignedInt, $height as xs:unsignedInt) as xs:base64Binary external;



(:~
 : Zooms the passed image by the specified factor while keeping the ratio between width and height.
 : 
 : @param $image is the image to resize.
 : @param $ratio is the ratio for which to zoom by.
 : @return A new image with the specified width and the height changed accordingly.
 : @error If the passed xs:base64Binary is not a valid image type.
 : @error If the ratio is smaller or equal zero.
 :)
declare function man:zoom($image as xs:base64Binary, $ratio as xs:double) as xs:base64Binary external;



(:~
 : Zooms the passed image while keeping the ratio between width and height.
 : Contrary to the resize function, zoom makes the content of the image bigger or smaller.
 : 
 : @param $image is the image to resize.
 : @param $width is the new width for the image in pixels.
 : @return A new image with the specified width and the height changed accordingly.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:zoom-by-width($image as xs:base64Binary, $width as xs:unsignedInt) as xs:base64Binary external;


(:~
 : Zooms the passed image while keeping the ratio between width and height.
 : 
 : @param $image is the image to resize.
 : @param $height is the new hight for the image in pixels.
 : @return A new image with the specified width and the height changed accordingly.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:zoom-by-height($image as xs:base64Binary, $height as xs:unsignedInt) as xs:base64Binary external;


(:~
 : Returns the specified rectangle of the passed image as a new image.
 : If the passed parameters for the sub-image specify a rectangle that isn't entirely in the image, then only the area of the rectangle that lies
 : in the image will be returned.
 :
 : @param $image is the image from which to extract a sub-image.
 : @param $left-upper-x is the x value of the upper left corner of the rectangle we want to chop out.
 : @param $left-upper-y is the y value of the upper left corner of the rectangle we want to chop out.
 : @param $width is the width which the sub image should have. 
 : @param $height is the height which the sub image should have.
 : @return A new image containing the specified rectangle of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:sub-image($image as xs:base64Binary, $left-upper-x as xs:unsignedInt, $left-upper-y as xs:unsignedInt, 
                                $width as xs:unsignedInt, $height as xs:unsignedInt) as xs:base64Binary external;
                                
                                

(:~
 : Overlays $image with $overlay-image at the specfied position.
 : 
 : @param $image is the base image onto which we overlay the $overlay-image.
 : @param $overlay-image is the image to overlay.
 : @param $overlay-upper-left-x is the horizontal value of the left upper edge where the $overlay-image should be placed withing the base image.
 : @param $overlay-upper-left-x is the horizontal value of the left upper edge where the $overlay-image should be placed withing the base image.
 : @param $operator defines how the overlay image should be overlayed.
 : @return A new image which consisting of $image overlayed with $overlay-image.
 : @error If either of the passed xs:base64Binary's is not a valid image type.
 :)
declare function man:overlay($image as xs:base64Binary, $overlay-image as xs:base64Binary, $overlay-upper-left-x as xs:unsignedInt,
                                $overlay-upper-left-y as xs:unsignedInt, $operator as image:compositeOperatorType) as xs:base64Binary external; 


(:~
 : Returns a part of the passed image which is right of $upper-left-x and under $upper-left-y.
 : 
 : @param $image is the image we want to chop.
 : @param $upper-left-x is the x value of the upper left corner of the part we want to chop out.
 : @param $upper-left-y is the y value of the upper left corner of the part we want to chop out.
 : @return A new image choped to the desired size.
 : @error The passed xs:base64Binary is not a valid image.
 : @error Faulty values for $upper-left-x and $upper-left-y.
 :)
declare function man:chop($image as xs:base64Binary, $upper-left-x as xs:unsignedInt, $upper-left-y as xs:unsignedInt) as xs:base64Binary external;

(:~
 : Returns a part of the passed image which is left of $lower-right-x and above $lower-right-y.
 : 
 : @param $image is the image we want to chrop.
 : @param $lower-right-x is the x value of the lower right corner of the part we want to crop out.
 : @param $lower-right-y is the y value of the lower right corner of the part we want to crop out.
 : @return A new image choped to the desired size.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:crop($image as xs:base64Binary, $lower-right-x as xs:unsignedInt, $lower-right-y as xs:unsignedInt) as xs:base64Binary external;


(:~
 : Rotates the passed image by a specifed angle (from -360 to 360 degrees) and returns a new, rotated image.
 : The image is enlarged if this is required for containing the rotated image, but never shrunk even if the rotation would make a smaller image possible.
 :
 : @param $image is the image to rotate.
 : @param $angle should be a value between -360 to 360 degrees. Other values will be used modulo 360.
 : @return The passed image rotated by the specified angle.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:rotate($image as xs:base64Binary, $angle as xs:int) as xs:base64Binary external;


(:~
 : Sets all pixels of the image to the current backround color.
 :
 : @param $image Is the image to erase.
 : @return A new image with all pixels set to the current background color.
 : @error The passed xs:base64Binary isn't a valid image.
 :)
declare function man:erase($image as xs:base64Binary) as xs:base64Binary external;


(:~
 : Flops the image (reflects each scanline in the horizontal direction).
 :
 : @param $image Is the image to flop.
 : @return A new image with which is the flopped version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:flop($image as xs:base64Binary) as xs:base64Binary external;  
  

(:~
 : Flips the image (reflects each scanline in the horizontal direction).
 :
 : @param $image Is the image to flip.
 : @return A new image with which is the flipped version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:flip($image as xs:base64Binary) as xs:base64Binary external;                                

(:~
 : Trims edges that are of the specified background color from the image.
 : @param $image is the image to trim.
 : @return A new image which is the trimmed image of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:trim($image as xs:base64Binary) as xs:base64Binary external;



(:~
 : Adds noise to the passed image.
 : Allowed noise types are specified in the schema.
 :
 : @param $image is the image to add noise to.
 : @param $noise-type specifies the type of noise to add 
 : @return a new image which is the passed image with added noise.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:add-noise($image as xs:base64Binary, $noise-type as image:noiseType) as xs:base64Binary external;


(:~ 
 : Blurs an image.
 : 
 : @param $image is the image to blur.
 : @param $radius is the radius of the Gaussian in pixels.
 : @param $sigma is the standard deviation of the Laplacian in pixels.
 : @return A blurred version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:blur($image as xs:base64Binary, $radius as xs:int, $sigma as xs:int) as xs:base64Binary external;


(:~
 : Despeckles and image.
 : 
 : @param $image is the image to dispecle.
 : @return A despecled version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:despeckle($image as xs:base64Binary) as xs:base64Binary external;


(:~
 : Enhances an images (minimizes noise).
 : 
 : @param $image is the image to enhance.
 : @return A enhanced version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :) 
declare function man:enhance($image as xs:base64Binary) as xs:base64Binary external;


(:~
 : Equalizes an images (historgramm equalization).
 : 
 : @param $image is the image to equalize.
 : @return A equalized version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :) 
declare function man:equalize($image as xs:base64Binary) as xs:base64Binary external;




(:~
 : Edge an images (highlights edges in image).
 : Pass a radius of 0 for autmatic radius selection.
 : 
 : @param $image is the image to emboss.
 : @param $radius specifies the radius of the pixel neighborhood, specify a radius of 0 for automatic radius selection.
 : @return A edged version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :) 
declare function man:edge($image as xs:base64Binary, $radius as xs:unsignedInt) as xs:base64Binary external;
 
 


(:~
 : Applies a charcoal manect to the image (looks like a charcoal sketch).
 :
 : @param $image is the image to apply a charcoal manect to.
 : @param $radius specifies the radius of the Gaussian in pixels.
 : @param $sigma specifies the standard deviation of the Laplacian in pixels.
 : @return A charcoaled version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:charcoal($image as xs:base64Binary, $radius as xs:double, $sigma as xs:double) as xs:base64Binary external; 

(:~
 : Embosses an images (highlights edges with 3D effect).
 : 
 : @param $image is the image to emboss.
 : @param $radius specifies the radius of the Gaussian in pixels.
 : @param $sigma specifies the standard deviation of the Laplacian in pixels.
 : @return A embossed version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :) 
declare function man:emboss($image as xs:base64Binary, $radius as xs:double, $sigma as xs:double) as xs:base64Binary external;

(:~
 : Applies a solarize manect on the image (similar to manect seen when exposing a photographic film to light during the development process).
 :
 : @param $image is the image to solarize.
 : @param $factor specifies the strength of the solarization.
 : @return A solarized version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:solarize($image as xs:base64Binary, $factor as xs:double) as xs:base64Binary external;

(:~
 : Makes the two passed images appear as stereo image when viewed with red-blue glasses.
 : Both images should be same but from a slightly different angle for this to work.
 : Both images should have the same size, if not, then the size of the left image will be taken.
 :
 : @param $left-image is the left image for the stereo image.
 : @param $right-image is the right image for the stereo image.
 : @return A new image that is the stereo version of both passed images.
 : @error If either of the passed xs:base64Binary is not a valid image type.
 :)
declare function man:stereo($left-image as xs:base64Binary, $right-image as xs:base64Binary) as xs:base64Binary external;


(:~
 : Makes all pixels which are of the specfied color transparent.
 :
 : @param $image is the image to which to add transparency.
 : @param $color is the color to make transparent (e.g. '#FFFFFF')
 : @return A version of the passed image with the specified color made transparent.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function man:transparent($image as xs:base64Binary, $color as image:colorType) as xs:base64Binary external;



(:~
 : Swirls the passed image (image pixels are rotated by degrees).
 :
 : @param $image is the image to swirl.
 : @param $degrees specifies by how much the image is to be swirled.
 : @return A swirled version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:swirl($image as xs:base64Binary, $degrees as xs:double) as xs:base64Binary external;



(:~
 : Reduces noise from the passed image using a noise peak elemination filter.
 :
 : @param $image is the image for which to reduce noise.  
 : @param $order defines how much the noise is reduced.
 : @return A version of the passed image with reduced noise.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:reduce-noise($image as xs:base64Binary, $order as xs:double) as xs:base64Binary external; 
  
 
(:~
 : Contrasts image (enhances image intensity differences) by a given value.
 : 
 : @param $image is the image which to contrast.
 : @param $sharpen defines how much the image should be contrasted.
 : @return A new version of the passed image with the given contrast.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:contrast($image as xs:base64Binary, $sharpen as xs:double) as xs:base64Binary external;


(:~
 : Gamma corrects image.
 : Gamma values less than zero will erase the image.
 : 
 : @param $image is the image to gamma correct.
 : @param $gamma-value is the value for which to gamma correct the image.
 : @return A new, gamma correction version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:gamma($image as xs:base64Binary, $gamma-value as xs:double) as xs:base64Binary external;

(:~
 : Gamma corrects image for every color channel seperately.
 : Gamma values less than zero for any color will erase the corresponding color.
 : 
 : @param $image is the image to gamma correct.
 : @param $gamma-red is the value for which to gamma correct the red channel of the image.
 : @param $gamma-green is the value for which to gamma correct the green channel of the image.
 : @param $gamma-blue is the value for which to gamma correct the blue channel of the image.
 : @return A new, gamma correction version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:gamma($image as xs:base64Binary, $gamma-red as xs:double, $gamma-green as xs:double, $gamma-blue as xs:double) as xs:base64Binary external;

    
(:~
 : Applies the implode effect on the passed image (a sort of special effect).
 : 
 : @param $image is the image to implode.
 : @param $factor is the factor to implode to.
 : @return A imploded version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:implode($image as xs:base64Binary, $factor as xs:double) as xs:base64Binary external;


(:~
 : Oil paints the passed image (makes the image look as if it was an oil paint).
 :
 : @param $image is the image to oil paint.
 : @param $radius is the radius with which to oil paint.
 : @return A oil painted version of the passed image.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function man:oil-paint($image as xs:base64Binary, $radius as xs:double) as xs:base64Binary external;      
 
 
(:~
 : Adds a digital watermark to $image based on the image $watermark.
 : 
 : @param $image is the image to which to apply the watermark.
 : @param $watermark is the image which contains the watermark data.
 : @return A version of $image with a digital watermark in form of $watermark.
 : @error If any of the passed xs:base64Binaries are not a valid image type.
 :)
declare function man:watermark($image as xs:base64Binary, $watermark as xs:base64Binary) as xs:base64Binary external;  


