
declare variable $rssfeed := fn:doc("rss.xml");

<result>{
  for tumbling window $w in $rssfeed/rss/channel/item 
    start  $s_curr when true()
    end next $e_next when 
      fn:day-from-dateTime(xs:dateTime($e_next/pubDate)) ne 
      fn:day-from-dateTime(xs:dateTime($s_curr/pubDate))
  return 
    <item>
        <date>{xs:date(xs:dateTime($s_curr/pubDate))}</date>
        {  for $item in $w 
                   where fn:contains( xs:string($item/title), 'XQuery')
                   return $item/title   }
      </item>
}</result>
