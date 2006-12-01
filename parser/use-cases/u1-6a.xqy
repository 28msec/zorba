let $user := 
doc("users.xml")/users/user_tuple[name="Dee Linquent"]
let $items := 
doc("items.xml")/items/item_tuple[offered_by=$user/userid]
let $bids := 
doc("bids.xml")/bids/bid_tuple[userid=$user/userid]
return 
  do delete $user, $items, $bids
