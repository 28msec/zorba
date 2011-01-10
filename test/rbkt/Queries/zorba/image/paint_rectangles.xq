(:~
 : This example creates a new image using the image/basic function and paints different sorts of rectangles onto it. 
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $image-with-rectangles, <method>binary</method>), send it in an email etc.
 :
 : Actually, all rectangles could have been painted with one single function call, as the paint function also takes sequences of shapes with
 : paint:paint($new-image, (<image:rectangle><upperLeft><x>10</x><y>10</y></upperLeft><lowerRight><x>20</x><y>20</y></lowerRight></image:rectangle>,
 :                         <image:roundedRectangle><upperLeft><x>30</x><y>30</y></upperLeft><lowerRight><x>50</x><y>60</y></lowerRight><corne
 rWidth>10</cornerWidth><cornerHeight>10</cornerHeight></image:roundedRectangle>,
 :                          <image:rectangle><strokeColor>#00FF00</strokeColor><fillColor>#FF0000</fillColor><upperLeft><x>75</x><y>10</y></u
 pperLeft><lowerRight><x>95</x><y>50</y></lowerRight></image:rectangle>))
 :
 : However, to make clear what exaclty is painted it was done with several function calls in this example (which is less performant).
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';

import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

let $new-image :=  basic:create(xs:unsignedInt(100), xs:unsignedInt(100), "GIF")

(: paint a simple rectangle to the image :) 
let $image-with-rectangle := paint:paint($new-image, <image:rectangle><upperLeft><x>10</x><y>10</y></upperLeft><lowerRight><x>20</x><y>20</y></lowerRight></image:rectangle>) 

(: paint a rounded rectangle to the image with a corner width of 10px and a corner height of 10 px :) 
let $image-with-rectangles := paint:paint($image-with-rectangle, <image:roundedRectangle><upperLeft><x>30</x><y>30</y></upperLeft><lowerRight><x>50</x><y>60</y></lowerRight><cornerWidth>10</cornerWidth><cornerHeight>10</cornerHeight></image:roundedRectangle>)

(: paint a rectangle with green contour which is filled with red to the image :)  
let $image-with-rectangles := paint:paint($image-with-rectangles, <image:rectangle><strokeColor>#00FF00</strokeColor><fillColor>#FF0000</fillColor><upperLeft><x>75</x><y>10</y></upperLeft><lowerRight><x>95</x><y>50</y></lowerRight></image:rectangle>)

return not(empty($image-with-rectangles)) 
