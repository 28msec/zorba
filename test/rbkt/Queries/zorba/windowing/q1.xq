declare variable $seq := fn:doc("arrange_rows.xml");

<table>{
  for tumbling window $w in $seq/doc/*
    start at $x when fn:true() 
    end at $y when $y - $x = 2
  return
    <tr>{
      for $i in $w
      return
        <td>{data($i)}</td>
    }</tr>
}</table>
