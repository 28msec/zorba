

let $x :=
(

<root1>
  <a id="1"/>
  <a id="2"/>
  <b id="1"/>
  <b id="2"/>
</root1>
,

<root2>
  <a id="3"/>
  <a id="4"/>
  <b id="3"/>
  <b id="4"/>
</root2>
,

<root3>
  <a id="5"/>
  <a id="6"/>
  <b id="5"/>
  <b id="6"/>
</root3>

)//(a union b)/@id

for $y in $x
return <result>{$y}</result>
