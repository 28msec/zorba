import module namespace r = "http://zorba.io/modules/random";

(: test call to a nondeterministic function in an element constructor :)
element book {
   element title { r:random() ; "Harold and the Purple Crayon" }
}

