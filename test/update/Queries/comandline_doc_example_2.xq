(: Name: comandline_doc_example_2 :)
(: Description: Evaluation of insert expression used with typeswitch expression where branch (a "case") is an updating expression. :)
(: All other branches return "fn:error()". :)

(: insert-start :)
declare variable $input-context external;
(: insert-end :)

typeswitch(xs:int(1))
 case $i as xs:int
    return (insert node <hours>30</hours> into $input-context/works[1]/employee[1])
 case $i as xs:double
    return fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'))
 default
    return fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'))