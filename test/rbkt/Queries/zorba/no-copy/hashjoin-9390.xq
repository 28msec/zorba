declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";

for $anzahl in (1 to 5)
return
<karteikasten>{


<gruppe anzahl="{
for $karte in  doc("books.xml")//book
where $anzahl=count($karte/author)
return $anzahl}">
</gruppe>
}</karteikasten>
