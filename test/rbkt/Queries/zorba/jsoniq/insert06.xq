import module namespace j = "http://www.jsoniq.org/functions";

declare namespace jerr = "http://www.jsoniq.org/errors";

variable $a1 := [ 1, 2, 3 ];

try {
  j:insert-before($a1, -2, 1 to 2)
} catch jerr:JUDY0061 {
  fn:true()
},
try {
  j:insert-before($a1, 4, 1 to 2)
} catch jerr:JUDY0061 {
  fn:true()
},
try {
  j:insert-after($a1, -2, 1 to 2)
} catch jerr:JUDY0061 {
  fn:true()
},
try {
  j:insert-after($a1, 4, 1 to 2)
} catch jerr:JUDY0061 {
  fn:true()
}

