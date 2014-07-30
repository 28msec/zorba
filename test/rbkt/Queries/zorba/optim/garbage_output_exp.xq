let $m := { "id" : "0"}
return
<table>{
        <td>{
             for $n in (1 to 1) 
             return <a href="a{$m("id")}">a</a>
        }</td>
}</table>