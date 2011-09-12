variable $x:=
<a><a1 xmlns="http://aaa.com" c1="d1"><d xmlns="http://ddd.com"/><e:e xmlns:e="http://eee"><f:f xmlns:f="f">g</f:f></e:e></a1></a>;

variable $z:=$x/*;

delete node $x/*;

$z
