import schema namespace atom = 'http://www.w3.org/2005/Atom';

validate { doc("feed.xml")/atom:feed }
instance of schema-element(atom:feed)
