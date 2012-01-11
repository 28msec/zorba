
declare variable $doc := <root><a attra=""/><b attrb=""/></root>;

declare function local:pul()
{
for $group in ($doc/b/@attrb, $doc/a/@attra, $doc/b/@attrb)
return exists($doc/a intersect $group/ancestor::node())
};

local:pul()


