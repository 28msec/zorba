declare variable $seq := fn:doc("cxml.xml");

<result>{
  for sliding window $w in $seq/sequence/* 
    start  $s when $s[self::OrderRequest]
    end  $e when $e/@orderID eq  $s/@orderID and
      ( $e[self::ConfirmationRequest] and $e/@status eq "reject" 
        or $e[self::ShipNotice])
  where $e[self::ShipNotice]
  return 
    <timeToShip orderID="{ $s/@orderID}">{xs:dateTime($e/@date) - xs:dateTime($s/@date) }</timeToShip> 
}</result>
