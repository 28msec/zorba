declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test() 
{
  let $indexHtmlDoc := <doc/>
  return 
         {
           for $module in (<m id="5"/>, <m id="2"/>, <m id="4"/>, <m id="1"/>)
           order by $module/@id
           return insert nodes <mi>{$module/@id}</mi> as last into $indexHtmlDoc;

           $indexHtmlDoc
         }
};


{
  variable $doc := local:test();
  $doc
}
