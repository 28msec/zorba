import module namespace raytracer="http://www.xqsharp.com/raytracer" at "raytracer.xqlib";
import module namespace scene="http://www.xqsharp.com/raytracer/scene" at "scene.xqlib";

declare namespace serialization="http://www.xqsharp.com/serialization";
declare option serialization:method "text";
declare option serialization:encoding "us-ascii";

declare variable $width as xs:integer := 10;
declare variable $height as xs:integer := 10;

declare variable $scene := scene:prepare-scene(doc("scene.xml")/scene);

string-join(
  (
    (: Magic number identifying the file as a "plain" ppm file :)
    "P3",
    
    (: width and height :)
    string-join((string($width), string($height)), " "),
    
    (: Maximum color value :)
    "255",

    (:
     : Now the pixel data.  We take each pixel in the image, and recenter it, so that the
     : y co-ordinate ($y-recentered) ranges from -0.5 at the bottom of the image, to 0.5 
     : at the top of the image.
     :        
     : The aspect ratio is used to "stretch" the range of x-coordinate values to stop the
     : image from being skewed.
     :)
    let $aspect-ratio := $width div $height
    for $y in 1 to $height
    let $y-recentered := ((-$y div $height) + 0.5)
    for $x in 1 to $width
    let $x-recentered := (($x div $width) - 0.5) * $aspect-ratio
    return
      (: plot-pixel returns us the rgb values of the color of this pixel.  We convert these
         to an integer value in the range [0, 255], and output them. :)
      string-join(
        for $channel in raytracer:plot-pixel($scene, $x-recentered, $y-recentered)
        return string(floor($channel * 255)),
        " ")

  ),
  "&#xA;"
), "&#xA;"
