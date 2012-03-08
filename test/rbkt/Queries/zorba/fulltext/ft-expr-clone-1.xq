(: This tests that full-text expressions are cloned properly. :)

declare function local:f() {
  let $x := <msg>hello world</msg>
  return $x contains text "hello"
};

local:f()

(: vim:set et sw=2 ts=2: :)
