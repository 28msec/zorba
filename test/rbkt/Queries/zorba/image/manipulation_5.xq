(:~
 : Simple test module for the manipulation functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace man = 'http://www.zorba-xquery.com/modules/image/manipulation';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

declare variable $local:png as xs:base64Binary := file:read("images/bird.png");
declare variable $local:gif as xs:base64Binary := file:read("images/bird.gif");
declare variable $local:tiff as xs:base64Binary := file:read("images/bird.tiff");
declare variable $local:jpg as xs:base64Binary := file:read("images/bird.jpg");


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
    let $gamma1-ref := file:read("images/manipulation/gamma1Bird.gif")
    return($gamma1 eq $gamma1-ref)
};

(:~
 : @return true if the man:gamma with seperate values for each color (rgb) function works.
 :)
declare function local:test-gamma-rgb() as xs:boolean {
    let $gamma2 := man:gamma($local:gif, 1.8, 4, 1)
    let $gamma2-ref := file:read("images/manipulation/gamma2Bird.gif")
    return($gamma2 eq $gamma2-ref)
};

(:~
 : @return true if the man:implode function works.
 :)
declare function local:test-implode() as xs:boolean {
    let $implode := man:implode($local:gif, 0.6)
    let $implode-ref := file:read("images/manipulation/implodeBird.gif")
    return($implode eq $implode-ref)
};

(:~
 : @return true if the man:oil-paint function works.
 :)
declare function local:test-oil-paint() as xs:boolean {
    let $oil-paint := man:oil-paint($local:gif, 0.6)
    let $oil-paint-ref := file:read("images/manipulation/oilPaintBird.gif")
    return($oil-paint eq $oil-paint-ref)
};

(:~
 : @return true if the man:watermark function works.
 :)
declare function local:test-watermark() as xs:boolean {
  let $watermark := man:watermark($local:gif, $local:jpg)
  let $watermark-ref := file:read("images/manipulation/watermarked.gif")
  return ($watermark eq $watermark-ref)

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



