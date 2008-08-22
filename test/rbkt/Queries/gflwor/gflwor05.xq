for $x in (<e attr="1"><b>3</b></e>,<e attr="2"><a>1</a></e>,<e attr="3"><b>4</b></e>,<e attr="4"><a>2</a></e>)
outer for $y in $x/b
return <r>{(fn:data($x/@attr), $y)}</r>
