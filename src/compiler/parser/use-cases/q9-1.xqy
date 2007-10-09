import schema namespace ipo = "http://www.example.com/IPO" at "ipo.xsd";
                        
count( 
  doc("ipo.xml")//shipTo[. instance of element(*, ipo:UKAddress)]
)
