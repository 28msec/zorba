for $x in (<a><b>3</b></a>,<a><b>2</b></a>,<a><b>1</b></a>,<a></a>)
order by $x/b ascending empty greatest collation "http://www.w3.org/2005/xpath-functions/collation/codepoint"
return $x
