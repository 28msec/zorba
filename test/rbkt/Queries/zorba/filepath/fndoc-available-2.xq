(: fn:doc() should accept relatve file paths when base URI is a file: URI :)
(: (which it is by default in Zorba; specifically it is the URI of the :)
(: currently-executing query) :)

fn:doc-available("input.xml")
