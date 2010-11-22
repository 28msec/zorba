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
    let $draw := paint:paint($local:gif, <image:line><start><x>-20</x><y>-20</y></start><end><x>80</x><y>80</y></end></image:line>) 
    let $draw-ref := file:read(concat($local:image-dir,"paint/line.gif"))
    return basic:equals($draw, $draw-ref)
};

declare function local:test-draw-line-color-red() {
    let $draw := paint:paint($local:gif, <image:line><strokeColor>#6F0000</strokeColor><start><x>0</x><y>0</y></start><end><x>80</x><y>80</y></end></image:line>) 
    let $draw-ref := file:read(concat($local:image-dir,"paint/redLine.gif"))
    return basic:equals($draw, $draw-ref)

};

declare function local:test-draw-line-color-green() {
    let $draw := paint:paint($local:gif, <image:line><strokeColor>#006F00</strokeColor><start><x>0</x><y>0</y></start><end><x>80</x><y>80</y></end></image:line>)

    let $draw-ref := file:read(concat($local:image-dir,"paint/greenLine.gif"))
    return basic:equals($draw, $draw-ref)

};

declare function local:test-draw-line-color-blue() {
    let $draw := paint:paint($local:gif, <image:line><strokeColor>#00006F</strokeColor><start><x>0</x><y>0</y></start><end><x>80</x><y>80</y></end></image:line>) 
    let $draw-ref := file:read(concat($local:image-dir,"paint/blueLine.gif"))
    return basic:equals($draw, $draw-ref)

};

declare function local:test-stroke-width() {
    let $draw := paint:paint($local:gif, (<image:line><strokeWidth>10</strokeWidth><strokeColor>#000000</strokeColor><start><x>0</x><y>0</y></start><end><x>80</x><y>80</y></end></image:line>,<image:line><strokeColor>#FF00FF</strokeColor><start><x>30</x><y>0</y></start><end><x>70</x><y>90</y></end></image:line>))
    let $draw-ref := file:read(concat($local:image-dir,"paint/wideLine.gif"))
    return basic:equals($draw, $draw-ref)

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



