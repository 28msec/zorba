xquery version "1.0";

(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

(:~
 : This module contains all the functions specified in the
 : W3C XPath and XQuery Functions and Operators 3.0.
 :
 :
 : @author www.w3c.org
 : @see http://www.w3.org/TR/xpath-functions-30/
 : @project W3C/XPath Functions
 :
 :)
module namespace fn = "http://www.w3.org/2005/xpath-functions";

(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Constructs an <code>xs:QName</code> value given a namespace URI and a lexical
 :             QName.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="QName" return-type="xs:QName" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="paramURI" type="xs:string?"/><arg name="paramQName" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The namespace URI in the returned QName is taken from <code>$paramURI</code>. If
 :                <code>$paramURI</code> is the zero-length string or the empty sequence, it represents
 :             "no namespace".</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The prefix (or absence of a prefix) in <code>$paramQName</code> is retained in the
 :             returned <code>xs:QName</code> value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The local name in the result is taken from the local part of
 :             <code>$paramQName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="CA" code="0002"/> if <code>$paramQName</code> does
 :             not have the correct lexical form for an instance of <code>xs:QName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="CA" code="0002"/> if <code>$paramURI</code> is the
 :             zero-length string or the empty sequence, and the value of <code>$paramQName</code>
 :             contains a colon (<code>:</code>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="G">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CA" code="0002"/> if <code>$paramURI</code> is not a valid URI (XML Namespaces 1.0) or
 :             IRI (XML Namespaces 1.1). </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-QName
 :)
declare function fn:QName($paramURI as xs:string?,  $paramQName as xs:string) as  xs:QName external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the absolute value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="abs" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">General rules: see <specref ref="numeric-value-functions"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is negative the function returns <code>-$arg</code>, otherwise it
 :             returns <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the type of <code>$arg</code> is one of the four numeric types <code>xs:float</code>,
 :                <code>xs:double</code>, <code>xs:decimal</code> or <code>xs:integer</code> the type
 :             of the result is the same as the type of <code>$arg</code>. If the type of
 :                <code>$arg</code> is a type derived from one of the numeric types, the result is an
 :             instance of the base numeric type.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For <code>xs:float</code> and <code>xs:double</code> arguments, if the argument is
 :             positive zero or negative zero, then positive zero is returned. If the argument is
 :             positive or negative infinity, positive infinity is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:abs(10.5)</code> returns <code>10.5</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:abs(-10.5)</code> returns <code>10.5</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-abs
 :)
declare function fn:abs($arg as numeric?) as  numeric? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Adjusts an <code>xs:date</code> value to a specific timezone, or to no timezone
 :             at all; the result is the date in the target timezone that contains the starting instant
 :             of the supplied date.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="adjust-date-to-timezone" return-type="xs:date?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/></proto></example><example role="signature"><proto name="adjust-date-to-timezone" return-type="xs:date?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/><arg name="timezone" type="xs:dayTimeDuration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$timezone</code> is not specified, then the effective value of
 :                <code>$timezone</code> is the value of the implicit timezone in the dynamic
 :             context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> is the empty sequence, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             the empty sequence, then the result is the value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             not the empty sequence, then the result is <code>$arg</code> with <code>$timezone</code>
 :             as the timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is the empty
 :             sequence, then the result is the local value of <code>$arg</code> without its timezone
 :             component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is not the
 :             empty sequence, then the function returns the value of the expression:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Let <code>$dt</code> be the value of <code>fn:dateTime($arg,
 :                      xs:time('00:00:00'))</code>.</p></item><item><p>Let <code>$adt</code> be the value of <code>fn:adjust-dateTime-to-timezone($dt,
 :                      $timezone)</code></p></item><item><p>The function returns the value of <code>xs:date($adt)</code></p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DT" code="0003"/> if <code>$timezone</code> is less
 :             than <code>-PT14H</code> or greater than <code>PT14H</code> or is not an integral number
 :             of minutes.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-adjust-date-to-timezone
 :)
declare function fn:adjust-date-to-timezone($arg as xs:date?) as  xs:date? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Adjusts an <code>xs:date</code> value to a specific timezone, or to no timezone
 :             at all; the result is the date in the target timezone that contains the starting instant
 :             of the supplied date.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="adjust-date-to-timezone" return-type="xs:date?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/></proto></example><example role="signature"><proto name="adjust-date-to-timezone" return-type="xs:date?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/><arg name="timezone" type="xs:dayTimeDuration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$timezone</code> is not specified, then the effective value of
 :                <code>$timezone</code> is the value of the implicit timezone in the dynamic
 :             context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> is the empty sequence, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             the empty sequence, then the result is the value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             not the empty sequence, then the result is <code>$arg</code> with <code>$timezone</code>
 :             as the timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is the empty
 :             sequence, then the result is the local value of <code>$arg</code> without its timezone
 :             component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is not the
 :             empty sequence, then the function returns the value of the expression:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Let <code>$dt</code> be the value of <code>fn:dateTime($arg,
 :                      xs:time('00:00:00'))</code>.</p></item><item><p>Let <code>$adt</code> be the value of <code>fn:adjust-dateTime-to-timezone($dt,
 :                      $timezone)</code></p></item><item><p>The function returns the value of <code>xs:date($adt)</code></p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DT" code="0003"/> if <code>$timezone</code> is less
 :             than <code>-PT14H</code> or greater than <code>PT14H</code> or is not an integral number
 :             of minutes.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-adjust-date-to-timezone
 :)
declare function fn:adjust-date-to-timezone( $arg as xs:date?,  $timezone as xs:dayTimeDuration?) as  xs:date? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Adjusts an <code>xs:dateTime</code> value to a specific timezone, or to no
 :             timezone at all.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="adjust-dateTime-to-timezone" return-type="xs:dateTime?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:dateTime?"/></proto></example><example role="signature"><proto name="adjust-dateTime-to-timezone" return-type="xs:dateTime?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:dateTime?"/><arg name="timezone" type="xs:dayTimeDuration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$timezone</code> is not specified, then the effective value of
 :                <code>$timezone</code> is the value of the implicit timezone in the dynamic
 :             context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> is the empty sequence, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             the empty sequence, then the result is <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             not the empty sequence, then the result is <code>$arg</code> with <code>$timezone</code>
 :             as the timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is the empty
 :             sequence, then the result is the local value of <code>$arg</code> without its timezone
 :             component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is not the
 :             empty sequence, then the result is the <code>xs:dateTime</code> value that is equal to
 :                <code>$arg</code> and that has a timezone component equal to
 :             <code>$timezone</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DT" code="0003"/> if <code>$timezone</code> is less
 :             than <code>-PT14H</code> or greater than <code>PT14H</code> or is not an integral number
 :             of minutes.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-adjust-dateTime-to-timezone
 :)
declare function fn:adjust-dateTime-to-timezone($arg as xs:dateTime?) as  xs:dateTime external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Adjusts an <code>xs:dateTime</code> value to a specific timezone, or to no
 :             timezone at all.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="adjust-dateTime-to-timezone" return-type="xs:dateTime?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:dateTime?"/></proto></example><example role="signature"><proto name="adjust-dateTime-to-timezone" return-type="xs:dateTime?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:dateTime?"/><arg name="timezone" type="xs:dayTimeDuration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$timezone</code> is not specified, then the effective value of
 :                <code>$timezone</code> is the value of the implicit timezone in the dynamic
 :             context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> is the empty sequence, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             the empty sequence, then the result is <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             not the empty sequence, then the result is <code>$arg</code> with <code>$timezone</code>
 :             as the timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is the empty
 :             sequence, then the result is the local value of <code>$arg</code> without its timezone
 :             component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is not the
 :             empty sequence, then the result is the <code>xs:dateTime</code> value that is equal to
 :                <code>$arg</code> and that has a timezone component equal to
 :             <code>$timezone</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DT" code="0003"/> if <code>$timezone</code> is less
 :             than <code>-PT14H</code> or greater than <code>PT14H</code> or is not an integral number
 :             of minutes.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-adjust-dateTime-to-timezone
 :)
declare function fn:adjust-dateTime-to-timezone( $arg as xs:dateTime?,  $timezone as xs:dayTimeDuration?) as  xs:dateTime external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Adjusts an <code>xs:time</code> value to a specific timezone, or to no timezone
 :             at all.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="adjust-time-to-timezone" return-type="xs:time?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/></proto></example><example role="signature"><proto name="adjust-time-to-timezone" return-type="xs:time?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/><arg name="timezone" type="xs:dayTimeDuration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$timezone</code> is not specified, then the effective value of
 :                <code>$timezone</code> is the value of the implicit timezone in the dynamic
 :             context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> is the empty sequence, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             the empty sequence, then the result is <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             not the empty sequence, then the result is <code>$arg</code> with <code>$timezone</code>
 :             as the timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is the empty
 :             sequence, then the result is the localized value of <code>$arg</code> without its
 :             timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is not the
 :             empty sequence, then:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Let <code>$dt</code> be the <code>xs:dateTime</code> value
 :                      <code>fn:dateTime(xs:date('1972-12-31'), $arg)</code>.</p></item><item><p>Let <code>$adt</code> be the value of <code>fn:adjust-dateTime-to-timezone($dt,
 :                      $timezone)</code>
 :                </p></item><item><p>The function returns the <code>xs:time</code> value
 :                   <code>xs:time($adt)</code>.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DT" code="0003"/> if <code>$timezone</code> is less
 :             than <code>-PT14H</code> or greater than <code>PT14H</code> or if does not contain an
 :             integral number of minutes.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-adjust-time-to-timezone
 :)
declare function fn:adjust-time-to-timezone($arg as xs:time?) as  xs:time? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Adjusts an <code>xs:time</code> value to a specific timezone, or to no timezone
 :             at all.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="adjust-time-to-timezone" return-type="xs:time?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/></proto></example><example role="signature"><proto name="adjust-time-to-timezone" return-type="xs:time?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/><arg name="timezone" type="xs:dayTimeDuration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$timezone</code> is not specified, then the effective value of
 :                <code>$timezone</code> is the value of the implicit timezone in the dynamic
 :             context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> is the empty sequence, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             the empty sequence, then the result is <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> does not have a timezone component and <code>$timezone</code> is
 :             not the empty sequence, then the result is <code>$arg</code> with <code>$timezone</code>
 :             as the timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is the empty
 :             sequence, then the result is the localized value of <code>$arg</code> without its
 :             timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$arg</code> has a timezone component and <code>$timezone</code> is not the
 :             empty sequence, then:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Let <code>$dt</code> be the <code>xs:dateTime</code> value
 :                      <code>fn:dateTime(xs:date('1972-12-31'), $arg)</code>.</p></item><item><p>Let <code>$adt</code> be the value of <code>fn:adjust-dateTime-to-timezone($dt,
 :                      $timezone)</code>
 :                </p></item><item><p>The function returns the <code>xs:time</code> value
 :                   <code>xs:time($adt)</code>.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DT" code="0003"/> if <code>$timezone</code> is less
 :             than <code>-PT14H</code> or greater than <code>PT14H</code> or if does not contain an
 :             integral number of minutes.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-adjust-time-to-timezone
 :)
declare function fn:adjust-time-to-timezone( $arg as xs:time?,  $timezone as xs:dayTimeDuration?) as  xs:time? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Analyzes a string using a regular expression, returning an XML structure that
 :             identifies which parts of the input string matched or failed to match the regular
 :             expression, and in the case of matched substrings, which substrings matched each
 :             capturing group in the regular expression.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="analyze-string" return-type="element(fn:analyze-string-result)" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/></proto></example><example role="signature"><proto name="analyze-string" return-type="element(fn:analyze-string-result)" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$flags</code> argument is interpreted in the same way as for the
 :                <code>fn:matches</code> function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence the function behaves as if
 :                <code>$input</code> were the zero-length string. In this situation the result will be
 :             an element node with no children.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an element node whose local name is
 :                <code>analyze-string-result</code>. This element and all its descendant elements have
 :             the namespace URI <code>http://www.w3.org/2005/xpath-functions</code>. The namespace
 :             prefix is <termref def="implementation-dependent"/>. The children of this element are a
 :             sequence of <code>fn:match</code> and <code>fn:non-match</code> elements. This sequence
 :             is formed by breaking the <code>$input</code> string into a sequence of strings,
 :             returning any substring that matches <code>$pattern</code> as the content of a
 :                <code>match</code> element, and any intervening substring as the content of a
 :                <code>non-match</code> element.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">More specifically, the function starts at the beginning of the input string and attempts
 :             to find the first substring that matches the regular expression. If there are several
 :             matches, the first match is defined to be the one whose starting position comes first in
 :             the string. If several alternatives within the regular expression both match at the same
 :             position in the input string, then the match that is chosen is the first alternative
 :             that matches. For example, if the input string is <code>The quick brown fox jumps</code>
 :             and the regular expression is <code>jump|jumps</code>, then the match that is chosen is
 :                <code>jump</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Having found the first match, the instruction proceeds to find the second and subsequent
 :             matches by repeating the search, starting at the first <termref def="character">character</termref> that was not included in the previous match.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The input string is thus partitioned into a sequence of substrings, some of which match
 :             the regular expression, others which do not match it. Each substring will contain at
 :             least one character. This sequence is represented in the result by the sequence of
 :                <code>fn:match</code> and <code>fn:non-match</code> children of the returned element
 :             node; the string value of the <code>fn:match</code> or <code>fn:non-match</code> element
 :             will be the corresponding substring of <code>$input</code>, and the string value of the
 :             returned element node will therefore be the same as <code>$input</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The content of an <code>fn:non-match</code> element is always a single text node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The content of a <code>fn:match</code> element, however, is in general a sequence of
 :             text nodes and <code>fn:group</code> element children. An <code>fn:group</code> element
 :             with a <code>nr</code> attribute having the integer value <var>N</var> identifies the
 :             substring captured by the <var>Nth</var> parenthesized sub-expression in the regular
 :             expression. For each capturing subexpression there will be at most one corresponding
 :                <code>fn:group</code> element in each <code>fn:match</code> element in the
 :             result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the function is called twice with the same arguments, it is <termref def="implementation-dependent"/> whether the two calls return the same element node
 :             or distinct (but deep equal) element nodes. In this respect it is
 :             <termref def="nondeterministic">nondeterministic</termref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="J">The base URI of the element nodes in the result is
 :          <termref def="implementation-dependent"/></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A schema is defined for the structure of the returned element, containing the
 :             definitions below. The returned element and its descendants will have type annotations
 :             obtained by validating the returned element against this schema, unless the function is
 :             used in an environment where type annotations are not supported (for example, a Basic
 :             XSLT Processor), in which case the elements will all be annotated as
 :                <code>xs:untyped</code> and the attributes as <code>xs:untypedAtomic</code>.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p diff="add" at="M">A free-standing copy of this schema can be found at <loc xmlns:xlink="http://www.w3.org/1999/xlink" href="analyze-string.xsd" xlink:type="simple" xlink:show="replace" xlink:actuate="onRequest">analyze-string.xsd</loc></p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">
 :             <pre highlight-as="xquery" xml:space="preserve">&lt;?xml version="1.0" encoding="UTF-8"?&gt;
 : &lt;xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema"
 :     targetNamespace="http://www.w3.org/2005/xpath-functions"
 :     xmlns:fn="http://www.w3.org/2005/xpath-functions"
 :     elementFormDefault="qualified"&gt; 
 : 
 :     &lt;xs:element name="analyze-string-result" type="fn:analyze-string-result-type"/&gt;
 :     &lt;xs:element name="match" type="fn:match-type"/&gt;
 :     &lt;xs:element name="non-match" type="xs:string"/&gt;
 :     &lt;xs:element name="group" type="fn:group-type"/&gt;
 :     
 :     &lt;xs:complexType name="analyze-string-result-type" mixed="true"&gt;
 :         &lt;xs:choice minOccurs="0" maxOccurs="unbounded"&gt;
 :             &lt;xs:element ref="fn:match"/&gt;
 :             &lt;xs:element ref="fn:non-match"/&gt;
 :         &lt;/xs:choice&gt;
 :     &lt;/xs:complexType&gt;
 :         
 :     &lt;xs:complexType name="match-type" mixed="true"&gt;
 :         &lt;xs:sequence&gt;
 :             &lt;xs:element ref="fn:group" minOccurs="0" maxOccurs="unbounded"/&gt;
 :         &lt;/xs:sequence&gt;
 :     &lt;/xs:complexType&gt;
 :     
 :     &lt;xs:complexType name="group-type" mixed="true"&gt;
 :         &lt;xs:sequence&gt;
 :             &lt;xs:element ref="fn:group" minOccurs="0" maxOccurs="unbounded"/&gt;
 :         &lt;/xs:sequence&gt;
 :         &lt;xs:attribute name="nr" type="xs:positiveInteger"/&gt;
 :     &lt;/xs:complexType&gt;    
 :  
 : &lt;/xs:schema&gt;
 : </pre>
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0003"/> if the supplied
 :                <code>$pattern</code> matches a zero-length string, that is, if <code>fn:matches("",
 :                $pattern, $flags)</code> returns <code>true</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-analyze-string
 :)
declare function fn:analyze-string( $input as xs:string?,  $pattern as xs:string) as  element(fn:analyze-string-result) external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Analyzes a string using a regular expression, returning an XML structure that
 :             identifies which parts of the input string matched or failed to match the regular
 :             expression, and in the case of matched substrings, which substrings matched each
 :             capturing group in the regular expression.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="analyze-string" return-type="element(fn:analyze-string-result)" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/></proto></example><example role="signature"><proto name="analyze-string" return-type="element(fn:analyze-string-result)" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$flags</code> argument is interpreted in the same way as for the
 :                <code>fn:matches</code> function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence the function behaves as if
 :                <code>$input</code> were the zero-length string. In this situation the result will be
 :             an element node with no children.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an element node whose local name is
 :                <code>analyze-string-result</code>. This element and all its descendant elements have
 :             the namespace URI <code>http://www.w3.org/2005/xpath-functions</code>. The namespace
 :             prefix is <termref def="implementation-dependent"/>. The children of this element are a
 :             sequence of <code>fn:match</code> and <code>fn:non-match</code> elements. This sequence
 :             is formed by breaking the <code>$input</code> string into a sequence of strings,
 :             returning any substring that matches <code>$pattern</code> as the content of a
 :                <code>match</code> element, and any intervening substring as the content of a
 :                <code>non-match</code> element.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">More specifically, the function starts at the beginning of the input string and attempts
 :             to find the first substring that matches the regular expression. If there are several
 :             matches, the first match is defined to be the one whose starting position comes first in
 :             the string. If several alternatives within the regular expression both match at the same
 :             position in the input string, then the match that is chosen is the first alternative
 :             that matches. For example, if the input string is <code>The quick brown fox jumps</code>
 :             and the regular expression is <code>jump|jumps</code>, then the match that is chosen is
 :                <code>jump</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Having found the first match, the instruction proceeds to find the second and subsequent
 :             matches by repeating the search, starting at the first <termref def="character">character</termref> that was not included in the previous match.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The input string is thus partitioned into a sequence of substrings, some of which match
 :             the regular expression, others which do not match it. Each substring will contain at
 :             least one character. This sequence is represented in the result by the sequence of
 :                <code>fn:match</code> and <code>fn:non-match</code> children of the returned element
 :             node; the string value of the <code>fn:match</code> or <code>fn:non-match</code> element
 :             will be the corresponding substring of <code>$input</code>, and the string value of the
 :             returned element node will therefore be the same as <code>$input</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The content of an <code>fn:non-match</code> element is always a single text node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The content of a <code>fn:match</code> element, however, is in general a sequence of
 :             text nodes and <code>fn:group</code> element children. An <code>fn:group</code> element
 :             with a <code>nr</code> attribute having the integer value <var>N</var> identifies the
 :             substring captured by the <var>Nth</var> parenthesized sub-expression in the regular
 :             expression. For each capturing subexpression there will be at most one corresponding
 :                <code>fn:group</code> element in each <code>fn:match</code> element in the
 :             result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the function is called twice with the same arguments, it is <termref def="implementation-dependent"/> whether the two calls return the same element node
 :             or distinct (but deep equal) element nodes. In this respect it is
 :             <termref def="nondeterministic">nondeterministic</termref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="J">The base URI of the element nodes in the result is
 :          <termref def="implementation-dependent"/></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A schema is defined for the structure of the returned element, containing the
 :             definitions below. The returned element and its descendants will have type annotations
 :             obtained by validating the returned element against this schema, unless the function is
 :             used in an environment where type annotations are not supported (for example, a Basic
 :             XSLT Processor), in which case the elements will all be annotated as
 :                <code>xs:untyped</code> and the attributes as <code>xs:untypedAtomic</code>.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p diff="add" at="M">A free-standing copy of this schema can be found at <loc xmlns:xlink="http://www.w3.org/1999/xlink" href="analyze-string.xsd" xlink:type="simple" xlink:show="replace" xlink:actuate="onRequest">analyze-string.xsd</loc></p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">
 :             <pre xml:space="preserve">&lt;?xml version="1.0" encoding="UTF-8"?&gt;
 : &lt;xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema"
 :     targetNamespace="http://www.w3.org/2005/xpath-functions"
 :     xmlns:fn="http://www.w3.org/2005/xpath-functions"
 :     elementFormDefault="qualified"&gt; 
 : 
 :     &lt;xs:element name="analyze-string-result" type="fn:analyze-string-result-type"/&gt;
 :     &lt;xs:element name="match" type="fn:match-type"/&gt;
 :     &lt;xs:element name="non-match" type="xs:string"/&gt;
 :     &lt;xs:element name="group" type="fn:group-type"/&gt;
 :     
 :     &lt;xs:complexType name="analyze-string-result-type" mixed="true"&gt;
 :         &lt;xs:choice minOccurs="0" maxOccurs="unbounded"&gt;
 :             &lt;xs:element ref="fn:match"/&gt;
 :             &lt;xs:element ref="fn:non-match"/&gt;
 :         &lt;/xs:choice&gt;
 :     &lt;/xs:complexType&gt;
 :         
 :     &lt;xs:complexType name="match-type" mixed="true"&gt;
 :         &lt;xs:sequence&gt;
 :             &lt;xs:element ref="fn:group" minOccurs="0" maxOccurs="unbounded"/&gt;
 :         &lt;/xs:sequence&gt;
 :     &lt;/xs:complexType&gt;
 :     
 :     &lt;xs:complexType name="group-type" mixed="true"&gt;
 :         &lt;xs:sequence&gt;
 :             &lt;xs:element ref="fn:group" minOccurs="0" maxOccurs="unbounded"/&gt;
 :         &lt;/xs:sequence&gt;
 :         &lt;xs:attribute name="nr" type="xs:positiveInteger"/&gt;
 :     &lt;/xs:complexType&gt;    
 :  
 : &lt;/xs:schema&gt;
 : </pre>
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0003"/> if the supplied
 :                <code>$pattern</code> matches a zero-length string, that is, if <code>fn:matches("",
 :                $pattern, $flags)</code> returns <code>true</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-analyze-string
 :)
declare function fn:analyze-string( $input as xs:string?,  $pattern as xs:string,  $flags as xs:string) as  element(fn:analyze-string-result) external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a list of environment variable names that are suitable for passing to
 :                <code>fn:environment-variable</code>, as a (possibly empty) sequence of strings.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="available-environment-variables" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		environment variables.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of strings, being the names of the environment variables
 :             in the dynamic context in some <termref def="implementation-dependent">implementation-dependent</termref> order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is <termref def="dt-deterministic">deterministic</termref>: that is, the
 :             set of available environment variables does not vary during evaluation.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a list of strings, containing no duplicates.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">It is intended that the strings in this list should be suitable for passing to
 :                <code>fn:environment-variable</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See also the note on security under the definition of the
 :                <code>fn:environment-variable</code> function. If access to environment variables has
 :             been disabled, <code>fn:available-environment-variables</code> always returns the empty
 :             sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-available-environment-variables
 :)
declare function fn:available-environment-variables() as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the average of the values in the input sequence <code>$arg</code>, that
 :             is, the sum of the values divided by the number of values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="avg" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> contains values of type <code>xs:untypedAtomic</code> they are cast
 :             to <code>xs:double</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Duration values must either all be <code>xs:yearMonthDuration</code> values or must all
 :             be <code>xs:dayTimeDuration</code> values. For numeric values, the numeric promotion
 :             rules defined in <specref ref="op.numeric"/> are used to promote all values to a single
 :             common type. After these operations, <code>$arg</code> must contain items of a single
 :             type, which must be one of the four numeric types, <code>xs:yearMonthDuration</code> or
 :                <code>xs:dayTimeDuration</code> or one if its subtypes.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the average of the values as <code>sum($arg) div
 :             count($arg)</code>; but the implementation may use an otherwise equivalent algorithm
 :             that avoids arithmetic overflow.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A type error is raised <errorref class="RG" code="0006"/> if the input sequence contains
 :             items of incompatible types, as described above.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-avg
 :)
declare function fn:avg($arg as xs:anyAtomicType*) as  xs:anyAtomicType? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Computes the effective boolean value of the sequence <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="boolean" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function computes the effective boolean value of a sequence, defined according to
 :             the following rules. See also <xspecref spec="XP30" ref="id-ebv"/>.</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If <code>$arg</code> is the empty sequence, <code>fn:boolean</code> returns
 :                      <code>false</code>.</p></item><item><p>If <code>$arg</code> is a sequence whose first item is a node,
 :                      <code>fn:boolean</code> returns <code>true</code>.</p></item><item><p>If <code>$arg</code> is a singleton value of type <code>xs:boolean</code> or a
 :                   derived from <code>xs:boolean</code>, <code>fn:boolean</code> returns
 :                      <code>$arg</code>.</p></item><item><p>If <code>$arg</code> is a singleton value of type <code>xs:string</code> or a type
 :                   derived from <code>xs:string</code>, <code>xs:anyURI</code> or a type derived from
 :                      <code>xs:anyURI</code> or <code>xs:untypedAtomic</code>,
 :                      <code>fn:boolean</code> returns <code>false</code> if the operand value has
 :                   zero length; otherwise it returns <code>true</code>.</p></item><item><p>If <code>$arg</code> is a singleton value of any numeric type or a type derived
 :                   from a numeric type, <code>fn:boolean</code> returns <code>false</code> if the
 :                   operand value is <code>NaN</code> or is numerically equal to zero; otherwise it
 :                   returns <code>true</code>.</p></item><item><p>In all other cases, <code>fn:boolean</code> raises a type error <errorref class="RG" code="0006"/>.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">The static semantics of this function are described in [Formal
 :             Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of this function is not necessarily the same as <code>$arg cast as
 :                xs:boolean</code>. For example, <code>fn:boolean("false")</code> returns the value
 :                <code>true</code> whereas <code>"false" cast as xs:boolean</code> (which can also be
 :             written <code>xs:boolean("false")</code>) returns <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">let <code>$abc</code> := <code>("a", "b", "")</code></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><code>fn:boolean($abc)</code> raises a type error <errorref class="RG" code="0006"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:boolean($abc[1])</code> returns <code>true()</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:boolean($abc[0])</code> returns <code>false()</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:boolean($abc[3])</code> returns <code>false()</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-boolean
 :)
declare function fn:boolean($arg as item()*) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Rounds <code>$arg</code> upwards to a whole number.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="ceiling" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">General rules: see <specref ref="numeric-value-functions"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the smallest (closest to negative infinity) number with no
 :             fractional part that is not less than the value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the type of <code>$arg</code> is one of the four numeric types <code>xs:float</code>,
 :                <code>xs:double</code>, <code>xs:decimal</code> or <code>xs:integer</code> the type
 :             of the result is the same as the type of <code>$arg</code>. If the type of
 :                <code>$arg</code> is a type derived from one of the numeric types, the result is an
 :             instance of the base numeric type.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For <code>xs:float</code> and <code>xs:double</code> arguments, if the argument is
 :             positive zero, then positive zero is returned. If the argument is negative zero, then
 :             negative zero is returned. If the argument is less than zero and greater than -1,
 :             negative zero is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:ceiling(10.5)</code> returns <code>11</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:ceiling(-10.5)</code> returns <code>-10</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-ceiling
 :)
declare function fn:ceiling($arg as numeric?) as  numeric? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if two strings are equal, considered codepoint-by-codepoint.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="codepoint-equal" return-type="xs:boolean?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="comparand1" type="xs:string?"/><arg name="comparand2" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If either argument is the empty sequence, the function returns the empty sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns <code>true</code> or <code>false</code> depending on
 :             whether the value of <code>$comparand1</code> is equal to the value of
 :                <code>$comparand2</code>, according to the Unicode codepoint collation
 :                (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function allows <code>xs:anyURI</code> values to be compared without having to
 :             specify the Unicode codepoint collation.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-codepoint-equal
 :)
declare function fn:codepoint-equal( $comparand1 as xs:string?,  $comparand2 as xs:string?) as  xs:boolean? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Creates an <code>xs:string</code> from a sequence of <termref def="codepoint">codepoints</termref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="codepoints-to-string" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:integer*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the string made up from the <termref def="character">characters</termref> whose Unicode <termref def="codepoint">codepoints</termref> are
 :             supplied in <code>$arg</code>. This will be the zero-length string if <code>$arg</code>
 :             is the empty sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <errorref class="CH" code="0001"/> if any of the codepoints in
 :                <code>$arg</code> is not a permitted XML character.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-codepoints-to-string
 :)
declare function fn:codepoints-to-string($arg as xs:integer*) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of nodes representing a collection of documents indentified
 :             by a collection URI; or a default collection if no URI is supplied.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="collection" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="collection" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available node collections, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function takes an <code>xs:string</code> as argument and returns a sequence of
 :             nodes obtained by interpreting <code>$arg</code> as an <code>xs:anyURI</code> and
 :             resolving it according to the mapping specified in <term>Available node collections</term>
 :             described in <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <term>Available node collections</term> provides a mapping from this string to a sequence
 :             of nodes, the function returns that sequence. If <term>Available node collections</term> maps
 :             the string to an empty sequence, then the function returns an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is not specified, the function returns the sequence of the nodes in
 :             the default node collection in the dynamic context. See <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is a relative <code>xs:anyURI</code>, it is resolved
 :             against the value of the base-URI property from the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function behaves as if it had been
 :             called without an argument. See above.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">By default, this function is <termref def="deterministic">deterministic</termref>. 
 :             This means that repeated
 :             calls on the function with the same argument will return the same result. However, for
 :             performance reasons, implementations may provide a user option to evaluate the function
 :             without a guarantee of determinism. The manner in which any such option is provided is
 :                <termref def="implementation-defined"/>. If the user has not selected such an option,
 :             a call to this function must either return a deterministic result or must raise a <phrase diff="add" at="L">dynamic</phrase> error
 :                <errorref class="DC" code="0003"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="G">There is no requirement that the returned nodes should be in document
 :             order, nor is there a requirement that the result should contain no duplicates.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if no URI is supplied and the
 :             value of the default collection is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="J">A <phrase diff="add" at="M">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if <term>available
 :                node collections</term> provides no mapping for the absolutized URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0004"/> if <code>$arg</code> is not a
 :             valid <code>xs:anyURI</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-collection
 :)
declare function fn:collection() as  node()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of nodes representing a collection of documents indentified
 :             by a collection URI; or a default collection if no URI is supplied.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="collection" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="collection" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available node collections, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function takes an <code>xs:string</code> as argument and returns a sequence of
 :             nodes obtained by interpreting <code>$arg</code> as an <code>xs:anyURI</code> and
 :             resolving it according to the mapping specified in <term>Available node collections</term>
 :             described in <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <term>Available node collections</term> provides a mapping from this string to a sequence
 :             of nodes, the function returns that sequence. If <term>Available node collections</term> maps
 :             the string to an empty sequence, then the function returns an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is not specified, the function returns the sequence of the nodes in
 :             the default node collection in the dynamic context. See <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is a relative <code>xs:anyURI</code>, it is resolved
 :             against the value of the base-URI property from the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function behaves as if it had been
 :             called without an argument. See above.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">By default, this function is <termref def="deterministic">deterministic</termref>. 
 :             This means that repeated
 :             calls on the function with the same argument will return the same result. However, for
 :             performance reasons, implementations may provide a user option to evaluate the function
 :             without a guarantee of determinism. The manner in which any such option is provided is
 :                <termref def="implementation-defined"/>. If the user has not selected such an option,
 :             a call to this function must either return a deterministic result or must raise a <phrase diff="add" at="L">dynamic</phrase> error
 :                <errorref class="DC" code="0003"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="G">There is no requirement that the returned nodes should be in document
 :             order, nor is there a requirement that the result should contain no duplicates.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if no URI is supplied and the
 :             value of the default collection is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="J">A <phrase diff="add" at="M">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if <term>available
 :                node collections</term> provides no mapping for the absolutized URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0004"/> if <code>$arg</code> is not a
 :             valid <code>xs:anyURI</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-collection
 :)
declare function fn:collection($arg as xs:string?) as  node()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns -1, 0, or 1, depending on whether <code>$comparand1</code> collates
 :             before, equal to, or after <code>$comparand2</code> according to the rules of a selected
 :             collation.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="compare" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="comparand1" type="xs:string?"/><arg name="comparand2" type="xs:string?"/></proto></example><example role="signature"><proto name="compare" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="comparand1" type="xs:string?"/><arg name="comparand2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns -1, 0, or 1, depending on whether the value of the <code>$comparand1</code> is
 :             respectively less than, equal to, or greater than the value of <code>$comparand2</code>,
 :             according to the rules of the collation that is used. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If either <code>$comparand1</code> or <code>$comparand2</code> is the empty sequence,
 :             the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function, called with the first signature, defines the semantics of the "eq", "ne",
 :             "gt", "lt", "le" and "ge" operators on <code>xs:string</code> values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('abc', 'abc')</code> returns <code>0</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('Strasse', 'Straße')</code> returns <code>0</code>. <emph>(Assuming the default collation includes provisions that equate
 :                      <quote>ss</quote> and the (German) character <quote>ß</quote>
 :                      (<quote>sharp-s</quote>). Otherwise, the returned value depends on the
 :                   semantics of the default collation.).</emph></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('Strasse', 'Straße',
 :                   'http://example.com/deutsch')</code> returns <code>0</code>. <emph>(Assuming the collation identified by the URI
 :                      <code>http://example.com/deutsch</code> includes provisions that equate
 :                      <quote>ss</quote> and the (German) character <quote>ß</quote>
 :                      (<quote>sharp-s</quote>). Otherwise, the returned value depends on the
 :                   semantics of that collation.).</emph></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('Strassen', 'Straße')</code> returns <code>1</code>. <emph>(Assuming the default collation includes provisions that treat
 :                   differences between <quote>ss</quote> and the (German) character <quote>ß</quote>
 :                      (<quote>sharp-s</quote>) with less strength than the differences between the
 :                   base characters, such as the final <quote>n</quote>. ).</emph></p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-compare
 :)
declare function fn:compare($comparand1 as xs:string?,  $comparand2 as xs:string?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns -1, 0, or 1, depending on whether <code>$comparand1</code> collates
 :             before, equal to, or after <code>$comparand2</code> according to the rules of a selected
 :             collation.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="compare" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="comparand1" type="xs:string?"/><arg name="comparand2" type="xs:string?"/></proto></example><example role="signature"><proto name="compare" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="comparand1" type="xs:string?"/><arg name="comparand2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns -1, 0, or 1, depending on whether the value of the <code>$comparand1</code> is
 :             respectively less than, equal to, or greater than the value of <code>$comparand2</code>,
 :             according to the rules of the collation that is used. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If either <code>$comparand1</code> or <code>$comparand2</code> is the empty sequence,
 :             the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function, called with the first signature, defines the semantics of the "eq", "ne",
 :             "gt", "lt", "le" and "ge" operators on <code>xs:string</code> values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('abc', 'abc')</code> returns <code>0</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('Strasse', 'Straße')</code> returns <code>0</code>. <emph>(Assuming the default collation includes provisions that equate
 :                      <quote>ss</quote> and the (German) character <quote>ß</quote>
 :                      (<quote>sharp-s</quote>). Otherwise, the returned value depends on the
 :                   semantics of the default collation.).</emph></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('Strasse', 'Straße',
 :                   'http://example.com/deutsch')</code> returns <code>0</code>. <emph>(Assuming the collation identified by the URI
 :                      <code>http://example.com/deutsch</code> includes provisions that equate
 :                      <quote>ss</quote> and the (German) character <quote>ß</quote>
 :                      (<quote>sharp-s</quote>). Otherwise, the returned value depends on the
 :                   semantics of that collation.).</emph></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:compare('Strassen', 'Straße')</code> returns <code>1</code>. <emph>(Assuming the default collation includes provisions that treat
 :                   differences between <quote>ss</quote> and the (German) character <quote>ß</quote>
 :                      (<quote>sharp-s</quote>) with less strength than the differences between the
 :                   base characters, such as the final <quote>n</quote>. ).</emph></p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-compare
 :)
declare function fn:compare( $comparand1 as xs:string?,  $comparand2 as xs:string?,  $collation as xs:string) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the concatenation of the string values of the arguments.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">
 :          The two-argument form of this function defines the semantics of the "||" operator.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="concat" return-type="xs:string" isOp="yes" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:anyAtomicType?"/><arg name="arg2" type="xs:anyAtomicType?"/><arg name="..." type="xs:anyAtomicType?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function accepts two or more <code>xs:anyAtomicType</code> arguments and casts each
 :             one to <code>xs:string</code>. The function returns the <code>xs:string</code> that is
 :             the concatenation of the values of its arguments after conversion. If any argument is
 :             the empty sequence, that argument is treated as the zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E19">The <code>fn:concat</code> function is specified to allow two or
 :             more arguments, which are concatenated together. This is the only function specified in
 :             this document that allows a variable number of arguments. This capability is retained
 :             for compatibility with <bibref ref="xpath"/>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-concat
 :)
declare function fn:concat( $arg1 as xs:anyAtomicType?,  $arg2 as xs:anyAtomicType?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the string <code>$arg1</code> contains <code>$arg2</code> as a
 :             substring, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="contains" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="contains" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :                <code>true</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> is the zero-length string, the function returns
 :                <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:boolean</code> indicating whether or not the value of
 :                <code>$arg1</code> contains (at the beginning, at the end, or anywhere within) at
 :             least one sequence of collation units that provides a <term>minimal match</term> to the
 :             collation units in the value of <code>$arg2</code>, according to the collation that is
 :             used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Minimal match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-contains
 :)
declare function fn:contains($arg1 as xs:string?,  $arg2 as xs:string?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the string <code>$arg1</code> contains <code>$arg2</code> as a
 :             substring, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="contains" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="contains" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :                <code>true</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> is the zero-length string, the function returns
 :                <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:boolean</code> indicating whether or not the value of
 :                <code>$arg1</code> contains (at the beginning, at the end, or anywhere within) at
 :             least one sequence of collation units that provides a <term>minimal match</term> to the
 :             collation units in the value of <code>$arg2</code>, according to the collation that is
 :             used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Minimal match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-contains
 :)
declare function fn:contains( $arg1 as xs:string?,  $arg2 as xs:string?,  $collation as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of items in a sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="count" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the number of items in the value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns 0 if <code>$arg</code> is the empty sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-count
 :)
declare function fn:count($arg as item()*) as  xs:integer external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns an <code>xs:dateTime</code> value created by combining an
 :                <code>xs:date</code> and an <code>xs:time</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="dateTime" return-type="xs:dateTime?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:date?"/><arg name="arg2" type="xs:time?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If either <code>$arg1</code> or <code>$arg2</code> is the empty sequence the function
 :             returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:dateTime</code> whose date component is
 :             equal to <code>$arg1</code> and whose time component is equal to <code>$arg2</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The timezone of the result is computed as follows:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If neither argument has a timezone, the result has no timezone.</p></item><item><p>If exactly one of the arguments has a timezone, or if both arguments have the same
 :                   timezone, the result has this timezone.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0008"/> if the two arguments both have
 :             timezones and the timezones are different. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-dateTime
 :)
declare function fn:dateTime($arg1 as xs:date?,  $arg2 as xs:time?) as  xs:dateTime? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the day component of an <code>xs:date</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="day-from-date" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> between 1 and 31, both
 :             inclusive, representing the day component in the localized value of
 :             <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:day-from-date(xs:date("1999-05-31-05:00"))</code> returns <code>31</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:day-from-date(xs:date("2000-01-01+05:00"))</code> returns <code>1</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-day-from-date
 :)
declare function fn:day-from-date($arg as xs:date?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of days in a duration.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="days-from-duration" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:duration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> representing the days
 :             component in the value of <code>$arg</code>. The result is obtained by casting
 :                <code>$arg</code> to an <code>xs:dayTimeDuration</code> (see <specref ref="casting-to-durations"/>) and then computing the days component as described in
 :                <specref ref="canonical-dayTimeDuration"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a negative duration then the result will be negative..</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an <code>xs:yearMonthDuration</code> the function returns 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:days-from-duration(xs:dayTimeDuration("P3DT10H"))</code> returns <code>3</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:days-from-duration(xs:dayTimeDuration("P3DT55H"))</code> returns <code>5</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:days-from-duration(xs:yearMonthDuration("P3Y5M"))</code> returns <code>0</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-days-from-duration
 :)
declare function fn:days-from-duration($arg as xs:duration?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> This function assesses whether two sequences are deep-equal to each other. To
 :             be deep-equal, they must contain items that are pairwise deep-equal; and for two items
 :             to be deep-equal, they must either be atomic values that compare equal, or nodes of the
 :             same kind, with the same name, whose children are deep-equal.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="deep-equal" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="parameter1" type="item()*"/><arg name="parameter2" type="item()*"/></proto></example><example role="signature"><proto name="deep-equal" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="parameter1" type="item()*"/><arg name="parameter2" type="item()*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$collation</code> argument identifies a collation which is used at all levels
 :             of recursion when strings are compared (but not when names are compared), according to
 :             the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the two sequences are both empty, the function returns <code>true</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the two sequences are of different lengths, the function returns
 :             <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the two sequences are of the same length, the function returns <code>true</code> if
 :             and only if every item in the sequence <code>$parameter1</code> is deep-equal to the
 :             item at the same position in the sequence <code>$parameter2</code>. The rules for
 :             deciding whether two items are deep-equal follow.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Call the two items <code>$i1</code> and <code>$i2</code> respectively.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$i1</code> and <code>$i2</code> are both atomic values, they are deep-equal if
 :             and only if <code>($i1 eq $i2)</code> is <code>true</code>, or if both values are
 :                <code>NaN</code>. If the <code>eq</code> operator is not defined for <code>$i1</code>
 :             and <code>$i2</code>, the function returns <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If one of the pair <code>$i1</code> or <code>$i2</code> is an atomic value and the
 :             other is not,
 :             <!--<phrase diff="add" at="MAP">or if one is a node and the other is not, </phrase>-->
 :             the function returns <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$i1</code> and <code>$i2</code> are both nodes, they are compared as described
 :             below:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the two nodes are of different kinds, the result is <code>false</code>.</p></item><item><p>If the two nodes are both document nodes then they are deep-equal if and only if
 :                   the sequence <code>$i1/(*|text())</code> is deep-equal to the sequence
 :                      <code>$i2/(*|text())</code>.</p></item><item><p> If the two nodes are both element nodes then they are deep-equal if and only if
 :                   all of the following conditions are satisfied:</p><olist><item><p>The two nodes have the same name, that is <code>(node-name($i1) eq
 :                            node-name($i2))</code>.</p></item><item><!-- bug 17252 --><p diff="chg" at="L">Either both nodes are both annotated as having simple content or both nodes are
 :                         annotated as having complex content. For this purpose "simple content" means either a simple
 :                      type or a complex type with simple content; "complex content" means a complex type whose variety
 :                      is mixed, element-only, or empty.</p><note diff="add" at="L"><p>It is a consequence of this rule that validating a document
 :                      <var>D</var> against a schema will usually (but not necessarily) result in a document that is not deep-equal
 :                         to <var>D</var>. The exception is when the schema allows all elements to have mixed content.</p></note></item><item><p>The two nodes have the same number of attributes, and for every attribute
 :                            <code>$a1</code> in <code>$i1/@*</code> there exists an attribute
 :                            <code>$a2</code> in <code>$i2/@*</code> such that <code>$a1</code> and
 :                            <code>$a2</code> are deep-equal.</p></item><item><p> One of the following conditions holds:</p><ulist><item><p>Both element nodes are annotated as having simple content 
 :                               <phrase diff="add" at="L">(as defined in 3(b) above)</phrase>, and
 :                               the typed value of <code>$i1</code> is deep-equal to the typed value
 :                               of <code>$i2</code>.</p></item><item><p>Both element nodes have a type annotation that is <phrase diff="chg" at="L">a complex type with
 :                               variety element-only, and the sequence <code>$i1/*</code> is
 :                               deep-equal to the sequence <code>$i2/*</code>.</phrase></p></item><item><p>Both element nodes have a type annotation that is <phrase diff="chg" at="L">a complex type with
 :                               variety mixed</phrase>, and the sequence <code>$i1/(*|text())</code> is
 :                               deep-equal to the sequence <code>$i2/(*|text())</code>.</p></item><item><p>Both element nodes have a type annotation that is <phrase diff="chg" at="L">a complex type with
 :                               variety empty</phrase>.</p></item></ulist></item></olist></item><item><p>If the two nodes are both attribute nodes then they are deep-equal if and only if
 :                   both the following conditions are satisfied:</p><olist><item><p>The two nodes have the same name, that is <code>(node-name($i1) eq
 :                            node-name($i2))</code>.</p></item><item><p>The typed value of <code>$i1</code> is deep-equal to the typed value of
 :                            <code>$i2</code>.</p></item></olist></item><item><p> If the two nodes are both processing instruction nodes<phrase diff="del" at="A-E42"> or namespace bindings</phrase>, then they are deep-equal if and
 :                   only if both the following conditions are satisfied:</p><olist><item><p>The two nodes have the same name, that is <code>(node-name($i1) eq
 :                            node-name($i2))</code>.</p></item><item><p>The string value of <code>$i1</code> is equal to the string value of
 :                            <code>$i2</code>.</p></item></olist></item><item><p diff="add" at="A-E42"> If the two nodes are both namespace nodes, then they are deep-equal if and only
 :                   if both the following conditions are satisfied:</p><olist><item><p diff="add" at="A-E42">The two nodes either have the same name or are both nameless, that is
 :                            <code>fn:deep-equal(node-name($i1), node-name($i2))</code>.</p></item><item><p diff="add" at="A-E42">The string value of <code>$i1</code> is equal to the string value of
 :                            <code>$i2</code> when compared using the Unicode codepoint collation.</p></item></olist></item><item><p>If the two nodes are both text nodes or comment nodes, then they are deep-equal if
 :                   and only if their string-values are equal.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0015" type="type"/> 
 :             if either input sequence contains a function item.
 :             <!--<phrase diff="add" at="MAP">that is not a map</phrase>,-->
 :          </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-deep-equal
 :)
declare function fn:deep-equal($parameter1 as item()*,  $parameter2 as item()*) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> This function assesses whether two sequences are deep-equal to each other. To
 :             be deep-equal, they must contain items that are pairwise deep-equal; and for two items
 :             to be deep-equal, they must either be atomic values that compare equal, or nodes of the
 :             same kind, with the same name, whose children are deep-equal.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="deep-equal" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="parameter1" type="item()*"/><arg name="parameter2" type="item()*"/></proto></example><example role="signature"><proto name="deep-equal" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="parameter1" type="item()*"/><arg name="parameter2" type="item()*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$collation</code> argument identifies a collation which is used at all levels
 :             of recursion when strings are compared (but not when names are compared), according to
 :             the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the two sequences are both empty, the function returns <code>true</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the two sequences are of different lengths, the function returns
 :             <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the two sequences are of the same length, the function returns <code>true</code> if
 :             and only if every item in the sequence <code>$parameter1</code> is deep-equal to the
 :             item at the same position in the sequence <code>$parameter2</code>. The rules for
 :             deciding whether two items are deep-equal follow.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Call the two items <code>$i1</code> and <code>$i2</code> respectively.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$i1</code> and <code>$i2</code> are both atomic values, they are deep-equal if
 :             and only if <code>($i1 eq $i2)</code> is <code>true</code>, or if both values are
 :                <code>NaN</code>. If the <code>eq</code> operator is not defined for <code>$i1</code>
 :             and <code>$i2</code>, the function returns <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If one of the pair <code>$i1</code> or <code>$i2</code> is an atomic value and the
 :             other is not,
 :             <!--<phrase diff="add" at="MAP">or if one is a node and the other is not, </phrase>-->
 :             the function returns <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$i1</code> and <code>$i2</code> are both nodes, they are compared as described
 :             below:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the two nodes are of different kinds, the result is <code>false</code>.</p></item><item><p>If the two nodes are both document nodes then they are deep-equal if and only if
 :                   the sequence <code>$i1/(*|text())</code> is deep-equal to the sequence
 :                      <code>$i2/(*|text())</code>.</p></item><item><p> If the two nodes are both element nodes then they are deep-equal if and only if
 :                   all of the following conditions are satisfied:</p><olist><item><p>The two nodes have the same name, that is <code>(node-name($i1) eq
 :                            node-name($i2))</code>.</p></item><item><!-- bug 17252 --><p diff="chg" at="L">Either both nodes are both annotated as having simple content or both nodes are
 :                         annotated as having complex content. For this purpose "simple content" means either a simple
 :                      type or a complex type with simple content; "complex content" means a complex type whose variety
 :                      is mixed, element-only, or empty.</p><note diff="add" at="L"><p>It is a consequence of this rule that validating a document
 :                      <var>D</var> against a schema will usually (but not necessarily) result in a document that is not deep-equal
 :                         to <var>D</var>. The exception is when the schema allows all elements to have mixed content.</p></note></item><item><p>The two nodes have the same number of attributes, and for every attribute
 :                            <code>$a1</code> in <code>$i1/@*</code> there exists an attribute
 :                            <code>$a2</code> in <code>$i2/@*</code> such that <code>$a1</code> and
 :                            <code>$a2</code> are deep-equal.</p></item><item><p> One of the following conditions holds:</p><ulist><item><p>Both element nodes are annotated as having simple content 
 :                               <phrase diff="add" at="L">(as defined in 3(b) above)</phrase>, and
 :                               the typed value of <code>$i1</code> is deep-equal to the typed value
 :                               of <code>$i2</code>.</p></item><item><p>Both element nodes have a type annotation that is <phrase diff="chg" at="L">a complex type with
 :                               variety element-only, and the sequence <code>$i1/*</code> is
 :                               deep-equal to the sequence <code>$i2/*</code>.</phrase></p></item><item><p>Both element nodes have a type annotation that is <phrase diff="chg" at="L">a complex type with
 :                               variety mixed</phrase>, and the sequence <code>$i1/(*|text())</code> is
 :                               deep-equal to the sequence <code>$i2/(*|text())</code>.</p></item><item><p>Both element nodes have a type annotation that is <phrase diff="chg" at="L">a complex type with
 :                               variety empty</phrase>.</p></item></ulist></item></olist></item><item><p>If the two nodes are both attribute nodes then they are deep-equal if and only if
 :                   both the following conditions are satisfied:</p><olist><item><p>The two nodes have the same name, that is <code>(node-name($i1) eq
 :                            node-name($i2))</code>.</p></item><item><p>The typed value of <code>$i1</code> is deep-equal to the typed value of
 :                            <code>$i2</code>.</p></item></olist></item><item><p> If the two nodes are both processing instruction nodes<phrase diff="del" at="A-E42"> or namespace bindings</phrase>, then they are deep-equal if and
 :                   only if both the following conditions are satisfied:</p><olist><item><p>The two nodes have the same name, that is <code>(node-name($i1) eq
 :                            node-name($i2))</code>.</p></item><item><p>The string value of <code>$i1</code> is equal to the string value of
 :                            <code>$i2</code>.</p></item></olist></item><item><p diff="add" at="A-E42"> If the two nodes are both namespace nodes, then they are deep-equal if and only
 :                   if both the following conditions are satisfied:</p><olist><item><p diff="add" at="A-E42">The two nodes either have the same name or are both nameless, that is
 :                            <code>fn:deep-equal(node-name($i1), node-name($i2))</code>.</p></item><item><p diff="add" at="A-E42">The string value of <code>$i1</code> is equal to the string value of
 :                            <code>$i2</code> when compared using the Unicode codepoint collation.</p></item></olist></item><item><p>If the two nodes are both text nodes or comment nodes, then they are deep-equal if
 :                   and only if their string-values are equal.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0015" type="type"/> 
 :             if either input sequence contains a function item.
 :             <!--<phrase diff="add" at="MAP">that is not a map</phrase>,-->
 :          </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-deep-equal
 :)
declare function fn:deep-equal( $parameter1 as item()*,  $parameter2 as item()*,  $collation as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the values that appear in a sequence, with duplicates eliminated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="distinct-values" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="distinct-values" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the sequence that results from removing from <code>$arg</code> all
 :             but one of a set of values that are equal to one another. Values are compared using the
 :                <code>eq</code> operator, subject to the caveats defined below.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Values of type <code>xs:untypedAtomic</code> are compared as if they were of type
 :                <code>xs:string</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Values that cannot be compared, because the <code>eq</code> operator is not defined for
 :             their types, are considered to be distinct.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>. This collation is used when string comparison is
 :             required.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For <code>xs:float</code> and <code>xs:double</code> values, positive zero is equal to
 :             negative zero and, although <code>NaN</code> does not equal itself, if <code>$arg</code>
 :             contains multiple <code>NaN</code> values a single <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>xs:dateTime</code>, <code>xs:date</code> or <code>xs:time</code> values do not
 :             have a timezone, they are considered to have the implicit timezone provided by the
 :             dynamic context for the purpose of comparison. Note that <code>xs:dateTime</code>,
 :                <code>xs:date</code> or <code>xs:time</code> values can compare equal even if their
 :             timezones are different.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The order in which the sequence of values is returned is <termref def="implementation-dependent"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Which value of a set of values that compare equal is returned is <termref def="implementation-dependent"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">The static type of the result is a sequence of prime types as defined
 :             in [Formal Semantics].</p><change xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E44">
 :             <p>If the input sequence contains values of different numeric types that differ from
 :                each other by small amounts, then the eq operator is not transitive, because of
 :                rounding effects occurring during type promotion. In the situation where the input
 :                contains three values <code>A</code>, <code>B</code>, and <code>C</code> such that
 :                   <code>A eq B</code>, <code>B eq C</code>, but <code>A ne C</code>, then the number
 :                of items in the result of the function (as well as the choice of which items are
 :                returned) is <termref def="implementation-dependent"/>, subject only to the
 :                constraints that (a) no two items in the result sequence compare equal to each other,
 :                and (b) every input item that does not appear in the result sequence compares equal
 :                to some item that does appear in the result sequence.</p>
 : 
 :             <p>For example, this arises when computing:</p>
 : 
 :             <pre highlight-as="xquery" xml:space="preserve">    distinct-values(
 :             (xs:float('1.0'),
 :             xs:decimal('1.0000000000100000000001',
 :             xs:double( '1.00000000001'))</pre>
 : 
 :             <p>because the values of type <code>xs:float</code> and <code>xs:double</code> both
 :                compare equal to the value of type <code>xs:decimal</code> but not equal to each
 :                other. </p>
 :          </change><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-distinct-values
 :)
declare function fn:distinct-values($arg as xs:anyAtomicType*) as  xs:anyAtomicType* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the values that appear in a sequence, with duplicates eliminated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="distinct-values" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="distinct-values" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the sequence that results from removing from <code>$arg</code> all
 :             but one of a set of values that are equal to one another. Values are compared using the
 :                <code>eq</code> operator, subject to the caveats defined below.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Values of type <code>xs:untypedAtomic</code> are compared as if they were of type
 :                <code>xs:string</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Values that cannot be compared, because the <code>eq</code> operator is not defined for
 :             their types, are considered to be distinct.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>. This collation is used when string comparison is
 :             required.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For <code>xs:float</code> and <code>xs:double</code> values, positive zero is equal to
 :             negative zero and, although <code>NaN</code> does not equal itself, if <code>$arg</code>
 :             contains multiple <code>NaN</code> values a single <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>xs:dateTime</code>, <code>xs:date</code> or <code>xs:time</code> values do not
 :             have a timezone, they are considered to have the implicit timezone provided by the
 :             dynamic context for the purpose of comparison. Note that <code>xs:dateTime</code>,
 :                <code>xs:date</code> or <code>xs:time</code> values can compare equal even if their
 :             timezones are different.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The order in which the sequence of values is returned is <termref def="implementation-dependent"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Which value of a set of values that compare equal is returned is <termref def="implementation-dependent"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">The static type of the result is a sequence of prime types as defined
 :             in [Formal Semantics].</p><change xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E44">
 :             <p>If the input sequence contains values of different numeric types that differ from
 :                each other by small amounts, then the eq operator is not transitive, because of
 :                rounding effects occurring during type promotion. In the situation where the input
 :                contains three values <code>A</code>, <code>B</code>, and <code>C</code> such that
 :                   <code>A eq B</code>, <code>B eq C</code>, but <code>A ne C</code>, then the number
 :                of items in the result of the function (as well as the choice of which items are
 :                returned) is <termref def="implementation-dependent"/>, subject only to the
 :                constraints that (a) no two items in the result sequence compare equal to each other,
 :                and (b) every input item that does not appear in the result sequence compares equal
 :                to some item that does appear in the result sequence.</p>
 : 
 :             <p>For example, this arises when computing:</p>
 : 
 :             <pre highlight-as="xquery" xml:space="preserve">    distinct-values(
 :             (xs:float('1.0'),
 :             xs:decimal('1.0000000000100000000001',
 :             xs:double( '1.00000000001'))</pre>
 : 
 :             <p>because the values of type <code>xs:float</code> and <code>xs:double</code> both
 :                compare equal to the value of type <code>xs:decimal</code> but not equal to each
 :                other. </p>
 :          </change><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-distinct-values
 :)
declare function fn:distinct-values( $arg as xs:anyAtomicType*,  $collation as xs:string) as  xs:anyAtomicType* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E26">Retrieves a document using a URI supplied as an
 :                <code>xs:string</code>, and returns the corresponding document node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="doc" return-type="document-node()?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="uri" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available documents, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$uri</code> is the empty sequence, the result is an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E26">If <code>$uri</code> is a relative URI reference, it is resolved
 :             relative to the value of the <phrase diff="chg" at="L">Static Base URI property from the static context</phrase>. The resulting
 :             absolute URI is promoted to an <code>xs:string</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E26">If the <term>Available documents</term> described in <xspecref spec="XP30" ref="eval_context"/> provides a mapping from this string to a document
 :             node, the function returns that document node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E26">The URI may include a fragment identifier.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">By default, this function is <termref def="deterministic">deterministic</termref>. Two calls on this function
 :             return the same document node if the same URI Reference (after resolution to an absolute
 :             URI Reference) is supplied to both calls. Thus, the following expression (if it does not
 :             raise an error) will always be true:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">doc("foo.xml") is doc("foo.xml")</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">However, for performance reasons, implementations may provide a user option to evaluate
 :             the function without a guarantee of determinism. The manner in which any such option is
 :             provided is implementation-defined. If the user has not selected such an option, a call
 :             of the function must either return a deterministic result or must raise a <phrase diff="add" at="L">dynamic</phrase> error
 :                <errorref class="DC" code="0003"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p>If <code>$uri</code> is read from a source document, it is generally appropriate to
 :                resolve it relative to the base URI property of the relevant node in the source
 :                document. This can be achieved by calling the <code>fn:resolve-uri</code> function,
 :                and passing the resulting absolute URI as an argument to the <code>fn:doc</code>
 :                function.</p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If two calls to this function supply different absolute URI References as arguments, the
 :             same document node may be returned if the implementation can determine that the two
 :             arguments refer to the same resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> By defining the semantics of this function in terms of a string-to-document-node
 :             mapping in the dynamic context, the specification is acknowledging that the results of
 :             this function are outside the purview of the language specification itself, and depend
 :             entirely on the run-time environment in which the expression is evaluated. This run-time
 :             environment includes not only an unpredictable collection of resources ("the web"), but
 :             configurable machinery for locating resources and turning their contents into document
 :             nodes within the XPath data model. Both the set of resources that are reachable, and the
 :             mechanisms by which those resources are parsed and validated, are <termref def="implementation-dependent"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> One possible processing model for this function is as follows. The resource identified
 :             by the URI Reference is retrieved. If the resource cannot be retrieved, a <phrase diff="add" at="L">dynamic</phrase> error is
 :             raised <errorref class="DC" code="0002"/>. The data resulting from the retrieval action
 :             is then parsed as an XML document and a tree is constructed in accordance with the
 :                <bibref ref="xpath-datamodel-30"/>. If the top-level media type is known and is
 :             "text", the content is parsed in the same way as if the media type were text/xml;
 :             otherwise, it is parsed in the same way as if the media type were application/xml. If
 :             the contents cannot be parsed successfully, a <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/>. Otherwise, the result of the function is the document node at the root
 :             of the resulting tree. This tree is then optionally validated against a schema.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Various aspects of this processing are <termref def="implementation-defined"/>.
 :             Implementations may provide external configuration options that allow any aspect of the
 :             processing to be controlled by the user. In particular:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>The set of URI schemes that the implementation recognizes is
 :                   implementation-defined. Implementations may allow the mapping of URIs to resources
 :                   to be configured by the user, using mechanisms such as catalogs or user-written
 :                   URI handlers.</p></item><item><p>The handling of non-XML media types is implementation-defined. Implementations may
 :                   allow instances of the data model to be constructed from non-XML resources, under
 :                   user control.</p></item><item><p>It is <termref def="implementation-defined"/> whether DTD validation and/or schema
 :                   validation is applied to the source document.</p></item><item><p>Implementations may provide user-defined error handling options that allow
 :                   processing to continue following an error in retrieving a resource, or in parsing
 :                   and validating its content. When errors have been handled in this way, the
 :                   function may return either an empty sequence, or a fallback document provided by
 :                   the error handler.</p></item><item><p>Implementations may provide user options that relax the requirement for the
 :                   function to return deterministic results.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E26">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="DC" code="0005"/> if <code>$uri</code> is not a valid URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if the
 :                <term>available documents</term> provides no mapping for the absolutized URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if the resource cannot be
 :             retrieved or cannot be parsed successfully as XML.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0003"/> if the implementation is not able
 :             to guarantee that the result of the function will be deterministic, and the user has not
 :             indicated that an unstable result is acceptable.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-doc
 :)
declare function fn:doc($uri as xs:string?) as  document-node()? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E26">The function returns true if and only if the function
 :             call <code>fn:doc($uri)</code> would return a document node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="doc-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="uri" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available documents, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E26">If <code>$uri</code> is an empty sequence, this function returns
 :                <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E26">If a call on <code>fn:doc($uri)</code> would return a document
 :             node, this function returns <code>true</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E26">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0005"/> if
 :                <code>$uri</code> is not a valid URI according to the rules applied by the
 :             implementation of <code>fn:doc</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E26">Otherwise, this function returns <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If this function returns <code>true</code>, then calling <code>fn:doc($uri)</code>
 :             within the same <termref def="execution-scope"/> must return a document node. However,
 :             if nondeterministic processing has been selected for the <code>fn:doc</code> function,
 :             this guarantee is lost.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-doc-available
 :)
declare function fn:doc-available($uri as xs:string?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E31"> Returns the sequence of element nodes that have an
 :                <code>ID</code> value matching the value of one or more of the <code>IDREF</code>
 :             values supplied in <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="element-with-id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/></proto></example><example role="signature"><proto name="element-with-id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><change xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E31">
 : 
 :             <note><p>The effect of this function is identical to <function>fn:id</function> in respect
 :                   of elements that have an attribute with the <code>is-id</code> property. However,
 :                   it behaves differently in respect of element nodes with the <code>is-id</code>
 :                   property. Whereas the <code>fn:id</code>, for legacy reasons, returns the element
 :                   that has the <code>is-id</code> property, this parent returns the element
 :                   identified by the ID, which is the parent of the element having the
 :                      <code>is-id</code> property.</p></note>
 :             <p>The function returns a sequence, in document order with duplicates eliminated,
 :                containing every element node <code>E</code> that satisfies all the following
 :                conditions:</p>
 :             <olist><item><p>
 :                      <code>E</code> is in the target document. The target document is the document
 :                      containing <code>$node</code>, or the document containing the context item
 :                         (<code>.</code>) if the second argument is omitted. The behavior of the
 :                      function if <code>$node</code> is omitted is exactly the same as if the context
 :                      item had been passed as <code>$node</code>.</p></item><item><p><code>E</code> has an <code>ID</code> value equal to one of the candidate
 :                         <code>IDREF</code> values, where:</p><ulist><item><p> An element has an <code>ID</code> value equal to <code>V</code> if
 :                            either or both of the following conditions are true:</p><ulist><item><p>The element has an child element node whose <code>is-id</code>
 :                                  property (See <xspecref spec="DM30" ref="dm-is-id"/>.) is true and
 :                                  whose typed value is equal to <code>V</code> under the rules of the
 :                                     <code>eq</code> operator using the Unicode code point collation
 :                                     (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item><item><p>The element has an attribute node whose <code>is-id</code> property
 :                                  (See <xspecref spec="DM30" ref="dm-is-id"/>.) is true and whose
 :                                  typed value is equal to <code>V</code> under the rules of the
 :                                     <code>eq</code> operator using the Unicode code point collation
 :                                     (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item></ulist></item><item><p>Each <code>xs:string</code> in <code>$arg</code> is parsed as if it were
 :                            of type <code>IDREFS</code>, that is, each <code>xs:string</code> in
 :                               <code>$arg</code> is treated as a whitespace-separated sequence of
 :                            tokens, each acting as an <code>IDREF</code>. These tokens are then
 :                            included in the list of candidate <code>IDREF</code>s. If any of the
 :                            tokens is not a lexically valid <code>IDREF</code> (that is, if it is not
 :                            lexically an <code>xs:NCName</code>), it is ignored. Formally, the
 :                            candidate <code>IDREF</code> values are the strings in the sequence given
 :                            by the expression:</p><pre highlight-as="xquery" xml:space="preserve">for $s in $arg return 
 :    fn:tokenize(fn:normalize-space($s), ' ')[. castable as xs:IDREF]</pre></item></ulist></item><item><p> If several elements have the same <code>ID</code> value, then <code>E</code>
 :                      is the one that is first in document order.</p></item></olist>
 :          </change><change xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E31">
 :             <p>A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0001" type="dynamic"/> if
 :                   <code>$node</code>, or the context item if the second argument is omitted, is a
 :                   node in a tree whose root is not a document node.</p>
 :             <p>The following errors may be raised when <code>$node</code> is omitted:</p>
 :             <ul><li><p>If the context
 :                   item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                   <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                   node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul>
 :             
 :          </change></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-element-with-id
 :)
declare function fn:element-with-id($arg as xs:string*) as  element()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E31"> Returns the sequence of element nodes that have an
 :                <code>ID</code> value matching the value of one or more of the <code>IDREF</code>
 :             values supplied in <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="element-with-id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/></proto></example><example role="signature"><proto name="element-with-id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><change xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E31">
 : 
 :             <note><p>The effect of this function is identical to <function>fn:id</function> in respect
 :                   of elements that have an attribute with the <code>is-id</code> property. However,
 :                   it behaves differently in respect of element nodes with the <code>is-id</code>
 :                   property. Whereas the <code>fn:id</code>, for legacy reasons, returns the element
 :                   that has the <code>is-id</code> property, this parent returns the element
 :                   identified by the ID, which is the parent of the element having the
 :                      <code>is-id</code> property.</p></note>
 :             <p>The function returns a sequence, in document order with duplicates eliminated,
 :                containing every element node <code>E</code> that satisfies all the following
 :                conditions:</p>
 :             <olist><item><p>
 :                      <code>E</code> is in the target document. The target document is the document
 :                      containing <code>$node</code>, or the document containing the context item
 :                         (<code>.</code>) if the second argument is omitted. The behavior of the
 :                      function if <code>$node</code> is omitted is exactly the same as if the context
 :                      item had been passed as <code>$node</code>.</p></item><item><p><code>E</code> has an <code>ID</code> value equal to one of the candidate
 :                         <code>IDREF</code> values, where:</p><ulist><item><p> An element has an <code>ID</code> value equal to <code>V</code> if
 :                            either or both of the following conditions are true:</p><ulist><item><p>The element has an child element node whose <code>is-id</code>
 :                                  property (See <xspecref spec="DM30" ref="dm-is-id"/>.) is true and
 :                                  whose typed value is equal to <code>V</code> under the rules of the
 :                                     <code>eq</code> operator using the Unicode code point collation
 :                                     (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item><item><p>The element has an attribute node whose <code>is-id</code> property
 :                                  (See <xspecref spec="DM30" ref="dm-is-id"/>.) is true and whose
 :                                  typed value is equal to <code>V</code> under the rules of the
 :                                     <code>eq</code> operator using the Unicode code point collation
 :                                     (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item></ulist></item><item><p>Each <code>xs:string</code> in <code>$arg</code> is parsed as if it were
 :                            of type <code>IDREFS</code>, that is, each <code>xs:string</code> in
 :                               <code>$arg</code> is treated as a whitespace-separated sequence of
 :                            tokens, each acting as an <code>IDREF</code>. These tokens are then
 :                            included in the list of candidate <code>IDREF</code>s. If any of the
 :                            tokens is not a lexically valid <code>IDREF</code> (that is, if it is not
 :                            lexically an <code>xs:NCName</code>), it is ignored. Formally, the
 :                            candidate <code>IDREF</code> values are the strings in the sequence given
 :                            by the expression:</p><pre highlight-as="xquery" xml:space="preserve">for $s in $arg return 
 :    fn:tokenize(fn:normalize-space($s), ' ')[. castable as xs:IDREF]</pre></item></ulist></item><item><p> If several elements have the same <code>ID</code> value, then <code>E</code>
 :                      is the one that is first in document order.</p></item></olist>
 :          </change><change xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="A-E31">
 :             <p>A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0001" type="dynamic"/> if
 :                   <code>$node</code>, or the context item if the second argument is omitted, is a
 :                   node in a tree whose root is not a document node.</p>
 :             <p>The following errors may be raised when <code>$node</code> is omitted:</p>
 :             <ul><li><p>If the context
 :                   item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                   <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                   node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul>
 :             
 :          </change></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-element-with-id
 :)
declare function fn:element-with-id($arg as xs:string*,  $node as node()) as  element()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the argument is the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="empty" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns
 :                <code>true</code>; otherwise, the function returns <code>false</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:empty((1,2,3)[10])</code> returns <code>true()</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:empty(fn:remove(("hello", "world"), 1))</code> returns <code>false()</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-empty
 :)
declare function fn:empty($arg as item()*) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the string <code>$arg1</code> contains <code>$arg2</code> as a
 :             trailing substring, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="ends-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="ends-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :                <code>true</code>. If the value of <code>$arg1</code> is the zero-length string and
 :             the value of <code>$arg2</code> is not the zero-length string, then the function returns
 :                <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:boolean</code> indicating whether or not the value of
 :                <code>$arg1</code> starts with a sequence of collation units that provides a
 :                <term>match</term> to the collation units of <code>$arg2</code> according to the
 :             collation that is used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p>
 :                <term>Match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-ends-with
 :)
declare function fn:ends-with($arg1 as xs:string?,  $arg2 as xs:string?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the string <code>$arg1</code> contains <code>$arg2</code> as a
 :             trailing substring, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="ends-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="ends-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :                <code>true</code>. If the value of <code>$arg1</code> is the zero-length string and
 :             the value of <code>$arg2</code> is not the zero-length string, then the function returns
 :                <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:boolean</code> indicating whether or not the value of
 :                <code>$arg1</code> starts with a sequence of collation units that provides a
 :                <term>match</term> to the collation units of <code>$arg2</code> according to the
 :             collation that is used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p>
 :                <term>Match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-ends-with
 :)
declare function fn:ends-with( $arg1 as xs:string?,  $arg2 as xs:string?,  $collation as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of a system environment variable, if it exists.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="environment-variable" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="name" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		environment variables.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The set of available <xtermref spec="XP30" ref="dt-environment-variables">environment variables</xtermref> 
 :             is a set of (name, value) pairs forming part
 :             of the dynamic context, in which the name is unique within the set of pairs. The name
 :             and value are arbitrary strings.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the <code>$name</code> argument matches the name of one of these pairs, the function
 :             returns the corresponding value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If there is no environment variable with a matching name, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used for matching names is <termref def="implementation-defined"/>, but
 :             must be the same as the collation used to ensure that the names of all environment
 :             variables are unique.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">The function is <termref def="dt-deterministic">deterministic</termref>, 
 :             which means that if it is called several times
 :          within the same <termref def="dt-execution-scope">execution scope</termref>, with the same arguments,
 :             it must return the same result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">On many platforms, the term "environment variable" has a natural meaning in terms of
 :             facilities provided by the operating system. This interpretation of the concept does not
 :             exclude other interpretations, such as a mapping to a set of configuration parameters in
 :             a database system.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Environment variable names are usually case sensitive. Names are usually of the form
 :                <code>(letter|_) (letter|_|digit)*</code>, but this varies by platform.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">On some platforms, there may sometimes be multiple environment variables with the same name;
 :             in this case, it is implementation-dependent as to which is returned; see for example
 :                <bibref ref="POSIX.1-2008"/> (Chapter 8, Environment Variables).
 :             Implementations <rfc2119>may</rfc2119> use prefixes or other naming conventions
 :             to disambiguate the names.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The requirement to ensure that the function is deterministic means in practice that
 :          the implementation must make a snapshot of the environment variables at some time
 :          during execution, and return values obtained from this snapshot, rather than using
 :          live values that are subject to change at any time.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Operating system environment variables may be associated with a particular process,
 :          while queries and stylesheets may execute across multiple processes (or multiple machines).
 :          In such circumstances implementations <rfc2119>may</rfc2119> choose to provide access
 :          to the environment variables associated with the process in which the query or stylesheet
 :          processing was initiated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Security advice: Queries from untrusted sources should not be permitted unrestricted
 :             access to environment variables. For example, the name of the account under which the
 :             query is running may be useful information to a would-be intruder. An implementation may
 :             therefore choose to restrict access to the environment, or may provide a facility to
 :             make <code>fn:environment-variable</code> always return the empty sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-environment-variable
 :)
declare function fn:environment-variable($name as xs:string) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the <code>fn:error</code> function raises an application-defined
 :             error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/><arg name="error-object" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function never returns a value. Instead it always raises an error. The effect of
 :             the error is identical to the effect of dynamic errors raised implicitly, for example
 :             when an incorrect argument is supplied to a function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The parameters to the <code>fn:error</code> function supply information that is
 :             associated with the error condition and that is made available to a caller that asks for
 :             information about the error. The error may be caught either by the host language (using
 :             a try/catch construct in XSLT or XQuery, for example), or by the calling application or
 :             external processing environment. The way in which error information is returned to the
 :             external processing environment is <termref def="implementation-dependent"/></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>fn:error</code> is called with no arguments, then its behavior is the same as
 :             the function call: </p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')) </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$code</code> is the empty sequence then the effective value is the
 :                <code>xs:QName</code> constructed by:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">There are three pieces of information that may be associated with an error:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>The <code>$code</code> is an error code that distinguishes this error from others.
 :                   It is an <code>xs:QName</code>; the namespace URI conventionally identifies the
 :                   component, subsystem, or authority responsible for defining the meaning of the
 :                   error code, while the local part identifies the specific error condition. The
 :                   namespace URI <code>http://www.w3.org/2005/xqt-errors</code> is used for errors
 :                   defined in this specification; other namespace URIs may be used for errors defined
 :                   by the application.</p><p>If the external processing environment expects the error code to be returned as a
 :                   URI or a string rather than as an <code>xs:QName</code>, then an error code with
 :                   namespace URI <code>NS</code> and local part <code>LP</code> will be returned in
 :                   the form <code>NS#LP</code>. The namespace URI part of the error code should
 :                   therefore not include a fragment identifier.</p></item><item><p>The <code>$description</code> is a natural-language description of the error
 :                   condition.</p></item><item><p>The <code>$error-object</code> is an arbitrary value used to convey additional
 :                   information about the error, and may be used in any way the application
 :                   chooses.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function always raises a <phrase diff="add" at="L">dynamic</phrase> error. By default, it raises <errorref class="ER" code="0000"/></p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-error
 :)
declare function fn:error() as  none external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the <code>fn:error</code> function raises an application-defined
 :             error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/><arg name="error-object" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function never returns a value. Instead it always raises an error. The effect of
 :             the error is identical to the effect of dynamic errors raised implicitly, for example
 :             when an incorrect argument is supplied to a function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The parameters to the <code>fn:error</code> function supply information that is
 :             associated with the error condition and that is made available to a caller that asks for
 :             information about the error. The error may be caught either by the host language (using
 :             a try/catch construct in XSLT or XQuery, for example), or by the calling application or
 :             external processing environment. The way in which error information is returned to the
 :             external processing environment is <termref def="implementation-dependent"/></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>fn:error</code> is called with no arguments, then its behavior is the same as
 :             the function call: </p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')) </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$code</code> is the empty sequence then the effective value is the
 :                <code>xs:QName</code> constructed by:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">There are three pieces of information that may be associated with an error:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>The <code>$code</code> is an error code that distinguishes this error from others.
 :                   It is an <code>xs:QName</code>; the namespace URI conventionally identifies the
 :                   component, subsystem, or authority responsible for defining the meaning of the
 :                   error code, while the local part identifies the specific error condition. The
 :                   namespace URI <code>http://www.w3.org/2005/xqt-errors</code> is used for errors
 :                   defined in this specification; other namespace URIs may be used for errors defined
 :                   by the application.</p><p>If the external processing environment expects the error code to be returned as a
 :                   URI or a string rather than as an <code>xs:QName</code>, then an error code with
 :                   namespace URI <code>NS</code> and local part <code>LP</code> will be returned in
 :                   the form <code>NS#LP</code>. The namespace URI part of the error code should
 :                   therefore not include a fragment identifier.</p></item><item><p>The <code>$description</code> is a natural-language description of the error
 :                   condition.</p></item><item><p>The <code>$error-object</code> is an arbitrary value used to convey additional
 :                   information about the error, and may be used in any way the application
 :                   chooses.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function always raises a <phrase diff="add" at="L">dynamic</phrase> error. By default, it raises <errorref class="ER" code="0000"/></p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-error
 :)
declare function fn:error($code as xs:QName) as  none external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the <code>fn:error</code> function raises an application-defined
 :             error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/><arg name="error-object" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function never returns a value. Instead it always raises an error. The effect of
 :             the error is identical to the effect of dynamic errors raised implicitly, for example
 :             when an incorrect argument is supplied to a function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The parameters to the <code>fn:error</code> function supply information that is
 :             associated with the error condition and that is made available to a caller that asks for
 :             information about the error. The error may be caught either by the host language (using
 :             a try/catch construct in XSLT or XQuery, for example), or by the calling application or
 :             external processing environment. The way in which error information is returned to the
 :             external processing environment is <termref def="implementation-dependent"/></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>fn:error</code> is called with no arguments, then its behavior is the same as
 :             the function call: </p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')) </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$code</code> is the empty sequence then the effective value is the
 :                <code>xs:QName</code> constructed by:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">There are three pieces of information that may be associated with an error:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>The <code>$code</code> is an error code that distinguishes this error from others.
 :                   It is an <code>xs:QName</code>; the namespace URI conventionally identifies the
 :                   component, subsystem, or authority responsible for defining the meaning of the
 :                   error code, while the local part identifies the specific error condition. The
 :                   namespace URI <code>http://www.w3.org/2005/xqt-errors</code> is used for errors
 :                   defined in this specification; other namespace URIs may be used for errors defined
 :                   by the application.</p><p>If the external processing environment expects the error code to be returned as a
 :                   URI or a string rather than as an <code>xs:QName</code>, then an error code with
 :                   namespace URI <code>NS</code> and local part <code>LP</code> will be returned in
 :                   the form <code>NS#LP</code>. The namespace URI part of the error code should
 :                   therefore not include a fragment identifier.</p></item><item><p>The <code>$description</code> is a natural-language description of the error
 :                   condition.</p></item><item><p>The <code>$error-object</code> is an arbitrary value used to convey additional
 :                   information about the error, and may be used in any way the application
 :                   chooses.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function always raises a <phrase diff="add" at="L">dynamic</phrase> error. By default, it raises <errorref class="ER" code="0000"/></p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-error
 :)
declare function fn:error($code as xs:QName?,  $description as xs:string) as  none external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the <code>fn:error</code> function raises an application-defined
 :             error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/></proto></example><example role="signature"><proto name="error" return-type="none" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="code" type="xs:QName?"/><arg name="description" type="xs:string"/><arg name="error-object" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function never returns a value. Instead it always raises an error. The effect of
 :             the error is identical to the effect of dynamic errors raised implicitly, for example
 :             when an incorrect argument is supplied to a function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The parameters to the <code>fn:error</code> function supply information that is
 :             associated with the error condition and that is made available to a caller that asks for
 :             information about the error. The error may be caught either by the host language (using
 :             a try/catch construct in XSLT or XQuery, for example), or by the calling application or
 :             external processing environment. The way in which error information is returned to the
 :             external processing environment is <termref def="implementation-dependent"/></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>fn:error</code> is called with no arguments, then its behavior is the same as
 :             the function call: </p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')) </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$code</code> is the empty sequence then the effective value is the
 :                <code>xs:QName</code> constructed by:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">There are three pieces of information that may be associated with an error:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>The <code>$code</code> is an error code that distinguishes this error from others.
 :                   It is an <code>xs:QName</code>; the namespace URI conventionally identifies the
 :                   component, subsystem, or authority responsible for defining the meaning of the
 :                   error code, while the local part identifies the specific error condition. The
 :                   namespace URI <code>http://www.w3.org/2005/xqt-errors</code> is used for errors
 :                   defined in this specification; other namespace URIs may be used for errors defined
 :                   by the application.</p><p>If the external processing environment expects the error code to be returned as a
 :                   URI or a string rather than as an <code>xs:QName</code>, then an error code with
 :                   namespace URI <code>NS</code> and local part <code>LP</code> will be returned in
 :                   the form <code>NS#LP</code>. The namespace URI part of the error code should
 :                   therefore not include a fragment identifier.</p></item><item><p>The <code>$description</code> is a natural-language description of the error
 :                   condition.</p></item><item><p>The <code>$error-object</code> is an arbitrary value used to convey additional
 :                   information about the error, and may be used in any way the application
 :                   chooses.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function always raises a <phrase diff="add" at="L">dynamic</phrase> error. By default, it raises <errorref class="ER" code="0000"/></p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-error
 :)
declare function fn:error( $code as xs:QName?,  $description as xs:string,  $error-object as item()*) as  none external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns <code>$arg</code> if it contains exactly one item. Otherwise, raises an
 :             error. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="exactly-one" return-type="item()" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Except in error cases, the function returns <code>$arg</code> unchanged.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0005"/> if <code>$arg</code> is an empty
 :             sequence or a sequence containing more than one item.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-exactly-one
 :)
declare function fn:exactly-one($arg as item()*) as  item() external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the argument is a non-empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="exists" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is a non-empty sequence, the function returns
 :                <code>true</code>; otherwise, the function returns <code>false</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:exists(fn:remove(("hello"), 1))</code> returns <code>false()</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:exists(fn:remove(("hello", "world"), 1))</code> returns <code>true()</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-exists
 :)
declare function fn:exists($arg as item()*) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the <code>xs:boolean</code> value <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="false" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result is equivalent to <code>xs:boolean("0")</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:false()</code> returns <code>xs:boolean(0)</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-false
 :)
declare function fn:false() as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns those items from the sequence <var>$seq</var> for which the supplied
 :             function <var>$f</var> returns true.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="filter" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="item()*"/><arg name="f" type="function(item()) as xs:boolean"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of the function is equivalent to the following implementation in XQuery:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : declare function fn:filter(
 :         $seq as item()*,
 :         $f as function(item()) as xs:boolean)
 :         as item()* {
 :   if (fn:empty($seq))
 :   then ()
 :   else ( fn:head($seq)[$f(.) eq fn:true()], 
 :          fn:filter(fn:tail($seq), $f)
 :        )
 : };</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">or its equivalent in XSLT:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : &lt;xsl:function name="fn:filter" as="item()*"&gt;
 :   &lt;xsl:param name="seq" as="item()*"/&gt;
 :   &lt;xsl:param name="f" as="function(item()) as xs:boolean"/&gt;
 :   &lt;xsl:if test="fn:exists($seq)"&gt;
 :     &lt;xsl:sequence select="fn:head($seq)[$f(.) eq fn:true()], fn:filter(fn:tail($seq), $f)"/&gt;
 :   &lt;/xsl:if&gt;
 : &lt;/xsl:function&gt;
 :          </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">As a consequence of the function signature and the function calling
 :             rules, a type error occurs if the supplied function <var>$f</var> returns anything other
 :             than a single <code>xs:boolean</code> item; there is no conversion to an effective
 :             boolean value.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-filter
 :)
declare function fn:filter($seq as item()*,  $f as function(item()) as xs:boolean) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Rounds <code>$arg</code> downwards to a whole number.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="floor" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">General rules: see <specref ref="numeric-value-functions"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the largest (closest to positive infinity) number with no
 :             fractional part that is not greater than the value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the type of <code>$arg</code> is one of the four numeric types <code>xs:float</code>,
 :                <code>xs:double</code>, <code>xs:decimal</code> or <code>xs:integer</code> the type
 :             of the result is the same as the type of <code>$arg</code>. If the type of
 :                <code>$arg</code> is a type derived from one of the numeric types, the result is an
 :             instance of the base numeric type.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For <code>xs:float</code> and <code>xs:double</code> arguments, if the argument is
 :             positive zero, then positive zero is returned. If the argument is negative zero, then
 :             negative zero is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:floor(10.5)</code> returns <code>10</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:floor(-10.5)</code> returns <code>-11</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-floor
 :)
declare function fn:floor($arg as numeric?) as  numeric? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Processes the supplied sequence from left to right, applying the supplied
 :             function repeatedly to each item in turn, together with an accumulated result value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="fold-left" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="item()*"/><arg name="zero" type="item()*"/><arg name="f" type="function(item()*, item()) as item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of the function is equivalent to the following implementation in XQuery:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : declare function fn:fold-left(
 :         $seq as item()*
 :         $zero as item()*,
 :         $f as function(item()*, item()) as item()*) 
 :         as item()* {
 :   if (fn:empty($seq))
 :   then $zero
 :   else fn:fold-left(fn:tail($seq), $f($zero, fn:head($seq)), $f)
 : };</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">or its equivalent in XSLT:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : &lt;xsl:function name="fn:fold-left" as="item()*"&gt;
 :   &lt;xsl:param name="seq" as="item()*"/&gt;
 :   &lt;xsl:param name="zero" as="item()*"/&gt;
 :   &lt;xsl:param name="f" as="function(item()*, item()) as item()*"/&gt;
 :   &lt;xsl:choose&gt;
 :     &lt;xsl:when test="fn:empty($seq)"&gt;
 :       &lt;xsl:sequence select="$zero"/&gt;
 :     &lt;/xsl:when&gt;
 :     &lt;xsl:otherwise&gt;
 :       &lt;xsl:sequence select="fn:fold-left(fn:tail($seq), $f($zero, fn:head($seq)), $f)"/&gt;
 :     &lt;/xsl:otherwise&gt;
 :   &lt;/xsl:choose&gt;
 : &lt;/xsl:function&gt;
 :          </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">As a consequence of the function signature and the function calling
 :             rules, a type error occurs if the supplied function <var>$f</var> cannot be applied to
 :             two arguments, where the first argument is either the value of <var>$zero</var> or the
 :             result of a previous application of <var>$f</var>, and the second is <var>$seq</var> or
 :             any trailing subsequence of <var>$seq</var>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-fold-left
 :)
declare function fn:fold-left($seq as item()*,  $zero as item()*,  $f as function(item()*, item()) as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Processes the supplied sequence from right to left, applying the supplied
 :             function repeatedly to each item in turn, together with an accumulated result value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="fold-right" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="item()*"/><arg name="zero" type="item()*"/><arg name="f" type="function(item()*, item()) as item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of the function is equivalent to the following implementation in XQuery:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : declare function fn:fold-right(
 :         $seq as item()*, 
 :         $zero as item()*, 
 :         $f as function(item(), item()*) as item()*) 
 :         as item()* {
 :   if (fn:empty($seq))
 :   then $zero
 :   else $f(fn:head($seq), fn:fold-right(fn:tail($seq), $zero, $f))
 : };</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">or its equivalent in XSLT:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : &lt;xsl:function name="fn:fold-right" as="item()*"&gt;
 :   &lt;xsl:param name="seq" as="item()*"/&gt;
 :   &lt;xsl:param name="zero" as="item()*"/&gt;
 :   &lt;xsl:param name="f" as="function(item(), item()*) as item()*"/&gt;
 :   &lt;xsl:choose&gt;
 :     &lt;xsl:when test="fn:empty($seq)"&gt;
 :       &lt;xsl:sequence select="$zero"/&gt;
 :     &lt;/xsl:when&gt;
 :     &lt;xsl:otherwise&gt;
 :       &lt;xsl:sequence select="$f(fn:head($seq), fn:fold-right(fn:tail($seq), $zero, $f))"/&gt;
 :     &lt;/xsl:otherwise&gt;
 :   &lt;/xsl:choose&gt;
 : &lt;/xsl:function&gt;
 :          </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">As a consequence of the function signature and the function calling
 :             rules, a type error occurs if the supplied function <var>$f</var> cannot be applied to
 :             two arguments, where the first argument is any item in the sequence <var>$seq</var>, and
 :             the second is either the value of <var>$zero</var> or the result of a previous
 :             application of <var>$f</var>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-fold-right
 :)
declare function fn:fold-right($seq as item()*,  $zero as item()*,  $f as function(item()*, item()) as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing an <code>xs:date</code> value formatted for display.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-date" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:date?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-date" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:date?"/><arg name="picture" type="xs:string"/><arg name="language" type="xs:string?"/><arg name="calendar" type="xs:string?"/><arg name="place" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default calendar, and default language, and default place, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The five-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See <specref ref="rules-for-datetime-formatting"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-date
 :)
declare function fn:format-date( $value as xs:date?,  $picture as xs:string,  $language as xs:string?,  $calendar as xs:string?,  $place as xs:string?) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing an <code>xs:date</code> value formatted for display.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-date" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:date?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-date" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:date?"/><arg name="picture" type="xs:string"/><arg name="language" type="xs:string?"/><arg name="calendar" type="xs:string?"/><arg name="place" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default calendar, and default language, and default place, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The five-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See <specref ref="rules-for-datetime-formatting"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-date
 :)
declare function fn:format-date($value as xs:date?,  $picture as xs:string) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing an <code>xs:dateTime</code> value formatted for display.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-dateTime" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:dateTime?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-dateTime" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:dateTime?"/><arg name="picture" type="xs:string"/><arg name="language" type="xs:string?"/><arg name="calendar" type="xs:string?"/><arg name="place" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default calendar, and default language, and default place, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The five-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See <specref ref="rules-for-datetime-formatting"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-dateTime
 :)
declare function fn:format-dateTime( $value as xs:dateTime?,  $picture as xs:string,  $language as xs:string?,  $calendar as xs:string?,  $place as xs:string?) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing an <code>xs:dateTime</code> value formatted for display.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-dateTime" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:dateTime?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-dateTime" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:dateTime?"/><arg name="picture" type="xs:string"/><arg name="language" type="xs:string?"/><arg name="calendar" type="xs:string?"/><arg name="place" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default calendar, and default language, and default place, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The five-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See <specref ref="rules-for-datetime-formatting"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-dateTime
 :)
declare function fn:format-dateTime($value as xs:dateTime?,  $picture as xs:string) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Formats an integer according to a given picture string, using the conventions
 :             of a given natural language if specified.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-integer" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:integer?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-integer" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:integer?"/><arg name="picture" type="xs:string"/><arg name="lang" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default language.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$value</code> is an empty sequence, the function returns a zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In all other cases, the <code>$picture</code> argument describes the format in which
 :                <code>$value</code> is output.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The rules that follow describe how non-negative numbers are output. If the value of
 :                <code>$value</code> is negative, the rules below are applied to the absolute value of
 :                <code>$value</code>, and a minus sign is prepended to the result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="L">The value of <code>$picture</code> consists of a primary format token, 
 :             optionally followed
 :             by a format modifier. The primary format token is always present and <rfc2119>must not</rfc2119>
 :             be zero-length. If the string contains one or more semicolons then everything that
 :             precedes the last semicolon is taken as the primary format token and everything
 :             that follows is taken as the format modifier; if the string contains no
 :             semicolon then the entire picture is taken as the primary format token, and the
 :             format modifier is taken to be absent (which is equivalent to supplying a
 :             zero-length string).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The primary format token is classified as one of the following:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>A <var>decimal-digit-pattern</var> made up of <var>optional-digit-signs</var>,
 :                      <var>mandatory-digit-signs</var>, and <var>grouping-separator-signs</var>.</p><ulist><item><p>The <var>optional-digit-sign</var> is the character "#".</p></item><item><p>A <var>mandatory-digit-sign</var> is a <termref def="character">character</termref> in Unicode category Nd. All
 :                            <var>mandatory-digit-signs</var> within the format token <rfc2119>must</rfc2119> be from the
 :                         same digit family, where a digit family is a sequence of ten consecutive
 :                         characters in Unicode category Nd, having digit values 0 through 9. Within
 :                         the format token, these digits are interchangeable: a three-digit number may
 :                         thus be indicated equivalently by <code>000</code>, <code>001</code>, or
 :                            <code>999</code>.</p></item><item><p>a <var>grouping-separator-sign</var> is a non-alphanumeric character, that
 :                         is a <termref def="character">character</termref> whose Unicode category is
 :                         other than Nd, Nl, No, Lu, Ll, Lt, Lm or Lo.</p></item></ulist><p diff="chg" at="L">If the primary format token contains at least one Unicode digit 
 :                   then it is taken as a decimal digit pattern, and in this case it <rfc2119>must</rfc2119>
 :                   match the regular expression <code>^((\p{Nd}|#|[^\p{N}\p{L}])+?)$</code>. If it contains
 :                   a digit but does not match this pattern, a <phrase diff="add" at="L">dynamic</phrase> error 
 :                   is raised <errorref class="DF" code="1310"/>.</p><note><p diff="add" at="L">If a semicolon is to be used as a grouping separator, then the primary
 :                format token as a whole must be followed by another semicolon, to ensure that
 :                the grouping separator is not mistaken as a separator between the primary format
 :                token and the format modifier.</p></note><p>There <rfc2119>must</rfc2119> be at least one <var>mandatory-digit-sign</var>. There may be zero or
 :                   more <var>optional-digit-signs</var>, and (if present) these <rfc2119>must</rfc2119> precede all
 :                      <var>mandatory-digit-signs</var>. There may be zero or more
 :                      <var>grouping-separator-signs</var>. A <var>grouping-separator-sign</var> <rfc2119>must
 :                   not</rfc2119> appear at the start or end of the <var>decimal-digit-pattern</var>, nor
 :                   adjacent to another <var>grouping-separator-sign</var>.</p><p>The corresponding output format is a decimal number, using this digit family, with
 :                   at least as many digits as there are <var>mandatory-digit-signs</var> in the
 :                   format token. Thus, a format token <code>1</code> generates the sequence <code>0 1
 :                      2 ... 10 11 12 ...</code>, and a format token <code>01</code> (or equivalently,
 :                      <code>00</code> or <code>99</code>) generates the sequence <code>00 01 02 ...
 :                      09 10 11 12 ... 99 100 101</code>. A format token of <code>&amp;#x661;</code>
 :                   (Arabic-Indic digit one) generates the sequence <code>١</code> then <code>٢</code>
 :                   then <code>٣</code> ...</p><p>The <var>grouping-separator-signs</var> are handled as follows. The position of
 :                   grouping separators within the format token, counting backwards from the last
 :                   digit, indicates the position of grouping separators to appear within the
 :                   formatted number, and the character used as the <var>grouping-separator-sign</var>
 :                   within the format token indicates the character to be used as the corresponding
 :                   grouping separator in the formatted number. If <var>grouping-separator-signs</var>
 :                   appear at regular intervals within the format token, that is if the same grouping
 :                   separator appears at positions forming a sequence <var>N</var>, 2<var>N</var>,
 :                      3<var>N</var>, ... for some integer value <var>N</var> (including the case
 :                   where there is only one number in the list), then the sequence is extrapolated to
 :                   the left, so grouping separators will be used in the formatted number at every
 :                   multiple of <var>N</var>. For example, if the format token is <code>0'000</code>
 :                   then the number one million will be formatted as <code>1'000'000</code>, while the
 :                   number fifteen will be formatted as <code>0'015</code>.</p><p>The only purpose of <var>optional-digit-signs</var> is to mark the position of
 :                      <var>grouping-separator-signs</var>. For example, if the format token is
 :                      <code>#'##0</code> then the number one million will be formatted as
 :                      <code>1'000'000</code>, while the number fifteen will be formatted as
 :                      <code>15</code>. A grouping separator is included in the formatted number only
 :                   if there is a digit to its left, which will only be the case if either (a) the
 :                   number is large enough to require that digit, or (b) the number of
 :                      <var>mandatory-digit-signs</var> in the format token requires insignificant
 :                   leading zeros to be present.</p><note><p>Numbers will never be truncated. Given the <var>decimal-digit-pattern</var>
 :                      <code>01</code>, the number three hundred will be output as <code>300</code>,
 :                      despite the absence of any <var>optional-digit-sign</var>.</p></note></item><item><p>The format token <code>A</code>, which generates the sequence <code>A B C ... Z AA AB
 :                      AC...</code>.</p></item><item><p>The format token <code>a</code>, which generates the sequence <code>a b c ... z aa ab
 :                      ac...</code>.</p></item><item><p>The format token <code>i</code>, which generates the sequence <code>i ii iii iv v vi vii
 :                      viii ix x ...</code>.</p></item><item><p>The format token <code>I</code>, which generates the sequence <code>I II III IV V VI VII
 :                      VIII IX X ...</code>.</p></item><item><p>The format token <code>w</code>, which generates numbers written as lower-case words, for
 :                   example in English, <code>one two three four ...</code>
 :                </p></item><item><p>The format token <code>W</code>, which generates numbers written as upper-case words, for
 :                   example in English, <code>ONE TWO THREE FOUR ...</code>
 :                </p></item><item><p>The format token <code>Ww</code>, which generates numbers written as title-case words, for
 :                   example in English, <code>One Two Three Four ...</code>
 :                </p></item><item><p>Any other format token, which indicates a numbering sequence in which that token
 :                   represents the number 1 (one) (but see the note below).
 :                   <!-- Where possible (given the constraint that format tokens
 : 						must be alphanumeric, and that they must be distinct) the format token
 : 						used to represent a numbering sequence should be the same as the representation
 : 						of the number 1 (one) in that sequence.-->
 :                   It is <termref def="implementation-defined">implementation-defined</termref> which
 :                   numbering sequences, additional to those listed above, are supported. If an
 :                   implementation does not support a numbering sequence represented by the given
 :                   token, it <rfc2119>must</rfc2119> use a format token of <code>1</code>.</p><note><p>In some traditional numbering sequences additional signs are added to denote
 :                      that the letters should be interpreted as numbers; these are not included in
 :                      the format token. An example (see also the example below) is classical Greek
 :                      where a <emph>dexia keraia</emph> (x0374, ʹ) and sometimes an <emph>aristeri keraia</emph>
 :                      (x0375, ͵) is added.</p></note></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For all format tokens other than the first kind above (one that consists of decimal
 :             digits), there <rfc2119>may</rfc2119> be <termref def="implementation-defined">implementation-defined</termref> lower and upper bounds on the range of numbers that
 :             can be formatted using this format token; indeed, for some numbering sequences there may
 :             be intrinsic limits. For example, the format token <code>&amp;#x2460;</code> (circled
 :             digit one, ①) has a range <phrase diff="chg" at="M">imposed by the Unicode character repertoire — 1 to 20 in
 :             Unicode versions prior to 4.0, increased in subsequent versions</phrase>. For
 :             the numbering sequences described above any upper bound imposed by the implementation
 :                <rfc2119>must not</rfc2119> be less than 1000 (one thousand) and any lower bound must
 :             not be greater than 1. Numbers that fall outside this range <rfc2119>must</rfc2119> be
 :             formatted using the format token <code>1</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The above expansions of numbering sequences for format tokens such as <code>a</code> and
 :                <code>i</code> are indicative but not prescriptive. There are various conventions in
 :             use for how alphabetic sequences continue when the alphabet is exhausted, and differing
 :             conventions for how roman numerals are written (for example, <code>IV</code> versus
 :                <code>IIII</code> as the representation of the number 4). Sometimes alphabetic
 :             sequences are used that omit letters such as <code>i</code> and <code>o</code>. This
 :             specification does not prescribe the detail of any sequence other than those sequences
 :             consisting entirely of decimal digits.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Many numbering sequences are language-sensitive. This applies especially to the sequence
 :             selected by the tokens <code>w</code>, <code>W</code> and <code>Ww</code>. It also
 :             applies to other sequences, for example different languages using the Cyrillic alphabet
 :             use different sequences of characters, each starting with the letter #x410 (Cyrillic
 :             capital letter A). In such cases, the <code>$lang</code> argument specifies which
 :             language's conventions are to be used. <phrase diff="chg" at="L">If the argument
 :             is specified, the value <rfc2119>should</rfc2119> be either an empty sequence
 :             or a value that would be valid for the <code>xml:lang</code> attribute (see <bibref ref="REC-xml"/>).
 :             Note that this permits the identification of sublanguages based on country codes (from ISO 3166-1)
 :             as well as identification of dialects and regions within a country.</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The set of languages
 :             for which numbering is supported is <termref def="implementation-defined"/>.
 :             If the <code>$lang</code> argument is absent, 
 :             or is set to an empty sequence, or is invalid, or is not a language supported by the
 :             implementation, then the number is formatted using <phrase diff="chg" at="K">the
 :             default language from the dynamic context</phrase>. 
 :             </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The format modifier <phrase diff="chg" at="L"><rfc2119>must</rfc2119>
 :             be a string that matches the regular expression <code diff="chg" at="M">^([co](\(.+\))?)?[at]?$</code>. </phrase>
 :             That is, if it is present it must consist of one <phrase diff="add" at="G">or more</phrase> of
 :             the following, in <phrase diff="del" at="K">any</phrase> order:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p diff="chg" at="G">either <code>c</code> or <code>o</code>, optionally followed by
 :                   a sequence of characters enclosed between parentheses, to indicate cardinal or
 :                   ordinal numbering respectively, the default being cardinal numbering</p></item><item><p diff="chg" at="G">either <code>a</code> or <code>t</code>, to indicate alphabetic
 :                   or traditional numbering respectively, the default being <termref def="implementation-defined">implementation-defined</termref>.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the <code>o</code> modifier is present, this indicates a request to output ordinal
 :             numbers rather than cardinal numbers. For example, in English, when used with the format
 :             token <code>1</code>, this outputs the sequence <code>1st 2nd 3rd 4th ...</code>, and
 :             when used with the format token <code>w</code> outputs the sequence <code>first second
 :             third fourth ...</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">The string of characters between the parentheses, if present, is used to
 :          select between other possible variations of cardinal or ordinal numbering sequences.
 :          The interpretation of this string is <termref def="implemementation-defined">implementation-defined</termref>. No error occurs
 :          if the implementation does not define any interpretation for the defined string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For example, in some languages, ordinal numbers vary depending on the grammatical context:
 :             they may have different genders and may decline with the noun that they qualify.
 :             In such cases the string appearing in parentheses after the letter <code>o</code> may be
 :             used to indicate the variation of the ordinal number required. The way in which the
 :             variation is indicated will depend on the conventions of the language. For inflected
 :             languages that vary the ending of the word, the <rfc2119>recommended</rfc2119> approach is to indicate the
 :             required ending, preceded by a hyphen: for example in German, appropriate values are
 :                <code>o(-e)</code>, <code>o(-er)</code>, <code>o(-es)</code>, <code>o(-en)</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">It is <termref def="implementation-defined">implementation-defined</termref> what
 :             combinations of values of the format token, the language, and the cardinal/ordinal
 :             modifier are supported. If ordinal numbering is not supported for the combination of the
 :             format token, the language, and the string appearing in parentheses, the request is
 :             ignored and cardinal numbers are generated instead.</p><example xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><head>Ordinal Numbering in Italian</head><p>The specification <code>"1;o(-º)"</code> with <code>$lang</code> equal to
 :                   <code>it</code>, if supported, should produce the sequence:</p><pre highlight-as="xquery" xml:space="preserve">1º 2º 3º 4º ...</pre><p>The specification <code>"Ww;o"</code> with <code>$lang</code> equal to
 :                   <code>it</code>, if supported, should produce the sequence:</p><pre highlight-as="xquery" xml:space="preserve">Primo Secondo Terzo Quarto Quinto ...</pre></example><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <phrase diff="chg" at="G">use of the <code>a</code> or <code>t</code>
 :                modifier</phrase> disambiguates between numbering sequences that use letters. In many
 :             languages there are two commonly used numbering sequences that use letters. One
 :             numbering sequence assigns numeric values to letters in alphabetic sequence, and the
 :             other assigns numeric values to each letter in some other manner traditional in that
 :             language. In English, these would correspond to the numbering sequences specified by the
 :             format tokens <code>a</code> and <code>i</code>. In some languages, the first member of
 :             each sequence is the same, and so the format token alone would be ambiguous. <phrase diff="chg" at="G">In the absence of the <code>a</code> or <code>t</code> modifier,
 :                the default is <termref def="implementation-defined">implementation-defined</termref></phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DF" code="1310"/> if the format token is invalid,
 :             that is, if it violates any mandatory rules (indicated by an emphasized <rfc2119>must</rfc2119>
 :             or <rfc2119>required</rfc2119> keyword in the above rules). For example, the error is raised if
 :             the primary format token contains a digit but does not match the required regular expression.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-integer
 :)
declare function fn:format-integer($value as xs:integer?,  $picture as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Formats an integer according to a given picture string, using the conventions
 :             of a given natural language if specified.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-integer" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:integer?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-integer" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:integer?"/><arg name="picture" type="xs:string"/><arg name="lang" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default language.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$value</code> is an empty sequence, the function returns a zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In all other cases, the <code>$picture</code> argument describes the format in which
 :                <code>$value</code> is output.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The rules that follow describe how non-negative numbers are output. If the value of
 :                <code>$value</code> is negative, the rules below are applied to the absolute value of
 :                <code>$value</code>, and a minus sign is prepended to the result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="L">The value of <code>$picture</code> consists of a primary format token, 
 :             optionally followed
 :             by a format modifier. The primary format token is always present and <rfc2119>must not</rfc2119>
 :             be zero-length. If the string contains one or more semicolons then everything that
 :             precedes the last semicolon is taken as the primary format token and everything
 :             that follows is taken as the format modifier; if the string contains no
 :             semicolon then the entire picture is taken as the primary format token, and the
 :             format modifier is taken to be absent (which is equivalent to supplying a
 :             zero-length string).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The primary format token is classified as one of the following:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>A <var>decimal-digit-pattern</var> made up of <var>optional-digit-signs</var>,
 :                      <var>mandatory-digit-signs</var>, and <var>grouping-separator-signs</var>.</p><ulist><item><p>The <var>optional-digit-sign</var> is the character "#".</p></item><item><p>A <var>mandatory-digit-sign</var> is a <termref def="character">character</termref> in Unicode category Nd. All
 :                            <var>mandatory-digit-signs</var> within the format token <rfc2119>must</rfc2119> be from the
 :                         same digit family, where a digit family is a sequence of ten consecutive
 :                         characters in Unicode category Nd, having digit values 0 through 9. Within
 :                         the format token, these digits are interchangeable: a three-digit number may
 :                         thus be indicated equivalently by <code>000</code>, <code>001</code>, or
 :                            <code>999</code>.</p></item><item><p>a <var>grouping-separator-sign</var> is a non-alphanumeric character, that
 :                         is a <termref def="character">character</termref> whose Unicode category is
 :                         other than Nd, Nl, No, Lu, Ll, Lt, Lm or Lo.</p></item></ulist><p diff="chg" at="L">If the primary format token contains at least one Unicode digit 
 :                   then it is taken as a decimal digit pattern, and in this case it <rfc2119>must</rfc2119>
 :                   match the regular expression <code>^((\p{Nd}|#|[^\p{N}\p{L}])+?)$</code>. If it contains
 :                   a digit but does not match this pattern, a <phrase diff="add" at="L">dynamic</phrase> error 
 :                   is raised <errorref class="DF" code="1310"/>.</p><note><p diff="add" at="L">If a semicolon is to be used as a grouping separator, then the primary
 :                format token as a whole must be followed by another semicolon, to ensure that
 :                the grouping separator is not mistaken as a separator between the primary format
 :                token and the format modifier.</p></note><p>There <rfc2119>must</rfc2119> be at least one <var>mandatory-digit-sign</var>. There may be zero or
 :                   more <var>optional-digit-signs</var>, and (if present) these <rfc2119>must</rfc2119> precede all
 :                      <var>mandatory-digit-signs</var>. There may be zero or more
 :                      <var>grouping-separator-signs</var>. A <var>grouping-separator-sign</var> <rfc2119>must
 :                   not</rfc2119> appear at the start or end of the <var>decimal-digit-pattern</var>, nor
 :                   adjacent to another <var>grouping-separator-sign</var>.</p><p>The corresponding output format is a decimal number, using this digit family, with
 :                   at least as many digits as there are <var>mandatory-digit-signs</var> in the
 :                   format token. Thus, a format token <code>1</code> generates the sequence <code>0 1
 :                      2 ... 10 11 12 ...</code>, and a format token <code>01</code> (or equivalently,
 :                      <code>00</code> or <code>99</code>) generates the sequence <code>00 01 02 ...
 :                      09 10 11 12 ... 99 100 101</code>. A format token of <code>&amp;#x661;</code>
 :                   (Arabic-Indic digit one) generates the sequence <code>١</code> then <code>٢</code>
 :                   then <code>٣</code> ...</p><p>The <var>grouping-separator-signs</var> are handled as follows. The position of
 :                   grouping separators within the format token, counting backwards from the last
 :                   digit, indicates the position of grouping separators to appear within the
 :                   formatted number, and the character used as the <var>grouping-separator-sign</var>
 :                   within the format token indicates the character to be used as the corresponding
 :                   grouping separator in the formatted number. If <var>grouping-separator-signs</var>
 :                   appear at regular intervals within the format token, that is if the same grouping
 :                   separator appears at positions forming a sequence <var>N</var>, 2<var>N</var>,
 :                      3<var>N</var>, ... for some integer value <var>N</var> (including the case
 :                   where there is only one number in the list), then the sequence is extrapolated to
 :                   the left, so grouping separators will be used in the formatted number at every
 :                   multiple of <var>N</var>. For example, if the format token is <code>0'000</code>
 :                   then the number one million will be formatted as <code>1'000'000</code>, while the
 :                   number fifteen will be formatted as <code>0'015</code>.</p><p>The only purpose of <var>optional-digit-signs</var> is to mark the position of
 :                      <var>grouping-separator-signs</var>. For example, if the format token is
 :                      <code>#'##0</code> then the number one million will be formatted as
 :                      <code>1'000'000</code>, while the number fifteen will be formatted as
 :                      <code>15</code>. A grouping separator is included in the formatted number only
 :                   if there is a digit to its left, which will only be the case if either (a) the
 :                   number is large enough to require that digit, or (b) the number of
 :                      <var>mandatory-digit-signs</var> in the format token requires insignificant
 :                   leading zeros to be present.</p><note><p>Numbers will never be truncated. Given the <var>decimal-digit-pattern</var>
 :                      <code>01</code>, the number three hundred will be output as <code>300</code>,
 :                      despite the absence of any <var>optional-digit-sign</var>.</p></note></item><item><p>The format token <code>A</code>, which generates the sequence <code>A B C ... Z AA AB
 :                      AC...</code>.</p></item><item><p>The format token <code>a</code>, which generates the sequence <code>a b c ... z aa ab
 :                      ac...</code>.</p></item><item><p>The format token <code>i</code>, which generates the sequence <code>i ii iii iv v vi vii
 :                      viii ix x ...</code>.</p></item><item><p>The format token <code>I</code>, which generates the sequence <code>I II III IV V VI VII
 :                      VIII IX X ...</code>.</p></item><item><p>The format token <code>w</code>, which generates numbers written as lower-case words, for
 :                   example in English, <code>one two three four ...</code>
 :                </p></item><item><p>The format token <code>W</code>, which generates numbers written as upper-case words, for
 :                   example in English, <code>ONE TWO THREE FOUR ...</code>
 :                </p></item><item><p>The format token <code>Ww</code>, which generates numbers written as title-case words, for
 :                   example in English, <code>One Two Three Four ...</code>
 :                </p></item><item><p>Any other format token, which indicates a numbering sequence in which that token
 :                   represents the number 1 (one) (but see the note below).
 :                   <!-- Where possible (given the constraint that format tokens
 : 						must be alphanumeric, and that they must be distinct) the format token
 : 						used to represent a numbering sequence should be the same as the representation
 : 						of the number 1 (one) in that sequence.-->
 :                   It is <termref def="implementation-defined">implementation-defined</termref> which
 :                   numbering sequences, additional to those listed above, are supported. If an
 :                   implementation does not support a numbering sequence represented by the given
 :                   token, it <rfc2119>must</rfc2119> use a format token of <code>1</code>.</p><note><p>In some traditional numbering sequences additional signs are added to denote
 :                      that the letters should be interpreted as numbers; these are not included in
 :                      the format token. An example (see also the example below) is classical Greek
 :                      where a <emph>dexia keraia</emph> (x0374, ʹ) and sometimes an <emph>aristeri keraia</emph>
 :                      (x0375, ͵) is added.</p></note></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For all format tokens other than the first kind above (one that consists of decimal
 :             digits), there <rfc2119>may</rfc2119> be <termref def="implementation-defined">implementation-defined</termref> lower and upper bounds on the range of numbers that
 :             can be formatted using this format token; indeed, for some numbering sequences there may
 :             be intrinsic limits. For example, the format token <code>&amp;#x2460;</code> (circled
 :             digit one, ①) has a range <phrase diff="chg" at="M">imposed by the Unicode character repertoire — 1 to 20 in
 :             Unicode versions prior to 4.0, increased in subsequent versions</phrase>. For
 :             the numbering sequences described above any upper bound imposed by the implementation
 :                <rfc2119>must not</rfc2119> be less than 1000 (one thousand) and any lower bound must
 :             not be greater than 1. Numbers that fall outside this range <rfc2119>must</rfc2119> be
 :             formatted using the format token <code>1</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The above expansions of numbering sequences for format tokens such as <code>a</code> and
 :                <code>i</code> are indicative but not prescriptive. There are various conventions in
 :             use for how alphabetic sequences continue when the alphabet is exhausted, and differing
 :             conventions for how roman numerals are written (for example, <code>IV</code> versus
 :                <code>IIII</code> as the representation of the number 4). Sometimes alphabetic
 :             sequences are used that omit letters such as <code>i</code> and <code>o</code>. This
 :             specification does not prescribe the detail of any sequence other than those sequences
 :             consisting entirely of decimal digits.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Many numbering sequences are language-sensitive. This applies especially to the sequence
 :             selected by the tokens <code>w</code>, <code>W</code> and <code>Ww</code>. It also
 :             applies to other sequences, for example different languages using the Cyrillic alphabet
 :             use different sequences of characters, each starting with the letter #x410 (Cyrillic
 :             capital letter A). In such cases, the <code>$lang</code> argument specifies which
 :             language's conventions are to be used. <phrase diff="chg" at="L">If the argument
 :             is specified, the value <rfc2119>should</rfc2119> be either an empty sequence
 :             or a value that would be valid for the <code>xml:lang</code> attribute (see <bibref ref="REC-xml"/>).
 :             Note that this permits the identification of sublanguages based on country codes (from ISO 3166-1)
 :             as well as identification of dialects and regions within a country.</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The set of languages
 :             for which numbering is supported is <termref def="implementation-defined"/>.
 :             If the <code>$lang</code> argument is absent, 
 :             or is set to an empty sequence, or is invalid, or is not a language supported by the
 :             implementation, then the number is formatted using <phrase diff="chg" at="K">the
 :             default language from the dynamic context</phrase>. 
 :             </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The format modifier <phrase diff="chg" at="L"><rfc2119>must</rfc2119>
 :             be a string that matches the regular expression <code diff="chg" at="M">^([co](\(.+\))?)?[at]?$</code>. </phrase>
 :             That is, if it is present it must consist of one <phrase diff="add" at="G">or more</phrase> of
 :             the following, in <phrase diff="del" at="K">any</phrase> order:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p diff="chg" at="G">either <code>c</code> or <code>o</code>, optionally followed by
 :                   a sequence of characters enclosed between parentheses, to indicate cardinal or
 :                   ordinal numbering respectively, the default being cardinal numbering</p></item><item><p diff="chg" at="G">either <code>a</code> or <code>t</code>, to indicate alphabetic
 :                   or traditional numbering respectively, the default being <termref def="implementation-defined">implementation-defined</termref>.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the <code>o</code> modifier is present, this indicates a request to output ordinal
 :             numbers rather than cardinal numbers. For example, in English, when used with the format
 :             token <code>1</code>, this outputs the sequence <code>1st 2nd 3rd 4th ...</code>, and
 :             when used with the format token <code>w</code> outputs the sequence <code>first second
 :             third fourth ...</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">The string of characters between the parentheses, if present, is used to
 :          select between other possible variations of cardinal or ordinal numbering sequences.
 :          The interpretation of this string is <termref def="implemementation-defined">implementation-defined</termref>. No error occurs
 :          if the implementation does not define any interpretation for the defined string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For example, in some languages, ordinal numbers vary depending on the grammatical context:
 :             they may have different genders and may decline with the noun that they qualify.
 :             In such cases the string appearing in parentheses after the letter <code>o</code> may be
 :             used to indicate the variation of the ordinal number required. The way in which the
 :             variation is indicated will depend on the conventions of the language. For inflected
 :             languages that vary the ending of the word, the <rfc2119>recommended</rfc2119> approach is to indicate the
 :             required ending, preceded by a hyphen: for example in German, appropriate values are
 :                <code>o(-e)</code>, <code>o(-er)</code>, <code>o(-es)</code>, <code>o(-en)</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">It is <termref def="implementation-defined">implementation-defined</termref> what
 :             combinations of values of the format token, the language, and the cardinal/ordinal
 :             modifier are supported. If ordinal numbering is not supported for the combination of the
 :             format token, the language, and the string appearing in parentheses, the request is
 :             ignored and cardinal numbers are generated instead.</p><example xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><head>Ordinal Numbering in Italian</head><p>The specification <code>"1;o(-º)"</code> with <code>$lang</code> equal to
 :                   <code>it</code>, if supported, should produce the sequence:</p><pre highlight-as="xquery" xml:space="preserve">1º 2º 3º 4º ...</pre><p>The specification <code>"Ww;o"</code> with <code>$lang</code> equal to
 :                   <code>it</code>, if supported, should produce the sequence:</p><pre highlight-as="xquery" xml:space="preserve">Primo Secondo Terzo Quarto Quinto ...</pre></example><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <phrase diff="chg" at="G">use of the <code>a</code> or <code>t</code>
 :                modifier</phrase> disambiguates between numbering sequences that use letters. In many
 :             languages there are two commonly used numbering sequences that use letters. One
 :             numbering sequence assigns numeric values to letters in alphabetic sequence, and the
 :             other assigns numeric values to each letter in some other manner traditional in that
 :             language. In English, these would correspond to the numbering sequences specified by the
 :             format tokens <code>a</code> and <code>i</code>. In some languages, the first member of
 :             each sequence is the same, and so the format token alone would be ambiguous. <phrase diff="chg" at="G">In the absence of the <code>a</code> or <code>t</code> modifier,
 :                the default is <termref def="implementation-defined">implementation-defined</termref></phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DF" code="1310"/> if the format token is invalid,
 :             that is, if it violates any mandatory rules (indicated by an emphasized <rfc2119>must</rfc2119>
 :             or <rfc2119>required</rfc2119> keyword in the above rules). For example, the error is raised if
 :             the primary format token contains a digit but does not match the required regular expression.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-integer
 :)
declare function fn:format-integer( $value as xs:integer?,  $picture as xs:string,  $language as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing a number formatted according to a given picture
 :             string, taking account of decimal formats specified in the static context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-number" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="numeric?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-number" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="numeric?"/><arg name="picture" type="xs:string"/><arg name="decimal-format-name" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		decimal formats, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="K">The effect of the two-argument form of the function is equivalent to calling
 :          the three-argument form with an empty sequence as the value of the third argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function formats <code>$value</code> as a string using the <termref def="dt-picture-string">picture string</termref> specified by the
 :                <code>$picture</code> argument and the decimal-format named by the
 :                <code>$decimal-format-name</code> argument, or the default decimal-format, if there
 :             is no <code>$decimal-format-name</code> argument. The syntax of the picture string is
 :             described in <specref ref="syntax-of-picture-string"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$value</code> argument may be of any numeric data type
 :             (<code>xs:double</code>, <code>xs:float</code>, <code>xs:decimal</code>, or their
 :             subtypes including <code>xs:integer</code>). Note that if an <code>xs:decimal</code> is
 :             supplied, it is not automatically promoted to an <code>xs:double</code>, as such
 :             promotion can involve a loss of precision.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the supplied value of the <code>$value</code> argument is an empty sequence, the
 :             function behaves as if the supplied value were the <code>xs:double</code> value
 :                <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The value of <code>$decimal-format-name</code>, 
 :             <phrase diff="add" at="K">if present and non-empty, </phrase>
 :             <rfc2119>must</rfc2119> <phrase diff="chg" at="L">be a string which after removal of leading and trailing whitespace is in the form of an
 :             an <code>EQName</code> as defined in the XPath 3.0 grammar, that is one of the following</phrase>:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>A lexical QName, which is expanded using the 
 :                <phrase diff="chg" at="J">statically known namespaces</phrase>. 
 :                The default namespace is not used (no prefix means no namespace).</p></item><item><p diff="add" at="L">A <code>URIQualifiedName</code> using the syntax <code>Q{uri}local</code>,
 :             where the URI can be zero-length to indicate a name in no namespace.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="K">The decimal format that is used is the decimal format
 :          in the static context whose name matches <code>$decimal-format-name</code> if supplied,
 :          or the default decimal format in the static context otherwise.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The evaluation of the <function>format-number</function> function takes place in two
 :             phases, an analysis phase described in <specref ref="analysing-picture-string"/> and a
 :             formatting phase described in <specref ref="formatting-the-number"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The analysis phase takes as its inputs the <termref def="dt-picture-string">picture
 :                string</termref> and the variables derived from the relevant decimal format in the
 :             static context, and produces as its output a number of variables with defined values.
 :             The formatting phase takes as its inputs the number to be formatted and the variables
 :             produced by the analysis phase, and produces as its output a string containing a
 :             formatted representation of the number.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function is the formatted string representation of the supplied
 :             number.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DF" code="1280"/> if the name specified as the
 :                <code>$decimal-format-name</code> argument is 
 :             <phrase diff="chg" at="L">neither a valid lexical QName nor a valid <code>URIQualifiedName</code></phrase>, or if it
 :             uses a prefix <phrase diff="add" at="J">that is not found in the statically known namespaces</phrase>, or if the static
 :             context does not contain a declaration of a decimal-format with a matching expanded
 :             QName. If the processor is able to detect the error statically (for example, when the
 :             argument is supplied as a string literal), then the processor <rfc2119>may</rfc2119>
 :             optionally signal this as a static error.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-number
 :)
declare function fn:format-number($value as numeric?,  $picture as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing a number formatted according to a given picture
 :             string, taking account of decimal formats specified in the static context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-number" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="numeric?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-number" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="numeric?"/><arg name="picture" type="xs:string"/><arg name="decimal-format-name" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		decimal formats, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="K">The effect of the two-argument form of the function is equivalent to calling
 :          the three-argument form with an empty sequence as the value of the third argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function formats <code>$value</code> as a string using the <termref def="dt-picture-string">picture string</termref> specified by the
 :                <code>$picture</code> argument and the decimal-format named by the
 :                <code>$decimal-format-name</code> argument, or the default decimal-format, if there
 :             is no <code>$decimal-format-name</code> argument. The syntax of the picture string is
 :             described in <specref ref="syntax-of-picture-string"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$value</code> argument may be of any numeric data type
 :             (<code>xs:double</code>, <code>xs:float</code>, <code>xs:decimal</code>, or their
 :             subtypes including <code>xs:integer</code>). Note that if an <code>xs:decimal</code> is
 :             supplied, it is not automatically promoted to an <code>xs:double</code>, as such
 :             promotion can involve a loss of precision.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the supplied value of the <code>$value</code> argument is an empty sequence, the
 :             function behaves as if the supplied value were the <code>xs:double</code> value
 :                <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The value of <code>$decimal-format-name</code>, 
 :             <phrase diff="add" at="K">if present and non-empty, </phrase>
 :             <rfc2119>must</rfc2119> <phrase diff="chg" at="L">be a string which after removal of leading and trailing whitespace is in the form of an
 :             an <code>EQName</code> as defined in the XPath 3.0 grammar, that is one of the following</phrase>:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>A lexical QName, which is expanded using the 
 :                <phrase diff="chg" at="J">statically known namespaces</phrase>. 
 :                The default namespace is not used (no prefix means no namespace).</p></item><item><p diff="add" at="L">A <code>URIQualifiedName</code> using the syntax <code>Q{uri}local</code>,
 :             where the URI can be zero-length to indicate a name in no namespace.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="K">The decimal format that is used is the decimal format
 :          in the static context whose name matches <code>$decimal-format-name</code> if supplied,
 :          or the default decimal format in the static context otherwise.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The evaluation of the <function>format-number</function> function takes place in two
 :             phases, an analysis phase described in <specref ref="analysing-picture-string"/> and a
 :             formatting phase described in <specref ref="formatting-the-number"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The analysis phase takes as its inputs the <termref def="dt-picture-string">picture
 :                string</termref> and the variables derived from the relevant decimal format in the
 :             static context, and produces as its output a number of variables with defined values.
 :             The formatting phase takes as its inputs the number to be formatted and the variables
 :             produced by the analysis phase, and produces as its output a string containing a
 :             formatted representation of the number.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function is the formatted string representation of the supplied
 :             number.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DF" code="1280"/> if the name specified as the
 :                <code>$decimal-format-name</code> argument is 
 :             <phrase diff="chg" at="L">neither a valid lexical QName nor a valid <code>URIQualifiedName</code></phrase>, or if it
 :             uses a prefix <phrase diff="add" at="J">that is not found in the statically known namespaces</phrase>, or if the static
 :             context does not contain a declaration of a decimal-format with a matching expanded
 :             QName. If the processor is able to detect the error statically (for example, when the
 :             argument is supplied as a string literal), then the processor <rfc2119>may</rfc2119>
 :             optionally signal this as a static error.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-number
 :)
declare function fn:format-number( $value as numeric?,  $picture as xs:string,  $decimal-format-name as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing an <code>xs:time</code> value formatted for display.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-time" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:time?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-time" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:time?"/><arg name="picture" type="xs:string"/><arg name="language" type="xs:string?"/><arg name="calendar" type="xs:string?"/><arg name="place" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default calendar, and default language, and default place, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The five-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See <specref ref="rules-for-datetime-formatting"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-time
 :)
declare function fn:format-time( $value as xs:time?,  $picture as xs:string,  $language as xs:string?,  $calendar as xs:string?,  $place as xs:string?) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string containing an <code>xs:time</code> value formatted for display.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="format-time" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:time?"/><arg name="picture" type="xs:string"/></proto></example><example role="signature"><proto name="format-time" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="xs:time?"/><arg name="picture" type="xs:string"/><arg name="language" type="xs:string?"/><arg name="calendar" type="xs:string?"/><arg name="place" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		default calendar, and default language, and default place, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The five-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone, and namespaces.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See <specref ref="rules-for-datetime-formatting"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-format-time
 :)
declare function fn:format-time($value as xs:time?,  $picture as xs:string) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the arity of the function identified by a function item.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="function-arity" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="func" type="function(*)"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:function-arity</code> function returns the arity (number of arguments) of
 :             the function identified by <code>$func</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:function-arity(fn:substring#2)</code> returns <code>2</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:function-arity(function($node){name($node)})</code> returns <code>1</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>let $initial := fn:substring(?, 1, 1) return fn:function-arity($initial)</code> returns <code>1</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-function-arity
 :)
declare function fn:function-arity($func as function(*)) as  xs:integer external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function returns a string that uniquely identifies a given node. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="generate-id" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="generate-id" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is the empty sequence, the result is the zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases, the function returns a string that uniquely identifies a given node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The returned identifier <rfc2119>must</rfc2119> consist of ASCII alphanumeric characters
 :             and <rfc2119>must</rfc2119> start with an alphabetic character. Thus, the string is
 :             syntactically an XML name.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">An implementation is free to generate an identifier in any convenient way provided that
 :             it always generates the same identifier for the same node and that different identifiers
 :             are always generated from different nodes. An implementation is under no obligation to
 :             generate the same identifiers each time a document is transformed or queried.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-generate-id
 :)
declare function fn:generate-id() as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function returns a string that uniquely identifies a given node. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="generate-id" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="generate-id" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is the empty sequence, the result is the zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases, the function returns a string that uniquely identifies a given node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The returned identifier <rfc2119>must</rfc2119> consist of ASCII alphanumeric characters
 :             and <rfc2119>must</rfc2119> start with an alphabetic character. Thus, the string is
 :             syntactically an XML name.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">An implementation is free to generate an identifier in any convenient way provided that
 :             it always generates the same identifier for the same node and that different identifiers
 :             are always generated from different nodes. An implementation is under no obligation to
 :             generate the same identifiers each time a document is transformed or queried.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-generate-id
 :)
declare function fn:generate-id($arg as node()?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the first item in a sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="head" return-type="item()?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the value of the expression <code>$arg[1]</code></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the empty sequence is returned. Otherwise
 :             the first item in the sequence is returned.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-head
 :)
declare function fn:head($arg as item()*) as  item()? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of hours in a duration.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="hours-from-duration" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:duration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> representing the hours
 :             component in the value of <code>$arg</code>. The result is obtained by casting
 :                <code>$arg</code> to an <code>xs:dayTimeDuration</code> (see <specref ref="casting-to-durations"/>) and then computing the hours component as described in
 :                <specref ref="canonical-dayTimeDuration"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a negative duration then the result will be negative..</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an <code>xs:yearMonthDuration</code> the function returns 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-duration(xs:dayTimeDuration("P3DT10H"))</code> returns <code>10</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-duration(xs:dayTimeDuration("P3DT12H32M12S"))</code> returns <code>12</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-duration(xs:dayTimeDuration("PT123H"))</code> returns <code>3</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-duration(xs:dayTimeDuration("-P3DT10H"))</code> returns <code>-10</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-hours-from-duration
 :)
declare function fn:hours-from-duration($arg as xs:duration?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the hours component of an <code>xs:time</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="hours-from-time" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> between 0 and 23, both
 :             inclusive, representing the value of the hours component in the local value of
 :                <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Assume that the dynamic context provides an implicit timezone value of
 :                   <code>-05:00</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-time(xs:time("11:23:00"))</code> returns <code>11</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-time(xs:time("21:23:00"))</code> returns <code>21</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-time(xs:time("01:23:00+05:00"))</code> returns <code>1</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-time(fn:adjust-time-to-timezone(xs:time("01:23:00+05:00"),
 :                   xs:dayTimeDuration("PT0S")))</code> returns <code>20</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:hours-from-time(xs:time("24:00:00"))</code> returns <code>0</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-hours-from-time
 :)
declare function fn:hours-from-time($arg as xs:time?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the sequence of element nodes that have an <code>ID</code> value
 :             matching the value of one or more of the <code>IDREF</code> values supplied in
 :                <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/></proto></example><example role="signature"><proto name="id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence, in document order with duplicates eliminated,
 :             containing every element node <code>E</code> that satisfies all the following
 :             conditions:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>
 :                   <code>E</code> is in the target document. The target document is the document
 :                   containing <code>$node</code>, or the document containing the context item
 :                      (<code>.</code>) if the second argument is omitted. The behavior of the
 :                   function if <code>$node</code> is omitted is exactly the same as if the context
 :                   item had been passed as <code>$node</code>.</p></item><item><p><code>E</code> has an <code>ID</code> value equal to one of the candidate
 :                      <code>IDREF</code> values, where:</p><ulist><item><p> An element has an <code>ID</code> value equal to <code>V</code> if either
 :                         or both of the following conditions are true:</p><ulist><item><p>The <code>is-id</code> property (See <xspecref spec="DM30" ref="dm-is-id"/>.) of the element node is true, and the typed value
 :                               of the element node is equal to <code>V</code> under the rules of the
 :                                  <code>eq</code> operator using the Unicode codepoint collation
 :                                  (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item><item><p>The element has an attribute node whose <code>is-id</code> property
 :                               (See <xspecref spec="DM30" ref="dm-is-id"/>.) is true and whose typed
 :                               value is equal to <code>V</code> under the rules of the
 :                                  <code>eq</code> operator using the Unicode code point collation
 :                                  (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item></ulist></item><item><p> Each <code>xs:string</code> in <code>$arg</code> is parsed as if it were of
 :                         type <code>IDREFS</code>, that is, each <code>xs:string</code> in
 :                            <code>$arg</code> is treated as a whitespace-separated sequence of
 :                         tokens, each acting as an <code>IDREF</code>. These tokens are then included
 :                         in the list of candidate <code>IDREF</code>s. If any of the tokens is not a
 :                         lexically valid <code>IDREF</code> (that is, if it is not lexically an
 :                            <code>xs:NCName</code>), it is ignored. Formally, the candidate
 :                            <code>IDREF</code> values are the strings in the sequence given by the
 :                         expression:</p><pre highlight-as="xquery" xml:space="preserve">for $s in $arg return 
 :     fn:tokenize(fn:normalize-space($s), ' ')[. castable as xs:IDREF]</pre></item></ulist></item><item><p>If several elements have the same <code>ID</code> value, then <code>E</code> is
 :                   the one that is first in document order.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0001" type="dynamic"/> if
 :                <code>$node</code>, or the context item if the second argument is absent, is a node
 :                in a tree whose root is not a document node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$node</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-id
 :)
declare function fn:id($arg as xs:string*) as  element()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the sequence of element nodes that have an <code>ID</code> value
 :             matching the value of one or more of the <code>IDREF</code> values supplied in
 :                <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/></proto></example><example role="signature"><proto name="id" return-type="element()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence, in document order with duplicates eliminated,
 :             containing every element node <code>E</code> that satisfies all the following
 :             conditions:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>
 :                   <code>E</code> is in the target document. The target document is the document
 :                   containing <code>$node</code>, or the document containing the context item
 :                      (<code>.</code>) if the second argument is omitted. The behavior of the
 :                   function if <code>$node</code> is omitted is exactly the same as if the context
 :                   item had been passed as <code>$node</code>.</p></item><item><p><code>E</code> has an <code>ID</code> value equal to one of the candidate
 :                      <code>IDREF</code> values, where:</p><ulist><item><p> An element has an <code>ID</code> value equal to <code>V</code> if either
 :                         or both of the following conditions are true:</p><ulist><item><p>The <code>is-id</code> property (See <xspecref spec="DM30" ref="dm-is-id"/>.) of the element node is true, and the typed value
 :                               of the element node is equal to <code>V</code> under the rules of the
 :                                  <code>eq</code> operator using the Unicode codepoint collation
 :                                  (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item><item><p>The element has an attribute node whose <code>is-id</code> property
 :                               (See <xspecref spec="DM30" ref="dm-is-id"/>.) is true and whose typed
 :                               value is equal to <code>V</code> under the rules of the
 :                                  <code>eq</code> operator using the Unicode code point collation
 :                                  (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item></ulist></item><item><p> Each <code>xs:string</code> in <code>$arg</code> is parsed as if it were of
 :                         type <code>IDREFS</code>, that is, each <code>xs:string</code> in
 :                            <code>$arg</code> is treated as a whitespace-separated sequence of
 :                         tokens, each acting as an <code>IDREF</code>. These tokens are then included
 :                         in the list of candidate <code>IDREF</code>s. If any of the tokens is not a
 :                         lexically valid <code>IDREF</code> (that is, if it is not lexically an
 :                            <code>xs:NCName</code>), it is ignored. Formally, the candidate
 :                            <code>IDREF</code> values are the strings in the sequence given by the
 :                         expression:</p><pre highlight-as="xquery" xml:space="preserve">for $s in $arg return 
 :     fn:tokenize(fn:normalize-space($s), ' ')[. castable as xs:IDREF]</pre></item></ulist></item><item><p>If several elements have the same <code>ID</code> value, then <code>E</code> is
 :                   the one that is first in document order.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0001" type="dynamic"/> if
 :                <code>$node</code>, or the context item if the second argument is absent, is a node
 :                in a tree whose root is not a document node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$node</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-id
 :)
declare function fn:id($arg as xs:string*,  $node as node()) as  element()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the sequence of element or attribute nodes with an <code>IDREF</code>
 :             value matching the value of one or more of the <code>ID</code> values supplied in
 :                <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="idref" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/></proto></example><example role="signature"><proto name="idref" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> The function returns a sequence, in document order with duplicates eliminated,
 :             containing every element or attribute node <code>$N</code> that satisfies all the
 :             following conditions:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p><code>$N</code> is in the target document. The target document is the document
 :                   containing <code>$node</code> or the document containing the context item
 :                      (<code>.</code>) if the second argument is omitted. The behavior of the
 :                   function if <code>$node</code> is omitted is exactly the same as if the context
 :                   item had been passed as <code>$node</code>.</p></item><item><p><code>$N</code> has an <code>IDREF</code> value equal to one of the candidate
 :                      <code>ID</code> values, where:</p><ulist><item><p>A node <code>$N</code> has an <code>IDREF</code> value equal to
 :                            <code>V</code> if both of the following conditions are true:</p><ulist><item><p>The <code>is-idrefs</code> property (see <xspecref spec="DM30" ref="dm-is-idrefs"/>) of <code>$N</code> is <code>true</code>.</p></item><item><p>The sequence <!--Text replaced by erratum E29 change 1"--><pre highlight-as="xquery" diff="chg" at="A-E29" xml:space="preserve">fn:tokenize(fn:normalize-space(fn:string($N)), ' ')</pre>
 :                               <!--End of text replaced by erratum E29--> contains a string that is
 :                               equal to <code>V</code> under the rules of the <code>eq</code>
 :                               operator using the Unicode code point collation
 :                                  (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item></ulist></item><item><p>Each <code>xs:string</code> in <code>$arg</code> is parsed as if it were of
 :                         lexically of type <code>xs:ID</code>. These <code>xs:string</code>s are then
 :                         included in the list of candidate <code>xs:ID</code>s. If any of the strings
 :                         in <code>$arg</code> is not a lexically valid <code>xs:ID</code> (that is,
 :                         if it is not lexically an <code>xs:NCName</code>), it is ignored. More
 :                         formally, the candidate <code>ID</code> values are the strings in the
 :                         sequence:</p><pre highlight-as="xquery" xml:space="preserve">$arg[. castable as xs:NCName]</pre></item></ulist></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0001" type="dynamic"/> if
 :                <code>$node</code>, or the context item if the second argument is omitted, is a node
 :                in a tree whose root is not a document node. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$node</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-idref
 :)
declare function fn:idref($arg as xs:string*) as  node()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the sequence of element or attribute nodes with an <code>IDREF</code>
 :             value matching the value of one or more of the <code>ID</code> values supplied in
 :                <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="idref" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/></proto></example><example role="signature"><proto name="idref" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string*"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> The function returns a sequence, in document order with duplicates eliminated,
 :             containing every element or attribute node <code>$N</code> that satisfies all the
 :             following conditions:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p><code>$N</code> is in the target document. The target document is the document
 :                   containing <code>$node</code> or the document containing the context item
 :                      (<code>.</code>) if the second argument is omitted. The behavior of the
 :                   function if <code>$node</code> is omitted is exactly the same as if the context
 :                   item had been passed as <code>$node</code>.</p></item><item><p><code>$N</code> has an <code>IDREF</code> value equal to one of the candidate
 :                      <code>ID</code> values, where:</p><ulist><item><p>A node <code>$N</code> has an <code>IDREF</code> value equal to
 :                            <code>V</code> if both of the following conditions are true:</p><ulist><item><p>The <code>is-idrefs</code> property (see <xspecref spec="DM30" ref="dm-is-idrefs"/>) of <code>$N</code> is <code>true</code>.</p></item><item><p>The sequence <!--Text replaced by erratum E29 change 1"--><pre highlight-as="xquery" diff="chg" at="A-E29" xml:space="preserve">fn:tokenize(fn:normalize-space(fn:string($N)), ' ')</pre>
 :                               <!--End of text replaced by erratum E29--> contains a string that is
 :                               equal to <code>V</code> under the rules of the <code>eq</code>
 :                               operator using the Unicode code point collation
 :                                  (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>).</p></item></ulist></item><item><p>Each <code>xs:string</code> in <code>$arg</code> is parsed as if it were of
 :                         lexically of type <code>xs:ID</code>. These <code>xs:string</code>s are then
 :                         included in the list of candidate <code>xs:ID</code>s. If any of the strings
 :                         in <code>$arg</code> is not a lexically valid <code>xs:ID</code> (that is,
 :                         if it is not lexically an <code>xs:NCName</code>), it is ignored. More
 :                         formally, the candidate <code>ID</code> values are the strings in the
 :                         sequence:</p><pre highlight-as="xquery" xml:space="preserve">$arg[. castable as xs:NCName]</pre></item></ulist></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0001" type="dynamic"/> if
 :                <code>$node</code>, or the context item if the second argument is omitted, is a node
 :                in a tree whose root is not a document node. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$node</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-idref
 :)
declare function fn:idref($arg as xs:string*,  $node as node()) as  node()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the prefixes of the in-scope namespaces for an element node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="in-scope-prefixes" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="element" type="element()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of strings representing the prefixes of the in-scope
 :             namespaces for <code>$element</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For namespace bindings that have a prefix, the function returns the prefix as an
 :                <code>xs:NCName</code>. For the default namespace, which has no prefix, it returns
 :             the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result sequence contains no duplicates.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The ordering of the result sequence is <termref def="implementation-dependent">implementation-dependent</termref>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-in-scope-prefixes
 :)
declare function fn:in-scope-prefixes($element as element()) as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of positive integers giving the positions within the
 :             sequence <code>$seq</code> of items that are equal to <code>$search</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="index-of" return-type="xs:integer*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="xs:anyAtomicType*"/><arg name="search" type="xs:anyAtomicType"/></proto></example><example role="signature"><proto name="index-of" return-type="xs:integer*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="xs:anyAtomicType*"/><arg name="search" type="xs:anyAtomicType"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of positive integers giving the positions within the
 :             sequence <code>$seq</code> of items that are equal to <code>$search</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>. This collation is used when string comparison is
 :             required.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The items in the sequence <code>$seq</code> are compared with <code>$search</code> under
 :             the rules for the <code>eq</code> operator. Values of type <code>xs:untypedAtomic</code>
 :             are compared as if they were of type <code>xs:string</code>. Values that cannot be
 :             compared, because the <code>eq</code> operator is not defined for their types, are
 :             considered to be distinct. If an item compares equal, then the position of that item in
 :             the sequence <code>$seq</code> is included in the result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first item in a sequence is at position 1, not position 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result sequence is in ascending numeric order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$seq</code> is the empty sequence, or if no item in
 :                <code>$seq</code> matches <code>$search</code>, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D">No error occurs if non-comparable values are encountered. So when
 :             comparing two atomic values, the effective boolean value of <code>fn:index-of($a,
 :                $b)</code> is true if <code>$a</code> and <code>$b</code> are equal, false if they
 :             are not equal or not comparable.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-index-of
 :)
declare function fn:index-of( $seq as xs:anyAtomicType*,  $search as xs:anyAtomicType) as  xs:integer* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of positive integers giving the positions within the
 :             sequence <code>$seq</code> of items that are equal to <code>$search</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="index-of" return-type="xs:integer*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="xs:anyAtomicType*"/><arg name="search" type="xs:anyAtomicType"/></proto></example><example role="signature"><proto name="index-of" return-type="xs:integer*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="xs:anyAtomicType*"/><arg name="search" type="xs:anyAtomicType"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of positive integers giving the positions within the
 :             sequence <code>$seq</code> of items that are equal to <code>$search</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>. This collation is used when string comparison is
 :             required.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The items in the sequence <code>$seq</code> are compared with <code>$search</code> under
 :             the rules for the <code>eq</code> operator. Values of type <code>xs:untypedAtomic</code>
 :             are compared as if they were of type <code>xs:string</code>. Values that cannot be
 :             compared, because the <code>eq</code> operator is not defined for their types, are
 :             considered to be distinct. If an item compares equal, then the position of that item in
 :             the sequence <code>$seq</code> is included in the result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first item in a sequence is at position 1, not position 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result sequence is in ascending numeric order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$seq</code> is the empty sequence, or if no item in
 :                <code>$seq</code> matches <code>$search</code>, then the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D">No error occurs if non-comparable values are encountered. So when
 :             comparing two atomic values, the effective boolean value of <code>fn:index-of($a,
 :                $b)</code> is true if <code>$a</code> and <code>$b</code> are equal, false if they
 :             are not equal or not comparable.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-index-of
 :)
declare function fn:index-of( $seq as xs:anyAtomicType*,  $search as xs:anyAtomicType,  $collation as xs:string) as  xs:integer* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence constructed by inserting an item or a sequence of items at a
 :             given position within an existing sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="insert-before" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="target" type="item()*"/><arg name="position" type="xs:integer"/><arg name="inserts" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The value returned by the function consists of all items of <code>$target</code> whose
 :             index is less than <code>$position</code>, followed by all items of
 :                <code>$inserts</code>, followed by the remaining elements of <code>$target</code>, in
 :             that order. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$target</code> is the empty sequence, <code>$inserts</code> is returned. If
 :                <code>$inserts</code> is the empty sequence, <code>$target</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$position</code> is less than one (1), the first position, the effective value
 :             of <code>$position</code> is one (1). If <code>$position</code> is greater than the
 :             number of items in <code>$target</code>, then the effective value of
 :                <code>$position</code> is equal to the number of items in <code>$target</code> plus
 :             1. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The value of <code>$target</code> is not affected by the sequence construction.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-insert-before
 :)
declare function fn:insert-before( $target as item()*,  $position as xs:integer,  $inserts as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the local part of the supplied QName.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="local-name-from-QName" return-type="xs:NCName?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:QName?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:NCName</code> representing the local part of
 :                <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:local-name-from-QName(fn:QName("http://www.example.com/example",
 :                   "person"))</code> returns <code>"person"</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-local-name-from-QName
 :)
declare function fn:local-name-from-QName($arg as xs:QName?) as  xs:NCName? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Converts a string to lower case.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="lower-case" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the zero-length string is
 :             returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of <code>$arg</code> after translating every
 :                <termref def="character">character</termref> to its lower-case correspondent as
 :             defined in the appropriate case mappings section in the Unicode standard <bibref ref="Unicode"/>. For versions of Unicode beginning with the 2.1.8 update, only
 :             locale-insensitive case mappings should be applied. Beginning with version 3.2.0 (and
 :             likely future versions) of Unicode, precise mappings are described in default case
 :             operations, which are full case mappings in the absence of tailoring for particular
 :             languages and environments. Every upper-case character that does not have a lower-case
 :             correspondent, as well as every lower-case character, is included in the returned value
 :             in its original form. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Case mappings may change the length of a string. In general, the
 :                <code>fn:upper-case</code> and <code>fn:lower-case</code> functions are not inverses
 :             of each other: <code>fn:lower-case(fn:upper-case($arg))</code> is not guaranteed to
 :             return <code>$arg</code>, nor is <code>fn:upper-case(fn:lower-case($arg))</code>. The
 :             Latin small letter dotless i (as used in Turkish) is perhaps the most prominent
 :             lower-case letter which will not round-trip. The Latin capital letter i with dot above
 :             is the most prominent upper-case letter which will not round trip; there are others,
 :             such as Latin capital letter Sharp S (#1E9E) which is introduced in Unicode 5.1.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> These functions may not always be linguistically appropriate (e.g. Turkish i without
 :             dot) or appropriate for the application (e.g. titlecase). In cases such as Turkish, a
 :             simple translation should be used first.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> Because the function is not sensitive to locale, results will not always match user
 :             expectations. In Quebec, for example, the standard uppercase equivalent of "è" is "È",
 :             while in metropolitan France it is more commonly "E"; only one of these is supported by
 :             the functions as defined.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> Many characters of class Ll lack uppercase equivalents in the Unicode case mapping
 :             tables; many characters of class Lu lack lowercase equivalents.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-lower-case
 :)
declare function fn:lower-case($arg as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Applies the function item <var>$f</var> to every item from the sequence
 :                <var>$seq</var> in turn, returning the concatenation of the resulting sequences in
 :             order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="for-each" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq" type="item()*"/><arg name="f" type="function(item()) as item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of the function is equivalent to the following implementation in XQuery:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : declare function fn:for-each($seq, $f) {
 :   if (fn:empty($seq))
 :   then ()
 :   else ($f(fn:head($seq)), fn:for-each(fn:tail($seq), $f))
 : };</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">or its equivalent in XSLT:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : &lt;xsl:function name="fn:for-each"&gt;
 :   &lt;xsl:param name="seq"/&gt;
 :   &lt;xsl:param name="f"/&gt;
 :   &lt;xsl:if test="fn:exists($seq)"&gt;
 :     &lt;xsl:sequence select="$f(fn:head($seq)), fn:for-each(fn:tail($seq), $f)"/&gt;
 :   &lt;/xsl:if&gt;
 : &lt;/xsl:function&gt;
 :          </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function call <code>fn:for-each($SEQ, $F)</code> is equivalent to the expression
 :                <code>for $i in $SEQ return $F($i)</code><phrase diff="add" at="G">, assuming that
 :                ordering mode is <code>ordered</code>.</phrase></p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-for-each
 :)
declare function fn:for-each( $seq as item()*,  $f as function(item()) as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Applies the function item <var>$f</var> to successive pairs of items taken one
 :             from <var>$seq1</var> and one from <var>$seq2</var>, returning the concatenation of the
 :             resulting sequences in order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="for-each-pair" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="seq1" type="item()*"/><arg name="seq2" type="item()*"/><arg name="f" type="function(item(), item()) as item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of the function is equivalent to the following implementation in XQuery:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : declare function fn:for-each-pair($seq1, $seq2, $f)
 : {
 :    if(fn:exists($seq1) and fn:exists($seq2)) 
 :    then (
 :      $f(fn:head($seq1), fn:head($seq2)),
 :      fn:for-each-pair(fn:tail($seq1), fn:tail($seq2), $f)
 :    )
 :    else ()
 : };</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">or its equivalent in XSLT:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : &lt;xsl:function name="fn:for-each-pair"&gt;
 :   &lt;xsl:param name="seq1/&gt;
 :   &lt;xsl:param name="seq2/&gt;
 :   &lt;xsl:param name="f"/&gt;
 :   &lt;xsl:if test="fn:exists($seq1) and fn:exists($seq2)"&gt;
 :     &lt;xsl:sequence select="$f(fn:head($seq1), fn:head($seq2))"/&gt;
 :     &lt;xsl:sequence select="fn:for-each-pair(fn:tail($seq1), fn:tail($seq2), $f)"/&gt;
 :   &lt;/xsl:if&gt;
 : &lt;/xsl:function&gt;
 :          </pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:for-each-pair(("a", "b", "c"), ("x", "y", "z"), concat#2)</code> returns <code>("ax", "by", "cz")</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:for-each-pair(1 to 5, 1 to 5, function($a, $b){10*$a + $b}</code> returns <code>(11, 22, 33, 44, 55)</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-for-each-pair
 :)
declare function fn:for-each-pair( $seq1 as item()*,  $seq2 as item()*,  $f as function(item(), item()) as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the supplied string matches a given regular expression.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="matches" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/></proto></example><example role="signature"><proto name="matches" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns <code>true</code> if <code>$input</code> or some substring of
 :                <code>$input</code> matches the regular expression supplied as <code>$pattern</code>.
 :             Otherwise, the function returns <code>false</code>. The matching rules are influenced by
 :             the value of <code>$flags</code> if present. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in <specref ref="regex-syntax"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in <specref ref="flags"/>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-matches
 :)
declare function fn:matches($input as xs:string?,  $pattern as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the supplied string matches a given regular expression.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="matches" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/></proto></example><example role="signature"><proto name="matches" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns <code>true</code> if <code>$input</code> or some substring of
 :                <code>$input</code> matches the regular expression supplied as <code>$pattern</code>.
 :             Otherwise, the function returns <code>false</code>. The matching rules are influenced by
 :             the value of <code>$flags</code> if present. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in <specref ref="regex-syntax"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in <specref ref="flags"/>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-matches
 :)
declare function fn:matches( $input as xs:string?,  $pattern as xs:string,  $flags as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a value that is equal to the highest value appearing in the input
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="max" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="max" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following rules are applied to the input sequence <code>$arg</code>:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Values of type <code>xs:untypedAtomic</code> in <code>$arg</code> are cast to
 :                      <code>xs:double</code>.</p></item><item><!--Text replaced by erratum E27 change 1"--><p diff="chg" at="A-E27">Numeric and <code>xs:anyURI</code> values are converted to
 :                   the least common type reachable by a combination of type promotion and subtype
 :                   substitution. See <xspecref spec="XP30" ref="promotion"/> and <xspecref spec="XP30" ref="mapping"/>.</p><!--End of text replaced by erratum E27--></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The items in the resulting sequence may be reordered in an arbitrary order. The
 :             resulting sequence is referred to below as the converted sequence. The function returns
 :             an item from the converted sequence rather than the input sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence is empty, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">All items in the <phrase diff="chg" at="A-E47">converted sequence must be
 :                derived</phrase> from a single base type for which the <code>le</code> operator is
 :             defined. In addition, the values in the sequence must have a total order. If date/time
 :             values do not have a timezone, they are considered to have the implicit timezone
 :             provided by the dynamic context for the purpose of comparison. Duration values must
 :             either all be <code>xs:yearMonthDuration</code> values or must all be
 :                <code>xs:dayTimeDuration</code> values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence contains the value <code>NaN</code>, the value
 :                <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> are of
 :             type <code>xs:string</code> or types derived by restriction from <code>xs:string</code>,
 :             then the determination of the item with the smallest value is made according to the
 :             collation that is used. If the type of the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> is not <code>xs:string</code> and
 :                <code>$collation</code> is specified, the collation is ignored.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the result of the expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 :    if (every $v in $c satisfies $c[1] ge $v)
 :    then $c[1] 
 :    else fn:max(fn:subsequence($c, 2))</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">evaluated with <code>$collation</code> as the default collation if specified, and with
 :                <code>$c</code> as the converted sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A type error is raised <errorref class="RG" code="0006"/> if the input sequence contains
 :             items of incompatible types, as described above.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-max
 :)
declare function fn:max($arg as xs:anyAtomicType*) as  xs:anyAtomicType? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a value that is equal to the highest value appearing in the input
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="max" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="max" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following rules are applied to the input sequence <code>$arg</code>:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Values of type <code>xs:untypedAtomic</code> in <code>$arg</code> are cast to
 :                      <code>xs:double</code>.</p></item><item><!--Text replaced by erratum E27 change 1"--><p diff="chg" at="A-E27">Numeric and <code>xs:anyURI</code> values are converted to
 :                   the least common type reachable by a combination of type promotion and subtype
 :                   substitution. See <xspecref spec="XP30" ref="promotion"/> and <xspecref spec="XP30" ref="mapping"/>.</p><!--End of text replaced by erratum E27--></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The items in the resulting sequence may be reordered in an arbitrary order. The
 :             resulting sequence is referred to below as the converted sequence. The function returns
 :             an item from the converted sequence rather than the input sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence is empty, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">All items in the <phrase diff="chg" at="A-E47">converted sequence must be
 :                derived</phrase> from a single base type for which the <code>le</code> operator is
 :             defined. In addition, the values in the sequence must have a total order. If date/time
 :             values do not have a timezone, they are considered to have the implicit timezone
 :             provided by the dynamic context for the purpose of comparison. Duration values must
 :             either all be <code>xs:yearMonthDuration</code> values or must all be
 :                <code>xs:dayTimeDuration</code> values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence contains the value <code>NaN</code>, the value
 :                <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> are of
 :             type <code>xs:string</code> or types derived by restriction from <code>xs:string</code>,
 :             then the determination of the item with the smallest value is made according to the
 :             collation that is used. If the type of the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> is not <code>xs:string</code> and
 :                <code>$collation</code> is specified, the collation is ignored.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the result of the expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 :    if (every $v in $c satisfies $c[1] ge $v)
 :    then $c[1] 
 :    else fn:max(fn:subsequence($c, 2))</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">evaluated with <code>$collation</code> as the default collation if specified, and with
 :                <code>$c</code> as the converted sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A type error is raised <errorref class="RG" code="0006"/> if the input sequence contains
 :             items of incompatible types, as described above.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-max
 :)
declare function fn:max($arg as xs:anyAtomicType*,  $collation as xs:string) as  xs:anyAtomicType? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a value that is equal to the lowest value appearing in the input
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="min" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="min" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following rules are applied to the input sequence:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Values of type <code>xs:untypedAtomic</code> in <code>$arg</code> are cast to
 :                      <code>xs:double</code>.</p></item><item><!--Text replaced by erratum E27 change 2"--><p diff="chg" at="A-E27">Numeric and <code>xs:anyURI</code> values are converted to
 :                   the least common type reachable by a combination of type promotion and subtype
 :                   substitution. See <xspecref spec="XP30" ref="promotion"/> and <xspecref spec="XP30" ref="mapping"/>.</p><!--End of text replaced by erratum E27--></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The items in the resulting sequence may be reordered in an arbitrary order. The
 :             resulting sequence is referred to below as the converted sequence. The function returns
 :             an item from the converted sequence rather than the input sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence is empty, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">All items in the <phrase diff="chg" at="A-E47">converted sequence must be
 :                derived</phrase> from a single base type for which the <code>le</code> operator is
 :             defined. In addition, the values in the sequence must have a total order. If date/time
 :             values do not have a timezone, they are considered to have the implicit timezone
 :             provided by the dynamic context for the purpose of comparison. Duration values must
 :             either all be <code>xs:yearMonthDuration</code> values or must all be
 :                <code>xs:dayTimeDuration</code> values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence contains the value <code>NaN</code>, the value
 :                <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> are of
 :             type <code>xs:string</code> or types derived by restriction from <code>xs:string</code>,
 :             then the determination of the item with the smallest value is made according to the
 :             collation that is used. If the type of the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> is not <code>xs:string</code> and
 :                <code>$collation</code> is specified, the collation is ignored.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the result of the expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 :    if (every $v in $c satisfies $c[1] le $v) 
 :    then $c[1] 
 :    else fn:min(fn:subsequence($c, 2))</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">evaluated with <code>$collation</code> as the default collation if specified, and with
 :                <code>$c</code> as the converted sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A type error is raised <errorref class="RG" code="0006"/> if the input sequence contains
 :             items of incompatible types, as described above.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-min
 :)
declare function fn:min($arg as xs:anyAtomicType*) as  xs:anyAtomicType? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a value that is equal to the lowest value appearing in the input
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="min" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="min" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri, and implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following rules are applied to the input sequence:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>Values of type <code>xs:untypedAtomic</code> in <code>$arg</code> are cast to
 :                      <code>xs:double</code>.</p></item><item><!--Text replaced by erratum E27 change 2"--><p diff="chg" at="A-E27">Numeric and <code>xs:anyURI</code> values are converted to
 :                   the least common type reachable by a combination of type promotion and subtype
 :                   substitution. See <xspecref spec="XP30" ref="promotion"/> and <xspecref spec="XP30" ref="mapping"/>.</p><!--End of text replaced by erratum E27--></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The items in the resulting sequence may be reordered in an arbitrary order. The
 :             resulting sequence is referred to below as the converted sequence. The function returns
 :             an item from the converted sequence rather than the input sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence is empty, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">All items in the <phrase diff="chg" at="A-E47">converted sequence must be
 :                derived</phrase> from a single base type for which the <code>le</code> operator is
 :             defined. In addition, the values in the sequence must have a total order. If date/time
 :             values do not have a timezone, they are considered to have the implicit timezone
 :             provided by the dynamic context for the purpose of comparison. Duration values must
 :             either all be <code>xs:yearMonthDuration</code> values or must all be
 :                <code>xs:dayTimeDuration</code> values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence contains the value <code>NaN</code>, the value
 :                <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> are of
 :             type <code>xs:string</code> or types derived by restriction from <code>xs:string</code>,
 :             then the determination of the item with the smallest value is made according to the
 :             collation that is used. If the type of the items in the <phrase diff="chg" at="A-E47">converted sequence</phrase> is not <code>xs:string</code> and
 :                <code>$collation</code> is specified, the collation is ignored.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the result of the expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 :    if (every $v in $c satisfies $c[1] le $v) 
 :    then $c[1] 
 :    else fn:min(fn:subsequence($c, 2))</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">evaluated with <code>$collation</code> as the default collation if specified, and with
 :                <code>$c</code> as the converted sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A type error is raised <errorref class="RG" code="0006"/> if the input sequence contains
 :             items of incompatible types, as described above.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-min
 :)
declare function fn:min($arg as xs:anyAtomicType*,  $collation as xs:string) as  xs:anyAtomicType? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the minute component of an <code>xs:dateTime</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="minutes-from-dateTime" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:dateTime?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> value between 0 and 59, both
 :             inclusive, representing the minute component in the local value of
 :             <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:minutes-from-dateTime(xs:dateTime("1999-05-31T13:20:00-05:00"))</code> returns <code>20</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:minutes-from-dateTime(xs:dateTime("1999-05-31T13:30:00+05:30"))</code> returns <code>30</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-minutes-from-dateTime
 :)
declare function fn:minutes-from-dateTime($arg as xs:dateTime?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of minutes in a duration.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="minutes-from-duration" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:duration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> representing the minutes
 :             component in the value of <code>$arg</code>. The result is obtained by casting
 :                <code>$arg</code> to an <code>xs:dayTimeDuration</code> (see <specref ref="casting-to-durations"/>) and then computing the minutes component as described
 :             in <specref ref="canonical-dayTimeDuration"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a negative duration then the result will be negative..</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an <code>xs:yearMonthDuration</code> the function returns 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:minutes-from-duration(xs:dayTimeDuration("P3DT10H"))</code> returns <code>0</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:minutes-from-duration(xs:dayTimeDuration("-P5DT12H30M"))</code> returns <code>-30</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-minutes-from-duration
 :)
declare function fn:minutes-from-duration($arg as xs:duration?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the minutes component of an <code>xs:time</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="minutes-from-time" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> value between 0 and 59, both
 :             inclusive, representing the value of the minutes component in the local value of
 :                <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:minutes-from-time(xs:time("13:00:00Z"))</code> returns <code>0</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-minutes-from-time
 :)
declare function fn:minutes-from-time($arg as xs:time?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the month component of an <code>xs:date</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="month-from-date" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> between 1 and 12, both
 :             inclusive, representing the month component in the local value of <code>$arg</code>.
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:month-from-date(xs:date("1999-05-31-05:00"))</code> returns <code>5</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:month-from-date(xs:date("2000-01-01+05:00"))</code> returns <code>1</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-month-from-date
 :)
declare function fn:month-from-date($arg as xs:date?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of months in a duration.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="months-from-duration" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:duration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> representing the months
 :             component in the value of <code>$arg</code>. The result is obtained by casting
 :                <code>$arg</code> to an <code>xs:yearMonthDuration</code> (see <specref ref="casting-to-durations"/>) and then computing the months component as described in
 :                <specref ref="canonical-yearMonthDuration"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a negative duration then the result will be negative..</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an <code>xs:dayTimeDuration</code> the function returns 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:months-from-duration(xs:yearMonthDuration("P20Y15M"))</code> returns <code>3</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:months-from-duration(xs:yearMonthDuration("-P20Y18M"))</code> returns <code>-6</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:months-from-duration(xs:dayTimeDuration("-P2DT15H0M0S"))</code> returns <code>0</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-months-from-duration
 :)
declare function fn:months-from-duration($arg as xs:duration?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the namespace URI of one of the in-scope namespaces for
 :                <code>$element</code>, identified by its namespace prefix.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="namespace-uri-for-prefix" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="prefix" type="xs:string?"/><arg name="element" type="element()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$element</code> has an in-scope namespace whose namespace prefix is equal to
 :                <code>$prefix</code>, the function returns the namespace URI of that namespace.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$element</code> has no in-scope namespace whose namespace prefix is equal to
 :             <code>$prefix</code>, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="I">If <code>$prefix</code> is the zero-length string or the empty
 :             sequence, then if <code>$element</code> has a default namespace (that is, a namespace
 :             node with no name), the function returns the namespace URI of the default namespace. If
 :                <code>$element</code> has no default namespace, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Prefixes are equal only if their Unicode codepoints match exactly.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">let <code>$e</code> := <pre highlight-as="xquery" xml:space="preserve">
 : &lt;z:a xmlns="http://example.org/one" xmlns:z="http://example.org/two"&gt;
 :   &lt;b xmlns=""/&gt;
 : &lt;/z:a&gt;</pre></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:namespace-uri-for-prefix("z", $e)</code> returns <code>"http://example.org/two"</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:namespace-uri-for-prefix("", $e)</code> returns <code>"http://example.org/one"</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:namespace-uri-for-prefix((), $e)</code> returns <code>"http://example.org/one"</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:namespace-uri-for-prefix("xml", $e)</code> returns <code>"http://www.w3.org/XML/1998/namespace"</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:namespace-uri-for-prefix("xml", $e)</code> returns <code>"http://www.w3.org/XML/1998/namespace"</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-namespace-uri-for-prefix
 :)
declare function fn:namespace-uri-for-prefix( $prefix as xs:string?,  $element as element()) as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the namespace URI part of the supplied QName.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="namespace-uri-from-QName" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:QName?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:anyURI</code> representing the namespace URI
 :             part of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is in no namespace, the function returns the zero-length
 :                <code>xs:anyURI</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:namespace-uri-from-QName(fn:QName("http://www.example.com/example",
 :                   "person"))</code> returns <code>xs:anyURI("http://www.example.com/example")</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-namespace-uri-from-QName
 :)
declare function fn:namespace-uri-from-QName($arg as xs:QName?) as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>$arg</code> with leading and trailing whitespace
 :             removed, and sequences of internal whitespace reduced to a single space character.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="normalize-space" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="normalize-space" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a string constructed by stripping leading and trailing whitespace
 :             from the value of <code>$arg</code>, and replacing sequences of one or more adjacent
 :             whitespace characters with a single space, <code>#x20</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The whitespace characters are defined in the metasymbol S (Production 3) of <bibref ref="REC-xml"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E14">If no argument is supplied, then <code>$arg</code> defaults to the
 :             string value (calculated using <code>fn:string</code>) of the context item
 :                (<code>.</code>). </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If no argument is supplied and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref> then a <phrase diff="add" at="dynamic">dynamic</phrase> error is raised: <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-normalize-space
 :)
declare function fn:normalize-space() as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>$arg</code> with leading and trailing whitespace
 :             removed, and sequences of internal whitespace reduced to a single space character.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="normalize-space" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="normalize-space" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a string constructed by stripping leading and trailing whitespace
 :             from the value of <code>$arg</code>, and replacing sequences of one or more adjacent
 :             whitespace characters with a single space, <code>#x20</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The whitespace characters are defined in the metasymbol S (Production 3) of <bibref ref="REC-xml"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E14">If no argument is supplied, then <code>$arg</code> defaults to the
 :             string value (calculated using <code>fn:string</code>) of the context item
 :                (<code>.</code>). </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If no argument is supplied and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref> then a <phrase diff="add" at="dynamic">dynamic</phrase> error is raised: <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-normalize-space
 :)
declare function fn:normalize-space($arg as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>$arg</code> after applying Unicode
 :             normalization.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="normalize-unicode" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example><example role="signature"><proto name="normalize-unicode" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/><arg name="normalizationForm" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the single-argument version of the function is used, the result is the same as
 :             calling the two-argument version with <code>$normalizationForm</code> set to the string
 :             "NFC".</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of <code>$arg</code> normalized according to
 :             the rules of the normalization form identified by the value of
 :                <code>$normalizationForm</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effective value of <code>$normalizationForm</code> is the value of the expression
 :                <code>fn:upper-case(fn:normalize-space($normalizationForm))</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="D">See <bibref ref="charmod-normalization"/> for a description of the
 :             normalization forms.</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFC</quote>,
 :                   then the function returns the value of <code>$arg</code> converted to Unicode
 :                   Normalization Form C (NFC).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFD</quote>,
 :                   then the function returns the value of <code>$arg</code> converted to Unicode
 :                   Normalization Form D (NFD).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFKC</quote>,
 :                   then the function returns the value of <code>$arg</code> in Unicode Normalization
 :                   Form KC (NFKC).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFKD</quote>,
 :                   then the function returns the value of <code>$arg</code> converted to Unicode
 :                   Normalization Form KD (NFKD).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is
 :                      <quote>FULLY-NORMALIZED</quote>, then the function returns the value of
 :                      <code>$arg</code> converted to fully normalized form. </p></item><item><p>If the effective value of <code>$normalizationForm</code> is the zero-length
 :                   string, no normalization is performed and <code>$arg</code> is returned.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D">Normalization forms NFC, NFD, NFKC, and NFKD, and the algorithms to be
 :             used for converting a string to each of these forms, are defined in <bibref ref="Unicode-Normalization"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D">The motivation for normalization form FULLY-NORMALIZED is explained in
 :                <bibref ref="charmod-normalization"/>. However, as that specification did not
 :             progress beyond working draft status, the normative specification is as follows:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D"><item><p>A string is <term>fully-normalized</term> if (a) it is in normalization form NFC
 :                   as defined in <bibref ref="Unicode-Normalization"/>, and (b) it does not start
 :                   with a composing character.</p></item><item><p>A composing character is a character that is one or both of the following:</p><ulist><item><p>the second character in the canonical decomposition mapping of some
 :                         character that is not listed in the Composition Exclusion Table defined in
 :                            <bibref ref="Unicode-Normalization"/>;</p></item><item><p>of non-zero canonical combining class (as defined in <bibref ref="Unicode"/>).</p></item></ulist></item><item><p>A string is converted to FULLY-NORMALIZED form as follows:</p><ulist><item><p>if the first character in the string is a composing character, prepend a
 :                         single space (x20);</p></item><item><p>convert the resulting string to normalization form NFC.</p></item></ulist></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" At="L">Conforming implementations <rfc2119>must</rfc2119> support normalization form "NFC" and
 :                <rfc2119>may</rfc2119> support normalization forms "NFD", "NFKC", "NFKD", and
 :             "FULLY-NORMALIZED". They <rfc2119>may</rfc2119> also support other normalization forms
 :             with <termref def="implementation-defined">implementation-defined</termref> semantics. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">It is <termref def="dt-implementation-defined">implementation-defined</termref> which version of
 :             Unicode (and therefore, of the normalization algorithms and their underlying
 :             data) is supported by the implementation. See <bibref ref="Unicode-Normalization"/> for details of the
 :             stability policy regarding changes to the normalization rules in future
 :             versions of Unicode. If the input string contains codepoints that are
 :             unassigned in the relevant version of Unicode, or for which no normalization
 :             rules are defined, the <code>fn:normalize-unicode</code> function leaves such codepoints
 :             unchanged. If the implementation supports the requested normalization form then
 :             it <rfc2119>must</rfc2119> be able to handle every input string without raising an error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="CH" code="0003"/> if the effective value of the
 :                <code>$normalizationForm</code> argument is not one of the values supported by the
 :             implementation.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-normalize-unicode
 :)
declare function fn:normalize-unicode($arg as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>$arg</code> after applying Unicode
 :             normalization.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="normalize-unicode" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example><example role="signature"><proto name="normalize-unicode" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/><arg name="normalizationForm" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the single-argument version of the function is used, the result is the same as
 :             calling the two-argument version with <code>$normalizationForm</code> set to the string
 :             "NFC".</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of <code>$arg</code> normalized according to
 :             the rules of the normalization form identified by the value of
 :                <code>$normalizationForm</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effective value of <code>$normalizationForm</code> is the value of the expression
 :                <code>fn:upper-case(fn:normalize-space($normalizationForm))</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="D">See <bibref ref="charmod-normalization"/> for a description of the
 :             normalization forms.</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFC</quote>,
 :                   then the function returns the value of <code>$arg</code> converted to Unicode
 :                   Normalization Form C (NFC).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFD</quote>,
 :                   then the function returns the value of <code>$arg</code> converted to Unicode
 :                   Normalization Form D (NFD).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFKC</quote>,
 :                   then the function returns the value of <code>$arg</code> in Unicode Normalization
 :                   Form KC (NFKC).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is <quote>NFKD</quote>,
 :                   then the function returns the value of <code>$arg</code> converted to Unicode
 :                   Normalization Form KD (NFKD).</p></item><item><p>If the effective value of <code>$normalizationForm</code> is
 :                      <quote>FULLY-NORMALIZED</quote>, then the function returns the value of
 :                      <code>$arg</code> converted to fully normalized form. </p></item><item><p>If the effective value of <code>$normalizationForm</code> is the zero-length
 :                   string, no normalization is performed and <code>$arg</code> is returned.</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D">Normalization forms NFC, NFD, NFKC, and NFKD, and the algorithms to be
 :             used for converting a string to each of these forms, are defined in <bibref ref="Unicode-Normalization"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D">The motivation for normalization form FULLY-NORMALIZED is explained in
 :                <bibref ref="charmod-normalization"/>. However, as that specification did not
 :             progress beyond working draft status, the normative specification is as follows:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="D"><item><p>A string is <term>fully-normalized</term> if (a) it is in normalization form NFC
 :                   as defined in <bibref ref="Unicode-Normalization"/>, and (b) it does not start
 :                   with a composing character.</p></item><item><p>A composing character is a character that is one or both of the following:</p><ulist><item><p>the second character in the canonical decomposition mapping of some
 :                         character that is not listed in the Composition Exclusion Table defined in
 :                            <bibref ref="Unicode-Normalization"/>;</p></item><item><p>of non-zero canonical combining class (as defined in <bibref ref="Unicode"/>).</p></item></ulist></item><item><p>A string is converted to FULLY-NORMALIZED form as follows:</p><ulist><item><p>if the first character in the string is a composing character, prepend a
 :                         single space (x20);</p></item><item><p>convert the resulting string to normalization form NFC.</p></item></ulist></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" At="L">Conforming implementations <rfc2119>must</rfc2119> support normalization form "NFC" and
 :                <rfc2119>may</rfc2119> support normalization forms "NFD", "NFKC", "NFKD", and
 :             "FULLY-NORMALIZED". They <rfc2119>may</rfc2119> also support other normalization forms
 :             with <termref def="implementation-defined">implementation-defined</termref> semantics. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">It is <termref def="dt-implementation-defined">implementation-defined</termref> which version of
 :             Unicode (and therefore, of the normalization algorithms and their underlying
 :             data) is supported by the implementation. See <bibref ref="Unicode-Normalization"/> for details of the
 :             stability policy regarding changes to the normalization rules in future
 :             versions of Unicode. If the input string contains codepoints that are
 :             unassigned in the relevant version of Unicode, or for which no normalization
 :             rules are defined, the <code>fn:normalize-unicode</code> function leaves such codepoints
 :             unchanged. If the implementation supports the requested normalization form then
 :             it <rfc2119>must</rfc2119> be able to handle every input string without raising an error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="CH" code="0003"/> if the effective value of the
 :                <code>$normalizationForm</code> argument is not one of the values supported by the
 :             implementation.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-normalize-unicode
 :)
declare function fn:normalize-unicode( $arg as xs:string?,  $normalizationForm as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns <code>true</code> if the effective boolean value of <code>$arg</code>
 :             is <code>false</code>, or <code>false</code> if it is <code>true</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="not" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The value of <code>$arg</code> is first reduced to an effective boolean value by
 :             applying the <code>fn:boolean()</code> function. The function returns <code>true</code>
 :             if the effective boolean value is <code>false</code>, or <code>false</code> if the
 :             effective boolean value is <code>true</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:not(fn:true())</code> returns <code>false()</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:not("false")</code> returns <code>false()</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-not
 :)
declare function fn:not($arg as item()*) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns <code>$arg</code> if it contains one or more items. Otherwise, raises
 :             an error. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="one-or-more" return-type="item()+" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Except in error cases, the function returns <code>$arg</code> unchanged.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0004"/> if <code>$arg</code> is an empty
 :             sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-one-or-more
 :)
declare function fn:one-or-more($arg as item()*) as  item()+ external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function takes as input an XML document represented as a string, and
 :             returns the document node at the root of an XDM tree representing the parsed
 :             document.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="parse-xml" return-type="document-node(element(*))?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="G">If <code>$arg</code> is the empty sequence, the function returns the
 :             empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The precise process used to construct the XDM instance is <termref def="implementation-defined"/>. In
 :             particular, it is implementation-defined whether DTD and/or schema validation is invoked, and it is
 :             implementation-defined whether an XML 1.0 or XML 1.1 parser is used.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The Static Base URI property from the static context of the
 :             <code>fn:parse-xml</code> function call is used both as the base URI used by the XML parser to resolve
 :             relative entity references within the document, and as the base URI of the document node
 :             that is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The document URI of the returned node is <termref def="absent">absent</termref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is <emph>not</emph>
 :             <termref def="deterministic">deterministic</termref>: that is, if the function is called
 :             twice with the same arguments, it is <termref def="implementation-dependent">implementation-dependent</termref> whether the same node is returned on both
 :             occasions.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0006"/> if the content of
 :                <code>$arg</code> is not a well-formed and namespace-well-formed XML document.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="G">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0006"/> if DTD-based
 :             validation is carried out and the content of <code>$arg</code> is not valid against its
 :             DTD.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-parse-xml
 :)
declare function fn:parse-xml($arg as xs:string?) as  document-node(element(*, xs:untyped)) external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function takes as input an XML document represented as a string, and
 :             returns the document node at the root of an XDM tree representing the parsed
 :             document.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="parse-xml" return-type="document-node(element(*))?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="G">If <code>$arg</code> is the empty sequence, the function returns the
 :             empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The precise process used to construct the XDM instance is <termref def="implementation-defined"/>. In
 :             particular, it is implementation-defined whether DTD and/or schema validation is invoked, and it is
 :             implementation-defined whether an XML 1.0 or XML 1.1 parser is used.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The Static Base URI property from the static context of the
 :             <code>fn:parse-xml</code> function call is used both as the base URI used by the XML parser to resolve
 :             relative entity references within the document, and as the base URI of the document node
 :             that is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The document URI of the returned node is <termref def="absent">absent</termref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is <emph>not</emph>
 :             <termref def="deterministic">deterministic</termref>: that is, if the function is called
 :             twice with the same arguments, it is <termref def="implementation-dependent">implementation-dependent</termref> whether the same node is returned on both
 :             occasions.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0006"/> if the content of
 :                <code>$arg</code> is not a well-formed and namespace-well-formed XML document.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="G">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0006"/> if DTD-based
 :             validation is carried out and the content of <code>$arg</code> is not valid against its
 :             DTD.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-parse-xml
 :)
declare function fn:parse-xml( $arg as xs:string?,  $baseURI as xs:string) as  document-node(element(*, xs:untyped)) external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function takes as input an XML external entity represented as a string,
 :             and returns the document node at the root of an XDM tree representing the parsed
 :             document fragment.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="parse-xml-fragment" return-type="document-node()?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-nondeterministic">nondeterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The input must be a namespace-well-formed external general parsed entity. More specifically,
 :             it must be a string conforming to the production rule <xnt xmlns:xlink="http://www.w3.org/1999/xlink" spec="xml" ref="NT-extParsedEnt" xlink:type="simple">extParsedEnt</xnt> in <bibref ref="REC-xml"/>, it must contain no entity references other
 :             than references to predefined entities,
 :             and it must satisfy all the rules
 :             of <bibref ref="REC-xml-names"/> for namespace-well-formed documents with the exception
 :             that the rule requiring it to be a well-formed document is replaced by the rule requiring
 :             it to be a well-formed external general parsed entity.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The string is parsed to form a sequence of nodes which
 :             become children of the new document node, in the same way as the content of any element
 :             is converted into a sequence of children for the resulting element node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Schema validation is <emph>not</emph> invoked, which means that the nodes in the
 :             returned document will all be untyped.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The precise process used to construct the XDM instance is <termref def="implementation-defined"/>. In
 :             particular, it is implementation-defined whether an XML 1.0 or XML 1.1 parser is
 :             used.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="L">The Static Base URI from the static context of the <code>fn:parse-xml-fragment</code> function call 
 :             is used as the base URI of the document node
 :             that is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The document URI of the returned node is <termref def="absent">absent</termref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is <emph>not</emph>
 :             <termref def="deterministic">deterministic</termref>: that is, if the function is called
 :             twice with the same arguments, it is <termref def="implementation-dependent">implementation-dependent</termref> whether the same node is returned on both
 :                occasions.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0006"/> if the content of
 :                <code>$arg</code> is not a well-formed external general parsed entity, 
 :             if it contains entity references other than references to predefined entities, or if a document that
 :             incorporates this well-formed parsed entity would not be namespace-well-formed.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-parse-xml-fragment
 :)
declare function fn:parse-xml-fragment( $arg as xs:string?) as  document-node(element(*, xs:untyped)) external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the prefix component of the supplied QName.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="prefix-from-QName" return-type="xs:NCName?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:QName?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> has no prefix component the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:NCName</code> representing the prefix
 :             component of <code>$arg</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-prefix-from-QName
 :)
declare function fn:prefix-from-QName($arg as xs:QName?) as  xs:NCName? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a new sequence containing all the items of <code>$target</code> except
 :             the item at position <code>$position</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="remove" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="target" type="item()*"/><arg name="position" type="xs:integer"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence consisting of all items of <code>$target</code> whose
 :             index is less than <code>$position</code>, followed by all items of <code>$target</code>
 :             whose index is greater than <code>$position</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$position</code> is less than 1 or greater than the number of items in
 :                <code>$target</code>, <code>$target</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$target</code> is the empty sequence, the empty sequence is returned.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-remove
 :)
declare function fn:remove($target as item()*,  $position as xs:integer) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string produced from the input string by replacing any substrings
 :             that match a given regular expression with a supplied replacement string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="replace" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="replacement" type="xs:string"/></proto></example><example role="signature"><proto name="replace" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="replacement" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$flags</code> argument is interpreted in the same manner as for the
 :                <code>fn:matches</code> function. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the <code>xs:string</code> that is obtained by replacing each
 :             non-overlapping substring of <code>$input</code> that matches the given
 :                <code>$pattern</code> with an occurrence of the <code>$replacement</code> string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If two overlapping substrings of <code>$input</code> both match the
 :                <code>$pattern</code>, then only the first one (that is, the one whose first <termref def="character">character</termref> comes first in the <code>$input</code> string) is
 :             replaced.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">If the <code>q</code> flag is present, the replacement string is used
 :                <emph>as is</emph>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><phrase diff="add" at="B">Otherwise,</phrase> within the <code>$replacement</code>
 :             string, a variable <code>$N</code> may be used to refer to the substring captured by the
 :             Nth parenthesized sub-expression in the regular expression. For each match of the
 :             pattern, these variables are assigned the value of the content matched by the relevant
 :             sub-expression, and the modified replacement string is then substituted for the <termref def="character">characters</termref> in <code>$input</code> that matched the pattern.
 :                <code>$0</code> refers to the substring captured by the regular expression as a
 :             whole.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">More specifically, the rules are as follows, where <code>S</code> is the number of
 :             parenthesized sub-expressions in the regular expression, and <code>N</code> is the
 :             decimal number formed by taking all the digits that consecutively follow the
 :                <code>$</code> character:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If <code>N</code>=<code>0</code>, then the variable is replaced by the substring
 :                   matched by the regular expression as a whole.</p></item><item><p>If <code>1</code>&lt;=<code>N</code>&lt;=<code>S</code>, then the variable is
 :                   replaced by the substring captured by the Nth parenthesized sub-expression. If the
 :                      <code>Nth</code> parenthesized sub-expression was not matched, then the
 :                   variable is replaced by the zero-length string.</p></item><item><p>If <code>S</code>&lt;<code>N</code>&lt;=<code>9</code>, then the variable is
 :                   replaced by the zero-length string.</p></item><item><p>Otherwise (if <code>N</code>&gt;<code>S</code> and
 :                      <code>N</code>&gt;<code>9</code>), the last digit of <code>N</code> is taken to
 :                   be a literal character to be included "as is" in the replacement string, and the
 :                   rules are reapplied using the number <code>N</code> formed by stripping off this
 :                   last digit.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For example, if the replacement string is <quote>
 :                <code>$23</code>
 :             </quote> and there are 5 substrings, the result contains the value of the substring that
 :             matches the second sub-expression, followed by the digit <quote>
 :                <code>3</code>
 :             </quote>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="B">Unless the <code>q</code> flag is used, a literal <code>$</code>
 :             character within the replacement string must be written as <code>\$</code>, and a
 :             literal <code>\</code> character must be written as <code>\\</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If two alternatives within the pattern both match at the same position in the
 :                <code>$input</code>, then the match that is chosen is the one matched by the first
 :             alternative. For example:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:replace("abcd", "(ab)|(a)", "[1=$1][2=$2]") returns "[1=ab][2=]cd"</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0003"/> if the pattern matches a
 :             zero-length string, that is, if the expression <code>fn:matches("", $pattern,
 :                $flags)</code> returns <code>true</code>. It is not an error, however, if a captured
 :             substring is zero-length.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0004"/> if the value of
 :                <code>$replacement</code> contains a "<code>$</code>" character that is not
 :             immediately followed by a digit <code>0-9</code> and not immediately preceded by a
 :             "\".</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0004"/> if the value of
 :                <code>$replacement</code> contains a "<code>\</code>" character that is not part of a
 :                "<code>\\</code>" pair, unless it is immediately followed by a "<code>$</code>"
 :             character.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-replace
 :)
declare function fn:replace( $input as xs:string?,  $pattern as xs:string,  $replacement as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string produced from the input string by replacing any substrings
 :             that match a given regular expression with a supplied replacement string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="replace" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="replacement" type="xs:string"/></proto></example><example role="signature"><proto name="replace" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="replacement" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$flags</code> argument is interpreted in the same manner as for the
 :                <code>fn:matches</code> function. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the <code>xs:string</code> that is obtained by replacing each
 :             non-overlapping substring of <code>$input</code> that matches the given
 :                <code>$pattern</code> with an occurrence of the <code>$replacement</code> string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If two overlapping substrings of <code>$input</code> both match the
 :                <code>$pattern</code>, then only the first one (that is, the one whose first <termref def="character">character</termref> comes first in the <code>$input</code> string) is
 :             replaced.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">If the <code>q</code> flag is present, the replacement string is used
 :                <emph>as is</emph>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><phrase diff="add" at="B">Otherwise,</phrase> within the <code>$replacement</code>
 :             string, a variable <code>$N</code> may be used to refer to the substring captured by the
 :             Nth parenthesized sub-expression in the regular expression. For each match of the
 :             pattern, these variables are assigned the value of the content matched by the relevant
 :             sub-expression, and the modified replacement string is then substituted for the <termref def="character">characters</termref> in <code>$input</code> that matched the pattern.
 :                <code>$0</code> refers to the substring captured by the regular expression as a
 :             whole.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">More specifically, the rules are as follows, where <code>S</code> is the number of
 :             parenthesized sub-expressions in the regular expression, and <code>N</code> is the
 :             decimal number formed by taking all the digits that consecutively follow the
 :                <code>$</code> character:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If <code>N</code>=<code>0</code>, then the variable is replaced by the substring
 :                   matched by the regular expression as a whole.</p></item><item><p>If <code>1</code>&lt;=<code>N</code>&lt;=<code>S</code>, then the variable is
 :                   replaced by the substring captured by the Nth parenthesized sub-expression. If the
 :                      <code>Nth</code> parenthesized sub-expression was not matched, then the
 :                   variable is replaced by the zero-length string.</p></item><item><p>If <code>S</code>&lt;<code>N</code>&lt;=<code>9</code>, then the variable is
 :                   replaced by the zero-length string.</p></item><item><p>Otherwise (if <code>N</code>&gt;<code>S</code> and
 :                      <code>N</code>&gt;<code>9</code>), the last digit of <code>N</code> is taken to
 :                   be a literal character to be included "as is" in the replacement string, and the
 :                   rules are reapplied using the number <code>N</code> formed by stripping off this
 :                   last digit.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For example, if the replacement string is <quote>
 :                <code>$23</code>
 :             </quote> and there are 5 substrings, the result contains the value of the substring that
 :             matches the second sub-expression, followed by the digit <quote>
 :                <code>3</code>
 :             </quote>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="B">Unless the <code>q</code> flag is used, a literal <code>$</code>
 :             character within the replacement string must be written as <code>\$</code>, and a
 :             literal <code>\</code> character must be written as <code>\\</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If two alternatives within the pattern both match at the same position in the
 :                <code>$input</code>, then the match that is chosen is the one matched by the first
 :             alternative. For example:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:replace("abcd", "(ab)|(a)", "[1=$1][2=$2]") returns "[1=ab][2=]cd"</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0003"/> if the pattern matches a
 :             zero-length string, that is, if the expression <code>fn:matches("", $pattern,
 :                $flags)</code> returns <code>true</code>. It is not an error, however, if a captured
 :             substring is zero-length.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0004"/> if the value of
 :                <code>$replacement</code> contains a "<code>$</code>" character that is not
 :             immediately followed by a digit <code>0-9</code> and not immediately preceded by a
 :             "\".</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0004"/> if the value of
 :                <code>$replacement</code> contains a "<code>\</code>" character that is not part of a
 :                "<code>\\</code>" pair, unless it is immediately followed by a "<code>$</code>"
 :             character.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-replace
 :)
declare function fn:replace( $input as xs:string?,  $pattern as xs:string,  $replacement as xs:string,  $flags as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns an <code>xs:QName</code> value (that is, an expanded-QName) by taking
 :             an <code>xs:string</code> that has the lexical form of an <code>xs:QName</code> (a
 :             string in the form "prefix:local-name" or "local-name") and resolving it using the
 :             in-scope namespaces for a given element.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="resolve-QName" return-type="xs:QName?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="qname" type="xs:string?"/><arg name="element" type="element()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$qname</code> is the empty sequence, returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">More specifically, the function searches the namespace bindings of <code>$element</code>
 :             for a binding whose name matches the prefix of <code>$qname</code>, or the zero-length
 :             string if it has no prefix, and constructs an expanded-QName whose local name is taken
 :             from the supplied <code>$qname</code>, and whose namespace URI is taken from the string
 :             value of the namespace binding.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the <code>$qname</code> has no prefix, and there is no namespace binding for
 :                <code>$element</code> corresponding to the default (unnamed) namespace, then the
 :             resulting expanded-QName has no namespace part.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The prefix (or absence of a prefix) in the supplied <code>$qname</code> argument is
 :             retained in the returned expanded-QName, as discussed in <xspecref spec="DM30" ref="terminology"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="CA" code="0002"/> if <code>$qname</code> does not
 :             have the correct lexical form for an instance of <code>xs:QName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="NS" code="0004"/> if <code>$qname</code> has a
 :             prefix and there is no namespace binding for <code>$element</code> that matches this
 :             prefix.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-resolve-QName
 :)
declare function fn:resolve-QName($qname as xs:string?,  $element as element()) as  xs:QName? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Reverses the order of items in a sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="reverse" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence containing the items in <code>$arg</code> in reverse
 :             order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the empty sequence is returned. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-reverse
 :)
declare function fn:reverse($arg as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Rounds a value to a specified number of decimal places, rounding upwards if two
 :             such values are equally near.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="round" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/></proto></example><example role="signature"><proto name="round" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/><arg name="precision" type="xs:integer"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">General rules: see <specref ref="numeric-value-functions"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the nearest (that is, numerically closest) value to
 :                <code>$arg</code> that is a multiple of ten to the power of minus
 :                <code>$precision</code>. If two such values are equally near (for example, if the
 :             fractional part in <code>$arg</code> is exactly .5), the function returns the one that
 :             is closest to positive infinity.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the type of <code>$arg</code> is one of the four numeric types <code>xs:float</code>,
 :                <code>xs:double</code>, <code>xs:decimal</code> or <code>xs:integer</code> the type
 :             of the result is the same as the type of <code>$arg</code>. If the type of
 :                <code>$arg</code> is a type derived from one of the numeric types, the result is an
 :             instance of the base numeric type.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The single-argument version of this function produces the same result as the
 :             two-argument version with <code>$precision=0</code> (that is, it rounds to a whole
 :             number).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">When <code>$arg</code> is of type <code>xs:float</code> and <code>xs:double</code>:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If <code>$arg</code> is NaN, positive or negative zero, or positive or negative
 :                   infinity, then the result is the same as the argument.</p></item><item><p>For other values, the argument is cast to <code>xs:decimal</code> using an
 :                   implementation of <code>xs:decimal</code> that imposes no limits on the number of
 :                   digits that can be represented. The function is applied to this
 :                      <code>xs:decimal</code> value, and the resulting <code>xs:decimal</code> is
 :                   cast back to <code>xs:float</code> or <code>xs:double</code> as appropriate to
 :                   form the function result. If the resulting <code>xs:decimal</code> value is zero,
 :                   then positive or negative zero is returned according to the sign of
 :                      <code>$arg</code>.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is typically used with a non-zero <code>$precision</code> in financial
 :             applications where the argument is of type <code>xs:decimal</code>. For arguments of
 :             type <code>xs:float</code> and <code>xs:double</code> the results may be
 :             counter-intuitive. For example, consider <code>round(35.425e0, 2)</code>. The result is
 :             not 35.43, as might be expected, but 35.42. This is because the <code>xs:double</code> written as 35.425e0
 :             has an exact value equal to 35.42499999999..., which is closer
 :             to 35.42 than to 35.43.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-round
 :)
declare function fn:round($arg as numeric?) as  numeric? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Rounds a value to a specified number of decimal places, rounding upwards if two
 :             such values are equally near.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="round" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/></proto></example><example role="signature"><proto name="round" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/><arg name="precision" type="xs:integer"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">General rules: see <specref ref="numeric-value-functions"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the nearest (that is, numerically closest) value to
 :                <code>$arg</code> that is a multiple of ten to the power of minus
 :                <code>$precision</code>. If two such values are equally near (for example, if the
 :             fractional part in <code>$arg</code> is exactly .5), the function returns the one that
 :             is closest to positive infinity.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the type of <code>$arg</code> is one of the four numeric types <code>xs:float</code>,
 :                <code>xs:double</code>, <code>xs:decimal</code> or <code>xs:integer</code> the type
 :             of the result is the same as the type of <code>$arg</code>. If the type of
 :                <code>$arg</code> is a type derived from one of the numeric types, the result is an
 :             instance of the base numeric type.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The single-argument version of this function produces the same result as the
 :             two-argument version with <code>$precision=0</code> (that is, it rounds to a whole
 :             number).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">When <code>$arg</code> is of type <code>xs:float</code> and <code>xs:double</code>:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If <code>$arg</code> is NaN, positive or negative zero, or positive or negative
 :                   infinity, then the result is the same as the argument.</p></item><item><p>For other values, the argument is cast to <code>xs:decimal</code> using an
 :                   implementation of <code>xs:decimal</code> that imposes no limits on the number of
 :                   digits that can be represented. The function is applied to this
 :                      <code>xs:decimal</code> value, and the resulting <code>xs:decimal</code> is
 :                   cast back to <code>xs:float</code> or <code>xs:double</code> as appropriate to
 :                   form the function result. If the resulting <code>xs:decimal</code> value is zero,
 :                   then positive or negative zero is returned according to the sign of
 :                      <code>$arg</code>.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is typically used with a non-zero <code>$precision</code> in financial
 :             applications where the argument is of type <code>xs:decimal</code>. For arguments of
 :             type <code>xs:float</code> and <code>xs:double</code> the results may be
 :             counter-intuitive. For example, consider <code>round(35.425e0, 2)</code>. The result is
 :             not 35.43, as might be expected, but 35.42. This is because the <code>xs:double</code> written as 35.425e0
 :             has an exact value equal to 35.42499999999..., which is closer
 :             to 35.42 than to 35.43.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-round
 :)
declare function fn:round($arg as numeric?,  $precision as xs:integer) as  numeric? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Rounds a value to a specified number of decimal places, rounding to make the
 :             last digit even if two such values are equally near.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="round-half-to-even" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/></proto></example><example role="signature"><proto name="round-half-to-even" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/><arg name="precision" type="xs:integer"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">General rules: see <specref ref="numeric-value-functions"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the nearest (that is, numerically closest) value to
 :                <code>$arg</code> that is a multiple of ten to the power of minus
 :                <code>$precision</code>. If two such values are equally near (e.g. if the fractional
 :             part in <code>$arg</code> is exactly .500...), the function returns the one whose least
 :             significant digit is even.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the type of <code>$arg</code> is one of the four numeric types <code>xs:float</code>,
 :                <code>xs:double</code>, <code>xs:decimal</code> or <code>xs:integer</code> the type
 :             of the result is the same as the type of <code>$arg</code>. If the type of
 :                <code>$arg</code> is a type derived from one of the numeric types, the result is an
 :             instance of the base numeric type.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> The first signature of this function produces the same result as the second signature
 :             with <code>$precision=0</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For arguments of type <code>xs:float</code> and <code>xs:double</code>:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the argument is <code>NaN</code>, positive or negative zero, or positive or
 :                   negative infinity, then the result is the same as the argument.</p></item><item><p>In all other cases, the argument is cast to <code>xs:decimal</code>
 :                   <phrase diff="add" at="A">using an implementation of xs:decimal that imposes no
 :                      limits on the number of digits that can be represented.</phrase> The function
 :                   is applied to this <code>xs:decimal</code> value, and the resulting
 :                      <code>xs:decimal</code> is cast back to <code>xs:float</code> or
 :                      <code>xs:double</code> as appropriate to form the function result. If the
 :                   resulting <code>xs:decimal</code> value is zero, then positive or negative zero is
 :                   returned according to the sign of the original argument.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A">This function is typically used in financial applications where the
 :             argument is of type <code>xs:decimal</code>. For arguments of type <code>xs:float</code>
 :             and <code>xs:double</code> the results may be counter-intuitive. For example, consider
 :                <code>round-half-to-even(xs:float(150.015), 2)</code>. The result is not 150.02 as
 :             might be expected, but 150.01. This is because the conversion of the
 :                <code>xs:float</code> value represented by the literal 150.015 to an
 :                <code>xs:decimal</code> produces the <code>xs:decimal</code> value 150.014999389...,
 :             which is closer to 150.01 than to 150.02.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-round-half-to-even
 :)
declare function fn:round-half-to-even($arg as numeric?) as  numeric? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Rounds a value to a specified number of decimal places, rounding to make the
 :             last digit even if two such values are equally near.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="round-half-to-even" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/></proto></example><example role="signature"><proto name="round-half-to-even" return-type="numeric?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="numeric?"/><arg name="precision" type="xs:integer"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">General rules: see <specref ref="numeric-value-functions"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the nearest (that is, numerically closest) value to
 :                <code>$arg</code> that is a multiple of ten to the power of minus
 :                <code>$precision</code>. If two such values are equally near (e.g. if the fractional
 :             part in <code>$arg</code> is exactly .500...), the function returns the one whose least
 :             significant digit is even.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the type of <code>$arg</code> is one of the four numeric types <code>xs:float</code>,
 :                <code>xs:double</code>, <code>xs:decimal</code> or <code>xs:integer</code> the type
 :             of the result is the same as the type of <code>$arg</code>. If the type of
 :                <code>$arg</code> is a type derived from one of the numeric types, the result is an
 :             instance of the base numeric type.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> The first signature of this function produces the same result as the second signature
 :             with <code>$precision=0</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">For arguments of type <code>xs:float</code> and <code>xs:double</code>:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the argument is <code>NaN</code>, positive or negative zero, or positive or
 :                   negative infinity, then the result is the same as the argument.</p></item><item><p>In all other cases, the argument is cast to <code>xs:decimal</code>
 :                   <phrase diff="add" at="A">using an implementation of xs:decimal that imposes no
 :                      limits on the number of digits that can be represented.</phrase> The function
 :                   is applied to this <code>xs:decimal</code> value, and the resulting
 :                      <code>xs:decimal</code> is cast back to <code>xs:float</code> or
 :                      <code>xs:double</code> as appropriate to form the function result. If the
 :                   resulting <code>xs:decimal</code> value is zero, then positive or negative zero is
 :                   returned according to the sign of the original argument.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A">This function is typically used in financial applications where the
 :             argument is of type <code>xs:decimal</code>. For arguments of type <code>xs:float</code>
 :             and <code>xs:double</code> the results may be counter-intuitive. For example, consider
 :                <code>round-half-to-even(xs:float(150.015), 2)</code>. The result is not 150.02 as
 :             might be expected, but 150.01. This is because the conversion of the
 :                <code>xs:float</code> value represented by the literal 150.015 to an
 :                <code>xs:decimal</code> produces the <code>xs:decimal</code> value 150.014999389...,
 :             which is closer to 150.01 than to 150.02.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-round-half-to-even
 :)
declare function fn:round-half-to-even($arg as numeric?,  $precision as xs:integer) as  numeric? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the seconds component of an <code>xs:dateTime</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="seconds-from-dateTime" return-type="xs:decimal?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:dateTime?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:decimal</code> value greater than or equal
 :             to zero and less than 60, representing the seconds and fractional seconds in the local
 :             value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:seconds-from-dateTime(xs:dateTime("1999-05-31T13:20:00-05:00"))</code> returns <code>0</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-seconds-from-dateTime
 :)
declare function fn:seconds-from-dateTime($arg as xs:dateTime?) as  xs:decimal? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of seconds in a duration.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="seconds-from-duration" return-type="xs:decimal?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:duration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:decimal</code> representing the seconds
 :             component in the value of <code>$arg</code>. The result is obtained by casting
 :                <code>$arg</code> to an <code>xs:dayTimeDuration</code> (see <specref ref="casting-to-durations"/>) and then computing the seconds component as described
 :             in <specref ref="canonical-dayTimeDuration"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a negative duration then the result will be negative..</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an <code>xs:yearMonthDuration</code> the function returns 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:seconds-from-duration(xs:dayTimeDuration("P3DT10H12.5S"))</code> returns <code>12.5</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:seconds-from-duration(xs:dayTimeDuration("-PT256S"))</code> returns <code>-16.0</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-seconds-from-duration
 :)
declare function fn:seconds-from-duration($arg as xs:duration?) as  xs:decimal? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the seconds component of an <code>xs:time</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="seconds-from-time" return-type="xs:decimal?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:decimal</code> value greater than or equal
 :             to zero and less than 60, representing the seconds and fractional seconds in the local
 :             value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:seconds-from-time(xs:time("13:20:10.5"))</code> returns <code>10.5</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-seconds-from-time
 :)
declare function fn:seconds-from-time($arg as xs:time?) as  xs:decimal? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function serializes the supplied <phrase diff="chg" at="G">input
 :                sequence</phrase>
 :             <code>$arg</code> as described in <bibref ref="xslt-xquery-serialization-30"/>,
 :             returning the serialized <phrase diff="chg" at="G">representation of the
 :                sequence</phrase> as a string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="serialize" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example><example role="signature"><proto name="serialize" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/><arg name="params" type="element(output:serialization-parameters)?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The value of <code>$arg</code> acts as the input sequence to the serialization process,
 :             which starts with sequence normalization.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">The single-argument version of this function has the same effect as
 :             the two-argument version called with <code>$params</code> set to an empty sequence. This
 :             in turn is the same as the effect of passing an
 :                <code>output:serialization-parameters</code> element with no child elements.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">The <code>$params</code> argument is used to identify a set of
 :             serialization parameters. These are supplied in the form of an
 :                <code>output:serialization-parameters</code> element, having the format described in
 :                <xspecref spec="SER30" ref="serparams-in-xdm-instance"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The final stage of serialization, that is, encoding, is skipped. If the serializer does
 :             not allow this phase to be skipped, then the sequence of octets returned by the
 :             serializer is decoded into a string by reversing the character encoding performed in the
 :             final stage.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">If the host language makes serialization an optional feature and
 :          the implementation does not support serialization, then a dynamic error
 :             <errorref class="DC" code="0010"/> is raised.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The serialization process will raise an error if <code>$arg</code> is an attribute or
 :             namespace node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If any serialization error occurs, including the detection of an invalid value for a
 :             serialization parameter, this results in the <code>fn:serialize</code> call failing with
 :             a dynamic error.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-serialize
 :)
declare function fn:serialize($arg as item()*) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function serializes the supplied <phrase diff="chg" at="G">input
 :                sequence</phrase>
 :             <code>$arg</code> as described in <bibref ref="xslt-xquery-serialization-30"/>,
 :             returning the serialized <phrase diff="chg" at="G">representation of the
 :                sequence</phrase> as a string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="serialize" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example><example role="signature"><proto name="serialize" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/><arg name="params" type="element(output:serialization-parameters)?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The value of <code>$arg</code> acts as the input sequence to the serialization process,
 :             which starts with sequence normalization.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">The single-argument version of this function has the same effect as
 :             the two-argument version called with <code>$params</code> set to an empty sequence. This
 :             in turn is the same as the effect of passing an
 :                <code>output:serialization-parameters</code> element with no child elements.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">The <code>$params</code> argument is used to identify a set of
 :             serialization parameters. These are supplied in the form of an
 :                <code>output:serialization-parameters</code> element, having the format described in
 :                <xspecref spec="SER30" ref="serparams-in-xdm-instance"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The final stage of serialization, that is, encoding, is skipped. If the serializer does
 :             not allow this phase to be skipped, then the sequence of octets returned by the
 :             serializer is decoded into a string by reversing the character encoding performed in the
 :             final stage.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">If the host language makes serialization an optional feature and
 :          the implementation does not support serialization, then a dynamic error
 :             <errorref class="DC" code="0010"/> is raised.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The serialization process will raise an error if <code>$arg</code> is an attribute or
 :             namespace node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If any serialization error occurs, including the detection of an invalid value for a
 :             serialization parameter, this results in the <code>fn:serialize</code> call failing with
 :             a dynamic error.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-serialize
 :)
declare function fn:serialize( $arg as item()*,  $params as element(output:serialization-parameters)?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the string <code>$arg1</code> contains <code>$arg2</code> as a
 :             leading substring, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="starts-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="starts-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :                <code>true</code>. If the value of <code>$arg1</code> is the zero-length string and
 :             the value of <code>$arg2</code> is not the zero-length string, then the function returns
 :                <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:boolean</code> indicating whether or not the value of
 :                <code>$arg1</code> starts with a sequence of collation units that provides a
 :                <term>match</term> to the collation units of <code>$arg2</code> according to the
 :             collation that is used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Match</term> is defined in <bibref ref="Unicode-Collations"/>.</p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-starts-with
 :)
declare function fn:starts-with($arg1 as xs:string?,  $arg2 as xs:string?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the string <code>$arg1</code> contains <code>$arg2</code> as a
 :             leading substring, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="starts-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="starts-with" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :                <code>true</code>. If the value of <code>$arg1</code> is the zero-length string and
 :             the value of <code>$arg2</code> is not the zero-length string, then the function returns
 :                <code>false</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:boolean</code> indicating whether or not the value of
 :                <code>$arg1</code> starts with a sequence of collation units that provides a
 :                <term>match</term> to the collation units of <code>$arg2</code> according to the
 :             collation that is used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Match</term> is defined in <bibref ref="Unicode-Collations"/>.</p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-starts-with
 :)
declare function fn:starts-with( $arg1 as xs:string?,  $arg2 as xs:string?,  $collation as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string created by concatenating the items in a sequence, with a
 :             defined separator between adjacent items.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string-join" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string*"/></proto></example><example role="signature"><proto name="string-join" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string*"/><arg name="arg2" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">The effect of calling the single-argument version of this function is
 :             the same as calling the two-argument version with <code>$arg2</code> set to a
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:string</code> created by concatenating the items in the
 :             sequence <code>$arg1</code>, in order, using the value of <code>$arg2</code> as a
 :             separator between adjacent items. If the value of <code>$arg2</code> is the zero-length
 :             string, then the members of <code>$arg1</code> are concatenated without a separator.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> is the empty sequence, the function returns the
 :             zero-length string.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string-join
 :)
declare function fn:string-join($arg1 as xs:string*) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a string created by concatenating the items in a sequence, with a
 :             defined separator between adjacent items.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string-join" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string*"/></proto></example><example role="signature"><proto name="string-join" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string*"/><arg name="arg2" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">The effect of calling the single-argument version of this function is
 :             the same as calling the two-argument version with <code>$arg2</code> set to a
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:string</code> created by concatenating the items in the
 :             sequence <code>$arg1</code>, in order, using the value of <code>$arg2</code> as a
 :             separator between adjacent items. If the value of <code>$arg2</code> is the zero-length
 :             string, then the members of <code>$arg1</code> are concatenated without a separator.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> is the empty sequence, the function returns the
 :             zero-length string.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string-join
 :)
declare function fn:string-join($arg1 as xs:string*,  $arg2 as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of <termref def="character">characters</termref> in a
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string-length" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="string-length" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:integer</code> equal to the length in <termref def="character">characters</termref> of the value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the zero-argument version of the function is equivalent to calling
 :                <code>fn:string-length(fn:string(.))</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns the
 :                <code>xs:integer</code> value zero (0).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is not specified and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, a <phrase diff="add" at="M">dynamic</phrase> error is raised: <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string-length
 :)
declare function fn:string-length() as  xs:integer external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of <termref def="character">characters</termref> in a
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string-length" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="string-length" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns an <code>xs:integer</code> equal to the length in <termref def="character">characters</termref> of the value of <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the zero-argument version of the function is equivalent to calling
 :                <code>fn:string-length(fn:string(.))</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns the
 :                <code>xs:integer</code> value zero (0).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is not specified and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, a <phrase diff="add" at="M">dynamic</phrase> error is raised: <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string-length
 :)
declare function fn:string-length($arg as xs:string?) as  xs:integer external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the sequence of <termref def="codepoint">codepoints</termref> that
 :             constitute an <code>xs:string</code> value. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string-to-codepoints" return-type="xs:integer*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of integers, each integer being the Unicode <termref def="codepoint">codepoints</termref> of the corresponding <termref def="character">character</termref> in <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a zero-length string or the empty sequence, the function returns
 :             the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:string-to-codepoints("Thérèse")</code> returns <code>(84, 104, 233, 114, 232, 115, 101)</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string-to-codepoints
 :)
declare function fn:string-to-codepoints($arg as xs:string?) as  xs:integer* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the contiguous sequence of items in the value of
 :                <code>$sourceSeq</code> beginning at the position indicated by the value of
 :                <code>$startingLoc</code> and continuing for the number of items indicated by the
 :             value of <code>$length</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="subsequence" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceSeq" type="item()*"/><arg name="startingLoc" type="xs:double"/></proto></example><example role="signature"><proto name="subsequence" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceSeq" type="item()*"/><arg name="startingLoc" type="xs:double"/><arg name="length" type="xs:double"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the two-argument case, returns:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E2" xml:space="preserve">$sourceSeq[fn:round($startingLoc) le position()]</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the three-argument case, returns:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E2" xml:space="preserve">$sourceSeq[fn:round($startingLoc) le position() 
 :          and position() lt fn:round($startingLoc) + fn:round($length)]</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first item of a sequence is located at position 1, not position 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$sourceSeq</code> is the empty sequence, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$startingLoc</code> is zero or negative, the subsequence includes items from
 :             the beginning of the <code>$sourceSeq</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$length</code> is not specified, the subsequence includes items to the end of
 :                <code>$sourceSeq</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$length</code> is greater than the number of items in the value of
 :                <code>$sourceSeq</code> following <code>$startingLoc</code>, the subsequence includes
 :             items to the end of <code>$sourceSeq</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">As an exception to the previous two notes, if
 :                <code>$startingLoc</code> is <code>-INF</code> and <code>$length</code> is
 :                <code>+INF</code>, then <code>fn:round($startingLoc) + fn:round($length)</code> is
 :                <code>NaN</code>; since <code>position() lt NaN</code> is always false, the result is
 :             an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The reason the function accepts arguments of type <code>xs:double</code> is that many
 :             computations on untyped data return an <code>xs:double</code> result; and the reason for
 :             the rounding rules is to compensate for any imprecision in these floating-point
 :             computations.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-subsequence
 :)
declare function fn:subsequence($sourceSeq as item()*,  $startingLoc as xs:double) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the contiguous sequence of items in the value of
 :                <code>$sourceSeq</code> beginning at the position indicated by the value of
 :                <code>$startingLoc</code> and continuing for the number of items indicated by the
 :             value of <code>$length</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="subsequence" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceSeq" type="item()*"/><arg name="startingLoc" type="xs:double"/></proto></example><example role="signature"><proto name="subsequence" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceSeq" type="item()*"/><arg name="startingLoc" type="xs:double"/><arg name="length" type="xs:double"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the two-argument case, returns:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E2" xml:space="preserve">$sourceSeq[fn:round($startingLoc) le position()]</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the three-argument case, returns:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E2" xml:space="preserve">$sourceSeq[fn:round($startingLoc) le position() 
 :          and position() lt fn:round($startingLoc) + fn:round($length)]</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first item of a sequence is located at position 1, not position 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$sourceSeq</code> is the empty sequence, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$startingLoc</code> is zero or negative, the subsequence includes items from
 :             the beginning of the <code>$sourceSeq</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$length</code> is not specified, the subsequence includes items to the end of
 :                <code>$sourceSeq</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If <code>$length</code> is greater than the number of items in the value of
 :                <code>$sourceSeq</code> following <code>$startingLoc</code>, the subsequence includes
 :             items to the end of <code>$sourceSeq</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">As an exception to the previous two notes, if
 :                <code>$startingLoc</code> is <code>-INF</code> and <code>$length</code> is
 :                <code>+INF</code>, then <code>fn:round($startingLoc) + fn:round($length)</code> is
 :                <code>NaN</code>; since <code>position() lt NaN</code> is always false, the result is
 :             an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The reason the function accepts arguments of type <code>xs:double</code> is that many
 :             computations on untyped data return an <code>xs:double</code> result; and the reason for
 :             the rounding rules is to compensate for any imprecision in these floating-point
 :             computations.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-subsequence
 :)
declare function fn:subsequence( $sourceSeq as item()*,  $startingLoc as xs:double,  $length as xs:double) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the portion of the value of <code>$sourceString</code> beginning at the
 :             position indicated by the value of <code>$start</code> and continuing for the number of
 :                <termref def="character">characters</termref> indicated by the value of
 :                <code>$length</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="substring" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceString" type="xs:string?"/><arg name="start" type="xs:double"/></proto></example><example role="signature"><proto name="substring" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceString" type="xs:string?"/><arg name="start" type="xs:double"/><arg name="length" type="xs:double"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$sourceString</code> is the empty sequence, the function returns
 :             the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns a string comprising those <termref def="character">characters</termref> of <code>$sourceString</code> whose index position (counting
 :             from one) is greater than or equal to the value of <code>$start</code> (rounded to an
 :             integer), and (if <code>$length</code> is specified) less than the sum of
 :                <code>$start</code> and <code>$length</code> (both rounded to integers).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The characters returned do not extend beyond <code>$sourceString</code>. If
 :                <code>$start</code> is zero or negative, only those characters in positions greater
 :             than zero are returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">More specifically, the three argument version of the function returns the characters in
 :                <code>$sourceString</code> whose position <code>$p</code> satisfies:</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">
 :             <code>fn:round($start) &lt;= $p &lt; fn:round($start) + fn:round($length)</code>
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two argument version of the function assumes that <code>$length</code> is infinite
 :             and thus returns the <termref def="character">characters</termref> in
 :                <code>$sourceString</code> whose position <code>$p</code> satisfies:</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">
 :             <code>fn:round($start) &lt;= $p</code>
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the above computations, the rules for <code>op:numeric-less-than</code> and
 :                <code>op:numeric-greater-than</code> apply.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first character of a string is located at position 1, not position 0.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-substring
 :)
declare function fn:substring($sourceString as xs:string?,  $start as xs:double) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the portion of the value of <code>$sourceString</code> beginning at the
 :             position indicated by the value of <code>$start</code> and continuing for the number of
 :                <termref def="character">characters</termref> indicated by the value of
 :                <code>$length</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="substring" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceString" type="xs:string?"/><arg name="start" type="xs:double"/></proto></example><example role="signature"><proto name="substring" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceString" type="xs:string?"/><arg name="start" type="xs:double"/><arg name="length" type="xs:double"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$sourceString</code> is the empty sequence, the function returns
 :             the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns a string comprising those <termref def="character">characters</termref> of <code>$sourceString</code> whose index position (counting
 :             from one) is greater than or equal to the value of <code>$start</code> (rounded to an
 :             integer), and (if <code>$length</code> is specified) less than the sum of
 :                <code>$start</code> and <code>$length</code> (both rounded to integers).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The characters returned do not extend beyond <code>$sourceString</code>. If
 :                <code>$start</code> is zero or negative, only those characters in positions greater
 :             than zero are returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">More specifically, the three argument version of the function returns the characters in
 :                <code>$sourceString</code> whose position <code>$p</code> satisfies:</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">
 :             <code>fn:round($start) &lt;= $p &lt; fn:round($start) + fn:round($length)</code>
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two argument version of the function assumes that <code>$length</code> is infinite
 :             and thus returns the <termref def="character">characters</termref> in
 :                <code>$sourceString</code> whose position <code>$p</code> satisfies:</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">
 :             <code>fn:round($start) &lt;= $p</code>
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the above computations, the rules for <code>op:numeric-less-than</code> and
 :                <code>op:numeric-greater-than</code> apply.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first character of a string is located at position 1, not position 0.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-substring
 :)
declare function fn:substring( $sourceString as xs:string?,  $start as xs:double,  $length as xs:double) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the part of <code>$arg1</code> that follows the first occurrence of
 :                <code>$arg2</code>, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="substring-after" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="substring-after" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :             the value of <code>$arg1</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> does not contain a string that is equal to the value
 :             of <code>$arg2</code>, then the function returns the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the substring of the value of <code>$arg1</code> that follows in
 :             the value of <code>$arg1</code> the first occurrence of a sequence of collation units
 :             that provides a <term>minimal match</term> to the collation units of <code>$arg2</code>
 :             according to the collation that is used. </p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Minimal match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-substring-after
 :)
declare function fn:substring-after($arg1 as xs:string?,  $arg2 as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the part of <code>$arg1</code> that follows the first occurrence of
 :                <code>$arg2</code>, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="substring-after" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="substring-after" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :             the value of <code>$arg1</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> does not contain a string that is equal to the value
 :             of <code>$arg2</code>, then the function returns the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the substring of the value of <code>$arg1</code> that follows in
 :             the value of <code>$arg1</code> the first occurrence of a sequence of collation units
 :             that provides a <term>minimal match</term> to the collation units of <code>$arg2</code>
 :             according to the collation that is used. </p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Minimal match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-substring-after
 :)
declare function fn:substring-after( $arg1 as xs:string?,  $arg2 as xs:string?,  $collation as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the part of <code>$arg1</code> that precedes the first occurrence of
 :                <code>$arg2</code>, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="substring-before" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="substring-before" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :             the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> does not contain a string that is equal to the value
 :             of <code>$arg2</code>, then the function returns the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the substring of the value of <code>$arg1</code> that precedes in
 :             the value of <code>$arg1</code> the first occurrence of a sequence of collation units
 :             that provides a <term>minimal match</term> to the collation units of <code>$arg2</code>
 :             according to the collation that is used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Minimal match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-substring-before
 :)
declare function fn:substring-before($arg1 as xs:string?,  $arg2 as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the part of <code>$arg1</code> that precedes the first occurrence of
 :                <code>$arg2</code>, taking collations into account.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="substring-before" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/></proto></example><example role="signature"><proto name="substring-before" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg1" type="xs:string?"/><arg name="arg2" type="xs:string?"/><arg name="collation" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The three-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If the value of <code>$arg1</code> or <code>$arg2</code> is the empty sequence, or
 :             contains only ignorable collation units, it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg2</code> is the zero-length string, then the function returns
 :             the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg1</code> does not contain a string that is equal to the value
 :             of <code>$arg2</code>, then the function returns the zero-length string. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used by this function is determined according to the rules in <specref ref="choosing-a-collation"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the substring of the value of <code>$arg1</code> that precedes in
 :             the value of <code>$arg1</code> the first occurrence of a sequence of collation units
 :             that provides a <term>minimal match</term> to the collation units of <code>$arg2</code>
 :             according to the collation that is used.</p><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><p><term>Minimal match</term> is defined in <bibref ref="Unicode-Collations"/>. </p></note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error <rfc2119>may</rfc2119> be raised <errorref class="CH" code="0004"/> if the
 :             specified collation does not support collation units.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-substring-before
 :)
declare function fn:substring-before( $arg1 as xs:string?,  $arg2 as xs:string?,  $collation as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a value obtained by adding together the values in
 :             <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="sum" return-type="xs:anyAtomicType" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="sum" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="zero" type="xs:anyAtomicType?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Any values of type <code>xs:untypedAtomic</code> in <code>$arg</code> are cast to
 :                <code>xs:double</code>. The items in the resulting sequence may be reordered in an
 :             arbitrary order. The resulting sequence is referred to below as the converted
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence is empty, then the single-argument form of the function
 :             returns the <code>xs:integer</code> value <code>0</code>; the two-argument form returns
 :             the value of the argument <code>$zero</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence contains the value <code>NaN</code>, <code>NaN</code> is
 :             returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">All items in <code>$arg</code> must be numeric or derived from a single base type. In
 :             addition, the type must support addition. Duration values must either all be
 :                <code>xs:yearMonthDuration</code> values or must all be
 :                <code>xs:dayTimeDuration</code> values. For numeric values, the numeric promotion
 :             rules defined in <specref ref="op.numeric"/> are used to promote all values to a single
 :             common type. The sum of a sequence of integers will therefore be an integer, while the
 :             sum of a numeric sequence that includes at least one <code>xs:double</code> will be an
 :                <code>xs:double</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function, using the second signature, is the result of the
 :             expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : if (fn:count($c) eq 0) then
 :     $zero
 : else if (fn:count($c) eq 1) then
 :     $c[1]
 : else
 :     $c[1] + fn:sum(subsequence($c, 2))</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">where <code>$c</code> is the converted sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function, using the first signature, is the result of the expression:
 :                <code>fn:sum($arg, 0)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A type error is raised <errorref class="RG" code="0006"/> if the input sequence contains
 :             items of incompatible types, as described above.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-sum
 :)
declare function fn:sum($arg as xs:anyAtomicType*) as  xs:anyAtomicType external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a value obtained by adding together the values in
 :             <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="sum" return-type="xs:anyAtomicType" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/></proto></example><example role="signature"><proto name="sum" return-type="xs:anyAtomicType?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType*"/><arg name="zero" type="xs:anyAtomicType?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Any values of type <code>xs:untypedAtomic</code> in <code>$arg</code> are cast to
 :                <code>xs:double</code>. The items in the resulting sequence may be reordered in an
 :             arbitrary order. The resulting sequence is referred to below as the converted
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence is empty, then the single-argument form of the function
 :             returns the <code>xs:integer</code> value <code>0</code>; the two-argument form returns
 :             the value of the argument <code>$zero</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the converted sequence contains the value <code>NaN</code>, <code>NaN</code> is
 :             returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">All items in <code>$arg</code> must be numeric or derived from a single base type. In
 :             addition, the type must support addition. Duration values must either all be
 :                <code>xs:yearMonthDuration</code> values or must all be
 :                <code>xs:dayTimeDuration</code> values. For numeric values, the numeric promotion
 :             rules defined in <specref ref="op.numeric"/> are used to promote all values to a single
 :             common type. The sum of a sequence of integers will therefore be an integer, while the
 :             sum of a numeric sequence that includes at least one <code>xs:double</code> will be an
 :                <code>xs:double</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function, using the second signature, is the result of the
 :             expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">
 : if (fn:count($c) eq 0) then
 :     $zero
 : else if (fn:count($c) eq 1) then
 :     $c[1]
 : else
 :     $c[1] + fn:sum(subsequence($c, 2))</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">where <code>$c</code> is the converted sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function, using the first signature, is the result of the expression:
 :                <code>fn:sum($arg, 0)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A type error is raised <errorref class="RG" code="0006"/> if the input sequence contains
 :             items of incompatible types, as described above.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-sum
 :)
declare function fn:sum( $arg as xs:anyAtomicType*,  $zero as xs:anyAtomicType?) as  xs:anyAtomicType? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns all but the first item in a sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="tail" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the value of the expression <code>subsequence($arg, 2)</code></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, or a sequence containing a single item, then
 :             the empty sequence is returned. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-tail
 :)
declare function fn:tail($arg as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the timezone component of an <code>xs:date</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="timezone-from-date" return-type="xs:dayTimeDuration?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the timezone component of <code>$arg</code>, if any. If
 :                <code>$arg</code> has a timezone component, then the result is an
 :                <code>xs:dayTimeDuration</code> that indicates deviation from UTC; its value may
 :             range from +14:00 to -14:00 hours, both inclusive. If <code>$arg</code> has no timezone
 :             component, the result is the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:timezone-from-date(xs:date("1999-05-31-05:00"))</code> returns <code>xs:dayTimeDuration("-PT5H")</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:timezone-from-date(xs:date("2000-06-12Z"))</code> returns <code>xs:dayTimeDuration("PT0S")</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-timezone-from-date
 :)
declare function fn:timezone-from-date($arg as xs:date?) as  xs:dayTimeDuration? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the timezone component of an <code>xs:dateTime</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="timezone-from-dateTime" return-type="xs:dayTimeDuration?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:dateTime?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the timezone component of <code>$arg</code>, if any. If
 :                <code>$arg</code> has a timezone component, then the result is an
 :                <code>xs:dayTimeDuration</code> that indicates deviation from UTC; its value may
 :             range from +14:00 to -14:00 hours, both inclusive. If <code>$arg</code> has no timezone
 :             component, the result is the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:timezone-from-dateTime(xs:dateTime("1999-05-31T13:20:00-05:00"))</code> returns <code>xs:dayTimeDuration("-PT5H")</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:timezone-from-dateTime(xs:dateTime("2000-06-12T13:20:00Z"))</code> returns <code>xs:dayTimeDuration("PT0S")</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:timezone-from-dateTime(xs:dateTime("2004-08-27T00:00:00"))</code> returns <code>()</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-timezone-from-dateTime
 :)
declare function fn:timezone-from-dateTime($arg as xs:dateTime?) as  xs:dayTimeDuration? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the timezone component of an <code>xs:time</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="timezone-from-time" return-type="xs:dayTimeDuration?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:time?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the timezone component of <code>$arg</code>, if any. If
 :                <code>$arg</code> has a timezone component, then the result is an
 :                <code>xs:dayTimeDuration</code> that indicates deviation from UTC; its value may
 :             range from +14:00 to -14:00 hours, both inclusive. If <code>$arg</code> has no timezone
 :             component, the result is the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:timezone-from-time(xs:time("13:20:00-05:00"))</code> returns <code>xs:dayTimeDuration("-PT5H")</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:timezone-from-time(xs:time("13:20:00"))</code> returns <code>()</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-timezone-from-time
 :)
declare function fn:timezone-from-time($arg as xs:time?) as  xs:dayTimeDuration? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of strings constructed by splitting the input wherever a
 :             separator is found; the separator is any substring that matches a given regular
 :             expression.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="tokenize" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/></proto></example><example role="signature"><proto name="tokenize" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$flags</code> argument is interpreted in the same way as for the
 :                <code>fn:matches</code> function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence, or if <code>$input</code> is the
 :             zero-length string, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of strings formed by breaking the <code>$input</code>
 :             string into a sequence of strings, treating any substring that matches
 :                <code>$pattern</code> as a separator. The separators themselves are not returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If a separator occurs at the start of the <code>$input</code> string, the result
 :             sequence will start with a zero-length string. Zero-length strings will also occur in
 :             the result sequence if a separator occurs at the end of the <code>$input</code> string,
 :             or if two adjacent substrings match the supplied <code>$pattern</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If two alternatives within the supplied <code>$pattern</code> both match at the same
 :             position in the <code>$input</code> string, then the match that is chosen is the first.
 :             For example:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:tokenize("abracadabra", "(ab)|(a)") returns ("", "r", "c", "d", "r", "")</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0003"/> if the supplied
 :                <code>$pattern</code> matches a zero-length string, that is, if <code>fn:matches("",
 :                $pattern, $flags)</code> returns <code>true</code>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-tokenize
 :)
declare function fn:tokenize($input as xs:string?,  $pattern as xs:string) as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of strings constructed by splitting the input wherever a
 :             separator is found; the separator is any substring that matches a given regular
 :             expression.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="tokenize" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/></proto></example><example role="signature"><proto name="tokenize" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="input" type="xs:string?"/><arg name="pattern" type="xs:string"/><arg name="flags" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of calling the first version of this function (omitting the argument
 :                <code>$flags</code>) is the same as the effect of calling the second version with the
 :                <code>$flags</code> argument set to a zero-length string. Flags are defined in
 :                <specref ref="flags"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$flags</code> argument is interpreted in the same way as for the
 :                <code>fn:matches</code> function.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$input</code> is the empty sequence, or if <code>$input</code> is the
 :             zero-length string, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of strings formed by breaking the <code>$input</code>
 :             string into a sequence of strings, treating any substring that matches
 :                <code>$pattern</code> as a separator. The separators themselves are not returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If a separator occurs at the start of the <code>$input</code> string, the result
 :             sequence will start with a zero-length string. Zero-length strings will also occur in
 :             the result sequence if a separator occurs at the end of the <code>$input</code> string,
 :             or if two adjacent substrings match the supplied <code>$pattern</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> If two alternatives within the supplied <code>$pattern</code> both match at the same
 :             position in the <code>$input</code> string, then the match that is chosen is the first.
 :             For example:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve"> fn:tokenize("abracadabra", "(ab)|(a)") returns ("", "r", "c", "d", "r", "")</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0002"/> if the value of
 :                <code>$pattern</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0001"/> if the value of
 :                <code>$flags</code> is invalid according to the rules described in section <specref ref="regex-syntax"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RX" code="0003"/> if the supplied
 :                <code>$pattern</code> matches a zero-length string, that is, if <code>fn:matches("",
 :                $pattern, $flags)</code> returns <code>true</code>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-tokenize
 :)
declare function fn:tokenize( $input as xs:string?,  $pattern as xs:string,  $flags as xs:string) as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Provides an execution trace intended to be used in debugging queries.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="trace" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="value" type="item()*"/><arg name="label" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the value of <code>$value</code>, unchanged.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In addition, the values of <code>$value</code>, converted to an <code>xs:string</code>,
 :             and <code>$label</code>
 :             <rfc2119>may</rfc2119> be directed to a trace data set. The destination of the trace
 :             output is <termref def="implementation-defined"/>. The format of the trace output is
 :                <termref def="implementation-dependent"/>. The ordering of output from calls of the
 :                <code>fn:trace</code> function is <termref def="implementation-dependent"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Consider a situation in which a user wants to investigate the actual value passed to
 :                a function. Assume that in a particular execution, <code>$v</code> is an
 :                   <code>xs:decimal</code> with value <code>124.84</code>. Writing <code>fn:trace($v,
 :                   'the value of $v is:')</code> will put the strings <code>"124.84"</code> and
 :                   <code>"the value of $v is:"</code> in the trace data set in implementation
 :                dependent order.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-trace
 :)
declare function fn:trace($value as item()*,  $label as xs:string) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>$arg</code> modified by replacing or removing
 :             individual characters. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="translate" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/><arg name="mapString" type="xs:string"/><arg name="transString" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns a result string constructed by processing each <termref def="character">character</termref> in the value of <code>$arg</code>, in order,
 :             according to the following rules:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the character does not appear in the value of <code>$mapString</code> then it
 :                   is added to the result string unchanged.</p></item><item><p>If the character first appears in the value of <code>$mapString</code> at some
 :                   position <emph>M</emph>, where the value of <code>$transString</code> is
 :                      <emph>M</emph> or more characters in length, then the character at position
 :                      <emph>M</emph> in <code>$transString</code> is added to the result string.</p></item><item><p>If the character first appears in the value of <code>$mapString</code> at some
 :                   position <emph>M</emph>, where the value of <code>$transString</code> is less than
 :                      <emph>M</emph> characters in length, then the character is omitted from the
 :                   result string.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$mapString</code> is the zero-length string then the function returns
 :                <code>$arg</code> unchanged.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If a character occurs more than once in <code>$mapString</code>, then the first
 :             occurrence determines the action taken.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$transString</code> is longer than <code>$mapString</code>, the excess
 :             characters are ignored.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-translate
 :)
declare function fn:translate( $arg as xs:string?,  $mapString as xs:string,  $transString as xs:string) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the <code>xs:boolean</code> value <code>true</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="true" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result is equivalent to <code>xs:boolean("1")</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:true()</code> returns <code>xs:boolean(1)</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-true
 :)
declare function fn:true() as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the items of <code>$sourceSeq</code> in an <termref def="implementation-dependent"/> order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unordered" return-type="item()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="sourceSeq" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the items of <code>$sourceSeq</code> in an <termref def="implementation-dependent"/> order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Query optimizers may be able to do a better job if the order of the output sequence is
 :             not specified. For example, when retrieving prices from a purchase order, if an index
 :             exists on prices, it may be more efficient to return the prices in index order rather
 :             than in document order.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unordered
 :)
declare function fn:unordered($sourceSeq as item()*) as  item()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:unparsed-text</code> function reads an external resource (for example, a
 :             file) and returns <phrase diff="chg" at="L">a string representation of the resource</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$href</code> argument <rfc2119>must</rfc2119> be a string in the form of a URI
 :             reference, which <rfc2119>must</rfc2119> contain no fragment identifier, and
 :                <rfc2119>must</rfc2119> identify a resource 
 :             <phrase diff="chg" at="L">for which a string representation is available</phrase>. If the URI is a
 :             relative URI reference, then it is resolved relative to the 
 :             <phrase diff="chg" at="L">Static Base URI property from the static context</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">The mapping of URIs to the string representation of a resource is the mapping defined
 :             in the <xtermref spec="XP30" ref="dt-available-text-resources">available text resources</xtermref>
 :          component of the dynamic context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of the <code>$href</code> argument is an empty sequence, the function
 :             returns an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$encoding</code> argument, if present, is the name of an encoding. The values
 :             for this attribute follow the same rules as for the <code>encoding</code> attribute in
 :             an XML declaration. The only values which every <termref def="implementation">implementation</termref> is <rfc2119>required</rfc2119> to recognize are
 :                <code>utf-8</code> and <code>utf-16</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The encoding of the external resource is determined as follows:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>external encoding information is used if available, otherwise</p></item><item><p>if the media type of the resource is <code>text/xml</code> or
 :                      <code>application/xml</code> (see <bibref ref="rfc2376"/>), or if it matches
 :                   the conventions <code>text/*+xml</code> or <code>application/*+xml</code> (see
 :                      <bibref ref="rfc3023"/> and/or its successors), then the encoding is recognized
 :                   as specified in <bibref ref="REC-xml"/>, otherwise</p></item><item><p>the value of the <code>$encoding</code> argument is used if present, otherwise</p></item><item><p>the processor <rfc2119>may</rfc2119> use <termref def="implementation-defined">implementation-defined</termref> heuristics to determine the likely encoding,
 :                   otherwise</p></item><item><p>UTF-8 is assumed.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function is a string containing the 
 :             <phrase diff="chg" at="L">string representation</phrase> of the resource retrieved
 :             using the URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1170"/> if <code>$href</code>
 :             contains a fragment identifier, or if it cannot be used to retrieve the 
 :             <phrase diff="chg" at="L">string representation</phrase> of a resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1190"/> <phrase diff="add" at="L">if the value 
 :             of the <code>$encoding</code> argument is not a valid encoding name, </phrase>if the <termref def="dt-processor">processor</termref> does not support the specified encoding,
 :             if the <phrase diff="chg" at="L">string representation</phrase> of the retrieved
 :             resource contains octets that cannot be decoded into Unicode <termref def="character">characters</termref> using the specified encoding, or if the resulting characters
 :             are not permitted XML characters.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1200"/> if
 :                <code>$encoding</code> is absent and the <termref def="dt-processor">processor</termref> cannot infer the encoding using external information and the
 :             encoding is not UTF-8.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text
 :)
declare function fn:unparsed-text($href as xs:string?) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:unparsed-text</code> function reads an external resource (for example, a
 :             file) and returns <phrase diff="chg" at="L">a string representation of the resource</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$href</code> argument <rfc2119>must</rfc2119> be a string in the form of a URI
 :             reference, which <rfc2119>must</rfc2119> contain no fragment identifier, and
 :                <rfc2119>must</rfc2119> identify a resource 
 :             <phrase diff="chg" at="L">for which a string representation is available</phrase>. If the URI is a
 :             relative URI reference, then it is resolved relative to the 
 :             <phrase diff="chg" at="L">Static Base URI property from the static context</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">The mapping of URIs to the string representation of a resource is the mapping defined
 :             in the <xtermref spec="XP30" ref="dt-available-text-resources">available text resources</xtermref>
 :          component of the dynamic context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of the <code>$href</code> argument is an empty sequence, the function
 :             returns an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$encoding</code> argument, if present, is the name of an encoding. The values
 :             for this attribute follow the same rules as for the <code>encoding</code> attribute in
 :             an XML declaration. The only values which every <termref def="implementation">implementation</termref> is <rfc2119>required</rfc2119> to recognize are
 :                <code>utf-8</code> and <code>utf-16</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The encoding of the external resource is determined as follows:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>external encoding information is used if available, otherwise</p></item><item><p>if the media type of the resource is <code>text/xml</code> or
 :                      <code>application/xml</code> (see <bibref ref="rfc2376"/>), or if it matches
 :                   the conventions <code>text/*+xml</code> or <code>application/*+xml</code> (see
 :                      <bibref ref="rfc3023"/> and/or its successors), then the encoding is recognized
 :                   as specified in <bibref ref="REC-xml"/>, otherwise</p></item><item><p>the value of the <code>$encoding</code> argument is used if present, otherwise</p></item><item><p>the processor <rfc2119>may</rfc2119> use <termref def="implementation-defined">implementation-defined</termref> heuristics to determine the likely encoding,
 :                   otherwise</p></item><item><p>UTF-8 is assumed.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function is a string containing the 
 :             <phrase diff="chg" at="L">string representation</phrase> of the resource retrieved
 :             using the URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1170"/> if <code>$href</code>
 :             contains a fragment identifier, or if it cannot be used to retrieve the 
 :             <phrase diff="chg" at="L">string representation</phrase> of a resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1190"/> <phrase diff="add" at="L">if the value 
 :             of the <code>$encoding</code> argument is not a valid encoding name, </phrase>if the <termref def="dt-processor">processor</termref> does not support the specified encoding,
 :             if the <phrase diff="chg" at="L">string representation</phrase> of the retrieved
 :             resource contains octets that cannot be decoded into Unicode <termref def="character">characters</termref> using the specified encoding, or if the resulting characters
 :             are not permitted XML characters.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1200"/> if
 :                <code>$encoding</code> is absent and the <termref def="dt-processor">processor</termref> cannot infer the encoding using external information and the
 :             encoding is not UTF-8.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text
 :)
declare function fn:unparsed-text($href as xs:string?,  $encoding as xs:string) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Because errors in evaluating the <function>fn:unparsed-text</function> function are
 :             non-recoverable, these two functions are provided to allow an application to determine
 :             whether a call with particular arguments would succeed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <function>fn:unparsed-text-available</function> function determines whether a call
 :             on the <function>fn:unparsed-text</function> function with identical arguments would
 :             return a string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the first argument is an empty sequence, the function returns false. <phrase diff="del" at="L">If the second
 :             argument is an empty sequence, the function behaves as if the second argument were
 :             omitted.</phrase></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases, the function returns true if a call on
 :                <function>fn:unparsed-text</function> with the same arguments would succeed, and
 :             false if a call on <function>fn:unparsed-text</function> with the same arguments would
 :             fail with a non-recoverable dynamic error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The functions <function>fn:unparsed-text</function> and
 :                <function>fn:unparsed-text-available</function> have the same requirement for
 :                <termref def="deterministic">determinism</termref> as the functions
 :                <code>fn:doc</code> and <code>fn:doc-available</code>. This means that unless the
 :             user has explicitly stated a requirement for a reduced level of determinism, either of
 :             these functions if called twice with the same arguments during the course of a
 :             transformation <rfc2119>must</rfc2119> return the same results each time; moreover, the
 :             results of a call on <function>fn:unparsed-text-available</function>
 :             <rfc2119>must</rfc2119> be consistent with the results of a subsequent call on
 :                <function>unparsed-text</function> with the same arguments.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This requires that the <function>unparsed-text-available</function> function should
 :             actually attempt to read the resource identified by the URI, and check that it is
 :             correctly encoded and contains no characters that are invalid in XML. Implementations
 :             may avoid the cost of repeating these checks for example by caching the validated
 :             contents of the resource, to anticipate a subsequent call on the
 :                <function>unparsed-text</function>
 :             <phrase diff="add" at="A">or <function>unparsed-text-lines</function>
 :             </phrase> function. Alternatively, implementations may be able to rewrite an expression
 :             such as <code>if (unparsed-text-available(A)) then unparsed-text(A) else ...</code> to
 :             generate a single call internally.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text-available
 :)
declare function fn:unparsed-text-available($href as xs:string?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Because errors in evaluating the <function>fn:unparsed-text</function> function are
 :             non-recoverable, these two functions are provided to allow an application to determine
 :             whether a call with particular arguments would succeed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <function>fn:unparsed-text-available</function> function determines whether a call
 :             on the <function>fn:unparsed-text</function> function with identical arguments would
 :             return a string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the first argument is an empty sequence, the function returns false. <phrase diff="del" at="L">If the second
 :             argument is an empty sequence, the function behaves as if the second argument were
 :             omitted.</phrase></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases, the function returns true if a call on
 :                <function>fn:unparsed-text</function> with the same arguments would succeed, and
 :             false if a call on <function>fn:unparsed-text</function> with the same arguments would
 :             fail with a non-recoverable dynamic error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The functions <function>fn:unparsed-text</function> and
 :                <function>fn:unparsed-text-available</function> have the same requirement for
 :                <termref def="deterministic">determinism</termref> as the functions
 :                <code>fn:doc</code> and <code>fn:doc-available</code>. This means that unless the
 :             user has explicitly stated a requirement for a reduced level of determinism, either of
 :             these functions if called twice with the same arguments during the course of a
 :             transformation <rfc2119>must</rfc2119> return the same results each time; moreover, the
 :             results of a call on <function>fn:unparsed-text-available</function>
 :             <rfc2119>must</rfc2119> be consistent with the results of a subsequent call on
 :                <function>unparsed-text</function> with the same arguments.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This requires that the <function>unparsed-text-available</function> function should
 :             actually attempt to read the resource identified by the URI, and check that it is
 :             correctly encoded and contains no characters that are invalid in XML. Implementations
 :             may avoid the cost of repeating these checks for example by caching the validated
 :             contents of the resource, to anticipate a subsequent call on the
 :                <function>unparsed-text</function>
 :             <phrase diff="add" at="A">or <function>unparsed-text-lines</function>
 :             </phrase> function. Alternatively, implementations may be able to rewrite an expression
 :             such as <code>if (unparsed-text-available(A)) then unparsed-text(A) else ...</code> to
 :             generate a single call internally.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text-available
 :)
declare function fn:unparsed-text-available( $href as xs:string?,  $encoding as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:unparsed-text-lines</code> function reads an external resource (for
 :             example, a file) and returns its contents as a sequence of strings, one for each line of
 :             text in the  <phrase diff="chg" at="L">string representation</phrase> of the resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text-lines" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text-lines" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>unparsed-text-lines</code> function reads an external resource (for example, a
 :             file) and returns its <phrase diff="chg" at="L">string representation</phrase> as a sequence of strings, separated at newline
 :             boundaries. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the single-argument function is the same as the result of the expression
 :                <code>fn:tokenize(fn:unparsed-text($href), '\r\n|\r|\n')[not(position()=last() and
 :                .='')]</code>. The result of the two-argument function is the same as the result of
 :             the expression <code>fn:tokenize(fn:unparsed-text($href, $encoding),
 :                '\r\n|\r|\n'))[not(position()=last() and .='')]</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result is a thus a sequence of strings containing the text of the resource retrieved
 :             using the URI, each string representing one line of text. Lines are separated by one of
 :             the sequences x0A, x0D, or x0Dx0A. The characters representing the newline are not
 :             included in the returned strings. If there are two adjacent newline sequences, a
 :             zero-length string will be returned to represent the empty line; but if the external
 :             resource ends with a newline sequence, no zero-length string will be returned as the
 :             last item in the result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Error conditions are the same as for the <code>fn:unparsed-text</code> function.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text-lines
 :)
declare function fn:unparsed-text-lines($href as xs:string?) as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:unparsed-text-lines</code> function reads an external resource (for
 :             example, a file) and returns its contents as a sequence of strings, one for each line of
 :             text in the  <phrase diff="chg" at="L">string representation</phrase> of the resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text-lines" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text-lines" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>unparsed-text-lines</code> function reads an external resource (for example, a
 :             file) and returns its <phrase diff="chg" at="L">string representation</phrase> as a sequence of strings, separated at newline
 :             boundaries. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the single-argument function is the same as the result of the expression
 :                <code>fn:tokenize(fn:unparsed-text($href), '\r\n|\r|\n')[not(position()=last() and
 :                .='')]</code>. The result of the two-argument function is the same as the result of
 :             the expression <code>fn:tokenize(fn:unparsed-text($href, $encoding),
 :                '\r\n|\r|\n'))[not(position()=last() and .='')]</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result is a thus a sequence of strings containing the text of the resource retrieved
 :             using the URI, each string representing one line of text. Lines are separated by one of
 :             the sequences x0A, x0D, or x0Dx0A. The characters representing the newline are not
 :             included in the returned strings. If there are two adjacent newline sequences, a
 :             zero-length string will be returned to represent the empty line; but if the external
 :             resource ends with a newline sequence, no zero-length string will be returned as the
 :             last item in the result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Error conditions are the same as for the <code>fn:unparsed-text</code> function.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text-lines
 :)
declare function fn:unparsed-text-lines( $href as xs:string?,  $encoding as xs:string) as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Converts a string to upper case.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="upper-case" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is the empty sequence, the zero-length string is
 :             returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of <code>$arg</code> after translating every
 :                <termref def="character">character</termref> to its upper-case correspondent as
 :             defined in the appropriate case mappings section in the Unicode standard <bibref ref="Unicode"/>. For versions of Unicode beginning with the 2.1.8 update, only
 :             locale-insensitive case mappings should be applied. Beginning with version 3.2.0 (and
 :             likely future versions) of Unicode, precise mappings are described in default case
 :             operations, which are full case mappings in the absence of tailoring for particular
 :             languages and environments. Every lower-case character that does not have an upper-case
 :             correspondent, as well as every upper-case character, is included in the returned value
 :             in its original form. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Case mappings may change the length of a string. In general, the
 :                <code>fn:upper-case</code> and <code>fn:lower-case</code> functions are not inverses
 :             of each other: <code>fn:lower-case(fn:upper-case($arg))</code> is not guaranteed to
 :             return <code>$arg</code>, nor is <code>fn:upper-case(fn:lower-case($arg))</code>. The
 :             Latin small letter dotless i (as used in Turkish) is perhaps the most prominent
 :             lower-case letter which will not round-trip. The Latin capital letter i with dot above
 :             is the most prominent upper-case letter which will not round trip; there are others,
 :             such as Latin capital letter Sharp S (#1E9E) which is introduced in Unicode 5.1.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> These functions may not always be linguistically appropriate (e.g. Turkish i without
 :             dot) or appropriate for the application (e.g. titlecase). In cases such as Turkish, a
 :             simple translation should be used first.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> Because the function is not sensitive to locale, results will not always match user
 :             expectations. In Quebec, for example, the standard uppercase equivalent of "è" is "È",
 :             while in metropolitan France it is more commonly "E"; only one of these is supported by
 :             the functions as defined.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> Many characters of class Ll lack uppercase equivalents in the Unicode case mapping
 :             tables; many characters of class Lu lack lowercase equivalents.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-upper-case
 :)
declare function fn:upper-case($arg as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of <code>xs:anyURI</code> values representing the URIs in a resource collection.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available resource collections, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of the function returns the URIs in the <term>Default resource collection</term>
 :             described in <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is a relative <code>xs:anyURI</code>, it is resolved
 :             against the value of the base-URI property from the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function behaves as if it had been
 :             called without an argument. See above.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The single-argument form of the function returns the sequence of URIs corresponding to the 
 :             supplied URI in the <term>Available resource collections</term> described in 
 :             <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if no URI is supplied (that is, if the
 :             the function is called with no arguments, or with a single argument that evaluates to an empty sequence), and the
 :             value of the default resource collection is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="J">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> 
 :             if <term>available resource collections</term> provides no mapping for the absolutized URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0004"/> if <code>$arg</code> is not a
 :             valid <code>xs:anyURI</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-uri-collection
 :)
declare function fn:uri-collection() as  xs:anyURI* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of <code>xs:anyURI</code> values representing the URIs in a resource collection.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available resource collections, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of the function returns the URIs in the <term>Default resource collection</term>
 :             described in <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is a relative <code>xs:anyURI</code>, it is resolved
 :             against the value of the base-URI property from the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function behaves as if it had been
 :             called without an argument. See above.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The single-argument form of the function returns the sequence of URIs corresponding to the 
 :             supplied URI in the <term>Available resource collections</term> described in 
 :             <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if no URI is supplied (that is, if the
 :             the function is called with no arguments, or with a single argument that evaluates to an empty sequence), and the
 :             value of the default resource collection is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="J">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> 
 :             if <term>available resource collections</term> provides no mapping for the absolutized URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0004"/> if <code>$arg</code> is not a
 :             valid <code>xs:anyURI</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-uri-collection
 :)
declare function fn:uri-collection($arg as xs:string?) as  xs:anyURI* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the year component of an <code>xs:date</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="year-from-date" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:date?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> representing the year in the
 :             local value of <code>$arg</code>. The value may be negative. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:year-from-date(xs:date("1999-05-31"))</code> returns <code>1999</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:year-from-date(xs:date("2000-01-01+05:00"))</code> returns <code>2000</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-year-from-date
 :)
declare function fn:year-from-date($arg as xs:date?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the number of years in a duration.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="years-from-duration" return-type="xs:integer?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:duration?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns an <code>xs:integer</code> representing the years
 :             component in the value of <code>$arg</code>. The result is obtained by casting
 :                <code>$arg</code> to an <code>xs:yearMonthDuration</code> (see <specref ref="casting-to-durations"/>) and then computing the years component as described in
 :                <specref ref="canonical-yearMonthDuration"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a negative duration then the result will be negative..</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an <code>xs:dayTimeDuration</code> the function returns 0.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:years-from-duration(xs:yearMonthDuration("P20Y15M"))</code> returns <code>21</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:years-from-duration(xs:yearMonthDuration("-P15M"))</code> returns <code>-1</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:years-from-duration(xs:dayTimeDuration("-P2DT15H"))</code> returns <code>0</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-years-from-duration
 :)
declare function fn:years-from-duration($arg as xs:duration?) as  xs:integer? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns <code>$arg</code> if it contains zero or one items. Otherwise, raises
 :             an error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="zero-or-one" return-type="item()?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Except in error cases, the function returns <code>$arg</code> unchanged.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="del" at="F">For detailed type semantics, see [Formal Semantics].</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0003"/> if <code>$arg</code> contains more
 :             than one item.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-zero-or-one
 :)
declare function fn:zero-or-one($arg as item()*) as  item()? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Creates an <code>xs:string</code> from a sequence of <termref def="codepoint">codepoints</termref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="codepoints-to-string" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:integer*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the string made up from the <termref def="character">characters</termref> whose Unicode <termref def="codepoint">codepoints</termref> are
 :             supplied in <code>$arg</code>. This will be the zero-length string if <code>$arg</code>
 :             is the empty sequence. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <errorref class="CH" code="0001"/> if any of the codepoints in
 :                <code>$arg</code> is not a permitted XML character.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-codepoints-to-string
 :)
declare function fn:codepoints-to-string($arg as xs:integer*) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the sequence of <termref def="codepoint">codepoints</termref> that
 :             constitute an <code>xs:string</code> value. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string-to-codepoints" return-type="xs:integer*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of integers, each integer being the Unicode <termref def="codepoint">codepoints</termref> of the corresponding <termref def="character">character</termref> in <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a zero-length string or the empty sequence, the function returns
 :             the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>fn:string-to-codepoints("Thérèse")</code> returns <code>(84, 104, 233, 114, 232, 115, 101)</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string-to-codepoints
 :)
declare function fn:string-to-codepoints($arg as xs:string?) as  xs:integer* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the base URI of a node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="base-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="base-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">The zero-argument version of the function returns the base URI of the
 :             context node: it is equivalent to calling <code>fn:base-uri(.)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">The single-argument version of the function behaves as follows:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item>If <code>$arg</code> is the empty sequence, the function returns the empty
 :                sequence.</item><item>Otherwise, the function returns the value of the <code>dm:base-uri</code> accessor
 :                applied to the node <code>$arg</code>. This accessor is defined, for each kind of
 :                node, in the XDM specification (See <xspecref spec="DM30" ref="dm-base-uri"/>).</item></olist><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">As explained in XDM, document, element and processing-instruction nodes have a
 :             base-uri property which may be empty. The base-uri property for all other node kinds is
 :             the empty sequence. The dm:base-uri accessor returns the base-uri property of a node if
 :             it exists and is non-empty; otherwise it returns the result of applying the dm:base-uri
 :             accessor to its parent, recursively. If the node does not have a parent, or if the
 :             recursive ascent up the ancestor chain encounters a parentless node whose base-uri
 :             property is empty, the empty sequence is returned. In the case of namespace nodes,
 :             however, the result is always an empty sequence -- it does not depend on the base URI of
 :             the parent element.</note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See also <code>fn:static-base-uri</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-base-uri
 :)
declare function fn:base-uri() as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the base URI of a node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="base-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="base-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">The zero-argument version of the function returns the base URI of the
 :             context node: it is equivalent to calling <code>fn:base-uri(.)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">The single-argument version of the function behaves as follows:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item>If <code>$arg</code> is the empty sequence, the function returns the empty
 :                sequence.</item><item>Otherwise, the function returns the value of the <code>dm:base-uri</code> accessor
 :                applied to the node <code>$arg</code>. This accessor is defined, for each kind of
 :                node, in the XDM specification (See <xspecref spec="DM30" ref="dm-base-uri"/>).</item></olist><note xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">As explained in XDM, document, element and processing-instruction nodes have a
 :             base-uri property which may be empty. The base-uri property for all other node kinds is
 :             the empty sequence. The dm:base-uri accessor returns the base-uri property of a node if
 :             it exists and is non-empty; otherwise it returns the result of applying the dm:base-uri
 :             accessor to its parent, recursively. If the node does not have a parent, or if the
 :             recursive ascent up the ancestor chain encounters a parentless node whose base-uri
 :             property is empty, the empty sequence is returned. In the case of namespace nodes,
 :             however, the result is always an empty sequence -- it does not depend on the base URI of
 :             the parent element.</note><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See also <code>fn:static-base-uri</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-base-uri
 :)
declare function fn:base-uri($arg as node()?) as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the current date.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="current-date" return-type="xs:date" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns <code>xs:date(fn:current-dateTime())</code>. This is an <code>xs:date</code>
 :             (with timezone) that is current at some time during the evaluation of a query or
 :             transformation in which <code>fn:current-date</code> is executed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic"/>. The precise instant during the query or
 :             transformation represented by the value of <code>fn:current-date</code> is <termref def="implementation-dependent"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The returned date will always have an associated timezone, which will always be the same
 :             as the implicit timezone in the dynamic context</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-current-date
 :)
declare function fn:current-date() as  xs:date external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the current date and time (with timezone).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="current-dateTime" return-type="xs:dateTimeStamp" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the current dateTime (with timezone) from the dynamic context. (See <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.) This is an
 :                <code>xs:dateTime</code> that is current at some time during the evaluation of a
 :             query or transformation in which <code>fn:current-dateTime</code> is executed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic"/>. The precise instant during the query or
 :             transformation represented by the value of <code>fn:current-dateTime()</code> is
 :                <termref def="implementation-dependent"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A">If the implementation supports data types from XSD 1.1 then the
 :             returned value will be an instance of <code>xs:dateTimeStamp</code>. Otherwise, the only
 :             guarantees are that it will be an instance of <code>xs:dateTime</code> and will have a
 :             timezone component.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The returned <code>xs:dateTime</code> will always have an associated timezone, which
 :             will always be the same as the implicit timezone in the dynamic context</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-current-dateTime
 :)
declare function fn:current-dateTime() as  xs:dateTimeStamp external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the current time.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="current-time" return-type="xs:time" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns <code>xs:time(fn:current-dateTime())</code>. This is an <code>xs:time</code>
 :             (with timezone) that is current at some time during the evaluation of a query or
 :             transformation in which <code>fn:current-time</code> is executed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic"/>. The precise instant during the query or
 :             transformation represented by the value of <code>fn:current-time()</code> is <termref def="implementation-dependent"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The returned time will always have an associated timezone, which will always be the same
 :             as the implicit timezone in the dynamic context</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-current-time
 :)
declare function fn:current-time() as  xs:time external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the result of atomizing a sequence, that is, replacing all nodes in the
 :             sequence by their typed values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="data" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="data" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">If the argument is omitted, it defaults to the context item
 :                (<code>.</code>). The behavior of the function if the argument is omitted is exactly
 :             the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> The result of <code>fn:data</code> is the sequence of atomic values produced by
 :             applying the following rules to each item in <code>$arg</code>:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the item is an atomic value, it is appended to the result sequence.</p></item><item><p> If the item is a node, the typed value of the node is appended to the result
 :                   sequence. The typed value is a sequence of zero or more atomic values:
 :                   specifically, the result of the <code>dm:typed-value</code> accessor as defined in
 :                      <bibref ref="xpath-datamodel-30"/> (See <xspecref spec="DM30" ref="dm-typed-value"/>).</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0012" type="type"/> if an item in the
 :             sequence <code>$arg</code> is a node that does not have a typed value. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0013" type="dynamic"/>
 :             if an item in the sequence <code>$arg</code> is a function item. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">A <phrase diff="add" at="M">dynamic</phrase> error is raised 
 :             if <code>$arg</code> is omitted
 :             and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-data
 :)
declare function fn:data() as  xs:anyAtomicType* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the result of atomizing a sequence, that is, replacing all nodes in the
 :             sequence by their typed values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="data" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="data" return-type="xs:anyAtomicType*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">If the argument is omitted, it defaults to the context item
 :                (<code>.</code>). The behavior of the function if the argument is omitted is exactly
 :             the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> The result of <code>fn:data</code> is the sequence of atomic values produced by
 :             applying the following rules to each item in <code>$arg</code>:</p><ulist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>If the item is an atomic value, it is appended to the result sequence.</p></item><item><p> If the item is a node, the typed value of the node is appended to the result
 :                   sequence. The typed value is a sequence of zero or more atomic values:
 :                   specifically, the result of the <code>dm:typed-value</code> accessor as defined in
 :                      <bibref ref="xpath-datamodel-30"/> (See <xspecref spec="DM30" ref="dm-typed-value"/>).</p></item></ulist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0012" type="type"/> if an item in the
 :             sequence <code>$arg</code> is a node that does not have a typed value. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="B">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0013" type="dynamic"/>
 :             if an item in the sequence <code>$arg</code> is a function item. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">A <phrase diff="add" at="M">dynamic</phrase> error is raised 
 :             if <code>$arg</code> is omitted
 :             and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-data
 :)
declare function fn:data($arg as item()*) as  xs:anyAtomicType* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of the default collation property from the static context.
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="default-collation" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		collations.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of the default collation property from the static context. Components
 :             of the static context are discussed in <xspecref spec="XP30" ref="id-xp-static-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The default collation property can never be absent. If it is not explicitly defined, a
 :             system defined default can be invoked. If this is not provided, the Unicode codepoint
 :             collation (<code>http://www.w3.org/2005/xpath-functions/collation/codepoint</code>) is
 :             used. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-default-collation
 :)
declare function fn:default-collation() as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the URI of a resource where a document can be found, if available.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="document-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="document-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">If the argument is omitted, it defaults to the context item
 :                (<code>.</code>). The behavior of the function if the argument is omitted is exactly
 :             the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is not a document node, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of the <code>document-uri</code> accessor
 :             applied to <code>$arg</code>, as defined in <bibref ref="xpath-datamodel-30"/> (See
 :                <xspecref spec="DM30" ref="DocumentNodeAccessors"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-document-uri
 :)
declare function fn:document-uri() as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the URI of a resource where a document can be found, if available.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="document-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="document-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">If the argument is omitted, it defaults to the context item
 :                (<code>.</code>). The behavior of the function if the argument is omitted is exactly
 :             the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is not a document node, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of the <code>document-uri</code> accessor
 :             applied to <code>$arg</code>, as defined in <bibref ref="xpath-datamodel-30"/> (See
 :                <xspecref spec="DM30" ref="DocumentNodeAccessors"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-document-uri
 :)
declare function fn:document-uri($arg as node()?) as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Encodes reserved characters in a string that is intended to be used in the path
 :             segment of a URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="encode-for-uri" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="uri-part" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$uri-part</code> is the empty sequence, the function returns the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function applies the URI escaping rules defined in section 2 of <bibref ref="rfc3986"/> to the <code>xs:string</code> supplied as <code>$uri-part</code>. The
 :             effect of the function is to escape reserved characters. Each such character in the
 :             string is replaced with its percent-encoded form as described in <bibref ref="rfc3986"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Since <bibref ref="rfc3986"/> recommends that, for consistency, URI producers and
 :             normalizers should use uppercase hexadecimal digits for all percent-encodings, this
 :             function must always generate hexadecimal values using the upper-case letters A-F.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">All characters are escaped except those identified as "unreserved" by <bibref ref="rfc3986"/>, that is the upper- and lower-case letters A-Z, the digits 0-9,
 :             HYPHEN-MINUS ("-"), LOW LINE ("_"), FULL STOP ".", and TILDE "~".</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function escapes URI delimiters and therefore cannot be used indiscriminately to
 :             encode "invalid" characters in a path segment.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is invertible but not idempotent. This is because a string containing a
 :             percent character will be modified by applying the function: for example
 :                <code>100%</code> becomes <code>100%25</code>, while <code>100%25</code> becomes
 :                <code>100%2525</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-encode-for-uri
 :)
declare function fn:encode-for-uri($uri-part as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Escapes a URI in the same way that HTML user agents handle attribute values
 :             expected to contain URIs.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="escape-html-uri" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="uri" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$uri</code> is the empty sequence, the function returns the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function escapes all <termref def="character">characters</termref> except
 :             printable characters of the US-ASCII coded character set, specifically the <termref def="codepoint">codepoints</termref> between 32 and 126 (decimal) inclusive. Each
 :             character in <code>$uri</code> to be escaped is replaced by an escape sequence, which is
 :             formed by encoding the character as a sequence of octets in UTF-8, and then representing
 :             each of these octets in the form %HH, where HH is the hexadecimal representation of the
 :             octet. This function must always generate hexadecimal values using the upper-case
 :             letters A-F.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The behavior of this function corresponds to the recommended handling of non-ASCII
 :             characters in URI attribute values as described in <bibref ref="HTML40"/> Appendix
 :             B.2.1.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-escape-html-uri
 :)
declare function fn:escape-html-uri($uri as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the supplied node has one or more child nodes (of any kind).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="has-children" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="has-children" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="node" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><phrase diff="add" at="L">Provided that the supplied argument <code>$node</code> matches the expected 
 :          type <code>node()?</code>, </phrase>the result of the function call <code>fn:has-children($node)</code> is defined to be
 :             the same as the result of the expression
 :             <code>fn:exists($node/child::node())</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$node</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-has-children
 :)
declare function fn:has-children() as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true if the supplied node has one or more child nodes (of any kind).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="has-children" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="has-children" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="node" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><phrase diff="add" at="L">Provided that the supplied argument <code>$node</code> matches the expected 
 :          type <code>node()?</code>, </phrase>the result of the function call <code>fn:has-children($node)</code> is defined to be
 :             the same as the result of the expression
 :             <code>fn:exists($node/child::node())</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$node</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-has-children
 :)
declare function fn:has-children($node as node()?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of the implicit timezone property from the dynamic context.
 :          </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="implicit-timezone" return-type="xs:dayTimeDuration" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		implicit timezone.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of the implicit timezone property from the dynamic context. Components
 :             of the dynamic context are discussed in <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-implicit-timezone
 :)
declare function fn:implicit-timezone() as  xs:dayTimeDuration external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns every node within the input sequence that is not an ancestor of another member
 :             of the input sequence; the nodes are returned in document order with duplicates
 :             eliminated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="innermost" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="nodes" type="node()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of the function call <code>fn:innermost($nodes)</code> is defined to be
 :             equivalent to the result of the expression <code>$nodes except
 :                $nodes/ancestor::node()</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">That is, the function takes as input a sequence of nodes, and returns every node within
 :             the sequence that is not an ancestor of another node within the sequence; the nodes are
 :             returned in document order with duplicates eliminated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the source document contains nested sections represented by <code>div</code>
 :                elements, the expression <code>innermost(//div)</code> returns those <code>div</code>
 :                elements that do not contain further <code>div</code> elements.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-innermost
 :)
declare function fn:innermost($nodes as node()*) as  node()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Converts a string containing an IRI into a URI according to the rules of
 :                <bibref ref="rfc3987"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="iri-to-uri" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="iri" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$iri</code> is the empty sequence, the function returns the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function converts the value of <code>$iri</code> into a URI according to
 :             the rules given in Section 3.1 of <bibref ref="rfc3987"/> by percent-encoding characters
 :             that are allowed in an IRI but not in a URI. If <code>$iri</code> contains a character
 :             that is invalid in an IRI, such as the space character (see note below), the invalid
 :             character is replaced by its percent-encoded form as described in <bibref ref="rfc3986"/> before the conversion is performed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Since <bibref ref="rfc3986"/> recommends that, for consistency, URI producers and
 :             normalizers should use uppercase hexadecimal digits for all percent-encodings, this
 :             function must always generate hexadecimal values using the upper-case letters A-F.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is idempotent but not invertible. Both the inputs <code>My Documents</code>
 :             and <code>My%20Documents</code> will be converted to the output
 :                <code>My%20Documents</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function does not check whether <code>$iri</code> is a valid IRI. It treats it as
 :             an <termref def="string">string</termref> and operates on the <termref def="character">characters</termref> in the string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> The following printable ASCII characters are invalid in an IRI: "&lt;", "&gt;", <quote>
 :                " </quote> (double quote), space, "{", "}", "|", "\", "^", and "`". Since these
 :             characters should not appear in an IRI, if they do appear in <code>$iri</code> they will
 :             be percent-encoded. In addition, characters outside the range x20-<phrase diff="chg" at="A-E8">x7E</phrase> will be percent-encoded because they are invalid in a URI. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"> Since this function does not escape the PERCENT SIGN "%" and this character is not
 :             allowed in data within a URI, users wishing to convert character strings (such as file
 :             names) that include "%" to a URI should manually escape "%" by replacing it with "%25".
 :          </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-iri-to-uri
 :)
declare function fn:iri-to-uri($iri as xs:string?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function tests whether the language of <code>$node</code>, or the context
 :             item if the second argument is omitted, as specified by <code>xml:lang</code> attributes
 :             is the same as, or is a sublanguage of, the language specified by
 :             <code>$testlang</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="lang" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="testlang" type="xs:string?"/></proto></example><example role="signature"><proto name="lang" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="testlang" type="xs:string?"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The behavior of the function if the second argument is omitted is exactly the same as if
 :             the context item (<code>.</code>) had been passed as the second argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The language of the argument <code>$node</code>, or the context item if the second
 :             argument is omitted, is determined by the value of the <code>xml:lang</code> attribute
 :             on the node, or, if the node has no such attribute, by the value of the
 :                <code>xml:lang</code> attribute on the nearest ancestor of the node that has an
 :                <code>xml:lang</code> attribute. If there is no such ancestor, then the function
 :             returns <code>false</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$testlang</code> is the empty sequence it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The relevant <code>xml:lang</code> attribute is determined by the value of the XPath
 :             expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">(ancestor-or-self::*/@xml:lang)[last()]</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If this expression returns an empty sequence, the function returns <code>false</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns <code>true</code> if and only if, based on a caseless
 :             default match as specified in section 3.13 of <bibref ref="Unicode"/>, either:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p diff="chg" at="A-E16">
 :                   <code>$testlang</code> is equal to the string-value of the relevant
 :                      <code>xml:lang</code> attribute, or</p></item><item><p diff="chg" at="A-E16">
 :                   <code>$testlang</code> is equal to some substring of the string-value of the
 :                   relevant <code>xml:lang</code> attribute that starts at the start of the
 :                   string-value and ends immediately before a hyphen, "-" (the character "-" is
 :                   HYPHEN-MINUS, #x002D).</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-lang
 :)
declare function fn:lang($testlang as xs:string?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function tests whether the language of <code>$node</code>, or the context
 :             item if the second argument is omitted, as specified by <code>xml:lang</code> attributes
 :             is the same as, or is a sublanguage of, the language specified by
 :             <code>$testlang</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="lang" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="testlang" type="xs:string?"/></proto></example><example role="signature"><proto name="lang" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="testlang" type="xs:string?"/><arg name="node" type="node()"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The behavior of the function if the second argument is omitted is exactly the same as if
 :             the context item (<code>.</code>) had been passed as the second argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The language of the argument <code>$node</code>, or the context item if the second
 :             argument is omitted, is determined by the value of the <code>xml:lang</code> attribute
 :             on the node, or, if the node has no such attribute, by the value of the
 :                <code>xml:lang</code> attribute on the nearest ancestor of the node that has an
 :                <code>xml:lang</code> attribute. If there is no such ancestor, then the function
 :             returns <code>false</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$testlang</code> is the empty sequence it is interpreted as the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The relevant <code>xml:lang</code> attribute is determined by the value of the XPath
 :             expression:</p><pre highlight-as="xquery" xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" xml:space="preserve">(ancestor-or-self::*/@xml:lang)[last()]</pre><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If this expression returns an empty sequence, the function returns <code>false</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns <code>true</code> if and only if, based on a caseless
 :             default match as specified in section 3.13 of <bibref ref="Unicode"/>, either:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p diff="chg" at="A-E16">
 :                   <code>$testlang</code> is equal to the string-value of the relevant
 :                      <code>xml:lang</code> attribute, or</p></item><item><p diff="chg" at="A-E16">
 :                   <code>$testlang</code> is equal to some substring of the string-value of the
 :                   relevant <code>xml:lang</code> attribute that starts at the start of the
 :                   string-value and ends immediately before a hyphen, "-" (the character "-" is
 :                   HYPHEN-MINUS, #x002D).</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-lang
 :)
declare function fn:lang($testlang as xs:string?,  $node as node()) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the context size from the dynamic context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="last" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the context size from the dynamic context. (See <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.)</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <xerrorref spec="XP" class="DY" code="0002" type="type"/> if the
 :             context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-last
 :)
declare function fn:last() as  xs:integer external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the local part of the name of <code>$arg</code> as an
 :                <code>xs:string</code> that is either the zero-length string, or has the lexical form
 :             of an <code>xs:NCName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="local-name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="local-name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is supplied and is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the node identified by <code>$arg</code> has no name (that is, if it is a document
 :             node, a comment, a text node, or a namespace node having no name), the function returns
 :             the zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the local part of the expanded-QName of the node
 :             identified by <code>$arg</code>, as determined by the <code>dm:node-name</code> accessor
 :             defined in <xspecref spec="DM30" ref="dm-node-name"/>). This will be an
 :                <code>xs:string</code> whose lexical form is an <code>xs:NCName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-local-name
 :)
declare function fn:local-name() as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the local part of the name of <code>$arg</code> as an
 :                <code>xs:string</code> that is either the zero-length string, or has the lexical form
 :             of an <code>xs:NCName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="local-name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="local-name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is supplied and is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the node identified by <code>$arg</code> has no name (that is, if it is a document
 :             node, a comment, a text node, or a namespace node having no name), the function returns
 :             the zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the local part of the expanded-QName of the node
 :             identified by <code>$arg</code>, as determined by the <code>dm:node-name</code> accessor
 :             defined in <xspecref spec="DM30" ref="dm-node-name"/>). This will be an
 :                <code>xs:string</code> whose lexical form is an <code>xs:NCName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-local-name
 :)
declare function fn:local-name($arg as node()?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the name of a node, as an <code>xs:string</code> that is either the
 :             zero-length string, or has the lexical form of an <code>xs:QName</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is supplied and is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the node identified by <code>$arg</code> has no name (that is, if it is a document
 :             node, a comment, a text node, or a namespace node having no name), the function returns
 :             the zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of the expression
 :                <code>fn:string(fn:node-name($arg))</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-name
 :)
declare function fn:name() as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the name of a node, as an <code>xs:string</code> that is either the
 :             zero-length string, or has the lexical form of an <code>xs:QName</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="name" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is supplied and is the empty sequence, the function returns the
 :             zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the node identified by <code>$arg</code> has no name (that is, if it is a document
 :             node, a comment, a text node, or a namespace node having no name), the function returns
 :             the zero-length string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the value of the expression
 :                <code>fn:string(fn:node-name($arg))</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-name
 :)
declare function fn:name($arg as node()?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E15">Returns the namespace URI part of the name of
 :                <code>$arg</code>, as an <code>xs:anyURI</code> value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="namespace-uri" return-type="xs:anyURI" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="namespace-uri" return-type="xs:anyURI" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context node (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the node identified by <code>$arg</code> is neither an element nor an attribute node,
 :             or if it is an element or attribute node whose expanded-QName (as determined by the
 :                <code>dm:node-name</code> accessor in the <xspecref spec="DM30" ref="dm-node-name"/>)
 :             is in no namespace, then the function returns the zero-length <code>xs:anyURI</code>
 :             value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the result will be the namespace URI part of the expanded-QName of the node
 :             identified by <code>$arg</code>, as determined by the <code>dm:node-name</code> accessor
 :             defined in <xspecref spec="DM30" ref="dm-node-name"/>), returned as an
 :                <code>xs:anyURI</code> value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-namespace-uri
 :)
declare function fn:namespace-uri() as  xs:anyURI external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="A-E15">Returns the namespace URI part of the name of
 :                <code>$arg</code>, as an <code>xs:anyURI</code> value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="namespace-uri" return-type="xs:anyURI" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="namespace-uri" return-type="xs:anyURI" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context node (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the node identified by <code>$arg</code> is neither an element nor an attribute node,
 :             or if it is an element or attribute node whose expanded-QName (as determined by the
 :                <code>dm:node-name</code> accessor in the <xspecref spec="DM30" ref="dm-node-name"/>)
 :             is in no namespace, then the function returns the zero-length <code>xs:anyURI</code>
 :             value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the result will be the namespace URI part of the expanded-QName of the node
 :             identified by <code>$arg</code>, as determined by the <code>dm:node-name</code> accessor
 :             defined in <xspecref spec="DM30" ref="dm-node-name"/>), returned as an
 :                <code>xs:anyURI</code> value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-namespace-uri
 :)
declare function fn:namespace-uri($arg as node()?) as  xs:anyURI external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true for an element that is <term>nilled</term>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="nilled" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="nilled" return-type="xs:boolean?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise the function returns the result of the <code>dm:nilled</code> accessor as
 :             defined in <bibref ref="xpath-datamodel-30"/> (see <xspecref spec="DM30" ref="dm-nilled"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-nilled
 :)
declare function fn:nilled() as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns true for an element that is <term>nilled</term>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="nilled" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="nilled" return-type="xs:boolean?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the argument is omitted, it defaults to the context item (<code>.</code>). The
 :             behavior of the function if the argument is omitted is exactly the same as if the
 :             context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise the function returns the result of the <code>dm:nilled</code> accessor as
 :             defined in <bibref ref="xpath-datamodel-30"/> (see <xspecref spec="DM30" ref="dm-nilled"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-nilled
 :)
declare function fn:nilled($arg as node()?) as  xs:boolean? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the name of a node, as an <code>xs:QName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="node-name" return-type="xs:QName?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="node-name" return-type="xs:QName?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">If the argument is omitted, it defaults to the context item
 :                (<code>.</code>). The behavior of the function if the argument is omitted is exactly
 :             the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the result of the <code>dm:node-name</code> accessor as
 :             defined in <bibref ref="xpath-datamodel-30"/> (see <xspecref spec="DM30" ref="dm-node-name"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-node-name
 :)
declare function fn:node-name() as  xs:QName? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the name of a node, as an <code>xs:QName</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="node-name" return-type="xs:QName?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="node-name" return-type="xs:QName?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="F">If the argument is omitted, it defaults to the context item
 :                (<code>.</code>). The behavior of the function if the argument is omitted is exactly
 :             the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function returns the result of the <code>dm:node-name</code> accessor as
 :             defined in <bibref ref="xpath-datamodel-30"/> (see <xspecref spec="DM30" ref="dm-node-name"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-node-name
 :)
declare function fn:node-name($arg as node()?) as  xs:QName? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value indicated by <code>$arg</code> or, if <code>$arg</code> is
 :             not specified, the context item after atomization, converted to an
 :                <code>xs:double</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="number" return-type="xs:double" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="number" return-type="xs:double" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the zero-argument version of the function is defined to give the same result as
 :             calling the single-argument version with the context item (<code>.</code>). That is,
 :                <code>fn:number()</code> is equivalent to <code>fn:number(.)</code>, as
 :          defined by the rules that follow.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence or if <code>$arg</code> <phrase diff="del" at="L">or the context item</phrase>
 :             cannot be converted to an <code>xs:double</code>, the <code>xs:double</code> value
 :                <code>NaN</code> is returned. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, <code>$arg</code> <phrase diff="del" at="L">, or the context item after atomization,</phrase> is converted to an
 :                <code>xs:double</code> following the rules of <specref ref="casting-to-double"/>. If
 :             the conversion to <code>xs:double</code> fails, the <code>xs:double</code> value
 :                <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/> if
 :                <code>$arg</code> is omitted and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">As a consequence of the rules given above, a type error occurs if the context
 :          item cannot be atomized, or if the result of atomizing the context item is a sequence containing
 :          more than one atomic value.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-number
 :)
declare function fn:number() as  xs:double external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value indicated by <code>$arg</code> or, if <code>$arg</code> is
 :             not specified, the context item after atomization, converted to an
 :                <code>xs:double</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="number" return-type="xs:double" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="number" return-type="xs:double" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:anyAtomicType?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Calling the zero-argument version of the function is defined to give the same result as
 :             calling the single-argument version with the context item (<code>.</code>). That is,
 :                <code>fn:number()</code> is equivalent to <code>fn:number(.)</code>, as
 :          defined by the rules that follow.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence or if <code>$arg</code> <phrase diff="del" at="L">or the context item</phrase>
 :             cannot be converted to an <code>xs:double</code>, the <code>xs:double</code> value
 :                <code>NaN</code> is returned. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, <code>$arg</code> <phrase diff="del" at="L">, or the context item after atomization,</phrase> is converted to an
 :                <code>xs:double</code> following the rules of <specref ref="casting-to-double"/>. If
 :             the conversion to <code>xs:double</code> fails, the <code>xs:double</code> value
 :                <code>NaN</code> is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/> if
 :                <code>$arg</code> is omitted and the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">As a consequence of the rules given above, a type error occurs if the context
 :          item cannot be atomized, or if the result of atomizing the context item is a sequence containing
 :          more than one atomic value.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-number
 :)
declare function fn:number($arg as xs:anyAtomicType?) as  xs:double external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns every node within the input sequence that has no ancestor that is itself a
 :             member of the input sequence; the nodes are returned in document order with duplicates
 :             eliminated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="outermost" return-type="node()*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="nodes" type="node()*"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The effect of the function call <code>fn:outermost($nodes)</code> is defined to be
 :             equivalent to the result of the expression <code diff="chg" at="L">$nodes[not(ancestor::node() intersect
 :                $nodes)]/.</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">That is, the function takes as input a sequence of nodes, and returns every node within
 :             the sequence that <phrase diff="chg" at="J">does not have another node within the sequence as an ancestor</phrase>; the nodes are
 :             returned in document order with duplicates eliminated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The formulation <code>$nodes except $nodes/descendant::node()</code> might appear to be
 :             simpler, but does not correctly account for attribute nodes, as these are not
 :             descendants of their parent element.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The motivation for the function was based on XSLT streaming use cases. There are cases
 :             where the <bibref ref="xslt-30"/> streaming rules allow the construct
 :                <code>outermost(//section)</code> but do not allow <code>//section</code>; the
 :             function can therefore be useful in cases where it is known that sections will not be
 :             nested, as well as cases where the application actually wishes to process all sections
 :             except those that are nested within another.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-outermost
 :)
declare function fn:outermost($nodes as node()*) as  node()* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the context position from the dynamic context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="position" return-type="xs:integer" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the context position from the dynamic context. (See <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.)</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <xerrorref spec="XP" class="DY" code="0002" type="type"/> if the
 :             context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-position
 :)
declare function fn:position() as  xs:integer external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Resolves a relative IRI reference against an absolute IRI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="resolve-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="relative" type="xs:string?"/></proto></example><example role="signature"><proto name="resolve-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="relative" type="xs:string?"/><arg name="base" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the second argument is absent, the effect is the same as calling the two-argument
 :             function with the value of <code>fn:static-base-uri()</code> as the second argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is defined to operate on IRI references as defined in <bibref ref="rfc3987"/>, and the implementation <rfc2119>must</rfc2119> permit all arguments that are valid
 :             according to that specification. In addition, the implementation <rfc2119>may</rfc2119>
 :             accept some or all strings that conform to the rules for (absolute or relative) Legacy
 :             Extended IRI references as defined in <bibref ref="LEIRI"/>. For the purposes of this
 :             section, the terms IRI and IRI reference include these extensions, insofar as the
 :             implementation chooses to support them.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$relative</code> is the empty sequence, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$relative</code> is an absolute IRI (as defined above), then it is returned
 :             unchanged.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function resolves the relative IRI reference <code>$relative</code>
 :             against the base IRI <code>$base</code> using the algorithm defined in <bibref ref="rfc3986"/>, adapted by treating any <termref def="character">character</termref>
 :             that would not be valid in an RFC3986 URI or relative reference in the same way that
 :             RFC3986 treats unreserved characters. No percent-encoding takes place.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first form of this function resolves <code>$relative</code> against the value of the
 :             base-uri property from the static context. A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="NS" code="0005"/> if the base-uri property is not initialized in the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0002"/> if <code>$relative</code> is not a
 :             valid IRI according to the rules of RFC3987, extended with an implementation-defined
 :             subset of the extensions permitted in LEIRI, or if it is not a suitable relative
 :             reference to use as input to the RFC3986 resolution algorithm extended to handle
 :             additional unreserved characters. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0002"/> if <code>$base</code> is not a
 :             valid IRI according to the rules of RFC3987, extended with an implementation-defined
 :             subset of the extensions permitted in LEIRI, or if it is not a suitable IRI to use as
 :             input to the chosen resolution algorithm (for example, if it is a relative IRI
 :             reference, if it is a non-hierarchic URI, or if it contains a fragment identifier). </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0009"/> if the chosen resolution algorithm
 :             fails for any other reason. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-resolve-uri
 :)
declare function fn:resolve-uri($relative as xs:string?) as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Resolves a relative IRI reference against an absolute IRI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="resolve-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="relative" type="xs:string?"/></proto></example><example role="signature"><proto name="resolve-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="relative" type="xs:string?"/><arg name="base" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The two-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the second argument is absent, the effect is the same as calling the two-argument
 :             function with the value of <code>fn:static-base-uri()</code> as the second argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is defined to operate on IRI references as defined in <bibref ref="rfc3987"/>, and the implementation <rfc2119>must</rfc2119> permit all arguments that are valid
 :             according to that specification. In addition, the implementation <rfc2119>may</rfc2119>
 :             accept some or all strings that conform to the rules for (absolute or relative) Legacy
 :             Extended IRI references as defined in <bibref ref="LEIRI"/>. For the purposes of this
 :             section, the terms IRI and IRI reference include these extensions, insofar as the
 :             implementation chooses to support them.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$relative</code> is the empty sequence, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$relative</code> is an absolute IRI (as defined above), then it is returned
 :             unchanged.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise, the function resolves the relative IRI reference <code>$relative</code>
 :             against the base IRI <code>$base</code> using the algorithm defined in <bibref ref="rfc3986"/>, adapted by treating any <termref def="character">character</termref>
 :             that would not be valid in an RFC3986 URI or relative reference in the same way that
 :             RFC3986 treats unreserved characters. No percent-encoding takes place.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The first form of this function resolves <code>$relative</code> against the value of the
 :             base-uri property from the static context. A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="NS" code="0005"/> if the base-uri property is not initialized in the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0002"/> if <code>$relative</code> is not a
 :             valid IRI according to the rules of RFC3987, extended with an implementation-defined
 :             subset of the extensions permitted in LEIRI, or if it is not a suitable relative
 :             reference to use as input to the RFC3986 resolution algorithm extended to handle
 :             additional unreserved characters. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0002"/> if <code>$base</code> is not a
 :             valid IRI according to the rules of RFC3987, extended with an implementation-defined
 :             subset of the extensions permitted in LEIRI, or if it is not a suitable IRI to use as
 :             input to the chosen resolution algorithm (for example, if it is a relative IRI
 :             reference, if it is a non-hierarchic URI, or if it contains a fragment identifier). </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="RG" code="0009"/> if the chosen resolution algorithm
 :             fails for any other reason. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-resolve-uri
 :)
declare function fn:resolve-uri($relative as xs:string?,  $base as xs:string) as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the root of the tree to which <code>$arg</code> belongs. This will
 :             usually, but not necessarily, be a document node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="root" return-type="node()" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="root" return-type="node()?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the function is called without an argument, the context item (<code>.</code>) is used
 :             as the default argument. The behavior of the function if the argument is omitted is
 :             exactly the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the value of the expression
 :                <code>($arg/ancestor-or-self::node())[1]</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-root
 :)
declare function fn:root() as  node() external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the root of the tree to which <code>$arg</code> belongs. This will
 :             usually, but not necessarily, be a document node.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="root" return-type="node()" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="root" return-type="node()?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="node()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the function is called without an argument, the context item (<code>.</code>) is used
 :             as the default argument. The behavior of the function if the argument is omitted is
 :             exactly the same as if the context item had been passed as the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the value of the expression
 :                <code>($arg/ancestor-or-self::node())[1]</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The following errors may be raised when <code>$arg</code> is omitted:</p><ul xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><li><p>If the context
 :                item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>, <phrase diff="add" at="M">dynamic error</phrase>
 :                <xerrorref spec="XP" class="DY" code="0002" type="dynamic"/></p></li><li><p>If the context item is not a
 :                node, <phrase diff="add" at="M">type error</phrase> <xerrorref spec="XP" class="TY" code="0004" type="type"/>.</p></li></ul></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-root
 :)
declare function fn:root($arg as node()?) as  node()? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function returns the value of the Static Base URI property from the static context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="static-base-uri" return-type="xs:anyURI?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns the value of the Static Base URI property from the static context. If the
 :             property is absent, the empty sequence is returned.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Components of the static context are discussed in <xspecref spec="XP30" ref="static_context"/> .</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">XQuery 3.0 and XSLT 3.0 give an implementation freedom to use different base URIs during the
 :          static analysis phase and the dynamic evaluation phase, that is, for compile-time and run-time resources respectively.
 :          In this situation, the <code>fn:static-base-uri</code> function should return a URI suitable for locating resources needed
 :          during dynamic evaluation.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-static-base-uri
 :)
declare function fn:static-base-uri() as  xs:anyURI? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>$arg</code> represented as an
 :             <code>xs:string</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="string" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the zero-argument version of the function, <code>$arg</code> defaults to the context
 :             item. That is, calling <code>fn:string()</code> is equivalent to calling
 :                <code>fn:string(.)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a node, the function returns the string-value of the node, as
 :             obtained using the <code>dm:string-value</code> accessor defined in <bibref ref="xpath-datamodel-30"/> (see <xspecref spec="DM30" ref="dm-string-value"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an atomic value, the function returns the result of the
 :             expression <code>$arg cast as xs:string</code> (see <specref ref="casting"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <xerrorref spec="XP" class="DY" code="0002" type="type"/> by the
 :             zero-argument version of the function if the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0014" type="type"/> if
 :                <code>$arg</code> is a function item. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string
 :)
declare function fn:string() as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>$arg</code> represented as an
 :             <code>xs:string</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="string" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="string" return-type="xs:string" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="item()?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-dependent">focus-dependent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The one-argument form of this function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In the zero-argument version of the function, <code>$arg</code> defaults to the context
 :             item. That is, calling <code>fn:string()</code> is equivalent to calling
 :                <code>fn:string(.)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the zero-length
 :             string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is a node, the function returns the string-value of the node, as
 :             obtained using the <code>dm:string-value</code> accessor defined in <bibref ref="xpath-datamodel-30"/> (see <xspecref spec="DM30" ref="dm-string-value"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is an atomic value, the function returns the result of the
 :             expression <code>$arg cast as xs:string</code> (see <specref ref="casting"/>).</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="M">dynamic</phrase> error is raised <xerrorref spec="XP" class="DY" code="0002" type="type"/> by the
 :             zero-argument version of the function if the context item is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">type</phrase> error is raised <errorref class="TY" code="0014" type="type"/> if
 :                <code>$arg</code> is a function item. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-string
 :)
declare function fn:string($arg as item()?) as  xs:string external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a list of environment variable names that are suitable for passing to
 :                <code>fn:environment-variable</code>, as a (possibly empty) sequence of strings.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="available-environment-variables" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		environment variables.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a sequence of strings, being the names of the environment variables
 :             in the dynamic context in some <termref def="implementation-dependent">implementation-dependent</termref> order.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function is <termref def="dt-deterministic">deterministic</termref>: that is, the
 :             set of available environment variables does not vary during evaluation.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The function returns a list of strings, containing no duplicates.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">It is intended that the strings in this list should be suitable for passing to
 :                <code>fn:environment-variable</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">See also the note on security under the definition of the
 :                <code>fn:environment-variable</code> function. If access to environment variables has
 :             been disabled, <code>fn:available-environment-variables</code> always returns the empty
 :             sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-available-environment-variables
 :)
declare function fn:available-environment-variables() as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of a system environment variable, if it exists.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="environment-variable" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="name" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		environment variables.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The set of available <xtermref spec="XP30" ref="dt-environment-variables">environment variables</xtermref> 
 :             is a set of (name, value) pairs forming part
 :             of the dynamic context, in which the name is unique within the set of pairs. The name
 :             and value are arbitrary strings.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the <code>$name</code> argument matches the name of one of these pairs, the function
 :             returns the corresponding value.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If there is no environment variable with a matching name, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The collation used for matching names is <termref def="implementation-defined"/>, but
 :             must be the same as the collation used to ensure that the names of all environment
 :             variables are unique.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="I">The function is <termref def="dt-deterministic">deterministic</termref>, 
 :             which means that if it is called several times
 :          within the same <termref def="dt-execution-scope">execution scope</termref>, with the same arguments,
 :             it must return the same result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">On many platforms, the term "environment variable" has a natural meaning in terms of
 :             facilities provided by the operating system. This interpretation of the concept does not
 :             exclude other interpretations, such as a mapping to a set of configuration parameters in
 :             a database system.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Environment variable names are usually case sensitive. Names are usually of the form
 :                <code>(letter|_) (letter|_|digit)*</code>, but this varies by platform.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">On some platforms, there may sometimes be multiple environment variables with the same name;
 :             in this case, it is implementation-dependent as to which is returned; see for example
 :                <bibref ref="POSIX.1-2008"/> (Chapter 8, Environment Variables).
 :             Implementations <rfc2119>may</rfc2119> use prefixes or other naming conventions
 :             to disambiguate the names.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The requirement to ensure that the function is deterministic means in practice that
 :          the implementation must make a snapshot of the environment variables at some time
 :          during execution, and return values obtained from this snapshot, rather than using
 :          live values that are subject to change at any time.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Operating system environment variables may be associated with a particular process,
 :          while queries and stylesheets may execute across multiple processes (or multiple machines).
 :          In such circumstances implementations <rfc2119>may</rfc2119> choose to provide access
 :          to the environment variables associated with the process in which the query or stylesheet
 :          processing was initiated.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Security advice: Queries from untrusted sources should not be permitted unrestricted
 :             access to environment variables. For example, the name of the account under which the
 :             query is running may be useful information to a would-be intruder. An implementation may
 :             therefore choose to restrict access to the environment, or may provide a facility to
 :             make <code>fn:environment-variable</code> always return the empty sequence.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-environment-variable
 :)
declare function fn:environment-variable($arg as xs:string) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:unparsed-text</code> function reads an external resource (for example, a
 :             file) and returns <phrase diff="chg" at="L">a string representation of the resource</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$href</code> argument <rfc2119>must</rfc2119> be a string in the form of a URI
 :             reference, which <rfc2119>must</rfc2119> contain no fragment identifier, and
 :                <rfc2119>must</rfc2119> identify a resource 
 :             <phrase diff="chg" at="L">for which a string representation is available</phrase>. If the URI is a
 :             relative URI reference, then it is resolved relative to the 
 :             <phrase diff="chg" at="L">Static Base URI property from the static context</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">The mapping of URIs to the string representation of a resource is the mapping defined
 :             in the <xtermref spec="XP30" ref="dt-available-text-resources">available text resources</xtermref>
 :          component of the dynamic context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of the <code>$href</code> argument is an empty sequence, the function
 :             returns an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$encoding</code> argument, if present, is the name of an encoding. The values
 :             for this attribute follow the same rules as for the <code>encoding</code> attribute in
 :             an XML declaration. The only values which every <termref def="implementation">implementation</termref> is <rfc2119>required</rfc2119> to recognize are
 :                <code>utf-8</code> and <code>utf-16</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The encoding of the external resource is determined as follows:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>external encoding information is used if available, otherwise</p></item><item><p>if the media type of the resource is <code>text/xml</code> or
 :                      <code>application/xml</code> (see <bibref ref="rfc2376"/>), or if it matches
 :                   the conventions <code>text/*+xml</code> or <code>application/*+xml</code> (see
 :                      <bibref ref="rfc3023"/> and/or its successors), then the encoding is recognized
 :                   as specified in <bibref ref="REC-xml"/>, otherwise</p></item><item><p>the value of the <code>$encoding</code> argument is used if present, otherwise</p></item><item><p>the processor <rfc2119>may</rfc2119> use <termref def="implementation-defined">implementation-defined</termref> heuristics to determine the likely encoding,
 :                   otherwise</p></item><item><p>UTF-8 is assumed.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function is a string containing the 
 :             <phrase diff="chg" at="L">string representation</phrase> of the resource retrieved
 :             using the URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1170"/> if <code>$href</code>
 :             contains a fragment identifier, or if it cannot be used to retrieve the 
 :             <phrase diff="chg" at="L">string representation</phrase> of a resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1190"/> <phrase diff="add" at="L">if the value 
 :             of the <code>$encoding</code> argument is not a valid encoding name, </phrase>if the <termref def="dt-processor">processor</termref> does not support the specified encoding,
 :             if the <phrase diff="chg" at="L">string representation</phrase> of the retrieved
 :             resource contains octets that cannot be decoded into Unicode <termref def="character">characters</termref> using the specified encoding, or if the resulting characters
 :             are not permitted XML characters.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1200"/> if
 :                <code>$encoding</code> is absent and the <termref def="dt-processor">processor</termref> cannot infer the encoding using external information and the
 :             encoding is not UTF-8.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text
 :)
declare function fn:unparsed-text($href as xs:string?) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:unparsed-text</code> function reads an external resource (for example, a
 :             file) and returns <phrase diff="chg" at="L">a string representation of the resource</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text" return-type="xs:string?" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$href</code> argument <rfc2119>must</rfc2119> be a string in the form of a URI
 :             reference, which <rfc2119>must</rfc2119> contain no fragment identifier, and
 :                <rfc2119>must</rfc2119> identify a resource 
 :             <phrase diff="chg" at="L">for which a string representation is available</phrase>. If the URI is a
 :             relative URI reference, then it is resolved relative to the 
 :             <phrase diff="chg" at="L">Static Base URI property from the static context</phrase>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="add" at="L">The mapping of URIs to the string representation of a resource is the mapping defined
 :             in the <xtermref spec="XP30" ref="dt-available-text-resources">available text resources</xtermref>
 :          component of the dynamic context.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of the <code>$href</code> argument is an empty sequence, the function
 :             returns an empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>$encoding</code> argument, if present, is the name of an encoding. The values
 :             for this attribute follow the same rules as for the <code>encoding</code> attribute in
 :             an XML declaration. The only values which every <termref def="implementation">implementation</termref> is <rfc2119>required</rfc2119> to recognize are
 :                <code>utf-8</code> and <code>utf-16</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The encoding of the external resource is determined as follows:</p><olist xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><item><p>external encoding information is used if available, otherwise</p></item><item><p>if the media type of the resource is <code>text/xml</code> or
 :                      <code>application/xml</code> (see <bibref ref="rfc2376"/>), or if it matches
 :                   the conventions <code>text/*+xml</code> or <code>application/*+xml</code> (see
 :                      <bibref ref="rfc3023"/> and/or its successors), then the encoding is recognized
 :                   as specified in <bibref ref="REC-xml"/>, otherwise</p></item><item><p>the value of the <code>$encoding</code> argument is used if present, otherwise</p></item><item><p>the processor <rfc2119>may</rfc2119> use <termref def="implementation-defined">implementation-defined</termref> heuristics to determine the likely encoding,
 :                   otherwise</p></item><item><p>UTF-8 is assumed.</p></item></olist><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the function is a string containing the 
 :             <phrase diff="chg" at="L">string representation</phrase> of the resource retrieved
 :             using the URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1170"/> if <code>$href</code>
 :             contains a fragment identifier, or if it cannot be used to retrieve the 
 :             <phrase diff="chg" at="L">string representation</phrase> of a resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1190"/> <phrase diff="add" at="L">if the value 
 :             of the <code>$encoding</code> argument is not a valid encoding name, </phrase>if the <termref def="dt-processor">processor</termref> does not support the specified encoding,
 :             if the <phrase diff="chg" at="L">string representation</phrase> of the retrieved
 :             resource contains octets that cannot be decoded into Unicode <termref def="character">characters</termref> using the specified encoding, or if the resulting characters
 :             are not permitted XML characters.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="UT" code="1200"/> if
 :                <code>$encoding</code> is absent and the <termref def="dt-processor">processor</termref> cannot infer the encoding using external information and the
 :             encoding is not UTF-8.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text
 :)
declare function fn:unparsed-text($href as xs:string?,  $encoding as xs:string) as  xs:string? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Because errors in evaluating the <function>fn:unparsed-text</function> function are
 :             non-recoverable, these two functions are provided to allow an application to determine
 :             whether a call with particular arguments would succeed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <function>fn:unparsed-text-available</function> function determines whether a call
 :             on the <function>fn:unparsed-text</function> function with identical arguments would
 :             return a string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the first argument is an empty sequence, the function returns false. <phrase diff="del" at="L">If the second
 :             argument is an empty sequence, the function behaves as if the second argument were
 :             omitted.</phrase></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases, the function returns true if a call on
 :                <function>fn:unparsed-text</function> with the same arguments would succeed, and
 :             false if a call on <function>fn:unparsed-text</function> with the same arguments would
 :             fail with a non-recoverable dynamic error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The functions <function>fn:unparsed-text</function> and
 :                <function>fn:unparsed-text-available</function> have the same requirement for
 :                <termref def="deterministic">determinism</termref> as the functions
 :                <code>fn:doc</code> and <code>fn:doc-available</code>. This means that unless the
 :             user has explicitly stated a requirement for a reduced level of determinism, either of
 :             these functions if called twice with the same arguments during the course of a
 :             transformation <rfc2119>must</rfc2119> return the same results each time; moreover, the
 :             results of a call on <function>fn:unparsed-text-available</function>
 :             <rfc2119>must</rfc2119> be consistent with the results of a subsequent call on
 :                <function>unparsed-text</function> with the same arguments.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This requires that the <function>unparsed-text-available</function> function should
 :             actually attempt to read the resource identified by the URI, and check that it is
 :             correctly encoded and contains no characters that are invalid in XML. Implementations
 :             may avoid the cost of repeating these checks for example by caching the validated
 :             contents of the resource, to anticipate a subsequent call on the
 :                <function>unparsed-text</function>
 :             <phrase diff="add" at="A">or <function>unparsed-text-lines</function>
 :             </phrase> function. Alternatively, implementations may be able to rewrite an expression
 :             such as <code>if (unparsed-text-available(A)) then unparsed-text(A) else ...</code> to
 :             generate a single call internally.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text-available
 :)
declare function fn:unparsed-text-available($href as xs:string?) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>fn:unparsed-text-lines</code> function reads an external resource (for
 :             example, a file) and returns its contents as a sequence of strings, one for each line of
 :             text in the  <phrase diff="chg" at="L">string representation</phrase> of the resource.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text-lines" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text-lines" return-type="xs:string*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <code>unparsed-text-lines</code> function reads an external resource (for example, a
 :             file) and returns its <phrase diff="chg" at="L">string representation</phrase> as a sequence of strings, separated at newline
 :             boundaries. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result of the single-argument function is the same as the result of the expression
 :                <code>fn:tokenize(fn:unparsed-text($href), '\r\n|\r|\n')[not(position()=last() and
 :                .='')]</code>. The result of the two-argument function is the same as the result of
 :             the expression <code>fn:tokenize(fn:unparsed-text($href, $encoding),
 :                '\r\n|\r|\n'))[not(position()=last() and .='')]</code>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The result is a thus a sequence of strings containing the text of the resource retrieved
 :             using the URI, each string representing one line of text. Lines are separated by one of
 :             the sequences x0A, x0D, or x0Dx0A. The characters representing the newline are not
 :             included in the returned strings. If there are two adjacent newline sequences, a
 :             zero-length string will be returned to represent the empty line; but if the external
 :             resource ends with a newline sequence, no zero-length string will be returned as the
 :             last item in the result.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Error conditions are the same as for the <code>fn:unparsed-text</code> function.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text-lines
 :)
declare function fn:unparsed-text-lines(	$href	 as xs:string?,  $encoding	 as xs:string) as  xs:string* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Because errors in evaluating the <function>fn:unparsed-text</function> function are
 :             non-recoverable, these two functions are provided to allow an application to determine
 :             whether a call with particular arguments would succeed.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/></proto></example><example role="signature"><proto name="unparsed-text-available" return-type="xs:boolean" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="href" type="xs:string?"/><arg name="encoding" type="xs:string"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The <function>fn:unparsed-text-available</function> function determines whether a call
 :             on the <function>fn:unparsed-text</function> function with identical arguments would
 :             return a string.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the first argument is an empty sequence, the function returns false. <phrase diff="del" at="L">If the second
 :             argument is an empty sequence, the function behaves as if the second argument were
 :             omitted.</phrase></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases, the function returns true if a call on
 :                <function>fn:unparsed-text</function> with the same arguments would succeed, and
 :             false if a call on <function>fn:unparsed-text</function> with the same arguments would
 :             fail with a non-recoverable dynamic error.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The functions <function>fn:unparsed-text</function> and
 :                <function>fn:unparsed-text-available</function> have the same requirement for
 :                <termref def="deterministic">determinism</termref> as the functions
 :                <code>fn:doc</code> and <code>fn:doc-available</code>. This means that unless the
 :             user has explicitly stated a requirement for a reduced level of determinism, either of
 :             these functions if called twice with the same arguments during the course of a
 :             transformation <rfc2119>must</rfc2119> return the same results each time; moreover, the
 :             results of a call on <function>fn:unparsed-text-available</function>
 :             <rfc2119>must</rfc2119> be consistent with the results of a subsequent call on
 :                <function>unparsed-text</function> with the same arguments.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This requires that the <function>unparsed-text-available</function> function should
 :             actually attempt to read the resource identified by the URI, and check that it is
 :             correctly encoded and contains no characters that are invalid in XML. Implementations
 :             may avoid the cost of repeating these checks for example by caching the validated
 :             contents of the resource, to anticipate a subsequent call on the
 :                <function>unparsed-text</function>
 :             <phrase diff="add" at="A">or <function>unparsed-text-lines</function>
 :             </phrase> function. Alternatively, implementations may be able to rewrite an expression
 :             such as <code>if (unparsed-text-available(A)) then unparsed-text(A) else ...</code> to
 :             generate a single call internally.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-unparsed-text-available
 :)
declare function fn:unparsed-text-available(	$href	 as xs:string?,  $encoding	 as xs:string) as  xs:boolean external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of <code>xs:anyURI</code> values representing the URIs in a resource collection.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available resource collections, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of the function returns the URIs in the <term>Default resource collection</term>
 :             described in <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is a relative <code>xs:anyURI</code>, it is resolved
 :             against the value of the base-URI property from the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function behaves as if it had been
 :             called without an argument. See above.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The single-argument form of the function returns the sequence of URIs corresponding to the 
 :             supplied URI in the <term>Available resource collections</term> described in 
 :             <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if no URI is supplied (that is, if the
 :             the function is called with no arguments, or with a single argument that evaluates to an empty sequence), and the
 :             value of the default resource collection is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="J">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> 
 :             if <term>available resource collections</term> provides no mapping for the absolutized URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0004"/> if <code>$arg</code> is not a
 :             valid <code>xs:anyURI</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-uri-collection
 :)
declare function fn:uri-collection() as  xs:anyURI* external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns a sequence of <code>xs:anyURI</code> values representing the URIs in a resource collection.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example><example role="signature"><proto name="uri-collection" return-type="xs:anyURI*" isOp="no" prefix="fn" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:string?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-dependent">context-dependent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>.  It depends on 
 : 		available resource collections, and static base uri.
 : 	</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The zero-argument form of the function returns the URIs in the <term>Default resource collection</term>
 :             described in <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If the value of <code>$arg</code> is a relative <code>xs:anyURI</code>, it is resolved
 :             against the value of the base-URI property from the static context. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function behaves as if it had been
 :             called without an argument. See above.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The single-argument form of the function returns the sequence of URIs corresponding to the 
 :             supplied URI in the <term>Available resource collections</term> described in 
 :             <xspecref spec="XP30" ref="id-xp-evaluation-context-components"/>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> if no URI is supplied (that is, if the
 :             the function is called with no arguments, or with a single argument that evaluates to an empty sequence), and the
 :             value of the default resource collection is <xtermref ref="dt-absent" spec="DM30">absent</xtermref>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="J">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0002"/> 
 :             if <term>available resource collections</term> provides no mapping for the absolutized URI.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">A <phrase diff="add" at="L">dynamic</phrase> error is raised <errorref class="DC" code="0004"/> if <code>$arg</code> is not a
 :             valid <code>xs:anyURI</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-uri-collection
 :)
declare function fn:uri-collection($arg as xs:string?) as  xs:anyURI* external;
