
declare variable $d :=
<root>
    <a-text-node>this is some text!</a-text-node>
    <parent id="1">
        <child id="1"/>
        <child id="2"/>
        <child id="3"/>
    </parent>
    <parent id="2">
        <child id="4"/>
        <child id="5"/>
    </parent>
</root>;

insert nodes (text { " foo-1 " } , text { " foo-2 " } , text { " foo-3 " }) after $d//text();

$d
