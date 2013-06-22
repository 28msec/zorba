declare namespace blub = "http://jsoniq.org/types";

(:  Only null may be cast to null:)
(: Null may be cast to string or untypedAtomic ("null", its lexical representation) only. :)

variable $test1 :=
try {
3.4 cast as blub:null
}
catch XPTY0004
{true()};

variable $test2 :=
try {
"3.4" cast as blub:null
}
catch XPTY0004
{true()}; 

variable $test3 :=
try {
3 cast as blub:null
}
catch XPTY0004
{true()};

variable $test4 :=
try {
(null cast as blub:null) eq null
}
catch *
{false()};

variable $test5 :=
try {
null cast as xs:integer
}
catch XPTY0004
{true()};

variable $test6 :=
try {
null cast as xs:float
}
catch XPTY0004
{true()};

variable $test7 :=
try {
(null cast as xs:string) eq "null"
}
catch *
{false()};

($test1, $test2, $test3, $test4,$test5, $test6, $test7)
