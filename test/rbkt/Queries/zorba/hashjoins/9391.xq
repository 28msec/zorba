<karteikasten>{
for $anzahl in (1 to 2)

return
<gruppe anzahl="
{for $karte in  doc("books.xml")//book
where $anzahl=count($karte/author)
return $anzahl}">
</gruppe>
}</karteikasten>