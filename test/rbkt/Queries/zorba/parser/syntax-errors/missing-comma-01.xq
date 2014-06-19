(: 
  Test for improved error messages logic:
  the error message contains the "missing comma?" hint
:)

import module namespace refl = "http://zorba.io/modules/reflection";
declare namespace err="http://www.w3.org/2005/xqt-errors";

try 
{

refl:eval(
'for $test in (1 to 10)
return if(true()) then {
 true();
 1
} else {

}

true()'
)

}
catch err:XPST0003
{
  $err:description eq 'invalid expression: syntax error, unexpected expression (missing comma "," between expressions?)'
}
