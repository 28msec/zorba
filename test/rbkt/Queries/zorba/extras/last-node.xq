
declare namespace  functx = "http://www.functx.com" ;


(:~
 : The XML node in a sequence that is last in document order 
 :
 : @author  Priscilla Walmsley, Datypic 
 : @version 1.0 
 : @see     http://www.xqueryfunctions.com/xq/functx_last-node.html 
 : @param   $nodes the sequence of nodes 
 :) 
declare function functx:last-node ( $nodes as node()* )  as node()? 
{
  ($nodes/.)[last()]
};



let $in-xml := 	

<authors>
   <author>
      <fName>Kate</fName>
      <lName>Jones</lName>
   </author>
   <author>
      <fName>John</fName>
      <lName>Doe</lName>
   </author>
</authors>

return

<result>{functx:last-node(($in-xml//lName,$in-xml//fName))}</result>
