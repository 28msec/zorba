jsoniq version "1.0";

(: In the JSONiq grammar, 
   "item" is now available as a QNAME,
   "replace", "insert", "rename", "delete", "append", "json" are all 
    available as function names
:)

declare function local:replace() { 43 };
declare function local:insert()  { 44 };
declare function local:rename()  { 45 };
declare function local:delete()  { 46 };
declare function local:append()  { 47 };
declare function local:json()    { 48 };


let $item := 42
return $item
,
local:replace(),
local:insert(),
local:rename(),
local:delete(),
local:append(),
local:json()
