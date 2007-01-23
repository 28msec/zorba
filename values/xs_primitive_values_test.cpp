/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitive_values_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen (pcp071098@yahoo.com)
 */

#include "xs_primitive_values.h"
#include "../context/context.h"
#include <time.h>
#include <iostream>


using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	context ctx;
	struct tm time1 = { 10, 30, 12, 15, 5, 107, 0, 135, 0 };

	xs_anyURI_value t1("http://aa.bb.c..");
	xs_boolean_value t3(true);
	xs_decimal_value t4(1234);
	xs_integer_value t5(1234);
	xs_long_value t6(1234567);
	xs_int_value t7(1234567);
	xs_short_value t8(12345);
	xs_byte_value t9(123);

	xs_double_value t12(123.456);
	xs_float_value t16(123.456);

	xs_negativeInteger_value t32(-123);
	xs_nonNegativeInteger_value t33(123);
	xs_nonPositiveInteger_value t34(-123);
	xs_positiveInteger_value t36(123);
	xs_unsignedByte_value t40(250);
	xs_unsignedInt_value t41(2000000000);
	xs_unsignedLong_value t42(4000000000UL);
	xs_unsignedShort_value t43(65000);

	xs_date_value t10(time1);
	xs_time_value t38(time1);
	xs_dateTime_value t11(time1);
	xs_gMonth_value t18(time1);
	xs_gDay_value t17(time1);
	xs_gMonthDay_value t19(time1);
	xs_gYear_value t20(time1);
	xs_gYearMonth_value t21(time1);

	xs_duration_value t13(200000);

	xs_ENTITIES_value t14("entity");
	xs_ENTITY_value t15("entity");
	xs_ID_value t23("id");
	xs_IDREF_value t24("idref");
	xs_IDREFS_value t25("idrefs");
	xs_language_value t26("lang");
	xs_NCName_value t27("ncname");
	xs_NMTOKEN_value t28("nmtoken");
	xs_NMTOKENS_value t29("nmtokens");
	xs_NOTATION_value t30("notation");
	xs_Name_value t31("name");
	xs_normalizedString_value t35("normalized string");
	xs_string_value t37("string value");
	xs_token_value t39("token");

	//xs_base64Binary_value t2();
	//xs_hexBinary_value t22();


	cout << "xs_anyURI_value = "; t1.put(cout,ctx) << endl;
	cout << "xs_boolean_value = "; t3.put(cout,ctx) << endl;
	cout << "xs_decimal_value = "; t4.put(cout,ctx) << endl;
	cout << "xs_integer_value = "; t5.put(cout,ctx) << endl;
	cout << "xs_long_value = "; t6.put(cout,ctx) << endl;
	cout << "xs_int_value = "; t7.put(cout,ctx) << endl;
	cout << "xs_short_value = "; t8.put(cout,ctx) << endl;
	cout << "xs_byte_value = "; t9.put(cout,ctx) << endl;

	cout << "xs_double_value = "; t12.put(cout,ctx) << endl;
	cout << "xs_float_value = "; t16.put(cout,ctx) << endl;

	cout << "xs_negativeInteger_value = "; t32.put(cout,ctx) << endl;
	cout << "xs_nonNegativeInteger_value = "; t33.put(cout,ctx) << endl;
	cout << "xs_nonPositiveInteger_value = "; t34.put(cout,ctx) << endl;
	cout << "xs_positiveInteger_value = "; t36.put(cout,ctx) << endl;
	cout << "xs_unsignedByte_value = "; t40.put(cout,ctx) << endl;
	cout << "xs_unsignedInt_value = "; t41.put(cout,ctx) << endl;
	cout << "xs_unsignedLong_value = "; t42.put(cout,ctx) << endl;
	cout << "xs_unsignedShort_value = "; t43.put(cout,ctx) << endl;

	cout << "xs_date_value = "; t10.put(cout,ctx) << endl;
	cout << "xs_time_value = "; t38.put(cout,ctx) << endl;
	cout << "xs_dateTime_value = "; t11.put(cout,ctx) << endl;
	cout << "xs_gMonth_value = "; t18.put(cout,ctx) << endl;
	cout << "xs_gDay_value = "; t17.put(cout,ctx) << endl;
	cout << "xs_gMonthDay_value = "; t19.put(cout,ctx) << endl;
	cout << "xs_gYear_value = "; t20.put(cout,ctx) << endl;
	cout << "xs_gYearMonth_value = "; t21.put(cout,ctx) << endl;

	cout << "xs_duration_value = "; t13.put(cout,ctx) << endl;

	cout << "xs_ENTITIES_value = "; t14.put(cout,ctx) << endl;
	cout << "xs_ENTITY_value = "; t15.put(cout,ctx) << endl;
	cout << "xs_ID_value = "; t23.put(cout,ctx) << endl;
	cout << "xs_IDREF_value = "; t24.put(cout,ctx) << endl;
	cout << "xs_IDREFS_value = "; t25.put(cout,ctx) << endl;
	cout << "xs_language_value = "; t26.put(cout,ctx) << endl;
	cout << "xs_NCName_value = "; t27.put(cout,ctx) << endl;
	cout << "xs_NMTOKEN_value = "; t28.put(cout,ctx) << endl;
	cout << "xs_NMTOKENS_value = "; t29.put(cout,ctx) << endl;
	cout << "xs_NOTATION_value = "; t30.put(cout,ctx) << endl;
	cout << "xs_Name_value = "; t31.put(cout,ctx) << endl;
	cout << "xs_normalizedString_value = "; t35.put(cout,ctx) << endl;
	cout << "xs_string_value = "; t37.put(cout,ctx) << endl;
	cout << "xs_token_value = "; t39.put(cout,ctx) << endl;

	//xs_base64Binary_value t2();
	//xs_hexBinary_value t22();


}

