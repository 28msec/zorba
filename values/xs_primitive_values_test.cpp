/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xs_primitiveValues_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen (pcp071098@yahoo.com)
 */

#include "xs_primitive_values.h"
#include "../store/itemstore.h"

#include <time.h>
#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	itemstore istore("data/itemstore");
	struct tm time1 = { 10, 30, 12, 15, 5, 107, 0, 135, 0 };

	xs_anyURIValue* t1 = new(istore) xs_anyURIValue("http://aa.bb.c..");
	xs_booleanValue* t3 = new(istore) xs_booleanValue(true);
	xs_decimalValue* t4 = new(istore) xs_decimalValue(1234);
	xs_integerValue* t5 = new(istore) xs_integerValue(1234);
	xs_longValue* t6 = new(istore) xs_longValue(1234567);
	xs_intValue* t7 = new(istore) xs_intValue(1234567);
	xs_shortValue* t8 = new(istore) xs_shortValue(12345);
	xs_byteValue* t9 = new(istore) xs_byteValue(123);

	xs_doubleValue* t12 = new(istore) xs_doubleValue(123.456);
	xs_floatValue* t16 = new(istore) xs_floatValue(123.456);

	xs_negativeIntegerValue* t32 = new(istore) xs_negativeIntegerValue(-123);
	xs_nonNegativeIntegerValue* t33 = new(istore) xs_nonNegativeIntegerValue(123);
	xs_nonPositiveIntegerValue* t34 = new(istore) xs_nonPositiveIntegerValue(-123);
	xs_positiveIntegerValue* t36 = new(istore) xs_positiveIntegerValue(123);
	xs_unsignedByteValue* t40 = new(istore) xs_unsignedByteValue(250);
	xs_unsignedIntValue* t41 = new(istore) xs_unsignedIntValue(2000000000);
	xs_unsignedLongValue* t42 = new(istore) xs_unsignedLongValue(4000000000UL);
	xs_unsignedShortValue* t43 = new(istore) xs_unsignedShortValue(65000);

	xs_dateValue* t10 = new(istore) xs_dateValue(time1);
	xs_timeValue* t38 = new(istore) xs_timeValue(time1);
	xs_dateTimeValue* t11 = new(istore) xs_dateTimeValue(time1);
	xs_gMonthValue* t18 = new(istore) xs_gMonthValue(time1);
	xs_gDayValue* t17 = new(istore) xs_gDayValue(time1);
	xs_gMonthDayValue* t19 = new(istore) xs_gMonthDayValue(time1);
	xs_gYearValue* t20 = new(istore) xs_gYearValue(time1);
	xs_gYearMonthValue* t21 = new(istore) xs_gYearMonthValue(time1);

	xs_durationValue* t13 = new(istore) xs_durationValue(200000);

	xs_ENTITIESValue* t14 = new(istore) xs_ENTITIESValue("entity");
	xs_ENTITYValue* t15 = new(istore) xs_ENTITYValue("entity");
	xs_IDValue* t23 = new(istore) xs_IDValue("id");
	xs_IDREFValue* t24 = new(istore) xs_IDREFValue("idref");
	xs_IDREFSValue* t25 = new(istore) xs_IDREFSValue("idrefs");
	xs_languageValue* t26 = new(istore) xs_languageValue("lang");
	xs_NCNameValue* t27 = new(istore) xs_NCNameValue("ncname");
	xs_NMTOKENValue* t28 = new(istore) xs_NMTOKENValue("nmtoken");
	xs_NMTOKENSValue* t29 = new(istore) xs_NMTOKENSValue("nmtokens");
	xs_NOTATIONValue* t30 = new(istore) xs_NOTATIONValue("notation");
	xs_NameValue* t31 = new(istore) xs_NameValue("name");
	xs_normalizedStringValue* t35 = new(istore) xs_normalizedStringValue("normalized string");
	xs_stringValue* t37 = new(istore) xs_stringValue(istore,"string value");
	xs_tokenValue* t39 = new(istore) xs_tokenValue("token");

	//xs_base64BinaryValue t2();
	//xs_hexBinaryValue t22();

	cout << "xs_anyURIValue = "; t1->put(cout) << endl;
	cout << "xs_booleanValue = "; t3->put(cout) << endl;
	cout << "xs_decimalValue = "; t4->put(cout) << endl;
	cout << "xs_integerValue = "; t5->put(cout) << endl;
	cout << "xs_longValue = "; t6->put(cout) << endl;
	cout << "xs_intValue = "; t7->put(cout) << endl;
	cout << "xs_shortValue = "; t8->put(cout) << endl;
	cout << "xs_byteValue = "; t9->put(cout) << endl;

	cout << "xs_doubleValue = "; t12->put(cout) << endl;
	cout << "xs_floatValue = "; t16->put(cout) << endl;

	cout << "xs_negativeIntegerValue = "; t32->put(cout) << endl;
	cout << "xs_nonNegativeIntegerValue = "; t33->put(cout) << endl;
	cout << "xs_nonPositiveIntegerValue = "; t34->put(cout) << endl;
	cout << "xs_positiveIntegerValue = "; t36->put(cout) << endl;
	cout << "xs_unsignedByteValue = "; t40->put(cout) << endl;
	cout << "xs_unsignedIntValue = "; t41->put(cout) << endl;
	cout << "xs_unsignedLongValue = "; t42->put(cout) << endl;
	cout << "xs_unsignedShortValue = "; t43->put(cout) << endl;

	cout << "xs_dateValue = "; t10->put(cout) << endl;
	cout << "xs_timeValue = "; t38->put(cout) << endl;
	cout << "xs_dateTimeValue = "; t11->put(cout) << endl;
	cout << "xs_gMonthValue = "; t18->put(cout) << endl;
	cout << "xs_gDayValue = "; t17->put(cout) << endl;
	cout << "xs_gMonthDayValue = "; t19->put(cout) << endl;
	cout << "xs_gYearValue = "; t20->put(cout) << endl;
	cout << "xs_gYearMonthValue = "; t21->put(cout) << endl;

	cout << "xs_durationValue = "; t13->put(cout) << endl;

	cout << "xs_ENTITIESValue = "; t14->put(cout) << endl;
	cout << "xs_ENTITYValue = "; t15->put(cout) << endl;
	cout << "xs_IDValue = "; t23->put(cout) << endl;
	cout << "xs_IDREFValue = "; t24->put(cout) << endl;
	cout << "xs_IDREFSValue = "; t25->put(cout) << endl;
	cout << "xs_languageValue = "; t26->put(cout) << endl;
	cout << "xs_NCNameValue = "; t27->put(cout) << endl;
	cout << "xs_NMTOKENValue = "; t28->put(cout) << endl;
	cout << "xs_NMTOKENSValue = "; t29->put(cout) << endl;
	cout << "xs_NOTATIONValue = "; t30->put(cout) << endl;
	cout << "xs_NameValue = "; t31->put(cout) << endl;
	cout << "xs_normalizedStringValue = "; t35->put(cout) << endl;
	cout << "xs_stringValue = "; t37->put(cout) << endl;
	cout << "xs_tokenValue = "; t39->put(cout) << endl;

	//xs_base64BinaryValue t2();
	//xs_hexBinaryValue t22();


}

