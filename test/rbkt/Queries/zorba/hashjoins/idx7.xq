
declare function local:analyze ($s as node() ) as node() 
{
  <element-statistics>
  {
     for $name in fn:distinct-values(for $n in $s//* return fn:name($n))
     return
        <element>
           <name>{$name}</name>

           <number-of-instances>
           {
             fn:count(
               for $nn in $s//*
               where $name = fn:name($nn)
               return $name
             )
           }
           </number-of-instances>

           <number-of-children>
           { 
             let $c :=
               for $nn in $s//*
               where $name = fn:name($nn)
               return fn:count($nn/*)
             return
               <avg>{fn:avg($c)}</avg>
           }  
           </number-of-children>

         </element>
  }
  </element-statistics>
};



local:analyze(<foo><bar1/><bar1/><bar2/></foo>)
