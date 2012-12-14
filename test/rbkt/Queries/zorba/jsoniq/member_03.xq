let $stats := [{
  "domain": "jsoniq.org"
}]
for $stat in $stats
return $stat("domain")
