let $uid := 
doc("users.xml")/users/user_tuple[name="Annabel Lee"]/userid
return do
  insert 
    <bid_tuple> 
      <userid>{data($uid)}</userid> 
      <itemno>1001</itemno> 
      <bid>60</bid> 
      <bid_date>1999-02-01</bid_date> 
    </bid_tuple>
  into doc("bids.xml")/bids
