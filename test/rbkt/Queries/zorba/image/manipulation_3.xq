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
 : @return true if the man:despecle function works.
 :)
declare function local:test-despeckle() as xs:boolean {
    let $despeckled := man:despeckle($local:jpg)
    let $despeckled-ref := file:read("images/manipulation/despeckledBird.jpg")
    return($despeckled eq $despeckled-ref)
};


(:~
 : @return true if the man:despecle function works.
 :)
declare function local:test-enhance() as xs:boolean {
    let $enhanced := man:enhance(man:enhance($local:jpg))
    let $enhanced-ref := file:read("images/manipulation/enhancedBird.jpg")
    return($enhanced eq $enhanced-ref)
};

(:~
 : @return true if the man:equalize function works.
 :)
declare function local:test-equalize() as xs:boolean {
    let $equalized := man:equalize($local:jpg)
    let $equalized-ref := file:read("images/manipulation/equalizedBird.jpg")
    return($equalized eq $equalized-ref)
};

(:~
 : @return true if the man:edge function works.
 :)
declare function local:test-edge() as xs:boolean {
    let $edged := man:edge($local:jpg, xs:unsignedInt(0))
    let $edged-ref := file:read("images/manipulation/edgedBird.jpg")
    return($edged eq $edged-ref)
};


(:~
 : @return true if the man:charcoal function works.
 :)
declare function local:test-charcoal() as xs:boolean {
    let $charcoaled := man:charcoal($local:jpg, -0.5, -0.5)
    let $charcoaled-ref := file:read("images/manipulation/charcoaledBird.jpg")
    return($charcoaled eq $charcoaled-ref)
};


(:~
 : @return true if the man:emboss function works.
 :)
declare function local:test-emboss() as xs:boolean {
    let $embossed := man:emboss($local:jpg, 0.1, 0.1)
    let $embossed-ref := file:read("images/manipulation/embossedBird.jpg")
    return($embossed eq $embossed-ref)
};

(:~
 : @return true if the man:solarize function works.
 :)
declare function local:test-solarize() as xs:boolean {
    let $solarized := man:solarize($local:jpg, 0.3)
    let $solarized-ref := file:read("images/manipulation/solarizedBird.jpg")
    return($solarized eq $solarized-ref)
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
    
  let $c := local:test-equalize()
  return
    if (fn:not($c)) then
      exit returning local:error(("Equalizing of images failed."))
    else ();
  
  let $d := local:test-edge()
  return
    if (fn:not($d)) then
      exit returning local:error(("Edging of images failed."))
    else ();
  
  let $e := local:test-charcoal()
  return
    if (fn:not($e)) then
      exit returning local:error(("Charcoal of images failed."))
    else ();
    
    
  let $f := local:test-emboss()
  return
    if (fn:not($f)) then
      exit returning local:error(("Emboss of images failed."))
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



