

for $x in (<a>1</a>, <a>2</a>, <a>3</a>)
let $y := for $z in (<b>1</b>, <b>2</b>, <b>2</b>)
          group by $z
          for $w in (1, 2, 3)
          where $w eq xs:integer($x)
          return $w
return (<res>{$x, count($y), sum($y)}</res>, "&#xA;")
