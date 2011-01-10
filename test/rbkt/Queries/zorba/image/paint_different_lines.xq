(:~
 : This example creates a new image using the image/basic function and paints a few different colored lines to it.
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $image-with-4-line, <method>binary</method>), send it in an email etc.
 :
 : Actually, as the paint function takes a sequence of shapes all lines could have been painted with one single function call with
 : paint:paint($new-image, (<image:line><start><x>10</x><y>0</y></start><end><x>10</x><y>100</y></end></image:line>,
                            <image:line><strokeColor>#FF0000</strokeColor><start><x>30</x><y>0</y></start><end><x>30</x><y>100</y></end></image:line>,
                            <image:line><strokeColor>#FF0000</strokeColor><antiAliasing>true</antiAliasing><start><x>50</x><y>0</y></start><end><x>50</x><y>100</y></end></image:line>,                        <image:line><strokeWidth>10</strokeWidth><strokeColor>#FF0000</strokeColor><antiAliasing>true</antiAliasing><start><x>70</x><y>0</y></start><end><x>70</x><y>100</y></end></image:line>)
 :
 : However, to show exactly what is painted it was done with several function calls in this example (which is much less performant).
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic'; 
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';

import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

let $new-image :=  basic:create(xs:unsignedInt(100), xs:unsignedInt(100), "GIF")
(: paint a simple line from (10, 0) to (10, 100) :)
let $image-with-1-line := paint:paint($new-image, <image:line><start><x>10</x><y>0</y></start><end><x>10</x><y>100</y></end></image:line>)
(: paint a simple red line from (30, 0) to (30, 100) :)
let $image-with-2-line := paint:paint($image-with-1-line, <image:line><strokeColor>#FF0000</strokeColor><start><x>30</x><y>0</y></start><end><x>30</x><y>100</y></end></image:line>)
(: paint a simple red anti-aliased line from (50, 0) to (50, 100) :)
let $image-with-3-line := paint:paint($image-with-2-line, <image:line><strokeColor>#FF0000</strokeColor><antiAliasing>true</antiAliasing><start><x>50</x><y>0</y></start><end><x>50</x><y>100</y></end></image:line>)
(: paint a simple red wide anti-aliased line  from (70, 0) to (70, 100) :)
let $image-with-4-line := paint:paint($image-with-3-line, <image:line><strokeWidth>10</strokeWidth><strokeColor>#FF0000</strokeColor><antiAliasing>true</antiAliasing><start><x>70</x><y>0</y></start><end><x>70</x><y>100</y></end></image:line>)

return not(empty($image-with-4-line))

