(: fn:doc-available() should NOT accept relative file paths when the static base URI :)
(: is not a file: URI (or, more precisely, it should not treat them as :)
(: absolute file paths, but instead should resolve them as relative URIs :)
(: relative to the base URI). :)

declare base-uri "test:///foo";
fn:doc-available("input.xml")
