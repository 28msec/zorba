let $stats := [{
  "domain": "www.jsoniq.org"
}]
for $stat in $stats
return $stat("domain")
