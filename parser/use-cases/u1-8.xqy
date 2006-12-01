let $uid := 
doc("users.xml")/users/user_tuple[name="Annabel Lee"]/userid
return do
  insert 
    <bid_tuple> 
      <userid>{data($uid)}</userid> 
      <itemno>1010</itemno> 
      <bid>60</bid> 
      <bid_date>2006-04-23</bid_date> 
    </bid_tuple>
  into doc("bids.xml")/bids
