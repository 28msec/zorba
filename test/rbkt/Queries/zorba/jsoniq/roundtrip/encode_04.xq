import schema namespace output =  "http://www.w3.org/2010/xslt-xquery-serialization";

{
  "serialized XML" :
    jn:encode-for-roundtrip(<a><b>text<c>more text</c></b></a>,
         {
           "prefix" : "pre-",
           "serialization-parameters" :
             <output:serialization-parameters>
               <output:indent value="yes"/>
               <output:omit-xml-declaration value="yes"/>
             </output:serialization-parameters>
         }
    )
}
