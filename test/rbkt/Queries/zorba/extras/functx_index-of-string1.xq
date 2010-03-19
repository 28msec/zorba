declare namespace functx="http://www.functx.com";

(:~
 : The position(s) of a substring 
 :
 : @author  Priscilla Walmsley, Datypic 
 : @version 1.0 
 : @see     http://www.xqueryfunctions.com/xq/functx_index-of-string.html 
 : @param   $arg the string 
 : @param   $substring the substring to find 
 :) 
declare function functx:index-of-string(
    $arg as xs:string? ,
    $substring as xs:string)  as xs:integer* 
{
  if (contains($arg, $substring))
  then 
    (string-length(substring-before($arg, $substring)) + 1,
     for $other in
        functx:index-of-string(substring-after($arg, $substring), $substring)
     return
        $other +
        string-length(substring-before($arg, $substring)) +
        string-length($substring))
  else
    ()
};


<result>{functx:index-of-string('abcdabcdabcd','abc')}</result>
