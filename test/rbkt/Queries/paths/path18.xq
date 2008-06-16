declare default element namespace "ns1";

<result>
  {
    (<a xmlns="ns1">
       <b a1='val1' a2='val2' xmlns:p1='ns2'>text1</b>
       text2
     </a>
    )//b/attribute::* 
  }
</result>
