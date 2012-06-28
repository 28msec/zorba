import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";
import schema namespace fts = "http://www.zorba-xquery.com/modules/full-text";

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

let $t1 := validate { $tokens[1] }
let $t2 := validate { $tokens[2] }
let $t3 := validate { $tokens[3] }
let $t4 := validate { $tokens[4] }

return  $t1/@value = "Notes"
    and $t2/@value = "to"
    and $t3/@value = "the"
    and $t4/@value = "Reader"

(: vim:set et sw=2 ts=2: :)
