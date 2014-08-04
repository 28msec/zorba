<table>{
    let $m := { "id" : "0"}
    return
        <td>{
             for $n in (1 to 1) 
             return <a href="a{$m("id")}"/>
        }</td>
}</table>