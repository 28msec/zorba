<karteikasten>{
for $anzahl in (1 to 2)
order by $anzahl descending
return
<gruppe anzahl="{$anzahl}">{
  for $book in doc("books.xml")//book
  where count($book/author)=$anzahl
  return $book
}</gruppe>
}</karteikasten>