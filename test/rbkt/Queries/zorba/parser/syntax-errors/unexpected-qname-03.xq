(:
  Syntax error with an improved error message:
  unexpected qualified name %actual_qname%
:)
    
import module namespace refl = "http://zorba.io/modules/reflection";
declare namespace err="http://www.w3.org/2005/xqt-errors";

let $query :=
'local:f bad()'

return
try 
{
  refl:eval($query)
}
catch err:XPST0003
{
  $err:description eq 'invalid expression: syntax error, unexpected qualified name "bad", expecting "end of file" or "," or "}"'
}
