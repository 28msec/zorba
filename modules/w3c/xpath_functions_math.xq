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
 : This module contains all the functions part of the
 : W3C XPath and XQuery Functions and Operators 3.0 
 : section "4.7 Trigonometric and exponential functions".
 :
 :
 : @author www.w3c.org
 : @see http://www.w3.org/TR/xpath-functions-30/#trigonometry
 : @project W3C/XPath Math Functions
 :
 :)
module namespace math = "http://www.w3.org/2005/xpath-functions/math";



(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns an approximation to the mathematical constant <var>π</var>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="pi" return-type="xs:double" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"/></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function returns the <code>xs:double</code> value whose lexical representation is
 :             3.141592653589793e0</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>2*math:pi()</code> returns <code>6.283185307179586e0</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The expression <code>60 * (math:pi() div 180)</code> converts an angle of 60 degrees
 :                to radians. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-pi
 :)
declare function math:pi() as  xs:double external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <var>e</var><sup><var>x</var></sup>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="exp" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the mathematical constant <var>e</var>
 :             raised to the power of <code>$arg</code>, as defined in the <bibref ref="ieee754-2008"/>
 :             specification of the <code>exp</code> function applied to 64-bit binary floating point
 :             values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of overflow and underflow is defined in <specref ref="op.numeric"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-exp
 :)
declare function math:exp($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the value of <code>10</code><sup><var>x</var></sup>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="exp10" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is ten raised to the power of <code>$arg</code>,
 :             as defined in the <bibref ref="ieee754-2008"/> specification of the <code>exp10</code>
 :             function applied to 64-bit binary floating point values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of overflow and underflow is defined in <specref ref="op.numeric"/>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-exp10
 :)
declare function math:exp10($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the natural logarithm of the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="log" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the natural logarithm of <code>$arg</code>, as
 :             defined in the <bibref ref="ieee754-2008"/> specification of the <code>log</code>
 :             function applied to 64-bit binary floating point values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of <code>divideByZero</code> and <code>invalidOperation</code> exceptions
 :             is defined in <specref ref="op.numeric"/>. The effect is that if the argument is less
 :             than or equal to zero, the result is <code>NaN</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-log
 :)
declare function math:log($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the base-ten logarithm of the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="log10" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the base-10 logarithm of <code>$arg</code>, as
 :             defined in the <bibref ref="ieee754-2008"/> specification of the <code>log10</code>
 :             function applied to 64-bit binary floating point values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of <code>divideByZero</code> and <code>invalidOperation</code> exceptions
 :             is defined in <specref ref="op.numeric"/>. The effect is that if the argument is less
 :             than or equal to zero, the result is <code>NaN</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-log10
 :)
declare function math:log10($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the result of raising the first argument to the power of the
 :             second.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="pow" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="x" type="xs:double?"/><arg name="y" type="numeric"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$x</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$y</code> is an instance of <code>xs:integer</code>, the result is
 :                <code>$x</code> raised to the power of <code>$y</code> as defined in the <bibref ref="ieee754-2008"/> specification of the <code>pown</code> function applied to a
 :             64-bit binary floating point value and an integer.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise <code>$y</code> is converted to an <code>xs:double</code> by numeric
 :             promotion, and the result is the value of <code>$x</code> raised to the power of
 :                <code>$y</code> as defined in the <bibref ref="ieee754-2008"/> specification of the
 :                <code>pow</code> function applied to two 64-bit binary floating point values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>divideByZero</code> and <code>invalidOperation</code>
 :             exceptions is defined in <specref ref="op.numeric"/>. Some of the consequences are
 :             illustrated in the examples below.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-pow
 :)
declare function math:pow($x as xs:double?,  $y as numeric) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the non-negative square root of the argument.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="sqrt" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the mathematical non-negative square root of
 :                <code>$arg</code> as defined in the <bibref ref="ieee754-2008"/> specification of the
 :                <code>squareRoot</code> function applied to 64-bit binary floating point values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>invalidOperation</code> exception is defined in <specref ref="op.numeric"/>. The effect is that if the argument is less than zero, the result
 :             is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is positive or negative zero, positive infinity, or
 :                <code>NaN</code>, then the result is <code>$arg</code>. (Negative zero is the only
 :             case where the result can have negative sign)</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-sqrt
 :)
declare function math:sqrt($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the sine of the argument, expressed in radians.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="sin" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="θ" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is the empty sequence, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the sine of <code>$</code><var>θ</var>,
 :             treated as an angle in radians, as defined in the <bibref ref="ieee754-2008"/>
 :             specification of the <code>sin</code> function applied to 64-bit binary floating point
 :             values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>invalidOperation</code> and <code>underflow</code> exceptions
 :             is defined in <specref ref="op.numeric"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is positive or negative zero, the result is
 :                <code>$</code><var>θ</var>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is positive or negative infinity, or <code>NaN</code>,
 :             then the result is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise the result is always in the range -1.0e0 to +1.0e0</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-sin
 :)
declare function math:sin($theta as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the cosine of the argument, expressed in radians.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="cos" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="θ" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is the empty sequence, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is positive or negative infinity, or <code>NaN</code>,
 :             then the result is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the cosine of <code>$</code><var>θ</var>,
 :             treated as an angle in radians, as defined in the <bibref ref="ieee754-2008"/>
 :             specification of the <code>cos</code> function applied to 64-bit binary floating point
 :             values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>invalidOperation</code> exception is defined in <specref ref="op.numeric"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is positive or negative zero, the result is
 :                <code>$</code><var>θ</var>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is positive or negative infinity, or <code>NaN</code>,
 :             then the result is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Otherwise the result is always in the range -1.0e0 to +1.0e0</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-cos
 :)
declare function math:cos($theta as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the tangent of the argument, expressed in radians.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="tan" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="θ" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is the empty sequence, the function returns the empty
 :             sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the tangent of <code>$</code><var>θ</var>,
 :             treated as an angle in radians, as defined in the <bibref ref="ieee754-2008"/>
 :             specification of the <code>tan</code> function applied to 64-bit binary floating point
 :             values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>invalidOperation</code> and <code>underflow</code> exceptions
 :             is defined in <specref ref="op.numeric"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$</code><var>θ</var> is positive or negative infinity, or <code>NaN</code>,
 :             then the result is <code>NaN</code>.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-tan
 :)
declare function math:tan($theta as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the arc sine of the argument, the result being in the range
 :                -<var>π</var>/2 to +<var>π</var>/2 radians.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="asin" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the arc sine of <code>$</code><var>θ</var>,
 :             treated as an angle in radians, as defined in the <bibref ref="ieee754-2008"/>
 :             specification of the <code>asin</code> function applied to 64-bit binary floating point
 :             values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>invalidOperation</code> and <code>underflow</code> exceptions
 :             is defined in <specref ref="op.numeric"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is positive or negative zero, the result is <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is <code>NaN</code>, or if its absolute value is greater than one,
 :             then the result is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases the result is an <code>xs:double</code> value representing an angle
 :                <var>θ</var> in radians in the range -<var>π</var><code>/2 &lt;=
 :                $</code><var>θ</var><code> &lt;= +</code><var>π</var><code>/2</code>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-asin
 :)
declare function math:asin($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the arc cosine of the argument, the result being in the range zero to
 :                +<var>π</var> radians.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="acos" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the arc cosine of <code>$</code><var>θ</var>,
 :             treated as an angle in radians, as defined in the <bibref ref="ieee754-2008"/>
 :             specification of the <code>acos</code> function applied to 64-bit binary floating point
 :             values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>invalidOperation</code> exception is defined in <specref ref="op.numeric"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is <code>NaN</code>, or if its absolute value is greater than one,
 :             then the result is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases the result is an <code>xs:double</code> value representing an angle
 :                <var>θ</var> in radians in the range <code>0 &lt;= $</code><var>θ</var><code> &lt;=
 :                +</code><var>π</var>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-acos
 :)
declare function math:acos($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the arc tangent of the argument, the result being in the range
 :                -<var>π</var>/2 to +<var>π</var>/2 radians.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="atan" return-type="xs:double?" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="arg" type="xs:double?"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is the empty sequence, the function returns the empty sequence.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">Otherwise the result is the arc tangent of <code>$</code><var>θ</var>,
 :             treated as an angle in radians, as defined in the <bibref ref="ieee754-2008"/>
 :             specification of the <code>atan</code> function applied to 64-bit binary floating point
 :             values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>underflow</code> exception is defined in <specref ref="op.numeric"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is positive or negative zero, the result is <code>$arg</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$arg</code> is <code>NaN</code> then the result is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">In other cases the result is an <code>xs:double</code> value representing an angle
 :                <var>θ</var> in radians in the range -<var>π</var><code>/2 &lt;=
 :                $</code><var>θ</var><code> &lt;= +</code><var>π</var><code>/2</code>. </p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-atan
 :)
declare function math:atan($arg as xs:double?) as  xs:double? external;
 
(:~
 : <div><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Returns the angle in radians subtended at the origin by the point on a plane
 :             with coordinates (x, y) and the positive x-axis, the result being in the range
 :                -<var>π</var> to +<var>π</var>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax"><example role="signature"><proto name="atan2" return-type="xs:double" isOp="no" prefix="math" returnEmptyOk="no" returnSeq="no" returnVaries="no" isSchema="no" isDatatype="no" isSpecial="no"><arg name="y" type="xs:double"/><arg name="x" type="xs:double"/></proto></example></p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">This function is <termref def="dt-deterministic">deterministic</termref>, <termref def="dt-context-independent">context-independent</termref>,  and <termref def="dt-focus-independent">focus-independent</termref>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax" diff="chg" at="G">The result is the value of <code>atan2(y, x)</code> as defined in the
 :                <bibref ref="ieee754-2008"/> specification of the <code>atan2</code> function applied
 :             to 64-bit binary floating point values.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">The treatment of the <code>underflow</code> exception is defined in <specref ref="op.numeric"/>. </p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <phrase diff="chg" at="L">either argument</phrase> is <code>NaN</code> 
 :             then the result is <code>NaN</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$y</code> is positive and <code>$x</code> is positive and finite, then 
 :             (subject to rules for overflow, underflow and approximation) 
 :          the value of <code>atan2($y, $x)</code> is <code>atan($y div $x)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">If <code>$y</code> is positive and <code>$x</code> is negative and finite, then 
 :             (subject to the same caveats) 
 :             the value of <code>atan2($y, $x)</code> is <var>π</var> <code>- atan($y div $x)</code>.</p><p xmlns:e="http://www.w3.org/1999/XSL/Spec/ElementSyntax">Some results for special values of the arguments are shown in the examples below.</p></div> 
 :
 : @see http://www.w3.org/TR/xpath-functions-30/#func-math-atan2
 :)
declare function math:atan2($y as xs:double,  $x as xs:double) as  xs:double external;
