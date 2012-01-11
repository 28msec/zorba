let $stock :=
  <stock>
    <closing> <date>2008-01-01</date> <price>105</price> </closing>
    <closing> <date>2008-01-02</date> <price>101</price> </closing>
    <closing> <date>2008-01-03</date> <price>102</price> </closing>
    <closing> <date>2008-01-04</date> <price>103</price> </closing>
    <closing> <date>2008-01-05</date> <price>102</price> </closing>
    <closing> <date>2008-01-06</date> <price>104</price> </closing>
  </stock>
for tumbling window $w in $stock//closing
   start $first next $second when $first/price < $second/price
   end $last next $beyond when $last/price > $beyond/price
return
   <run-up>
      <start-date>{fn:data($first/date)}</start-date>
      <start-price>{fn:data($first/price)}</start-price>
      <end-date>{fn:data($last/date)}</end-date>
      <end-price>{fn:data($last/price)}</end-price>
   </run-up>
