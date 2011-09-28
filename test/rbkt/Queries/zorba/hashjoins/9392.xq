<karteikasten>{


<gruppe anzahl="
{for $anzahl in (1 to 2)
for $karte in  doc("books.xml")//book
where $anzahl=count($karte/author)
return $anzahl}">
</gruppe>
}</karteikasten>