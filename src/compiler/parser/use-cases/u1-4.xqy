let $user := 
doc("users.xml")/users/user_tuple[name="Annabel Lee"]
return 
  do replace value of $user/rating with "B"
