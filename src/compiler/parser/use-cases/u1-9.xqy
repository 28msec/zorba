let $uid := 
doc("users.xml")/users/user_tuple[name="Annabel Lee"]/userid
let $topbid := 
max(doc("bids.xml")//bid_tuple[itemno=1002]/bid)
return do
  insert 
    <bid_tuple> 
      <userid>{data($uid)}</userid> 
      <itemno>1002</itemno> 
      <bid>{$topbid - 5.00}</bid> 
      <bid_date>2006-04-23</bid_date> 
    </bid_tuple>
  into doc("bids.xml")/bids
