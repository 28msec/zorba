for $b in doc("books.xml")
for $er in (1 to 3)
where count($b/bib/book/author)=$er
return <gruppe anzahl="{$er}"></gruppe>