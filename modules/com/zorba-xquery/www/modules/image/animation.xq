(:~
 : This module provides functions to handle animations of images. 
 : Please note that all images passed back by these functions described here are required to be written to disc as GIF.
 :
 : @author Daniel Thomas
 : @see http://www.zorba-xquery.com/modules/image/image
 : @library <a href="http://www.imagemagick.org/Magick++/">Magick++ C++ Library</a>
 :)
module namespace anim = 'http://www.zorba-xquery.com/modules/image/animation';





(:~
 : Creates an animated GIF image from the passed $images. The width and height of the first passed image will be used.
 :
 : @param $images are the images with which the animated GIF shall be created (in the right order).
 : @param $delay specifies how long a given image shows in the animated GIF in 1/100 of a second.
 : @param $iterations specifies how many times the animation loop should be executed (0 for endless loop).
 : @return A new image that is an animated GIF composed out of the passed images.
 : @error IM001 If any of the passed xs:base64Binary is not a valid image.
 :)
declare function anim:create-animated-gif($images as xs:base64Binary+, $delay as xs:unsignedInt, $iterations as xs:unsignedInt) as xs:base64Binary external; 


(:~
 : Creates an animated GIF image from the passed $images expanding the number of passed image frames by adding specified frames such that the original frames morph into each other. 
 : The width and height of the first passed image will be used.
 :
 : @param $images are the images with which the morphed GIF shall be created (in the right order).
 : @param $delay specifies how long a given image shows in the animated GIF in 1/100 of a second.
 : @param $iterations specifies how many times the animation loop should be executed (0 for endless loop).
 : @param $number-of-added-frames specifies how many frames shall be added to the passed frames for the morph effect.
 : @return A new image that is an animated GIF composed out of the passed images.
 : @error IM001 If any of the passed xs:base64Binary is not a valid image. 
 :)
declare function anim:create-morphed-gif($images as xs:base64Binary+, $delay as xs:unsignedInt, $iterations as xs:unsignedInt, $number-of-added-frames as xs:unsignedInt) as xs:base64Binary external; 

