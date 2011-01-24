declare variable $seq := fn:doc("head_para.xml");

<chapter>{
  for tumbling window $w in $seq/body/* 
    start previous $s when $s[self::h2]  
    end next $e when $e[self::h2] 
  return
    <section title="{data($s)}">{
       for $x in $w 
       return
         <para>{data($x)}</para>
  }</section>
}</chapter>
