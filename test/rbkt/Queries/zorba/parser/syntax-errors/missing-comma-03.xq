(: 
  Test for improved error messages logic:
  the error message should not contain the "missing comma?" hint
:)

import module namespace refl = "http://zorba.io/modules/reflection";
declare namespace err="http://www.w3.org/2005/xqt-errors";

try 
{

refl:eval(
'variable $x := <a b="c"/>;

declare function local:test($a)
{
  $a
};

local:test($x)'
)

}
catch err:XPST0003
{
  $err:description eq 'invalid expression: syntax error, unexpected "function", expecting "end of file" or "," or "}"'
}
