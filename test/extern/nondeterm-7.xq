declare namespace extern="urn:extern";
declare %nondeterministic function extern:nondeterm() external;

for $i in (1 to 3)
return ($i * 2, extern:nondeterm())

