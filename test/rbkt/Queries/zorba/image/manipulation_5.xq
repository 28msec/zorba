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
 : @return true if the man:gamma function works.
 :)
declare function local:test-gamma() as xs:boolean {
    let $gamma1 := man:gamma($local:gif, 1.8)
    let $gamma1-ref := file:read-binary(concat($local:image-dir, "manipulation/gamma1Bird.gif"))
    return basic:equals($gamma1, $gamma1-ref)
};

(:~
 : @return true if the man:gamma with seperate values for each color (rgb) function works.
 :)
declare function local:test-gamma-rgb() as xs:boolean {
    let $gamma2 := man:gamma($local:gif, 1.8, 4, 1)
    let $gamma2-ref := file:read-binary(concat($local:image-dir, "manipulation/gamma2Bird.gif"))
    return basic:equals($gamma2, $gamma2-ref)
};

(:~
 : @return true if the man:implode function works.
 :)
declare function local:test-implode() as xs:boolean {
    let $implode := man:implode($local:gif, 0.6)
    let $implode-ref := file:read-binary(concat($local:image-dir, "manipulation/implodeBird.gif"))
    return basic:equals($implode, $implode-ref)
};

(:~
 : @return true if the man:oil-paint function works.
 :)
declare function local:test-oil-paint() as xs:boolean {
    let $oil-paint := man:oil-paint($local:gif, 0.6)
    let $oil-paint-ref := file:read-binary(concat($local:image-dir, "manipulation/oilPaintBird.gif"))
    return basic:equals($oil-paint,  $oil-paint-ref)
};

(:~
 : @return true if the man:watermark function works.
 :)
declare function local:test-watermark() as xs:boolean {
  let $watermark := man:watermark($local:gif, $local:jpg)
  let $watermark-ref := file:read-binary(concat($local:image-dir, "manipulation/watermarked.gif"))
  return basic:equals($watermark, $watermark-ref)

};


declare sequential function local:main() as xs:string* {

  let $a := local:test-gamma()
  return
    if (fn:not($a)) then
      exit returning local:error(("Gamma correction of images failed."))
    else ();
    
  let $b := local:test-gamma-rgb()
  return
    if (fn:not($b)) then
      exit returning local:error(("Gamma correction of images failed."))
    else ();  
 
  let $c := local:test-implode()
  return
    if (fn:not($c)) then
      exit returning local:error(("Implode of images failed."))
    else ();  
 
  let $d := local:test-oil-paint()
  return
    if (fn:not($d)) then
      exit returning local:error(("Oil paint of images failed."))
    else ();  
        
  let $e := local:test-watermark()
  return
    if (fn:not($e)) then
      exit returning local:error(("Applying watermark to image failed."))
    else ();

          
    
  (: If all went well ... make sure the world knows! :) 
  "SUCCESS";

    


};

local:main();



