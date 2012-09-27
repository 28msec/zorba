variable $doc := <doc><a/><a/><a/><a/><a/></doc>;

($doc/a)[if (position() > 3) then position() else 1]
