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
 : Module implementing the sumproduct functions from Excel 2003 math library.
 : There are 30 functions defined, implementing the same function
 : but with 1 to 30 parameters.
 : Each parameter can be a sequence of infinite length.
 :
 : @see <a href="http://office.microsoft.com/en-us/excel/HP052092931033.aspx"
 : target="_blank">Excel 2003 Documentation: Math-sumproduct Functions</a>
 :
 : @spec XQuery Specification: January 2007
 : @author Daniel Turcanu
 :
 :)
module namespace  excel = "http://www.zorba-xquery.com/modules/excel/math-sumproduct";

(:~
 : Import excel-math module functions.
:)
import module namespace excel-math = "http://www.zorba-xquery.com/modules/excel/math";


(:~
 : Sums the values in the sequence.
 : The sequence can be of any length.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
 : @param $array1 the sequence of numbers or arguments castable to numeric
 : @return the sum
 : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
 : @example rbkt/Queries/zorba/excel/math/sumproduct1.xq
:)
declare function excel:sumproduct( $array1 as xs:anyAtomicType*) as xs:anyAtomicType
 {
   excel-math:sum( $array1 )
 };

(:~
 : Multiplies the elements on the same position in each sequence
 : and sums up the results.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
 : @param $array1 the sequences of numbers or arguments castable to numeric
 : @param $array2 the sequences of numbers or arguments castable to numeric
 : @return the sum of products
 : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
 : @example rbkt/Queries/zorba/excel/math/sumproduct2.xq
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2)) 
        then
      0
    else
      excel-math:cast-as-numeric($array1[1]) * 
      excel-math:cast-as-numeric($array2[1]) + excel:sumproduct( fn:subsequence($array1,2),
                                                          fn:subsequence($array2,2))
 };
 
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
  : @example rbkt/Queries/zorba/excel/math/sumproduct3.xq
:)
declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2))
 };
 
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2))
 };
 
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2))
 };
 
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2))
 };
 

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2))
 };
 
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2))
 };
  
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2))
 };
 
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @param $array24 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*,
                                    $array24 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23) or
        fn:empty($array24)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) *
        excel-math:cast-as-numeric($array24[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2),
                                             fn:subsequence($array24,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @param $array24 the sequences of numbers or arguments castable to numeric
  : @param $array25 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*,
                                    $array24 as xs:anyAtomicType*,
                                    $array25 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23) or
        fn:empty($array24) or
        fn:empty($array25)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) *
        excel-math:cast-as-numeric($array24[1]) *
        excel-math:cast-as-numeric($array25[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2),
                                             fn:subsequence($array24,2),
                                             fn:subsequence($array25,2))
 };
 
 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @param $array24 the sequences of numbers or arguments castable to numeric
  : @param $array25 the sequences of numbers or arguments castable to numeric
  : @param $array26 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*,
                                    $array24 as xs:anyAtomicType*,
                                    $array25 as xs:anyAtomicType*,
                                    $array26 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23) or
        fn:empty($array24) or
        fn:empty($array25) or
        fn:empty($array26)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) *
        excel-math:cast-as-numeric($array24[1]) *
        excel-math:cast-as-numeric($array25[1]) *
        excel-math:cast-as-numeric($array26[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2),
                                             fn:subsequence($array24,2),
                                             fn:subsequence($array25,2),
                                             fn:subsequence($array26,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @param $array24 the sequences of numbers or arguments castable to numeric
  : @param $array25 the sequences of numbers or arguments castable to numeric
  : @param $array26 the sequences of numbers or arguments castable to numeric
  : @param $array27 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*,
                                    $array24 as xs:anyAtomicType*,
                                    $array25 as xs:anyAtomicType*,
                                    $array26 as xs:anyAtomicType*,
                                    $array27 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23) or
        fn:empty($array24) or
        fn:empty($array25) or
        fn:empty($array26) or
        fn:empty($array27)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) *
        excel-math:cast-as-numeric($array24[1]) *
        excel-math:cast-as-numeric($array25[1]) *
        excel-math:cast-as-numeric($array26[1]) *
        excel-math:cast-as-numeric($array27[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2),
                                             fn:subsequence($array24,2),
                                             fn:subsequence($array25,2),
                                             fn:subsequence($array26,2),
                                             fn:subsequence($array27,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @param $array24 the sequences of numbers or arguments castable to numeric
  : @param $array25 the sequences of numbers or arguments castable to numeric
  : @param $array26 the sequences of numbers or arguments castable to numeric
  : @param $array27 the sequences of numbers or arguments castable to numeric
  : @param $array28 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*,
                                    $array24 as xs:anyAtomicType*,
                                    $array25 as xs:anyAtomicType*,
                                    $array26 as xs:anyAtomicType*,
                                    $array27 as xs:anyAtomicType*,
                                    $array28 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23) or
        fn:empty($array24) or
        fn:empty($array25) or
        fn:empty($array26) or
        fn:empty($array27) or
        fn:empty($array28)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) *
        excel-math:cast-as-numeric($array24[1]) *
        excel-math:cast-as-numeric($array25[1]) *
        excel-math:cast-as-numeric($array26[1]) *
        excel-math:cast-as-numeric($array27[1]) *
        excel-math:cast-as-numeric($array28[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2),
                                             fn:subsequence($array24,2),
                                             fn:subsequence($array25,2),
                                             fn:subsequence($array26,2),
                                             fn:subsequence($array27,2),
                                             fn:subsequence($array28,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @param $array24 the sequences of numbers or arguments castable to numeric
  : @param $array25 the sequences of numbers or arguments castable to numeric
  : @param $array26 the sequences of numbers or arguments castable to numeric
  : @param $array27 the sequences of numbers or arguments castable to numeric
  : @param $array28 the sequences of numbers or arguments castable to numeric
  : @param $array29 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*,
                                    $array24 as xs:anyAtomicType*,
                                    $array25 as xs:anyAtomicType*,
                                    $array26 as xs:anyAtomicType*,
                                    $array27 as xs:anyAtomicType*,
                                    $array28 as xs:anyAtomicType*,
                                    $array29 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23) or
        fn:empty($array24) or
        fn:empty($array25) or
        fn:empty($array26) or
        fn:empty($array27) or
        fn:empty($array28) or
        fn:empty($array29)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) *
        excel-math:cast-as-numeric($array24[1]) *
        excel-math:cast-as-numeric($array25[1]) *
        excel-math:cast-as-numeric($array26[1]) *
        excel-math:cast-as-numeric($array27[1]) *
        excel-math:cast-as-numeric($array28[1]) *
        excel-math:cast-as-numeric($array29[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2),
                                             fn:subsequence($array24,2),
                                             fn:subsequence($array25,2),
                                             fn:subsequence($array26,2),
                                             fn:subsequence($array27,2),
                                             fn:subsequence($array28,2),
                                             fn:subsequence($array29,2))
 };

 (:~
  : Multiplies the elements on the same position in each sequence
  : and sums up the results.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
  : @param $array1 the sequences of numbers or arguments castable to numeric
  : @param $array2 the sequences of numbers or arguments castable to numeric
  : @param $array3 the sequences of numbers or arguments castable to numeric
  : @param $array4 the sequences of numbers or arguments castable to numeric
  : @param $array5 the sequences of numbers or arguments castable to numeric
  : @param $array6 the sequences of numbers or arguments castable to numeric
  : @param $array7 the sequences of numbers or arguments castable to numeric
  : @param $array8 the sequences of numbers or arguments castable to numeric
  : @param $array9 the sequences of numbers or arguments castable to numeric
  : @param $array10 the sequences of numbers or arguments castable to numeric
  : @param $array11 the sequences of numbers or arguments castable to numeric
  : @param $array12 the sequences of numbers or arguments castable to numeric
  : @param $array13 the sequences of numbers or arguments castable to numeric
  : @param $array14 the sequences of numbers or arguments castable to numeric
  : @param $array15 the sequences of numbers or arguments castable to numeric
  : @param $array16 the sequences of numbers or arguments castable to numeric
  : @param $array17 the sequences of numbers or arguments castable to numeric
  : @param $array18 the sequences of numbers or arguments castable to numeric
  : @param $array19 the sequences of numbers or arguments castable to numeric
  : @param $array20 the sequences of numbers or arguments castable to numeric
  : @param $array21 the sequences of numbers or arguments castable to numeric
  : @param $array22 the sequences of numbers or arguments castable to numeric
  : @param $array23 the sequences of numbers or arguments castable to numeric
  : @param $array24 the sequences of numbers or arguments castable to numeric
  : @param $array25 the sequences of numbers or arguments castable to numeric
  : @param $array26 the sequences of numbers or arguments castable to numeric
  : @param $array27 the sequences of numbers or arguments castable to numeric
  : @param $array28 the sequences of numbers or arguments castable to numeric
  : @param $array29 the sequences of numbers or arguments castable to numeric
  : @param $array30 the sequences of numbers or arguments castable to numeric
  : @return the sum of products
  : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
:)
 declare function excel:sumproduct( $array1 as xs:anyAtomicType*,
                                    $array2 as xs:anyAtomicType*,
                                    $array3 as xs:anyAtomicType*,
                                    $array4 as xs:anyAtomicType*,
                                    $array5 as xs:anyAtomicType*,
                                    $array6 as xs:anyAtomicType*,
                                    $array7 as xs:anyAtomicType*,
                                    $array8 as xs:anyAtomicType*,
                                    $array9 as xs:anyAtomicType*,
                                    $array10 as xs:anyAtomicType*,
                                    $array11 as xs:anyAtomicType*,
                                    $array12 as xs:anyAtomicType*,
                                    $array13 as xs:anyAtomicType*,
                                    $array14 as xs:anyAtomicType*,
                                    $array15 as xs:anyAtomicType*,
                                    $array16 as xs:anyAtomicType*,
                                    $array17 as xs:anyAtomicType*,
                                    $array18 as xs:anyAtomicType*,
                                    $array19 as xs:anyAtomicType*,
                                    $array20 as xs:anyAtomicType*,
                                    $array21 as xs:anyAtomicType*,
                                    $array22 as xs:anyAtomicType*,
                                    $array23 as xs:anyAtomicType*,
                                    $array24 as xs:anyAtomicType*,
                                    $array25 as xs:anyAtomicType*,
                                    $array26 as xs:anyAtomicType*,
                                    $array27 as xs:anyAtomicType*,
                                    $array28 as xs:anyAtomicType*,
                                    $array29 as xs:anyAtomicType*,
                                    $array30 as xs:anyAtomicType*  ) as xs:anyAtomicType
 {
    if( fn:empty($array1) or 
        fn:empty($array2) or
        fn:empty($array3) or
        fn:empty($array4) or
        fn:empty($array5) or
        fn:empty($array6) or
        fn:empty($array7) or
        fn:empty($array8) or
        fn:empty($array9) or
        fn:empty($array10) or
        fn:empty($array11) or
        fn:empty($array12) or
        fn:empty($array13) or
        fn:empty($array14) or
        fn:empty($array15) or
        fn:empty($array16) or
        fn:empty($array17) or
        fn:empty($array18) or
        fn:empty($array19) or
        fn:empty($array20) or
        fn:empty($array21) or
        fn:empty($array22) or
        fn:empty($array23) or
        fn:empty($array24) or
        fn:empty($array25) or
        fn:empty($array26) or
        fn:empty($array27) or
        fn:empty($array28) or
        fn:empty($array29) or
        fn:empty($array30)) 
        then
      0
    else
        excel-math:cast-as-numeric($array1[1]) * 
        excel-math:cast-as-numeric($array2[1]) * 
        excel-math:cast-as-numeric($array3[1]) * 
        excel-math:cast-as-numeric($array4[1]) * 
        excel-math:cast-as-numeric($array5[1]) * 
        excel-math:cast-as-numeric($array6[1]) * 
        excel-math:cast-as-numeric($array7[1]) * 
        excel-math:cast-as-numeric($array8[1]) * 
        excel-math:cast-as-numeric($array9[1]) * 
        excel-math:cast-as-numeric($array10[1]) * 
        excel-math:cast-as-numeric($array11[1]) * 
        excel-math:cast-as-numeric($array12[1]) * 
        excel-math:cast-as-numeric($array13[1]) * 
        excel-math:cast-as-numeric($array14[1]) * 
        excel-math:cast-as-numeric($array15[1]) * 
        excel-math:cast-as-numeric($array16[1]) * 
        excel-math:cast-as-numeric($array17[1]) * 
        excel-math:cast-as-numeric($array18[1]) *
        excel-math:cast-as-numeric($array19[1]) *
        excel-math:cast-as-numeric($array20[1]) *
        excel-math:cast-as-numeric($array21[1]) *
        excel-math:cast-as-numeric($array22[1]) *
        excel-math:cast-as-numeric($array23[1]) *
        excel-math:cast-as-numeric($array24[1]) *
        excel-math:cast-as-numeric($array25[1]) *
        excel-math:cast-as-numeric($array26[1]) *
        excel-math:cast-as-numeric($array27[1]) *
        excel-math:cast-as-numeric($array28[1]) *
        excel-math:cast-as-numeric($array29[1]) *
        excel-math:cast-as-numeric($array30[1]) +
                    excel:sumproduct(  fn:subsequence($array1,2),
                                             fn:subsequence($array2,2),
                                             fn:subsequence($array3,2),
                                             fn:subsequence($array4,2),
                                             fn:subsequence($array5,2),
                                             fn:subsequence($array6,2),
                                             fn:subsequence($array7,2),
                                             fn:subsequence($array8,2),
                                             fn:subsequence($array9,2),
                                             fn:subsequence($array10,2),
                                             fn:subsequence($array11,2),
                                             fn:subsequence($array12,2),
                                             fn:subsequence($array13,2),
                                             fn:subsequence($array14,2),
                                             fn:subsequence($array15,2),
                                             fn:subsequence($array16,2),
                                             fn:subsequence($array17,2),
                                             fn:subsequence($array18,2),
                                             fn:subsequence($array19,2),
                                             fn:subsequence($array20,2),
                                             fn:subsequence($array21,2),
                                             fn:subsequence($array22,2),
                                             fn:subsequence($array23,2),
                                             fn:subsequence($array24,2),
                                             fn:subsequence($array25,2),
                                             fn:subsequence($array26,2),
                                             fn:subsequence($array27,2),
                                             fn:subsequence($array28,2),
                                             fn:subsequence($array29,2),
                                             fn:subsequence($array30,2))
 };

(:~
 : Returns the sum of the squares of the arguments.
 : It used the sumproduct function.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092951033.aspx
 : @param $numbers the sequence of one or more numbers or arguments castable to numeric
 : @return the sum of squared values, as numeric type
 : @error XQP0021(errValue) if the parameters cannot be casted to numeric type
 : @example rbkt/Queries/zorba/excel/math/sumsq1.xq
:)
 declare function excel:sumsq( $numbers as xs:anyAtomicType+) as xs:anyAtomicType
 {
   excel:sumproduct($numbers, $numbers)
 };
 
