jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";

let $book :=
  <book>
    <title>The C++ Programming Language</title>
    <authors>
      <author>Bjarne Stroustrup</author>
    </authors>
    <chapters>
      <chapter>
        <title>Notes to the Reader</title>
        <content>
          <quote>
            <content>
              "The time has come," the Walrus said,
              "to talk of many things."
            </content>
            <source>Lewis Carroll</source>
          </quote>
          <!-- more content -->
        </content>
      </chapter>
    </chapters>
  </book>

let $includes := $book//chapter
let $excludes := $book//quote

let $tokens := ft:tokenize-nodes( $includes, $excludes, xs:language("en") )

let $t1 := $tokens[1]
let $t2 := $tokens[2]
let $t3 := $tokens[3]
let $t4 := $tokens[4]

return  $t1.value eq "Notes"
    and $t2.value eq "to"
    and $t3.value eq "the"
    and $t4.value eq "Reader"

(: vim:set et sw=2 ts=2: :)
