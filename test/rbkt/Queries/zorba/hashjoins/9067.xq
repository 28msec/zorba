for $b in doc("books.xml")//book
for $er in (1 to 3)
where count($b/author)=$er
return <gruppe anzahl="{$er}"></gruppe>