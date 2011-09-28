for $x in (<a>3</a>,<a>1</a>,<a>2</a>,<a>4</a>)
for $z in (<b>4</b>,<b>1</b>,<b>3</b>,<b>2</b>)
order by $x ascending, $z descending
return <r>{($x, $z)}</r>
