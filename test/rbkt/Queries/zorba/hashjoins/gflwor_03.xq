

declare variable $sales := 
<sales>
<sale pid="3" locid="5" qty="3" date="2013-01-01"/>
<sale pid="3" locid="5" qty="5" date="2013-01-02"/>
<sale pid="2" locid="4" qty="1" date="2013-01-01"/>
</sales>;

declare variable $locations := 
<locations>
<loc id="5" city="paris"/>
<loc id="4" city="san fransisco"/>
</locations>;


for $s in $sales/sale
let $loc := $s/@locid
group by $loc
let $city := $locations/loc[string(./@id) eq string($loc)]/@city
return <sale city="{$city}" qty="{sum($s/@qty)}"/>
