

typeswitch(xs:int(1))
 case $i as xs:int
    return (insert node <hours>30</hours> into doc("works-mod.xml")/works[1]/employee[1])
 case $i as xs:double
    return fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'))
 default
    return fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'))
