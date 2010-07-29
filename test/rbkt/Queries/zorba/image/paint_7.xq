(:~
 : Simple test module for the paint functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

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
 : @return true if the man:draw-text function works.
 :)
declare function local:test-draw-text() as xs:boolean {
    let $draw := paint:draw-text($local:jpg, "Hello Zorba", 30, 40,  "Arial", (), (), (), ())
    let $draw-ref := file:read("images/paint/text.jpg")
    return ($draw eq $draw-ref)
};


(:~
 : @return true if the man:draw-text function works.
 :)
declare function local:test-draw-text-helvetica() as xs:boolean {
    let $draw := paint:draw-text($local:jpg, "Hello Zorba", 30, 40,  "Helvetica", (), (), (), ())
    let $draw-ref := file:read("images/paint/textHelvetica.jpg")
    return($draw eq $draw-ref)
};

(:~
 : @return true if the man:draw-text function works.
 :)
declare function local:test-draw-text-red() as xs:boolean {
    let $draw := paint:draw-text($local:jpg, "Hello Zorba", 30, 40,  "Arial", (), (), (), image:colorType("#FF0000"))
    let $draw-ref := file:read("images/paint/textRed.jpg")
    return($draw eq $draw-ref)
};

(:~
 : @return true if the man:draw-text function works.
 :)
declare function local:test-draw-text-big() as xs:boolean {
    let $draw := paint:draw-text($local:jpg, "Hello Zorba", 30, 40,  "Arial", 20, (), (), image:colorType("#FF0000"))
    let $draw-ref := file:read("images/paint/textBig.jpg")
    return($draw eq $draw-ref)
};

(:~
 : @return true if the man:draw-text function works.
 :)
declare function local:test-draw-text-italic() as xs:boolean {
    let $draw := paint:draw-text($local:jpg, "Hello Zorba", 30, 40,  "Arial", (), (), image:fontStyleType("Italic"), image:colorType("#FF0000"))
    let $draw-ref := file:read("images/paint/textItalic.jpg")
    return($draw eq $draw-ref)
};

(:~
 : @return true if the man:draw-text function works.
 :)
declare function local:test-draw-text-oblique() as xs:boolean {
    let $draw := paint:draw-text($local:jpg, "Hello Zorba", 30, 40,  "Helvetica", (), (), image:fontStyleType("Oblique"), image:colorType("#FF0000"))
    let $draw-ref := file:read("images/paint/textOblique.jpg")
    return($draw eq $draw-ref)
};

(:~
 : @return true if the man:draw-text function works.
 :)
declare function local:test-draw-text-heavy() as xs:boolean {
    let $draw := paint:draw-text($local:jpg, "Hello Zorba", 30, 40,  "Arial", (), image:fontWeightType(700), (), ())
    let $draw-ref := file:read("images/paint/textHeavy.jpg")
    return($draw eq $draw-ref)
};



declare sequential function local:main() as xs:string* {

  let $a := local:test-draw-text()
  return
    if (fn:not($a)) then
      exit returning local:error(("Drawing a text to an image failed."))
    else ();
  
  let $b := local:test-draw-text-helvetica()
  return
    if (fn:not($b)) then
      exit returning local:error(("Drawing a text in helvetica to an image failed."))
    else ();
    
    
  let $c := local:test-draw-text-red()
  return
    if (fn:not($c)) then
      exit returning local:error(("Drawing a red text to an image failed."))
    else ();    
  
  let $d := local:test-draw-text-big()
  return
    if (fn:not($d)) then
      exit returning local:error(("Drawing a big text to an image failed."))
    else ();    
      
  let $e := local:test-draw-text-italic()
  return
    if (fn:not($e)) then
      exit returning local:error(("Drawing a italic text to an image failed."))
    else ();    
        
  let $f := local:test-draw-text-oblique()
  return
    if (fn:not($f)) then
      exit returning local:error(("Drawing an oblique text to an image failed."))
    else ();               

  let $g := local:test-draw-text-heavy()
  return
    if (fn:not($g)) then
      exit returning local:error(("Drawing a heavy text to an image failed."))
    else ();               
            
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

    


};

local:main();



