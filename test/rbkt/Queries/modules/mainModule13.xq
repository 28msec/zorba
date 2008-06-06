(:*******************************************************:)
(: Test: moduleMain13.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: Error: XPTY0004 returned type of the         :)
(: expression does not match the declared type of the var:)
(:*******************************************************:)

declare namespace lmns="http://www.w3.org/TestModules/lmns";

declare variable $lmns:flag2 as xs:integer := fn:string(1);

<result>{$lmns:flag2}</result>

