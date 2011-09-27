import module namespace id = "http://www.zorba-xquery.com/modules/store/node-identifiers";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare function local:identity($node as node()) as xs:boolean
{
    exists($node) and $node is id:node-by-identifier(id:node-identifier($node,true(),true()))
};

ddl:create(xs:QName("ddl:test"),
(
	document 
	{
		<?processinginstruction someprocessinginstruction?>,
		comment {"This is a comment"},
		<root>		
			<nonEmptyElement1 emptyAttribute="">
				<textElement>sometext</textElement>
			</nonEmptyElement1>
		</root>
	}
));
let $x := doc("../document.xml")
let $y := document 
	{
		<?processinginstruction someprocessinginstruction?>,
		comment {"This is a comment"},
		<root>		
			<nonEmptyElement1 emptyAttribute="">
				<textElement>sometext</textElement>
			</nonEmptyElement1>
		</root>
	}
return
  (
	<doc>
	{
		local:identity($x),
		local:identity($x/processing-instruction()),	    
		local:identity($x/comment()),	    
		local:identity($x/root),	    
		local:identity($x/root/nonEmptyElement1/@emptyAttribute),
		local:identity($x/root/nonEmptyElement1/textElement/text())
	}
	</doc>,
	<collection>
	{
		local:identity(dml:collection(xs:QName("ddl:test"))[1]),
		local:identity(dml:collection(xs:QName("ddl:test"))[1]/processing-instruction()),	    
		local:identity(dml:collection(xs:QName("ddl:test"))[1]/comment()),	    
		local:identity(dml:collection(xs:QName("ddl:test"))[1]/root),	    
		local:identity(dml:collection(xs:QName("ddl:test"))[1]/root/nonEmptyElement1/@emptyAttribute),
		local:identity(dml:collection(xs:QName("ddl:test"))[1]/root/nonEmptyElement1/textElement/text())
	}
	</collection>,
	<in-memory>
	{
		local:identity($y),
		local:identity($y/processing-instruction()),	    
		local:identity($y/comment()),	    
		local:identity($y/root),	    
		local:identity($y/root/nonEmptyElement1/@emptyAttribute),
		local:identity($y/root/nonEmptyElement1/textElement/text())
	}
	</in-memory>
  )
