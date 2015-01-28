import schema default element namespace "http://ns.example.com/anonsimpletype" at "anonsimpletype.xsd";

variable $a :=
validate strict {
<test>
  <type>temporary</type>
</test>
};

(:return ($a/*:type eq "temporary"):)
replace value of node $a/*:type with "free";
$a