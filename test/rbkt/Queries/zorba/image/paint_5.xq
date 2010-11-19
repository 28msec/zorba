(:~
 : Simple test module for the paint functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


declare variable $local:jpg as xs:base64Binary := basic:create(xs:unsignedInt(100), xs:unsignedInt(100), image:imageType("JPEG"));


(:~
 : Outputs a nice error message to the screen ...
 :
 : @param $messsage is the message to be displayed
 : @return The passed message but really very, very nicely formatted.
 :)
declare function local:error($messages as xs:string*) as xs:string* {
  "
************************************************************************
ERROR:
  Location:", file:path-to-full-path("."), "
  Cause:",
  $messages,
  "
************************************************************************
"
};



(:~
 : @return true if the man:draw-circle function works.
 :)
declare function local:test-draw-circle() as xs:boolean {
    let $draw := paint:draw-circle($local:jpg, 20, 20, 10 , (), (), (), ())
    let $draw-ref := file:read(concat($local:image-dir, "paint/circle.jpg"))
    return basic:equals($draw, $draw-ref)
};


(:~
 : @return true if the man:draw-ellipse function works.
 :)
declare function local:test-draw-ellipse() as xs:boolean {
    let $draw := paint:draw-ellipse($local:jpg, 50, 50, 10, 20, (), (), (), ())
    let $draw-ref := file:read(concat($local:image-dir, "paint/ellipse.jpg"))
    return basic:equals($draw, $draw-ref)
};

(:~
 : @return true if the man:draw-arc function works.
 :)
declare function local:test-draw-arc() as xs:boolean {
    let $draw := paint:draw-arc($local:jpg, 50, 50, 10, 20, 180, 270, (), (), (), ())
    let $draw-ref := file:read(concat($local:image-dir, "paint/arc.jpg"))
    return basic:equals($draw, $draw-ref)
};

(:~
 : @return true if the man:draw-arc function works.
 :)
declare function local:test-draw-red-arc() as xs:boolean {
    let $draw := paint:draw-arc($local:jpg, 50, 50, 10, 20, 180, 270, "#FF0000", (), (), ())
    let $draw-ref := file:read(concat($local:image-dir, "paint/arcRed.jpg"))
    return basic:equals($draw, $draw-ref)
};

(:~
 : @return true if the man:draw-arc function works.
 :)
declare function local:test-draw-red-green-arc() as xs:boolean {
    let $draw := paint:draw-arc($local:jpg, 50, 50, 10, 20, 180, 270, "#FF0000", "#00AF00", (), ())
    let $draw-ref := file:read(concat($local:image-dir, "paint/arcRedGreen.jpg"))
    return basic:equals($draw, $draw-ref)
};

(:~
 : @return true if the man:draw-arc function works.
 :)
declare function local:test-draw-wide-arc() as xs:boolean {
    let $draw := paint:draw-arc($local:jpg, 50, 50, 10, 20, 180, 270, "#FF0000", "#00AF00", 5, ())
    let $draw-ref := file:read(concat($local:image-dir, "paint/arcWide.jpg"))
    return basic:equals($draw, $draw-ref)
};



(:~
 : @return true if the man:draw-arc function works.
 :)
declare function local:test-draw-anti-aliased-arc() as xs:boolean {
    let $draw := paint:draw-arc($local:jpg, 50, 50, 10, 20, 180, 270, "#FF0000", "#00AF00", 5, true())
    let $draw-ref := file:read(concat($local:image-dir, "paint/arcAntiAliased.jpg"))
    return basic:equals($draw, $draw-ref)
};





declare sequential function local:main() as xs:string* {

  let $a := local:test-draw-circle()
  return
    if (fn:not($a)) then
      exit returning local:error(("Drawing a circle on an image failed."))
    else ();
    
  let $b := local:test-draw-ellipse()
  return
    if (fn:not($b)) then
      exit returning local:error(("Drawing an ellipse on an image failed."))
    else ();  
              
    
  let $c := local:test-draw-arc()
  return
    if (fn:not($c)) then
      exit returning local:error(("Drawing an arc on an image failed."))
    else ();  
                         
  let $d := local:test-draw-red-arc()
  return
    if (fn:not($d)) then
      exit returning local:error(("Drawing a red arc on an image failed."))
    else ();  
    
  let $e := local:test-draw-red-green-arc()
  return
    if (fn:not($e)) then
      exit returning local:error(("Drawing a red arc with green background on an image failed."))
    else ();  
  
  let $f := local:test-draw-wide-arc()
  return
    if (fn:not($f)) then
      exit returning local:error(("Drawing an arc with wide strokes on an image failed."))
    else ();    
      
  let $g := local:test-draw-anti-aliased-arc()
  return
    if (fn:not($g)) then
      exit returning local:error(("Drawing an anti-aliased arc with wide strokes on an image failed."))
    else ();    
      
      
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

    


};

local:main();



