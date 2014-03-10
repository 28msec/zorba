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

declare function local:jsd-valid() as item*
{
  ()
}

declare function local:check-types() as item*
{
  let $type := ()
  let $b := ()
  return ()
};

()'
)

}
catch err:XPST0003
{
  $err:description eq 'invalid expression: syntax error, missing semicolon ";" after declaration'
}
