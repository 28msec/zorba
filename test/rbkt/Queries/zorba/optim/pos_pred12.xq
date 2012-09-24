variable $doc := <doc><a i="1"/><a i="2"/><a i="3"/><a i="4"/><a i="5"/></doc>;

($doc/a)[position() < 2]
,
"
"
,
($doc/a)[position() <= 2]
,
"
"
,
($doc/a)[position() < -1]
,
"
"
,
($doc/a)[2 > position()]
,
"
"
,
($doc/a)[2 >= position()]
,
"
"
,
($doc/a)[2 < position()]
,
"
"
,
($doc/a)[2 <= position()]
,
"
"

