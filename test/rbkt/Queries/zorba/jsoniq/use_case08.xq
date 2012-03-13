import module namespace j = "http://www.jsoniq.org/functions";

let $j :=
  [
    { "color" : "Green" },
    { "color" : "Pink" },
    { "color" : "Lilac" },
    { "color" : "Turquoise" },
    { "color" : "Peach" },
    { "color" : "Opal" },
    { "color" : "Champagne" }
  ]
return
  <table>{
    for tumbling window $w in j:members($j)
      start at $x when fn:true()
      end at $y when $y - $x = 2
    return
      <tr>{
        for $i in $w
        return
          <td>{ $i("color") }</td>
      }</tr>
  }</table>
