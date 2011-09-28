module namespace u = "http://www.zorba-xquery.com/test/undo/utils";
import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

declare function u:dump-types($nodes as node()*) as element()*
{
for $node in $nodes
return
  if ($node instance of text()) then ()
  else
  (
  element 
  {
  if ($node instance of element()) then node-name($node)
  else if ($node instance of attribute()) then node-name($node)
  else if ($node instance of text()) then 'text'
  else if ($node instance of document-node()) then 'document-node'
  else if ($node instance of comment()) then 'comment'
  else if ($node instance of processing-instruction()) then 'processing-instruction'
  else 'unknown'   
  } 
  {
    attribute type {schema:schema-type($node)},
    for $attr in $node/@*
      return u:dump-types($attr),
    for $elem in $node/node()
      return u:dump-types($elem)     
  }
  )
};

