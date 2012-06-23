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
      <chapter>
        <title>A Tour of C++</title>
        <content>
          <quote>
            <content>
              The first thing we do,
              let's kill all the lawyers.
            </content>
            <source>Henry VI, part II</source>
          </quote>
          <!-- more content -->
        </content>
      </chapter>
    </chapters>
  </book>

let $includes := $book//chapter
let $excludes := $book//quote

let $tokens := ft:tokenize-nodes( $includes, $excludes, xs:language("en") )
return $tokens

(: vim:set et sw=2 ts=2: :)
