declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

for $b in doc("books.xml")
for $er in (1 to 3)
where count($b/bib/book/author)=$er
return <gruppe anzahl="{$er}">
   {$b/bib/book/title}</gruppe>
