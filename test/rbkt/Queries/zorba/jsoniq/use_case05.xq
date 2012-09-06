for $page in doc("use_case05.xml")//page
return {
  "title": string($page/title),
  "id" : string($page/id),
  "last updated" : string($page/revision[1]/timestamp),
  "authors" : [
       for $a in $page/revision/contributor/username
       return string($a)
  ]
}
