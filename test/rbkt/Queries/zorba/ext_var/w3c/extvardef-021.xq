declare variable $x as xs:integer external := xs:int(5);
declare variable $y as xs:decimal external := $x;
$y instance of xs:decimal
