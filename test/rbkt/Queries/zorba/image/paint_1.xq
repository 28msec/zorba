(:~
 : Simple test module for the paint functions of the image library.
 :
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

declare variable $local:image-dir := fn:concat(file:dir-of-base-uri(<a/>), "images/");


declare variable $local:gif as xs:base64Binary := basic:create(xs:unsignedInt(100), xs:unsignedInt(100), image:imageType("GIF"));


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
 : @return true if the man:draw-line function works.
 :)
declare function local:test-draw-line() as xs:boolean {
    let $draw := paint:draw-line($local:gif, -20, -20, 80, 80, (), (), ())
    let $draw-ref := file:read(concat($local:image-dir,"paint/line.gif"))
    return basic:equals($draw, $draw-ref)
};

(:~
 : @return true if the man:draw-line with passed red color (#6F0000) function works.
 :)
declare function local:test-draw-line-color-red() {
    let $draw := paint:draw-line($local:gif, 0, 0, 80, 80, "#6F0000", (), ())
    let $draw-ref := file:read(concat($local:image-dir,"paint/redLine.gif"))
    return basic:equals($draw, $draw-ref)

};

(:~
 : @return true if the man:draw-line with passed green color (#006F00) function works.
 :)
declare function local:test-draw-line-color-green() {
    let $draw := paint:draw-line($local:gif, 0, 0, 80, 80, "#006F00", (), ())
    let $draw-ref := file:read(concat($local:image-dir,"paint/greenLine.gif"))
    return basic:equals($draw, $draw-ref)

};

(:~
 : @return true if the man:draw-line with passed blue color (#00006F) function works.
 :)
declare function local:test-draw-line-color-blue() {
    let $draw := paint:draw-line($local:gif, 0, 0, 80, 80, "#00006F", (), ())
    let $draw-ref := file:read(concat($local:image-dir,"paint/blueLine.gif"))
    return basic:equals($draw, $draw-ref)

};

(:~
 : @return true if the man:draw-line with passed blue color (#00006F) function works.
 :)
declare function local:test-stroke-width() {
    let $draw := paint:draw-line($local:gif, 0, 0, 80, 80, "#000000", 10, false()) 
    let $draw2 := paint:draw-line($draw, 30, 0, 70, 90, "#FF00FF", 1, false())    
    let $draw2-ref := file:read(concat($local:image-dir,"paint/wideLine.gif"))
    return basic:equals($draw2, $draw2-ref)

};




declare sequential function local:main() as xs:string* {

  let $a := local:test-draw-line()
  return
    if (fn:not($a)) then
      exit returning local:error(("Drawing a line on an image failed."))
    else ();

  let $b := local:test-draw-line-color-red()
  return
    if (fn:not($b)) then
      exit returning local:error(("Drawing a red (#6F0000) line on an image failed."))
    else ();

  let $c := local:test-draw-line-color-green()
  return
    if (fn:not($c)) then
      exit returning local:error(("Drawing a green (#006F00) line on an image failed."))
    else ();

  let $d := local:test-draw-line-color-blue()
  return
    if (fn:not($d)) then
      exit returning local:error(("Drawing a blue (#00006F) line on an image failed."))
    else ();

  let $e := local:test-stroke-width()
  return
    if (fn:not($e)) then
      exit returning local:error(("Setting stroke width of an image failed."))
    else ();


  (: If all went well ... make sure the world knows! :)
  "SUCCESS";


};

local:main();



