import module namespace j = "http://jsoniq.org/functions";

let $j := 
{
  "col labels" : ["singular", "plural"],
  "row labels" : ["1p", "2p", "3p"],
  "data" :
     [
        ["spinne", "spinnen"],
        ["spinnst", "spinnt"],
        ["spinnt", "spinnen"]
     ]
}
return
  <table>
    <tr> (: Column headings :)
    {
       <th> </th>,
       for $th in j:members($j("col labels"))
       return <th>{ $th }</th>
    }
    </tr>
    {  (: Data for each row :)
       for $r at $i in j:members($j("data"))
       return
          <tr>
           {
             <td>{ j:members($j("row labels"))[$i] }</td>,
             for $c in j:members($r)
             return <td>{ $c }</td>
           }
          </tr>
    }
  </table>
