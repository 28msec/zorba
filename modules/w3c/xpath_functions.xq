(:~
 : This module contains all the functions specified in the
 : W3C XPath and XQuery Functions and Operators 3.0.
 :
 :
 : @author www.w3c.org
 : @see http://www.w3.org/TR/xpath-functions-30/
 : @project www.w3.org/2005
 :
 :)
module namespace fn = "http://www.w3.org/2005/xpath-functions";

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-QName">fn:QName</a>
 :)
declare function fn:QName($paramURI as xs:string?, $paramQName as xs:string) as xs:QName external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-abs">fn:abs</a>
 :)
declare function fn:abs($arg as numeric?) as numeric? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-adjust-date-to-timezone">fn:adjust-date-to-timezone</a>
 :)
declare function fn:adjust-date-to-timezone($arg as xs:date?) as xs:date? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-adjust-date-to-timezone">fn:adjust-date-to-timezone</a>
 :)
declare function fn:adjust-date-to-timezone( $arg as xs:date?, $timezone as xs:dayTimeDuration?) as xs:date? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-adjust-dateTime-to-timezone">fn:adjust-dateTime-to-timezone</a>
 :)
declare function fn:adjust-dateTime-to-timezone($arg as xs:dateTime?) as xs:dateTime external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-adjust-dateTime-to-timezone">fn:adjust-dateTime-to-timezone</a>
 :)
declare function fn:adjust-dateTime-to-timezone( $arg as xs:dateTime?, $timezone as xs:dayTimeDuration?) as xs:dateTime external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-adjust-time-to-timezone">fn:adjust-time-to-timezone</a>
 :)
declare function fn:adjust-time-to-timezone($arg as xs:time?) as xs:time? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-adjust-time-to-timezone">fn:adjust-time-to-timezone</a>
 :)
declare function fn:adjust-time-to-timezone( $arg as xs:time?, $timezone as xs:dayTimeDuration?) as xs:time? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-analyze-string">fn:analyze-string</a>
 :)
declare function fn:analyze-string( $input as xs:string?, $pattern as xs:string) as element(fn:analyze-string-result) external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-analyze-string">fn:analyze-string</a>
 :)
declare function fn:analyze-string( $input as xs:string?, $pattern as xs:string, $flags as xs:string) as element(fn:analyze-string-result) external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-available-environment-variables">fn:available-environment-variables</a>
 :)
declare function fn:available-environment-variables() as xs:string* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-avg">fn:avg</a>
 :)
declare function fn:avg($arg as xs:anyAtomicType*) as xs:anyAtomicType? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-boolean">fn:boolean</a>
 :)
declare function fn:boolean($arg as item()*) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-ceiling">fn:ceiling</a>
 :)
declare function fn:ceiling($arg as numeric?) as numeric? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-codepoint-equal">fn:codepoint-equal</a>
 :)
declare function fn:codepoint-equal( $comparand1 as xs:string?, $comparand2 as xs:string?) as xs:boolean? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-codepoints-to-string">fn:codepoints-to-string</a>
 :)
declare function fn:codepoints-to-string($arg as xs:integer*) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-collection">fn:collection</a>
 :)
declare function fn:collection() as node()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-collection">fn:collection</a>
 :)
declare function fn:collection($arg as xs:string?) as node()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-compare">fn:compare</a>
 :)
declare function fn:compare($comparand1 as xs:string?, $comparand2 as xs:string?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-compare">fn:compare</a>
 :)
declare function fn:compare( $comparand1 as xs:string?, $comparand2 as xs:string?, $collation as xs:string) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-concat">fn:concat</a>
 :)
declare function fn:concat( $arg1 as xs:anyAtomicType?, $arg2 as xs:anyAtomicType? ) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-contains">fn:contains</a>
 :)
declare function fn:contains($arg1 as xs:string?, $arg2 as xs:string?) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-contains">fn:contains</a>
 :)
declare function fn:contains( $arg1 as xs:string?, $arg2 as xs:string?, $collation as xs:string) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-count">fn:count</a>
 :)
declare function fn:count($arg as item()*) as xs:integer external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-dateTime">fn:dateTime</a>
 :)
declare function fn:dateTime($arg1 as xs:date?, $arg2 as xs:time?) as xs:dateTime? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-day-from-date">fn:day-from-date</a>
 :)
declare function fn:day-from-date($arg as xs:date?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-days-from-duration">fn:days-from-duration</a>
 :)
declare function fn:days-from-duration($arg as xs:duration?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-deep-equal">fn:deep-equal</a>
 :)
declare function fn:deep-equal($parameter1 as item()*, $parameter2 as item()*) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-deep-equal">fn:deep-equal</a>
 :)
declare function fn:deep-equal( $parameter1 as item()*, $parameter2 as item()*, $collation as xs:string) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-distinct-values">fn:distinct-values</a>
 :)
declare function fn:distinct-values($arg as xs:anyAtomicType*) as xs:anyAtomicType* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-distinct-values">fn:distinct-values</a>
 :)
declare function fn:distinct-values( $arg as xs:anyAtomicType*, $collation as xs:string) as xs:anyAtomicType* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-doc">fn:doc</a>
 :)
declare function fn:doc($uri as xs:string?) as document-node()? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-doc-available">fn:doc-available</a>
 :)
declare function fn:doc-available($uri as xs:string?) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-element-with-id">fn:element-with-id</a>
 :)
declare function fn:element-with-id($arg as xs:string*) as element()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-element-with-id">fn:element-with-id</a>
 :)
declare function fn:element-with-id($arg as xs:string*, $node as node()) as element()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-empty">fn:empty</a>
 :)
declare function fn:empty($arg as item()*) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-ends-with">fn:ends-with</a>
 :)
declare function fn:ends-with($arg1 as xs:string?, $arg2 as xs:string?) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-ends-with">fn:ends-with</a>
 :)
declare function fn:ends-with( $arg1 as xs:string?, $arg2 as xs:string?, $collation as xs:string) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-environment-variable">fn:environment-variable</a>
 :)
declare function fn:environment-variable($name as xs:string) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-error">fn:error</a>
 :)
declare function fn:error() as none external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-error">fn:error</a>
 :)
declare function fn:error($code as xs:QName) as none external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-error">fn:error</a>
 :)
declare function fn:error($code as xs:QName?, $description as xs:string) as none external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-error">fn:error</a>
 :)
declare function fn:error( $code as xs:QName?, $description as xs:string, $error-object as item()*) as none external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-exactly-one">fn:exactly-one</a>
 :)
declare function fn:exactly-one($arg as item()*) as item() external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-exists">fn:exists</a>
 :)
declare function fn:exists($arg as item()*) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-false">fn:false</a>
 :)
declare function fn:false() as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-filter">fn:filter</a>
 :)
declare function fn:filter($f as function(item()) as xs:boolean, $seq as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-floor">fn:floor</a>
 :)
declare function fn:floor($arg as numeric?) as numeric? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-fold-left">fn:fold-left</a>
 :)
declare function fn:fold-left( $f as function(item()*, item()) as item()*, $zero as item()*, $seq as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-fold-right">fn:fold-right</a>
 :)
declare function fn:fold-right( $f as function(item(), item()*) as item()*, $zero as item()*, $seq as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-date">fn:format-date</a>
 :)
declare function fn:format-date( $value as xs:date?, $picture as xs:string, $language as xs:string?, $calendar as xs:string?, $place as xs:string?) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-date">fn:format-date</a>
 :)
declare function fn:format-date($value as xs:date?, $picture as xs:string) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-dateTime">fn:format-dateTime</a>
 :)
declare function fn:format-dateTime( $value as xs:dateTime?, $picture as xs:string, $language as xs:string?, $calendar as xs:string?, $place as xs:string?) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-dateTime">fn:format-dateTime</a>
 :)
declare function fn:format-dateTime($value as xs:dateTime?, $picture as xs:string) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-integer">fn:format-integer</a>
 :)
declare function fn:format-integer($value as xs:integer?, $picture as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-integer">fn:format-integer</a>
 :)
declare function fn:format-integer( $value as xs:integer?, $picture as xs:string, $language as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-number">fn:format-number</a>
 :)
declare function fn:format-number($value as numeric?, $picture as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-number">fn:format-number</a>
 :)
declare function fn:format-number( $value as numeric?, $picture as xs:string, $decimal-format-name as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-time">fn:format-time</a>
 :)
declare function fn:format-time( $value as xs:time?, $picture as xs:string, $language as xs:string?, $calendar as xs:string?, $place as xs:string?) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-format-time">fn:format-time</a>
 :)
declare function fn:format-time($value as xs:time?, $picture as xs:string) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-function-arity">fn:function-arity</a>
 :)
declare function fn:function-arity($func as function(*)) as xs:integer external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-generate-id">fn:generate-id</a>
 :)
declare function fn:generate-id() as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-generate-id">fn:generate-id</a>
 :)
declare function fn:generate-id($arg as node()?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-head">fn:head</a>
 :)
declare function fn:head($arg as item()*) as item()? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-hours-from-duration">fn:hours-from-duration</a>
 :)
declare function fn:hours-from-duration($arg as xs:duration?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-hours-from-time">fn:hours-from-time</a>
 :)
declare function fn:hours-from-time($arg as xs:time?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-id">fn:id</a>
 :)
declare function fn:id($arg as xs:string*) as element()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-id">fn:id</a>
 :)
declare function fn:id($arg as xs:string*, $node as node()) as element()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-idref">fn:idref</a>
 :)
declare function fn:idref($arg as xs:string*) as node()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-idref">fn:idref</a>
 :)
declare function fn:idref($arg as xs:string*, $node as node()) as node()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-in-scope-prefixes">fn:in-scope-prefixes</a>
 :)
declare function fn:in-scope-prefixes($element as element()) as xs:string* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-index-of">fn:index-of</a>
 :)
declare function fn:index-of( $seq as xs:anyAtomicType*, $search as xs:anyAtomicType) as xs:integer* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-index-of">fn:index-of</a>
 :)
declare function fn:index-of( $seq as xs:anyAtomicType*, $search as xs:anyAtomicType, $collation as xs:string) as xs:integer* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-insert-before">fn:insert-before</a>
 :)
declare function fn:insert-before( $target as item()*, $position as xs:integer, $inserts as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-local-name-from-QName">fn:local-name-from-QName</a>
 :)
declare function fn:local-name-from-QName($arg as xs:QName?) as xs:NCName? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-lower-case">fn:lower-case</a>
 :)
declare function fn:lower-case($arg as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-map">fn:map</a>
 :)
declare function fn:map($f as function(item()) as item()*, $seq as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-map-pairs">fn:map-pairs</a>
 :)
declare function fn:map-pairs( $f as function(item(), item()) as item()*, $seq1 as item()*, $seq2 as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-matches">fn:matches</a>
 :)
declare function fn:matches($input as xs:string?, $pattern as xs:string) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-matches">fn:matches</a>
 :)
declare function fn:matches( $input as xs:string?, $pattern as xs:string, $flags as xs:string) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-max">fn:max</a>
 :)
declare function fn:max($arg as xs:anyAtomicType*) as xs:anyAtomicType? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-max">fn:max</a>
 :)
declare function fn:max($arg as xs:anyAtomicType*, $collation as xs:string) as xs:anyAtomicType? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-min">fn:min</a>
 :)
declare function fn:min($arg as xs:anyAtomicType*) as xs:anyAtomicType? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-min">fn:min</a>
 :)
declare function fn:min($arg as xs:anyAtomicType*, $collation as xs:string) as xs:anyAtomicType? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-minutes-from-dateTime">fn:minutes-from-dateTime</a>
 :)
declare function fn:minutes-from-dateTime($arg as xs:dateTime?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-minutes-from-duration">fn:minutes-from-duration</a>
 :)
declare function fn:minutes-from-duration($arg as xs:duration?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-minutes-from-time">fn:minutes-from-time</a>
 :)
declare function fn:minutes-from-time($arg as xs:time?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-month-from-date">fn:month-from-date</a>
 :)
declare function fn:month-from-date($arg as xs:date?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-months-from-duration">fn:months-from-duration</a>
 :)
declare function fn:months-from-duration($arg as xs:duration?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-namespace-uri-for-prefix">fn:namespace-uri-for-prefix</a>
 :)
declare function fn:namespace-uri-for-prefix( $prefix as xs:string?, $element as element()) as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-namespace-uri-from-QName">fn:namespace-uri-from-QName</a>
 :)
declare function fn:namespace-uri-from-QName($arg as xs:QName?) as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-normalize-space">fn:normalize-space</a>
 :)
declare function fn:normalize-space() as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-normalize-space">fn:normalize-space</a>
 :)
declare function fn:normalize-space($arg as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-normalize-unicode">fn:normalize-unicode</a>
 :)
declare function fn:normalize-unicode($arg as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-normalize-unicode">fn:normalize-unicode</a>
 :)
declare function fn:normalize-unicode( $arg as xs:string?, $normalizationForm as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-not">fn:not</a>
 :)
declare function fn:not($arg as item()*) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-one-or-more">fn:one-or-more</a>
 :)
declare function fn:one-or-more($arg as item()*) as item()+ external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-parse-xml">fn:parse-xml</a>
 :)
declare function fn:parse-xml($arg as xs:string?) as document-node(element(*, xs:untyped)) external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-parse-xml">fn:parse-xml</a>
 :)
declare function fn:parse-xml( $arg as xs:string?, $baseURI as xs:string) as document-node(element(*, xs:untyped)) external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-prefix-from-QName">fn:prefix-from-QName</a>
 :)
declare function fn:prefix-from-QName($arg as xs:QName?) as xs:NCName? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-remove">fn:remove</a>
 :)
declare function fn:remove($target as item()*, $position as xs:integer) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-replace">fn:replace</a>
 :)
declare function fn:replace( $input as xs:string?, $pattern as xs:string, $replacement as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-replace">fn:replace</a>
 :)
declare function fn:replace( $input as xs:string?, $pattern as xs:string, $replacement as xs:string, $flags as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-resolve-QName">fn:resolve-QName</a>
 :)
declare function fn:resolve-QName($qname as xs:string?, $element as element()) as xs:QName? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-reverse">fn:reverse</a>
 :)
declare function fn:reverse($arg as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-round">fn:round</a>
 :)
declare function fn:round($arg as numeric?) as numeric? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-round">fn:round</a>
 :)
declare function fn:round($arg as numeric?, $precision as xs:integer) as numeric? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-round-half-to-even">fn:round-half-to-even</a>
 :)
declare function fn:round-half-to-even($arg as numeric?) as numeric? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-round-half-to-even">fn:round-half-to-even</a>
 :)
declare function fn:round-half-to-even($arg as numeric?, $precision as xs:integer) as numeric? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-seconds-from-dateTime">fn:seconds-from-dateTime</a>
 :)
declare function fn:seconds-from-dateTime($arg as xs:dateTime?) as xs:decimal? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-seconds-from-duration">fn:seconds-from-duration</a>
 :)
declare function fn:seconds-from-duration($arg as xs:duration?) as xs:decimal? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-seconds-from-time">fn:seconds-from-time</a>
 :)
declare function fn:seconds-from-time($arg as xs:time?) as xs:decimal? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-serialize">fn:serialize</a>
 :)
declare function fn:serialize($arg as item()*) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-serialize">fn:serialize</a>
 :)
declare function fn:serialize( $arg as item()*, $params as element(output:serialization-parameters)?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-starts-with">fn:starts-with</a>
 :)
declare function fn:starts-with($arg1 as xs:string?, $arg2 as xs:string?) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-starts-with">fn:starts-with</a>
 :)
declare function fn:starts-with( $arg1 as xs:string?, $arg2 as xs:string?, $collation as xs:string) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string-join">fn:string-join</a>
 :)
declare function fn:string-join($arg1 as xs:string*) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string-join">fn:string-join</a>
 :)
declare function fn:string-join($arg1 as xs:string*, $arg2 as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string-length">fn:string-length</a>
 :)
declare function fn:string-length() as xs:integer external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string-length">fn:string-length</a>
 :)
declare function fn:string-length($arg as xs:string?) as xs:integer external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string-to-codepoints">fn:string-to-codepoints</a>
 :)
declare function fn:string-to-codepoints($arg as xs:string?) as xs:integer* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-subsequence">fn:subsequence</a>
 :)
declare function fn:subsequence($sourceSeq as item()*, $startingLoc as xs:double) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-subsequence">fn:subsequence</a>
 :)
declare function fn:subsequence( $sourceSeq as item()*, $startingLoc as xs:double, $length as xs:double) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-substring">fn:substring</a>
 :)
declare function fn:substring($sourceString as xs:string?, $start as xs:double) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-substring">fn:substring</a>
 :)
declare function fn:substring( $sourceString as xs:string?, $start as xs:double, $length as xs:double) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-substring-after">fn:substring-after</a>
 :)
declare function fn:substring-after($arg1 as xs:string?, $arg2 as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-substring-after">fn:substring-after</a>
 :)
declare function fn:substring-after( $arg1 as xs:string?, $arg2 as xs:string?, $collation as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-substring-before">fn:substring-before</a>
 :)
declare function fn:substring-before($arg1 as xs:string?, $arg2 as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-substring-before">fn:substring-before</a>
 :)
declare function fn:substring-before( $arg1 as xs:string?, $arg2 as xs:string?, $collation as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-sum">fn:sum</a>
 :)
declare function fn:sum($arg as xs:anyAtomicType*) as xs:anyAtomicType external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-sum">fn:sum</a>
 :)
declare function fn:sum( $arg as xs:anyAtomicType*, $zero as xs:anyAtomicType?) as xs:anyAtomicType? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-tail">fn:tail</a>
 :)
declare function fn:tail($arg as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-timezone-from-date">fn:timezone-from-date</a>
 :)
declare function fn:timezone-from-date($arg as xs:date?) as xs:dayTimeDuration? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-timezone-from-dateTime">fn:timezone-from-dateTime</a>
 :)
declare function fn:timezone-from-dateTime($arg as xs:dateTime?) as xs:dayTimeDuration? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-timezone-from-time">fn:timezone-from-time</a>
 :)
declare function fn:timezone-from-time($arg as xs:time?) as xs:dayTimeDuration? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-tokenize">fn:tokenize</a>
 :)
declare function fn:tokenize($input as xs:string?, $pattern as xs:string) as xs:string* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-tokenize">fn:tokenize</a>
 :)
declare function fn:tokenize( $input as xs:string?, $pattern as xs:string, $flags as xs:string) as xs:string* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-trace">fn:trace</a>
 :)
declare function fn:trace($value as item()*, $label as xs:string) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-translate">fn:translate</a>
 :)
declare function fn:translate( $arg as xs:string?, $mapString as xs:string, $transString as xs:string) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-true">fn:true</a>
 :)
declare function fn:true() as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-unordered">fn:unordered</a>
 :)
declare function fn:unordered($sourceSeq as item()*) as item()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-unparsed-text">fn:unparsed-text</a>
 :)
declare function fn:unparsed-text($href as xs:string?) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-unparsed-text">fn:unparsed-text</a>
 :)
declare function fn:unparsed-text($href as xs:string?, $encoding as xs:string) as xs:string? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-unparsed-text-available">fn:unparsed-text-available</a>
 :)
declare function fn:unparsed-text-available($href as xs:string?) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-unparsed-text-available">fn:unparsed-text-available</a>
 :)
declare function fn:unparsed-text-available( $href as xs:string?, $encoding as xs:string) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-unparsed-text-lines">fn:unparsed-text-lines</a>
 :)
declare function fn:unparsed-text-lines($href as xs:string?) as xs:string* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-unparsed-text-lines">fn:unparsed-text-lines</a>
 :)
declare function fn:unparsed-text-lines( $href as xs:string?, $encoding as xs:string) as xs:string* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-upper-case">fn:upper-case</a>
 :)
declare function fn:upper-case($arg as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-uri-collection">fn:uri-collection</a>
 :)
declare function fn:uri-collection() as xs:anyURI* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-uri-collection">fn:uri-collection</a>
 :)
declare function fn:uri-collection($arg as xs:string?) as xs:anyURI* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-year-from-date">fn:year-from-date</a>
 :)
declare function fn:year-from-date($arg as xs:date?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-years-from-duration">fn:years-from-duration</a>
 :)
declare function fn:years-from-duration($arg as xs:duration?) as xs:integer? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-zero-or-one">fn:zero-or-one</a>
 :)
declare function fn:zero-or-one($arg as item()*) as item()? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-codepoints-to-string">fn:codepoints-to-string</a>
 :)
declare function fn:codepoints-to-string($arg as xs:integer*) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string-to-codepoints">fn:string-to-codepoints</a>
 :)
declare function fn:string-to-codepoints($arg as xs:string?) as xs:integer* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-base-uri">fn:base-uri</a>
 :)
declare function fn:base-uri() as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-base-uri">fn:base-uri</a>
 :)
declare function fn:base-uri($arg as node()?) as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-current-date">fn:current-date</a>
 :)
declare function fn:current-date() as xs:date external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-current-dateTime">fn:current-dateTime</a>
 :)
declare function fn:current-dateTime() as xs:dateTimeStamp external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-current-time">fn:current-time</a>
 :)
declare function fn:current-time() as xs:time external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-data">fn:data</a>
 :)
declare function fn:data() as xs:anyAtomicType* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-data">fn:data</a>
 :)
declare function fn:data($arg as item()*) as xs:anyAtomicType* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-default-collation">fn:default-collation</a>
 :)
declare function fn:default-collation() as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-document-uri">fn:document-uri</a>
 :)
declare function fn:document-uri() as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-document-uri">fn:document-uri</a>
 :)
declare function fn:document-uri($arg as node()?) as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-encode-for-uri">fn:encode-for-uri</a>
 :)
declare function fn:encode-for-uri($uri-part as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-escape-html-uri">fn:escape-html-uri</a>
 :)
declare function fn:escape-html-uri($uri as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-has-children">fn:has-children</a>
 :)
declare function fn:has-children($node as node()?) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-implicit-timezone">fn:implicit-timezone</a>
 :)
declare function fn:implicit-timezone() as xs:dayTimeDuration external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-innermost">fn:innermost</a>
 :)
declare function fn:innermost($nodes as node()*) as node()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-iri-to-uri">fn:iri-to-uri</a>
 :)
declare function fn:iri-to-uri($iri as xs:string?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-lang">fn:lang</a>
 :)
declare function fn:lang($testlang as xs:string?) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-lang">fn:lang</a>
 :)
declare function fn:lang($testlang as xs:string?, $node as node()) as xs:boolean external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-last">fn:last</a>
 :)
declare function fn:last() as xs:integer external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-local-name">fn:local-name</a>
 :)
declare function fn:local-name() as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-local-name">fn:local-name</a>
 :)
declare function fn:local-name($arg as node()?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-name">fn:name</a>
 :)
declare function fn:name() as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-name">fn:name</a>
 :)
declare function fn:name($arg as node()?) as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-namespace-uri">fn:namespace-uri</a>
 :)
declare function fn:namespace-uri() as xs:anyURI external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-namespace-uri">fn:namespace-uri</a>
 :)
declare function fn:namespace-uri($arg as node()?) as xs:anyURI external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-nilled">fn:nilled</a>
 :)
declare function fn:nilled($arg as node()?) as xs:boolean? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-node-name">fn:node-name</a>
 :)
declare function fn:node-name() as xs:QName? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-node-name">fn:node-name</a>
 :)
declare function fn:node-name($arg as node()?) as xs:QName? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-number">fn:number</a>
 :)
declare function fn:number() as xs:double external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-number">fn:number</a>
 :)
declare function fn:number($arg as xs:anyAtomicType?) as xs:double external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-outermost">fn:outermost</a>
 :)
declare function fn:outermost($nodes as node()*) as node()* external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-position">fn:position</a>
 :)
declare function fn:position() as xs:integer external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-resolve-uri">fn:resolve-uri</a>
 :)
declare function fn:resolve-uri($relative as xs:string?) as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-resolve-uri">fn:resolve-uri</a>
 :)
declare function fn:resolve-uri($relative as xs:string?, $base as xs:string) as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-root">fn:root</a>
 :)
declare function fn:root() as node() external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-root">fn:root</a>
 :)
declare function fn:root($arg as node()?) as node()? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-static-base-uri">fn:static-base-uri</a>
 :)
declare function fn:static-base-uri() as xs:anyURI? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string">fn:string</a>
 :)
declare function fn:string() as xs:string external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions/#func-string">fn:string</a>
 :)
declare function fn:string($arg as item()?) as xs:string external;