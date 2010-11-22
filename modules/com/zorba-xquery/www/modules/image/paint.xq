(:~
 : This module provides functions to handle basic painting operations on images.<br></br> 
 : 
 : The paint function takes an image and a sequence of elements which extend paintableType as defined in the image schema and applies each element to the passed image.<br></br>
 : Every paintable element can optionally contain strokeWidth, strokeColor, fillColor, antiAliasing elements at its beginning.<br></br>
 : <ul>
 :  <li>Following shapes are paintable:
 :    <ul>
 :      <li> line: <code>&lt;image:line&gt;&lt;start&gt;&lt;x&gt;-20&lt;/x&gt;&lt;y&gt;-20&lt;/y&gt;&lt;/start&gt;&lt;end&gt;&lt;x&gt;80&lt;/x&gt;&lt;y&gt;80&lt;/y&gt;&lt;/end&gt;&lt;/image:line&gt;</code></li> 
 :       <li> polyLine: <code>&lt;image:polyLine&gt;&lt;point&gt;&lt;x&gt;10&lt;/x&gt;&lt;y&gt;10&lt;/y&gt;&lt;/point&gt;&lt;point&gt;&lt;x&gt;40&lt;/x&gt;&lt;y&gt;80&lt;/y&gt;&lt;/point&gt;&lt;point&gt;&lt;x&gt;50&lt;/x&gt;&lt;y&gt;30&lt;/y&gt;&lt;/point&gt;&lt;point&gt;&lt;x&gt;200&lt;/x&gt;&lt;y&gt;200&lt;/y&gt;&lt;/point&gt;&lt;/image:polyLine&gt; </code></li>
 :       <li> strokedPolyLine: <code>&lt;image:strokedPolyLine&gt;&lt;point&gt;&lt;x&gt;10&lt;/x&gt;&lt;y&gt;10&lt;/y&gt;&lt;/point&gt;&lt;point&gt;&lt;x&gt;40&lt;/x&gt;&lt;y&gt;80&lt;/y&gt;&lt;/point&gt;&lt;point&gt;&lt;x&gt;50&lt;/x&gt;&lt;y&gt;30&lt;/y&gt;&lt;/point&gt;&lt;strokeLength&gt;5&lt;/strokeLength&gt;&lt;gapLength&gt;2&lt;/gapLength&gt;&lt;/image:strokedPolyLine&gt;</code></li>
 :       <li> rectangle:<code>&lt;image:rectangle&gt;&lt;upperLeft&gt;&lt;x&gt;20&lt;/x&gt;&lt;y&gt;20&lt;/y&gt;&lt;/upperLeft&gt;&lt;lowerRight&gt;&lt;x&gt;50&lt;/x&gt;&lt;y&gt;50&lt;/y&gt;&lt;/lowerRight&gt;&lt;/image:rectangle&gt;&lt;/code&gt;&lt;/li&gt;</code></li>
 :       <li> roundedRectangle: <code>&lt;image:roundedRectangle&gt;&lt;upperLeft&gt;&lt;x&gt;20&lt;/x&gt;&lt;y&gt;20&lt;/y&gt;&lt;/upperLeft&gt;&lt;lowerRight&gt;&lt;x&gt;50&lt;/x&gt;&lt;y&gt;50&lt;/y&gt;&lt;/lowerRight&gt;&lt;cornerWidth&gt;10&lt;/cornerWidth&gt;&lt;cornerHeight&gt;10&lt;/cornerHeight&gt;&lt;/image:roundedRectangle&gt;</code></li>
 :       <li> circle: <code>&lt;image:circle&gt;&lt;origin&gt;&lt;x&gt;20&lt;/x&gt;&lt;y&gt;20&lt;/y&gt;&lt;/origin&gt;&lt;perimeter&gt;5&lt;/perimeter&gt;&lt;/image:circle&gt;</code></li>
 :       <li> ellipse: <code>&lt;image:ellipse&gt;&lt;origin&gt;&lt;x&gt;50&lt;/x&gt;&lt;y&gt;50&lt;/y&gt;&lt;/origin&gt;&lt;perimeterX&gt;30&lt;/perimeterX&gt;&lt;perimeterY&gt;20&lt;/perimeterY&gt;&lt;/image:ellipse&gt;</code></li>
 :       <li> arc: <code>&lt;image:arc&gt;&lt;origin&gt;&lt;x&gt;50&lt;/x&gt;&lt;y&gt;50&lt;/y&gt;&lt;/origin&gt;&lt;perimeterX&gt;10&lt;/perimeterX&gt;&lt;perimeterY&gt;20&lt;/perimeterY&gt;&lt;startDegrees&gt;180&lt;/startDegrees&gt;&lt;endDegrees&gt;270&lt;/endDegrees&gt;&lt;/image:arc&gt;</code></li>
 :       <li> polygon: <code>&lt;image:polygon&gt;&lt;point&gt;&lt;x&gt;10&lt;/x&gt;&lt;y&gt;10&lt;/y&gt;&lt;/point&gt;&lt;point&gt;&lt;x&gt;40&lt;/x&gt;&lt;y&gt;80&lt;/y&gt;&lt;/point&gt;&lt;point&gt;&lt;x&gt;50&lt;/x&gt;&lt;y&gt;30&lt;/y&gt;&lt;/point&gt;&lt;/image:polygon&gt;</code></li>
 :       <li> text: <code>&lt;image:text&gt;&lt;origin&gt;&lt;x&gt;20&lt;/x&gt;&lt;y&gt;20&lt;/y&gt;&lt;/origin&gt;&lt;text&gt;Hello Zorba&lt;/text&gt;&lt;font&gt;&lt;/font&gt;&lt;font-size&gt;12&lt;/font-size&gt;&lt;/image:text&gt;</code></li>
 :
 :     </ul>
 :    </li>
 :  </ul>  
 :
 : @author Daniel Thomas
 : @library <a href="http://www.imagemagick.org/Magick++/">Magick++ C++ Library</a>
 :
 :)
module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';

(:~
 : Contains the definitions of the possible image types.
 :)
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';


(:~
 : Paints a sequence of paintable shapes to the passed image.<br></br>
 : 
 : The paintable shapes are definened in the image namespace, each of them is an extension of paintableType.
 :
 : @param $image is the image to paint to.
 : @param $shapes is a sequence of shapes that should be painted to the image.
 : @return The passed image with the specified shapes painted.
 : @error If the passed xs:base64Binary is not a valid image type.
 : @error If an item of the shapes sequence is not valid.
 :)
declare function paint:paint($image as xs:base64Binary, $shapes as element()*) as xs:base64Binary  {
  
  paint:paint-impl($image, for $x in $shapes return validate{$x})
};


(:~
 : Paints a sequence of paintable shapes to the passed image.
 :
 : @param $image is the image to paint to.
 : @param $shapes is a sequence of shapes that should be painted to the image.
 : @return The passed image with the specified shapes painted.
 : @error If the passed xs:base64Binary is not a valid image type.
 : @error If an item of the shapes sequence is not valid.
 :)
declare %private function paint:paint-impl($image as xs:base64Binary, $shapes as element(*, image:paintableType)*) as xs:base64Binary external; 

