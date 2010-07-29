(:~
 : Simple test module for the manipulation functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace man = 'http://www.zorba-xquery.com/modules/image/manipulation';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

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
 : @return true if the man:rotate function works.
 :)
declare function local:test-rotate() as xs:boolean {
    let $rotated := man:rotate($local:jpg, xs:int(180))
    let $rotated-ref := file:read("images/manipulation/rotatedBird.jpg")
    return($rotated eq $rotated-ref)
};



(:~
 : @return true if the man:rotate function works.
 :)
declare function local:test-erase() as xs:boolean {
    let $erased := man:erase($local:jpg)
    let $erased-ref := file:read("images/manipulation/erased.jpg")
    return($erased eq $erased-ref)
};

(:~
 : @return true if the man:flop function works.
 :)
declare function local:test-flop() as xs:boolean {
    let $flopped := man:flop($local:jpg)
    let $flopped-ref := file:read("images/manipulation/floppedBird.jpg")
    return($flopped eq $flopped-ref)
};


(:~
 : @return true if the man:flip function works.
 :)
declare function local:test-flip() as xs:boolean {
    let $flipped := man:flip($local:jpg)
    let $flipped-ref := file:read("images/manipulation/flippedBird.jpg")
    return($flipped eq $flipped-ref)
};

(:~
 : @return true if the man:trim function works.
 :)
declare function local:test-trim() as xs:boolean {
    let $trimmed := man:trim($local:jpg)
    let $trimmed-ref := file:read("images/manipulation/trimmedBird.jpg")
    return($trimmed eq $trimmed-ref)
};



(:~
 : @return true if the man:blur function works.
 :)
declare function local:test-blur() as xs:boolean {
    let $blurred := man:blur($local:jpg, xs:int(8), xs:int(-4))
    let $blurred-ref := file:read("images/manipulation/blurredBird.jpg")
    return($blurred eq $blurred-ref)
};




declare sequential function local:main() as xs:string* {

  let $a := local:test-rotate()
  return
    if (fn:not($a)) then
      exit returning local:error(("Rotating of images failed."))
    else ();
    
  let $b := local:test-erase()
  return
    if (fn:not($b)) then
      exit returning local:error(("Erasing of images failed."))
    else ();  
    
  let $c := local:test-flop()
  return
    if (fn:not($c)) then
      exit returning local:error(("Flop of images failed."))
    else ();  
        
  let $d := local:test-flip()
  return
    if (fn:not($d)) then
      exit returning local:error(("Flip of images failed."))
    else ();  
          
  let $e := local:test-trim()
  return
    if (fn:not($e)) then
      exit returning local:error(("Trim of images failed."))
    else ();  
    
           
  let $g := local:test-blur()
  return
    if (fn:not($g)) then
      exit returning local:error(("Blurring of images failed."))
    else ();     
    
  
    
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

    


};

local:main();



