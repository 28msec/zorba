(: 
  Test for improved error messages logic:
  the error message should not contain the "missing comma?" hint
:)

import module namespace refl = "http://zorba.io/modules/reflection";
declare namespace err="http://www.w3.org/2005/xqt-errors";

try 
{

refl:eval(
'declare namespace an = "http://zorba.io/annotations";

 declare %an:sequential function local:image(
   $id as xs:string, $width as xs:int*,
   $height as xs:int*, $ratio as xs:decimal*, $format as xs:string) as xs:base64Binary
 {
   variable $obj := null;

   if (fn:empty($obj)) then
     ()
   else
   {
     variable $svg := $obj("svg");
     if (fn:not(jn:is-null($obj("size")("width")))) then
     {
       variable $svg-width := $obj("size")("width");
       variable $svg-height := $obj("size")("height");

       if ($width) then
       {
         $svg-height := xs:int(($svg-height div $svg-width) * $width);
         $svg-width := $width;
       }
       else if ($height) then
       {
         $svg-width := xs:int(($svg-width div $svg-height) * $height);
         $svg-height := $height;
       }
       else if ($ratio) then
       {
         $svg-width := xs:int($svg-width * $ratio);
         $svg-height := xs:int($svg-height * $ratio);
       }
       else
         {} 

       $svg := <a>{$svg}</a>/*;

       replace value of node $svg/@height width xs:string($svg-height) || "px";
     }
     else
     {
     }
   }   

 };        

()'
)

}
catch err:XPST0003
{
  $err:description eq 'invalid expression: syntax error, unexpected qualified name "width", expecting "with"'
}
