(: 
  Test for improved error messages logic:
  the error message contains the "missing semicolon?" hint
:)

import module namespace refl = "http://zorba.io/modules/reflection";
declare namespace err="http://www.w3.org/2005/xqt-errors";

try 
{

refl:eval(
'jsoniq version "1.0";

declare namespace an = "http://www.zorba-xquery.com/annotations";

declare %an:sequential function local:same-sentence( $tokens as object* )
  as xs:boolean
{
  let $head := head( $tokens )
  for $t in tail( $tokens ) { (: <-- missing "return" here :)
    if ( $t.sentence ne $head.sentence )
    then exit returning false;
    else ;
  }
  true
};

let $tokens := (
  { "sentence" : 1 },
  { "sentence" : 1 },
  { "sentence" : 2 }
)
return local:same-sentence( $tokens )'
)

}
catch err:XPST0003
{
  $err:description eq 'invalid expression: syntax error, unexpected "{"'
}
