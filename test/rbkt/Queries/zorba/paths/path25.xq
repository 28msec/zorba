let $x1 := <x>A<y>B</y></x>
let $x2 := <x>C</x>
return
  <test>
    <case1>{for $node in ($x1, $x2) return $node//text()[not(ancestor::*:y)]}</case1>
    <case2>{for $node in ($x2, $x1) return $node//text()[not(ancestor::*:y)]}</case2>
  </test>
