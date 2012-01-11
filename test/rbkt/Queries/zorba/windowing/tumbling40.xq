let $s := <stocks>
  <closing> <symbol>ABC</symbol> <date>2008-01-01</date> <price>105</price> </closing>
  <closing> <symbol>DEF</symbol> <date>2008-01-01</date> <price>057</price> </closing>
  <closing> <symbol>ABC</symbol> <date>2008-01-02</date> <price>101</price> </closing>
  <closing> <symbol>DEF</symbol> <date>2008-01-02</date> <price>054</price> </closing>
  <closing> <symbol>ABC</symbol> <date>2008-01-03</date> <price>102</price> </closing>
  <closing> <symbol>DEF</symbol> <date>2008-01-03</date> <price>056</price> </closing>
  <closing> <symbol>ABC</symbol> <date>2008-01-04</date> <price>103</price> </closing>
  <closing> <symbol>DEF</symbol> <date>2008-01-04</date> <price>052</price> </closing>
  <closing> <symbol>ABC</symbol> <date>2008-01-05</date> <price>101</price> </closing>
  <closing> <symbol>DEF</symbol> <date>2008-01-05</date> <price>055</price> </closing>
  <closing> <symbol>ABC</symbol> <date>2008-01-06</date> <price>104</price> </closing>
  <closing> <symbol>DEF</symbol> <date>2008-01-06</date> <price>059</price> </closing>
</stocks>
for $closings in $s//closing
let $symbol := $closings/symbol
group by $symbol
for tumbling window $w in $closings
   start $first next $second when $first/price < $second/price
   end $last next $beyond when $last/price > $beyond/price
return
   <run-up symbol="{$symbol}">
      <start-date>{fn:data($first/date)}</start-date>
      <start-price>{fn:data($first/price)}</start-price>
      <end-date>{fn:data($last/date)}</end-date>
      <end-price>{fn:data($last/price)}</end-price>
   </run-up>
