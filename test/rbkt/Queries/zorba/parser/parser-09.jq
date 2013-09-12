jsoniq version "1.0"; 

(: In both grammars, 
   "null", "true", "false", "from" and "select" can be used as function names
:)

declare default function namespace "local";

declare function null()   { 42 };
declare function true()   { 43 };
declare function false()  { 44 };
declare function from()   { 45 };
declare function select() { 46 };

null(), 
true(), 
false(), 
from(), 
select()
