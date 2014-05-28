let $offset := 2
let $limit  := 5
for $i in (1 to 10)
offset $offset
limit $limit
limit $offset
offset $limit
limit 1
return $i
