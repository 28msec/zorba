import module namespace
fn-zorba-util="http://www.zorba-xquery.com/zorba/util-functions";
declare variable $input-context1 external;
declare variable $input-context2 external;

<test>
<q1>{fn-zorba-util:tdoc($input-context1)}</q1>
<in_427820>{fn-zorba-util:tdoc($input-context2)}</in_427820>
</test>
