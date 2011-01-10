(:~
 : This example creates a new image using the image/basic function and paints a polygon to it. 
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $image-with-polygon, <method>binary</method>), send it in an email etc.
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic'; 
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';

import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

let $new-image :=  basic:create(xs:unsignedInt(100), xs:unsignedInt(100), "GIF")

(: paint an anti-aliased polyline which goes through the points (0,0) (30, 70), (20, 18), (89, 33) :)
let $image-with-polygon := paint:paint($new-image, <image:polygon><antiAliasing>true</antiAliasing><point><x>0</x><y>0</y></point><point><x>30</x><y>70</y></point><point><x>20</x><y>18</y></point><point><x>89</x><y>33</y></point></image:polygon>)

return not(empty($image-with-polygon)) 

