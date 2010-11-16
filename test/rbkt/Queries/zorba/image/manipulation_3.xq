(:~
 : Simple test module for the manipulation functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace man = 'http://www.zorba-xquery.com/modules/image/manipulation';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "images/");


declare variable $local:jpg as xs:base64Binary :=  file:read(concat($local:image-dir, "bird.jpg"));


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
 : @return true if the man:despecle function works.
 :)
declare function local:test-despeckle() as xs:boolean {
    let $despeckled := man:despeckle($local:jpg)
    let $despeckled-ref :=  file:read(concat($local:image-dir, "manipulation/despeckledBird.jpg"))
    return basic:equals($despeckled, $despeckled-ref)
};


(:~
 : @return true if the man:despecle function works.
 :)
declare function local:test-enhance() as xs:boolean {
    let $enhanced := man:enhance(man:enhance($local:jpg))
    let $enhanced-ref :=  file:read(concat($local:image-dir, "manipulation/enhancedBird.jpg"))
    return basic:equals($enhanced, $enhanced-ref)
};



(:~
 : @return true if the man:charcoal function works.
 :)
declare function local:test-charcoal() as xs:boolean {
    let $charcoaled := man:charcoal($local:jpg, 0.5, 0.5)
    let $charcoaled-ref :=  file:read(concat($local:image-dir, "manipulation/charcoaledBird.jpg"))
    return basic:equals($charcoaled, $charcoaled-ref)
};


(:~
 : @return true if the man:solarize function works.
 :)
declare function local:test-solarize() as xs:boolean {
    let $solarized := man:solarize($local:jpg, 0.3)
    let $solarized-ref :=  file:read(concat($local:image-dir, "manipulation/solarizedBird.jpg"))
    return basic:equals($solarized, $solarized-ref)
};


declare sequential function local:main() as xs:string* {

  let $a := local:test-despeckle()
  return
    if (fn:not($a)) then
      exit returning local:error(("Despecle of images failed."))
    else ();
    
  let $b := local:test-enhance()
  return
    if (fn:not($b)) then
      exit returning local:error(("Enhancing of images failed."))
    else ();
    
    
  let $g := local:test-solarize()
  return
    if (fn:not($g)) then
      exit returning local:error(("Solarize of images failed."))
    else ();    
    
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

    


};

local:main();



