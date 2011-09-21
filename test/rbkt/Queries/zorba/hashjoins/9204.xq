  for $book in doc("books.xml")//book
return
<karteikasten>{

  for $anzahl in (1 to 2)
  where $anzahl=count($book/author)
  return
    <gruppe anzahl="{$anzahl}">{$book}</gruppe>
}</karteikasten>