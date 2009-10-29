import schema 
  default element namespace "http://ns.example.com/books-modified-zorba" 
  at "attr-id-idref.xsd";

validate lax
{
  <ITEM CAT="P" xml:id="jff001">
    <TITLE>The Eyre Affair</TITLE>
  </ITEM>
}
