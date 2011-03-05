(:~
 : Simple test module for the manipulation functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace man = 'http://www.zorba-xquery.com/modules/image/manipulation';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


declare variable $local:png as xs:base64Binary := file:read-binary(concat($local:image-dir, "bird.png"));
declare variable $local:gif as xs:base64Binary := file:read-binary(concat($local:image-dir, "bird.gif"));
declare variable $local:tiff as xs:base64Binary := file:read-binary(concat($local:image-dir, "bird.tiff"));
declare variable $local:jpg as xs:base64Binary := file:read-binary(concat($local:image-dir, "bird.jpg"));


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
 : @return true if the man:resize function works.
 :)
declare function local:test-resize() as xs:boolean {
    let $resized := man:resize($local:gif, xs:unsignedInt(500), xs:unsignedInt(600))
    let $resized-ref as xs:base64Binary := file:read-binary(concat($local:image-dir, "manipulation/bigBird.gif"))
    return basic:equals($resized, $resized-ref)
};



(:~
 : @return true if the man:zoom function works.
 :)
declare function local:test-zoom() as xs:boolean {
    let $zoomed := man:zoom($local:jpg, 2)
    let $ref-zoomed := file:read-binary(concat($local:image-dir, "manipulation/zoomedBird.jpg"))
    return basic:equals($zoomed, $ref-zoomed)
};




(:~
 : @return true if the man:zoom-by-width function works.
 :)
declare function local:test-zoom-by-width() as xs:boolean {
    let $zoomed := man:zoom-by-width($local:jpg, xs:unsignedInt(268))
    let $ref-zoomed := file:read-binary(concat($local:image-dir, "manipulation/zoomedBird.jpg"))
    return basic:equals($zoomed, $ref-zoomed)
};

(:~
 : @return true if the man:zoom-by-height function works.
 :)
declare function local:test-zoom-by-height() as xs:boolean {
    let $zoomed := man:zoom-by-height($local:jpg, xs:unsignedInt(320))
    let $ref-zoomed := file:read-binary(concat($local:image-dir, "manipulation/zoomedBird.jpg"))
    return basic:equals($zoomed, $ref-zoomed)
};

(:~
 : @return true if the man:sub-image function works.
 :)
declare function local:test-sub-image() as xs:boolean {
    let $sub := man:sub-image($local:jpg, xs:unsignedInt(20), xs:unsignedInt(20), xs:unsignedInt(200), xs:unsignedInt(30))
    let $ref-sub := file:read-binary(concat($local:image-dir, "manipulation/subBird.jpg"))
    return basic:equals($sub, $ref-sub)
};

(:~
 : @return true if the man:overlay function works.
 :)
declare function local:test-overlay() {
    let $ref-overlay:= file:read-binary(concat($local:image-dir, "manipulation/overlayBird.jpg"))
    let $ref-zoomed := file:read-binary(concat($local:image-dir, "manipulation/zoomedBird.jpg"))
    return basic:equals(man:overlay($ref-zoomed, $local:png, xs:unsignedInt(50), xs:unsignedInt(50), 
            "AtopCompositeOp"), $ref-overlay) 
};




declare sequential function local:main() as xs:string* {

  let $a := local:test-resize()
  return
    if (fn:not($a)) then
      exit returning local:error(("Resizing of images failed."))
    else ();
    
    
  let $b := local:test-zoom()
  return
    if (fn:not($b)) then
      exit returning local:error(("Zooming of image failed."))
    else ();   
    
    
  let $c := local:test-zoom-by-width()
  return
    if (fn:not($c)) then
      exit returning local:error(("Zooming of image by width failed."))
    else ();
              
  let $d := local:test-zoom-by-height()
  return
    if (fn:not($d)) then
      exit returning local:error(("Zooming of image by height failed."))
    else (); 
    
  let $f := local:test-sub-image()
  return
    if (fn:not($f)) then
      exit returning local:error("Extracting sub image failed.")     
    else();
      
  let $g := local:test-overlay()
  return
    if (fn:not($g)) then
      exit returning local:error("Overlaying of image failed.")     
    else(); 
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

    


};

local:main();


