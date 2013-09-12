(: We can't test the exact output of item:size() as it is platform-dependent.
   However we can at least check that we can call it without error. :)

import module namespace item = "http://zorba.io/modules/item";

item:size(1) gt 1

