let $x := <msg>wealthy man</msg>
return $x contains text "poor"
  using thesaurus at "http://wordnet.princeton.edu"
  relationship "antonym"

(: vim:set syntax=xquery et sw=2 ts=2: :)
