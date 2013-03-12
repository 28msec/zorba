

declare variable $products := 
<products>
<prod id = "1" name="car1" price="10"/>
<prod id = "2" name="car2" price="15"/>
<prod id = "3" name="car3" price="9"/>
</products>;

declare variable $sales := 
<sales>
<sale pid="3" qty="3" date="2013-01-01"/>
<sale pid="3" qty="5" date="2013-01-02"/>
<sale pid="2" qty="1" date="2013-01-01"/>
</sales>;


for $p in $products/prod
where xs:integer($p/@price) > 9
for $s in $sales/sale
where string($p/@id) eq string($s/@pid)
return <sale prod="{$p/@name}" amount="{$p/@price * $s/@qty}"/>
