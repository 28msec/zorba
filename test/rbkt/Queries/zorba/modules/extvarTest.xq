(:*******************************************************:)
(: Written By: Chris Hillery                             :)
(: Date: 2011/01/09                                      :)
(: Purpose: Test library module with external variable   :)
(:*******************************************************:)

import module namespace zm-A = "http://zorbatest.lambda.nu/modules-A"
at "extvarModule-A.xqlib";

zm-A:getVar()
