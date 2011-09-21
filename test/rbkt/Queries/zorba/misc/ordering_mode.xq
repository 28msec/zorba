
declare variable $x := 
(
 <a id = "1">
   <c id = "2"/>
   <a id = "3">
     <b id = "4"/>
     <c id = "5"/>
   </a>
   <c id = "6"/>
 </a>,
 
 <a1 id="7">
   <a1 id="8"><b/></a1>\
 </a1>
);

unordered
{
for $a in $x//b/ancestor::a1
return <a1 id="{$a/@id}"/>
}

,

for $c in $x//b/ancestor::a/c
return $c

