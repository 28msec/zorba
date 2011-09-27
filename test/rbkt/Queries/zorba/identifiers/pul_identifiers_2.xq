import module namespace id = "http://www.zorba-xquery.com/modules/store/node-identifiers";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace pulr="http://www.zorba-xquery.com/modules/store/pul/representation";
import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $local:out-coll as xs:QName:=xs:QName("local:out-coll");
declare variable $localopMapName := fn:QName("http://www.zorba-xquery.com/map", "operationsMap");
declare variable $localtype := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:string");



declare variable $test:=<oldnode><child/></oldnode>;

declare updating function local:update()
{
	replace node $test/child with (<lockedA/>,<lockedB/>,<lockedC/>,<lockedD/>,<lockedE/>)
};

declare %ann:sequential function local:test($node as node()*, $request-uuid as xs:boolean) as xs:boolean*
{
	variable $original-ids:= (for $n in $node return id:node-identifier($n,$request-uuid,false()));
	variable $test:=<test/>;
	variable $ret:=(); 
	$ret:=($ret,
		$original-ids[1] = id:node-identifier((element {"test"}{$node[1]})/*,$request-uuid,false()) 
	      );
	insert node $test into $node[2];
	$ret:=($ret,
		$original-ids[2] = id:node-identifier($node[2],$request-uuid,false())
	      );
	insert node $node[3] into $test;
	$ret:=($ret,
		$original-ids[3] = id:node-identifier($test/*,$request-uuid,false())
	      );
	ddl:create(node-name($node[4]));
	dml:insert-nodes-last(node-name($node[4]),$node[4]);
	$ret:=($ret,
		$original-ids[4] = id:node-identifier(dml:collection(node-name($node[4])),$request-uuid,false())
	      );
	
	map:create(node-name($node[5]), $localtype);
	map:insert(node-name($node[5]), $node[5], "1");
	$ret:=($ret,
		$original-ids[5] = id:node-identifier(map:get(node-name($node[5]),"1"),$request-uuid,false())
	      );

	$ret
};

let $locked:=pulr:pul-to-xdm(local:update())//*:replacement/*
let $unlocked:=(<unlockedA/>,<unlockedB/>,<unlockedC/>,<unlockedD/>,<unlockedE/>)
return 
(
<locked>{local:test($locked,false())}</locked>,<unlocked>{local:test($unlocked,true())}</unlocked>
)

