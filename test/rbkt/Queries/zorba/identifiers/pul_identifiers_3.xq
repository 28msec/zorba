import module namespace pulr="http://www.zorba-xquery.com/modules/store/pul/representation";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

(:
GetID, Apply, GetID Again, Apply (XDM and CXDM) (T,T - A,T)
GetID, GetID Again, Apply1, Apply2 (XDM and CXDM) (T,T - A,T)
GetID, GetID Again, Apply2, Apply1 (XDM and CXDM) (T,T - A,T)
:)

declare %ann:sequential function local:test1()
{
variable $doc:=doc("../document.xml");
pulr:xdm-to-pul(pulr:pul-to-xdm(rename node ($doc//*)[1] as "test"));
pulr:xdm-to-pul(pulr:pul-to-xdm(rename node ($doc//*)[1] as "test2"));
$doc
};

declare %ann:sequential function local:test2()
{
variable $doc:=doc("../document.xml");
variable $first:=pulr:pul-to-xdm(rename node ($doc//*)[1] as "test");
variable $second:=pulr:pul-to-xdm(rename node ($doc//*)[1] as "test2");
pulr:xdm-to-pul($first);
pulr:xdm-to-pul($second);
$doc
};

declare %ann:sequential function local:test3()
{
variable $doc:=doc("../document.xml");
variable $first:=pulr:pul-to-xdm(rename node ($doc//*)[1] as "test");
variable $second:=pulr:pul-to-xdm(rename node ($doc//*)[1] as "test2");
pulr:xdm-to-pul($first);
pulr:xdm-to-pul($second);
$doc
};

declare %ann:sequential function local:testCXDM()
{
variable $doc:=doc("../document.xml");
pulr:apply-pul-to-complete-xdm(rename node ($doc//*)[1] as "test");
pulr:apply-pul-to-complete-xdm(rename node ($doc//*)[1] as "test2");
$doc
};

<result>
<test1>
{local:test1()}
</test1>
<test2>
{local:test2()}
</test2>
<test3>
{local:test3()}
</test3>
<testCXDM>
{local:testCXDM()}
</testCXDM>
</result>
