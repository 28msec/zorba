let $uid := 
doc("users.xml")/users/user_tuple[name="Annabel Lee"]/userid
let $topbid := 
max(doc("bids.xml")/bids/bid_tuple[itemno=1002]/bid)
return 
  do insert 
    <bid_tuple> 
      <userid>{data($uid)}</userid> 
      <itemno>1002</itemno> 
      <bid>{$topbid*1.1}</bid> 
      <bid_date>1999-02-01</bid_date> 
    </bid_tuple>
  into doc("bids.xml")/bids
