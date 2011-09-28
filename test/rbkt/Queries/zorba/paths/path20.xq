
(: Description: Delete all text nodes that come directly after a comment or PI. :)

fn:doc("TopMany.xml")//text()[preceding-sibling::node()[1]/(self::comment() | self::processing-instruction())]
