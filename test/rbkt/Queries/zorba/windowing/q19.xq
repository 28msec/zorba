declare variable $seq := fn:doc("cxml.xml");

<result>
{
for sliding window $w in $seq/sequence/* 
    start $startCurr previous $wSPrev when $wSPrev[self::OrderRequest]
    end $endCurr next $wENext when $wENext/@orderID eq $wSPrev/@orderID and
                         ($wENext[self::ConfirmationRequest] and 
                          $wENext/@status eq "reject" or 
                          $wENext[self::ShipNotice])
where $wENext[self::ShipNotice]
return 
    <window>
    {
     $startCurr, $endCurr
    }
    </window>
}
</result>


(:


<result>
<window>
<OrderRequest xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" billTo="ACME2" date="2006-01-01T11:00:00-00:00" orderID="OID02" total="100" type="new">
    <Item partID="ID2" quantity="10" unitPrice="10"/>
  </OrderRequest>
<time xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" date="2006-01-05T00:00:00-00:00"/>
</window>
</result>

<result>
{
for sliding window $w in $seq/sequence/* 
    start previous $wSPrev when $wSPrev[self::OrderRequest]
    end next $wENext when $wENext/@orderID eq $wSPrev/@orderID and
                         ($wENext[self::ConfirmationRequest] and 
                          $wENext/@status eq "reject" or 
                          $wENext[self::ShipNotice])
where $wENext[self::ShipNotice]
return 
    <bundleWith orderId="{$wSPrev/@orderID}">
    {
        for sliding window $bundle in $w 
          start  $bSCur 
            when $bSCur[self::OrderRequest] and $bSCur/@shipTo eq $wSPrev/@shipTo
          end  $bECur next $bENext 
            when $bECur/@orderID eq  $bSCur/@orderID 
             and ($bECur[self::ConfirmationRequest] and $bECur/@status eq "reject") 
              or $bECur[self::ShipNotice]
          where empty($bENext)
          return $bSCur
    }
    </bundleWith>
}
</result>


or2 - time1  XXXX


cr2  XXXX


cr3


time

:)
