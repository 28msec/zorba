(:~
 : This module provides functions to retrieve the current dateTime.
 : In contrast to the current-dateTime functions specified in
 : "XQuery Functions and Operators" (see http://www.w3.org/TR/xpath-functions/#context)
 : the functions in this module are nondeterministic. That is, they do not
 : return the current-dateTime from the dynamic context but return the actual
 : value.
 :)
module namespace datetime = "http://www.zorba-xquery.com/modules/datetime";

(:~
 : Return the current dateTime value.
 : Please note, that this function is not stable. It returns the
 : dateTime value of the date and time the function has actually been invoked.
 :
 : @return the non-stable datetime value
 :)
declare nondeterministic function datetime:current-dateTime ( ) as xs:dateTime external;

(:~
 : Return the current time value.
 : Please note, that this function is not stable. It returns the
 : time value of the date and time the function has actually been invoked.
 :
 : @return the non-stable time value
 :)
declare nondeterministic function datetime:current-time ( ) as xs:time external;

(:~
 : Return the current date value.
 : Please note, that this function is not stable. It returns the
 : dat value of the date the function has been actually invoked.
 :
 : @return the non-stable date value
 :)
declare nondeterministic function datetime:current-date ( ) as xs:date external;
