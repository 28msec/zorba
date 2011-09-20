import module namespace zorba =
  "http://www.zorba-xquery.com/zorba/internal-functions";

import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare variable $nl := "
";


declare %sequential function local:calc-one ($s as xs:string) as xs:boolean 
{
  if (string-length ($s) = 0) then
    exit returning false ();
  else {
    zorba:print (("Result: ", refl:eval($s), $nl));
    exit returning true();
  }
};


while (local:calc-one(zorba:read-line()))
{ 
  ();
}
