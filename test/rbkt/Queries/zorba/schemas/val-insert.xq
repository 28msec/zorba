import schema namespace d = "http://www.zorba-xquery.com/simple.xsd" at "simple.xsd";

declare variable $local:x := <test><a/></test>;

insert node validate {
    <d:product>
      <d:name>Underwear</d:name>
      <d:number>42</d:number>
    </d:product>
  } into $local:x/a;

$local:x
