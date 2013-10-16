xquery version '1.0';

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 
 (:
  : THIS FILE IS GENERATED.
  : PLEASE DO NOT EDIT.
  :)

(:~
 : This module contains one variable declaration for each diagnostic of the
 : http://zorba.io/errors namespace.
 : The variables serves as documentation for the errors but can also
 : be used in the code. For example, one useful scenario is to compare
 : an error caught in the catch clause of a try-catch expression with one of
 : the variables.
 :
 : @author Carlos Lopez
 : @project Zorba/Zorba Error Codes
 :
 :)

module namespace zerr = 'http://zorba.io/errors';

declare variable $zerr:NS := 'http://zorba.io/errors';

(:~
 :
 : An "error" constant for "no error."
 : 
:)
declare variable $zerr:ZXQP0000 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0000");

(:~
:)
declare variable $zerr:ZXQP0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0001");

(:~
 :
 : A Zorba programming assertion failed.  If this error occurs, it is a bug
 : and should be reported.
 : 
:)
declare variable $zerr:ZXQP0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0002");

(:~
 :
 : Something unexpected occurred in Zorba.  If this error occurs, it is a
 : bug and should be reported.
 : 
:)
declare variable $zerr:ZXQP0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0003");

(:~
 :
 : A particular XQuery feature has not been implemented by Zorba.
 : 
:)
declare variable $zerr:ZXQP0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0004");

(:~
 :
 : A particular XQuery feature has been implemented by Zorba, but the
 : feature has not been enabled in the current build.
 : 
:)
declare variable $zerr:ZXQP0005 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0005");

(:~
:)
declare variable $zerr:ZXQP0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0006");

(:~
:)
declare variable $zerr:ZXQP0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0007");

(:~
:)
declare variable $zerr:ZXQP0008 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0008");

(:~
:)
declare variable $zerr:ZXQP0009 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0009");

(:~
:)
declare variable $zerr:ZXQP0010 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0010");

(:~
:)
declare variable $zerr:ZXQP0011 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0011");

(:~
:)
declare variable $zerr:ZXQP0012 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0012");

(:~
:)
declare variable $zerr:ZXQP0013 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0013");

(:~
:)
declare variable $zerr:ZXQP0014 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0014");

(:~
:)
declare variable $zerr:ZXQP0016 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0016");

(:~
:)
declare variable $zerr:ZXQP0017 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0017");

(:~
:)
declare variable $zerr:ZXQP0020 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0020");

(:~
:)
declare variable $zerr:ZXQP0021 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0021");

(:~
:)
declare variable $zerr:ZXQP0024 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0024");

(:~
:)
declare variable $zerr:ZXQP0025 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0025");

(:~
:)
declare variable $zerr:ZXQP0026 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0026");

(:~
:)
declare variable $zerr:ZXQP0028 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0028");

(:~
:)
declare variable $zerr:ZXQP0029 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0029");

(:~
:)
declare variable $zerr:ZXQP0030 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0030");

(:~
:)
declare variable $zerr:ZXQP0031 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0031");

(:~
:)
declare variable $zerr:ZXQP0032 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0032");

(:~
:)
declare variable $zerr:ZXQP0033 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0033");

(:~
:)
declare variable $zerr:ZXQP0035 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0035");

(:~
:)
declare variable $zerr:ZXQP0036 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0036");

(:~
:)
declare variable $zerr:ZXQP0037 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0037");

(:~
:)
declare variable $zerr:ZXQP0038 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0038");

(:~
:)
declare variable $zerr:ZXQP0039 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0039");

(:~
:)
declare variable $zerr:ZXQP0040 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0040");

(:~
:)
declare variable $zerr:ZXQP0050 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0050");

(:~
:)
declare variable $zerr:ZXQP0060 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0060");

(:~
:)
declare variable $zerr:ZXQP0061 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP0061");

(:~
 :
 : The version of the thesaurus is not the expected version.
 : 
:)
declare variable $zerr:ZXQP8401 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP8401");

(:~
 :
 : The thesaurus data file's endianness does not match that of the CPU.
 : 
:)
declare variable $zerr:ZXQP8402 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP8402");

(:~
 :
 : The thesaurus data contains an unexpected value.
 : 
:)
declare variable $zerr:ZXQP8403 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQP8403");

(:~
:)
declare variable $zerr:ZXQD0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQD0001");

(:~
:)
declare variable $zerr:ZXQD0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQD0002");

(:~
:)
declare variable $zerr:ZXQD0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQD0003");

(:~
:)
declare variable $zerr:ZXQD0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQD0004");

(:~
:)
declare variable $zerr:ZXQD0005 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQD0005");

(:~
:)
declare variable $zerr:ZXQD0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZXQD0006");

(:~
:)
declare variable $zerr:ZAPI0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0002");

(:~
:)
declare variable $zerr:ZAPI0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0003");

(:~
:)
declare variable $zerr:ZAPI0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0004");

(:~
:)
declare variable $zerr:ZAPI0005 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0005");

(:~
:)
declare variable $zerr:ZAPI0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0006");

(:~
:)
declare variable $zerr:ZAPI0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0007");

(:~
:)
declare variable $zerr:ZAPI0008 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0008");

(:~
:)
declare variable $zerr:ZAPI0009 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0009");

(:~
:)
declare variable $zerr:ZAPI0011 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0011");

(:~
:)
declare variable $zerr:ZAPI0014 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0014");

(:~
:)
declare variable $zerr:ZAPI0015 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0015");

(:~
:)
declare variable $zerr:ZAPI0019 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0019");

(:~
:)
declare variable $zerr:ZAPI0020 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0020");

(:~
:)
declare variable $zerr:ZAPI0021 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0021");

(:~
:)
declare variable $zerr:ZAPI0023 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0023");

(:~
:)
declare variable $zerr:ZAPI0024 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0024");

(:~
:)
declare variable $zerr:ZAPI0025 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0025");

(:~
:)
declare variable $zerr:ZAPI0026 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0026");

(:~
:)
declare variable $zerr:ZAPI0027 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0027");

(:~
:)
declare variable $zerr:ZAPI0028 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0028");

(:~
:)
declare variable $zerr:ZAPI0029 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0029");

(:~
:)
declare variable $zerr:ZAPI0030 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0030");

(:~
:)
declare variable $zerr:ZAPI0039 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0039");

(:~
:)
declare variable $zerr:ZAPI0040 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0040");

(:~
:)
declare variable $zerr:ZAPI0041 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0041");

(:~
:)
declare variable $zerr:ZAPI0042 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0042");

(:~
:)
declare variable $zerr:ZAPI0043 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0043");

(:~
:)
declare variable $zerr:ZAPI0045 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0045");

(:~
:)
declare variable $zerr:ZAPI0070 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0070");

(:~
:)
declare variable $zerr:ZAPI0080 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0080");

(:~
:)
declare variable $zerr:ZAPI0090 as xs:QName := fn:QName($zerr:NS, "zerr:ZAPI0090");

(:~
:)
declare variable $zerr:ZCSE0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0001");

(:~
:)
declare variable $zerr:ZCSE0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0002");

(:~
:)
declare variable $zerr:ZCSE0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0003");

(:~
:)
declare variable $zerr:ZCSE0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0004");

(:~
:)
declare variable $zerr:ZCSE0005 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0005");

(:~
:)
declare variable $zerr:ZCSE0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0006");

(:~
:)
declare variable $zerr:ZCSE0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0007");

(:~
:)
declare variable $zerr:ZCSE0008 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0008");

(:~
:)
declare variable $zerr:ZCSE0009 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0009");

(:~
:)
declare variable $zerr:ZCSE0010 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0010");

(:~
:)
declare variable $zerr:ZCSE0011 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0011");

(:~
:)
declare variable $zerr:ZCSE0012 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0012");

(:~
:)
declare variable $zerr:ZCSE0013 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0013");

(:~
:)
declare variable $zerr:ZCSE0014 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0014");

(:~
:)
declare variable $zerr:ZCSE0015 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0015");

(:~
:)
declare variable $zerr:ZCSE0016 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0016");

(:~
:)
declare variable $zerr:ZCSE0017 as xs:QName := fn:QName($zerr:NS, "zerr:ZCSE0017");

(:~
:)
declare variable $zerr:ZDDY0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0001");

(:~
:)
declare variable $zerr:ZDDY0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0002");

(:~
:)
declare variable $zerr:ZDDY0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0003");

(:~
:)
declare variable $zerr:ZDDY0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0004");

(:~
:)
declare variable $zerr:ZDDY0005 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0005");

(:~
:)
declare variable $zerr:ZDDY0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0006");

(:~
:)
declare variable $zerr:ZDDY0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0007");

(:~
:)
declare variable $zerr:ZDDY0008 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0008");

(:~
:)
declare variable $zerr:ZDDY0009 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0009");

(:~
:)
declare variable $zerr:ZDDY0010 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0010");

(:~
:)
declare variable $zerr:ZDDY0011 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0011");

(:~
:)
declare variable $zerr:ZDDY0012 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0012");

(:~
:)
declare variable $zerr:ZDDY0013 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0013");

(:~
:)
declare variable $zerr:ZDDY0014 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0014");

(:~
:)
declare variable $zerr:ZDDY0015 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0015");

(:~
:)
declare variable $zerr:ZDDY0016 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0016");

(:~
:)
declare variable $zerr:ZDDY0017 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0017");

(:~
:)
declare variable $zerr:ZDDY0018 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0018");

(:~
:)
declare variable $zerr:ZDDY0020 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0020");

(:~
:)
declare variable $zerr:ZDDY0019 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0019");

(:~
:)
declare variable $zerr:ZDDY0021 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0021");

(:~
:)
declare variable $zerr:ZDDY0022 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0022");

(:~
:)
declare variable $zerr:ZDDY0023 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0023");

(:~
:)
declare variable $zerr:ZDDY0024 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0024");

(:~
:)
declare variable $zerr:ZDDY0025 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0025");

(:~
:)
declare variable $zerr:ZDDY0026 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0026");

(:~
:)
declare variable $zerr:ZDDY0027 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0027");

(:~
:)
declare variable $zerr:ZDDY0028 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0028");

(:~
:)
declare variable $zerr:ZDDY0029 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0029");

(:~
:)
declare variable $zerr:ZDDY0030 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0030");

(:~
:)
declare variable $zerr:ZDDY0031 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0031");

(:~
:)
declare variable $zerr:ZDDY0032 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0032");

(:~
:)
declare variable $zerr:ZDDY0033 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0033");

(:~
:)
declare variable $zerr:ZDDY0034 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0034");

(:~
:)
declare variable $zerr:ZDDY0035 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0035");

(:~
:)
declare variable $zerr:ZDDY0036 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0036");

(:~
:)
declare variable $zerr:ZDDY0037 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0037");

(:~
:)
declare variable $zerr:ZDDY0038 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0038");

(:~
:)
declare variable $zerr:ZDDY0039 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0039");

(:~
:)
declare variable $zerr:ZDDY0040 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0040");

(:~
:)
declare variable $zerr:ZDDY0041 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0041");

(:~
:)
declare variable $zerr:ZDDY0042 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0042");

(:~
:)
declare variable $zerr:ZDDY0043 as xs:QName := fn:QName($zerr:NS, "zerr:ZDDY0043");

(:~
:)
declare variable $zerr:ZDST0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0001");

(:~
:)
declare variable $zerr:ZDST0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0002");

(:~
:)
declare variable $zerr:ZDST0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0003");

(:~
:)
declare variable $zerr:ZDST0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0004");

(:~
:)
declare variable $zerr:ZDST0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0006");

(:~
:)
declare variable $zerr:ZDST0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0007");

(:~
:)
declare variable $zerr:ZDST0021 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0021");

(:~
:)
declare variable $zerr:ZDST0022 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0022");

(:~
:)
declare variable $zerr:ZDST0023 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0023");

(:~
:)
declare variable $zerr:ZDST0024 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0024");

(:~
:)
declare variable $zerr:ZDST0025 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0025");

(:~
:)
declare variable $zerr:ZDST0026 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0026");

(:~
:)
declare variable $zerr:ZDST0027 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0027");

(:~
:)
declare variable $zerr:ZDST0028 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0028");

(:~
:)
declare variable $zerr:ZDST0029 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0029");

(:~
:)
declare variable $zerr:ZDST0030 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0030");

(:~
:)
declare variable $zerr:ZDST0031 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0031");

(:~
:)
declare variable $zerr:ZDST0032 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0032");

(:~
:)
declare variable $zerr:ZDST0033 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0033");

(:~
:)
declare variable $zerr:ZDST0034 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0034");

(:~
:)
declare variable $zerr:ZDST0035 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0035");

(:~
:)
declare variable $zerr:ZDST0036 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0036");

(:~
:)
declare variable $zerr:ZDST0041 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0041");

(:~
:)
declare variable $zerr:ZDST0044 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0044");

(:~
:)
declare variable $zerr:ZDST0048 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0048");

(:~
:)
declare variable $zerr:ZDST0060 as xs:QName := fn:QName($zerr:NS, "zerr:ZDST0060");

(:~
:)
declare variable $zerr:ZDTY0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZDTY0001");

(:~
:)
declare variable $zerr:ZDTY0010 as xs:QName := fn:QName($zerr:NS, "zerr:ZDTY0010");

(:~
:)
declare variable $zerr:ZDTY0011 as xs:QName := fn:QName($zerr:NS, "zerr:ZDTY0011");

(:~
:)
declare variable $zerr:ZDTY0012 as xs:QName := fn:QName($zerr:NS, "zerr:ZDTY0012");


declare variable $zerr:ZGDB0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZGDB0001");

(:~
:)
declare variable $zerr:ZOSE0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZOSE0001");

(:~
:)
declare variable $zerr:ZOSE0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZOSE0002");

(:~
:)
declare variable $zerr:ZOSE0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZOSE0003");

(:~
:)
declare variable $zerr:ZOSE0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZOSE0004");

(:~
:)
declare variable $zerr:ZOSE0005 as xs:QName := fn:QName($zerr:NS, "zerr:ZOSE0005");

(:~
:)
declare variable $zerr:ZOSE0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZOSE0006");

(:~
:)
declare variable $zerr:ZOSE0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZOSE0007");

(:~
:)
declare variable $zerr:ZSTR0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0001");

(:~
:)
declare variable $zerr:ZSTR0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0002");

(:~
:)
declare variable $zerr:ZSTR0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0003");

(:~
:)
declare variable $zerr:ZSTR0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0004");

(:~
:)
declare variable $zerr:ZSTR0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0007");

(:~
:)
declare variable $zerr:ZSTR0008 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0008");

(:~
:)
declare variable $zerr:ZSTR0009 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0009");

(:~
:)
declare variable $zerr:ZSTR0010 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0010");

(:~
:)
declare variable $zerr:ZSTR0011 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0011");

(:~
:)
declare variable $zerr:ZSTR0012 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0012");

(:~
:)
declare variable $zerr:ZSTR0013 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0013");

(:~
:)
declare variable $zerr:ZSTR0015 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0015");

(:~
:)
declare variable $zerr:ZSTR0016 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0016");

(:~
:)
declare variable $zerr:ZSTR0020 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0020");

(:~
:)
declare variable $zerr:ZSTR0021 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0021");

(:~
:)
declare variable $zerr:ZSTR0030 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0030");

(:~
:)
declare variable $zerr:ZSTR0040 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0040");

(:~
:)
declare variable $zerr:ZSTR0041 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0041");

(:~
:)
declare variable $zerr:ZSTR0045 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0045");

(:~
:)
declare variable $zerr:ZSTR0050 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0050");

(:~
:)
declare variable $zerr:ZSTR0055 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0055");

(:~
:)
declare variable $zerr:ZSTR0060 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0060");

(:~
:)
declare variable $zerr:ZSTR0065 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0065");

(:~
:)
declare variable $zerr:ZSTR0066 as xs:QName := fn:QName($zerr:NS, "zerr:ZSTR0066");

(:~
:)
declare variable $zerr:XSST0001 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0001");

(:~
:)
declare variable $zerr:XSST0002 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0002");

(:~
:)
declare variable $zerr:XSST0003 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0003");

(:~
:)
declare variable $zerr:XSST0004 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0004");

(:~
:)
declare variable $zerr:XSST0005 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0005");

(:~
:)
declare variable $zerr:XSST0006 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0006");

(:~
:)
declare variable $zerr:XSST0007 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0007");

(:~
:)
declare variable $zerr:XSST0008 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0008");

(:~
:)
declare variable $zerr:XSST0009 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0009");

(:~
:)
declare variable $zerr:XSST0010 as xs:QName := fn:QName($zerr:NS, "zerr:XSST0010");

(:~
:)
declare variable $zerr:ZJPE0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0001");

(:~
:)
declare variable $zerr:ZJPE0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0002");

(:~
:)
declare variable $zerr:ZJPE0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0003");

(:~
:)
declare variable $zerr:ZJPE0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0004");

(:~
:)
declare variable $zerr:ZJPE0005 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0005");

(:~
:)
declare variable $zerr:ZJPE0006 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0006");

(:~
:)
declare variable $zerr:ZJPE0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0007");

(:~
:)
declare variable $zerr:ZJPE0008 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0008");

(:~
:)
declare variable $zerr:ZJPE0009 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0009");

(:~
:)
declare variable $zerr:ZJPE0010 as xs:QName := fn:QName($zerr:NS, "zerr:ZJPE0010");

(:~
:)
declare variable $zerr:ZJSE0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZJSE0001");

(:~
:)
declare variable $zerr:ZJSE0002 as xs:QName := fn:QName($zerr:NS, "zerr:ZJSE0002");

(:~
:)
declare variable $zerr:ZJSE0003 as xs:QName := fn:QName($zerr:NS, "zerr:ZJSE0003");

(:~
:)
declare variable $zerr:ZJSE0004 as xs:QName := fn:QName($zerr:NS, "zerr:ZJSE0004");

(:~
:)
declare variable $zerr:ZJSE0007 as xs:QName := fn:QName($zerr:NS, "zerr:ZJSE0007");

(:~
:)
declare variable $zerr:ZJSE0008 as xs:QName := fn:QName($zerr:NS, "zerr:ZJSE0008");

(:~
:)
declare variable $zerr:ZJSE0009 as xs:QName := fn:QName($zerr:NS, "zerr:ZJSE0009");

(:~
:)
declare variable $zerr:ZJ2X0001 as xs:QName := fn:QName($zerr:NS, "zerr:ZJ2X0001");