declare variable $sales := 
<sales>
<sale pid="3" locid="5" qty="3" date="2013-01-01"/>
<sale pid="3" locid="5" qty="5" date="2013-01-02"/>
<sale pid="2" locid="4" qty="1" date="2013-01-01"/>
<sale pid="2" locid="4" qty="1" date="2014-01-01"/>
<sale pid="2" locid="7" qty="1" date="2014-01-01"/>
</sales>;

declare variable $locations := 
<locations>
<loc id="5" city="paris"/>
<loc id="4" city="san fransisco"/>
<loc id="7" city="chania"/>
</locations>;


for tumbling window $yearly-sales in $sales/sale

start $s previous $p when 
substring($s/@date, 1, 4) ne substring($p/@date, 1, 4)
and
$locations/loc[@id eq $s/@locid and @city eq "paris"]

end next $n when substring($s/@date, 1, 4) ne substring($n/@date, 1, 4)

return <yearly-sales year="{substring($s/@date, 1, 4)}"
                     qty="{sum($yearly-sales/@qty)}"/>
