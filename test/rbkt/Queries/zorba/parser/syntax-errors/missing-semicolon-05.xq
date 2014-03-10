(: 
  Test for improved error messages logic:
  the error message contains the "missing semicolon?" hint
:)

import module namespace refl = "http://zorba.io/modules/reflection";
declare namespace err="http://www.w3.org/2005/xqt-errors";

try 
{

refl:eval(
'declare namespace an = "http://zorba.io/annotations";

declare %an:sequential function local:func($a, $b) {
  if ($a) then {
    ();
  } else {
    if ($b) then {
      ();
      local:func(false(), false()) (: forgot semicolon :)
      local:func(true(), false());
    } else {
      ();
    }
  }
};'
)

}
catch err:XPST0003
{
  $err:description eq 'invalid expression: syntax error, unexpected statement (missing semicolon ";" between statements?)'
}
