(:*******************************************************:)
(: Test: K2-ConcatFunc-2                                 :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Invalid amount of arguments to fn:concat().  :)
(:*******************************************************:)
"1" || "2" || "3" || ("a", "b") || "c"
