declare namespace a="http://railroad.my28msec.com/lib/cst-to-ast";
declare namespace g="http://www.w3.org/2001/03/XPath/grammar";

declare function a:ast($nodes)
{
  for $node in $nodes
  return
    typeswitch ($node)
    case element(NCName) return
      "element(NCName)"
    case element(StringLiteral) return
      let $string := $node
      return
        element g:string {substring($string, 2, string-length($string) - 2)}
    case element(NameOrString) return
      let $a := a:ast($node/*[1])
      return
        if (count($node/*) = 2) then
          element {node-name($a)}
          {
            $a/@*,
            attribute context {substring($node/*[2], 2)},
            $a/node()
          }
        else
          $a
    case element(ProcessingInstruction) return
      processing-instruction {$node/NCName} {data($node/ProcessingInstructionContents)}
    case element(Link) return
      attribute xhref {$node/URL}
    case element(Primary) return
      if ($node/TOKEN = ".") then
        element g:ref {attribute name {"."}}
      else if ($node/TOKEN = "$") then
        element g:endOfFile {}
      else
        a:ast($node/*[not(self::TOKEN)])
    case element(Item) return
      if ($node/TOKEN = "?") then
        element g:optional {a:ast($node/Primary)}
      else if ($node/TOKEN = "+") then
        element g:oneOrMore {a:ast($node/Primary)}
      else if ($node/TOKEN = "*") then
        element g:zeroOrMore {a:ast($node/Primary)}
      else
        a:ast($node/Primary)
    case element(SequenceOrDifference) return
      if ($node/TOKEN = "-") then
        element g:subtract
        {
          for $i in $node/Item
          let $ast := a:ast($i)
          return if (count($ast) = 1) then $ast else element g:sequence {$ast}
        }
      else
        a:ast($node/Item)
    case element(Choice) return
      
      if (count($node/SequenceOrDifference) = 1) then
        a:ast($node/SequenceOrDifference)
      else if ($node/TOKEN = "|") then
          element g:choice
          {
            for $s in $node/SequenceOrDifference
            let $ast := a:ast($s)
            return if (count($ast) = 1) then $ast else element g:sequence {$ast}
          }
      else
          element g:orderedChoice
          {
            for $s in $node/SequenceOrDifference
            let $ast := a:ast($s)
            return if (count($ast) = 1) then $ast else element g:sequence {$ast}
          }
    case element(Alternative) return
      "element(Alternative)"
    case element(Alternatives) return
      "element(Alternatives)"
    case element(Preference) return
      let $lhs := $node/NameOrString[1]
      let $lhs-ast := a:ast($lhs)
      for $rhs in $node/NameOrString[. >> $lhs]
      return
        if ($node/TOKEN = "<<") then          
          element g:preference {$lhs-ast, a:ast($rhs)}
        else
          element g:preference {a:ast($rhs), $lhs-ast}
    case element(Delimiter) return
      let $lhs-ast := a:ast($node/NCName)
      for $rhs in $node/NameOrString
      return element g:delimiter {$lhs-ast, a:ast($rhs)}
    default return
      error(xs:QName("a:ast"), concat("invalid parse tree node type: ", local-name($node)))
};

a:ast(<NCName>B</NCName>)
