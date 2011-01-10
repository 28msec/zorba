(:~
 : This example creates a new image using the image/basic function and paints different sorts of circles and arcs onto it. 
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $image-with-circles, <method>binary</method>), send it in an email etc.
 : 
 : Actually, as the paint function accepts sequences of shapes, it would have been possible to paint all circles, ellipses and arcs with one single command
 : paint:paint($new-image, (<image:circle><origin><x>20</x><y>20</y></origin><perimeter>20</perimeter></image:circle>,
 :                          <image:ellipse><origin><x>40</x><y>70</y></origin><perimeterX>20</perimeterX><perimeterY>10</perimeterY></image:ellipse>,
 :                          <image:arc><origin><x>70</x><y>35</y></origin><perimeterX>15</perimeterX><perimeterY>25</perimeterY><startDegrees>90</startDegrees><endDegrees>180</endDegrees></image:arc>,
 :                          <image:circle><fillColor>#0000FF</fillColor><origin><x>80</x><y>20</y></origin><perimeter>20</perimeter></image:circle>))
 :                           
 : However, here it is done with several function calls to make it more clear what exactly is painted.
 :
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';

import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

let $new-image :=  basic:create(xs:unsignedInt(100), xs:unsignedInt(100), "GIF")

(: paint a simple circle with origin in (20, 20) and a perimeter of 20px to the image :)
let $image-with-circle := paint:paint($new-image, <image:circle><origin><x>20</x><y>20</y></origin><perimeter>20</perimeter></image:circle>)

(: paint an ellipse to the image :)
let $image-with-circles := paint:paint($image-with-circle, <image:ellipse><origin><x>40</x><y>70</y></origin><perimeterX>20</perimeterX><perimeterY>10</perimeterY></image:ellipse>)

(: paint an arc from 90 to 180 degrees to the image :)
let $image-with-circles := paint:paint($image-with-circles, <image:arc><origin><x>70</x><y>35</y></origin><perimeterX>15</perimeterX><perimeterY>25</perimeterY><startDegrees>90</startDegrees><endDegrees>180</endDegrees></image:arc>)

(: paint a blue circle with black contour onto the image :)
let $image-with-circles := paint:paint($image-with-circles, <image:circle><fillColor>#0000FF</fillColor><origin><x>80</x><y>20</y></origin><perimeter>20</perimeter></image:circle>)


return not(empty($image-with-circles)) 

