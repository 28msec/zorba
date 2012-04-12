declare variable $seq := fn:doc("cxml.xml");

<result>
{
for sliding window $w in $seq/sequence/* 
    start previous $wSPrev when $wSPrev[self::OrderRequest]
    end next $wENext when $wENext/@orderID eq  $wSPrev/@orderID and
        ( $wENext[self::ConfirmationRequest] and $wENext/@status eq "reject"
        or $wENext[self::ShipNotice])
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
