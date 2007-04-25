/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: value_factory_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "value_factory.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	value_factory* vf_p = new value_factory();

	qname_value* qname = vf_p->make_qname("uri", "prefix", "localname");
	if (qname)
		cout << "qname["<<qname->length()<<"] = "<<qname->string_value()<<endl;

	uri_value* uri = vf_p->make_uri("uri");
	if (uri)
	cout << "uri = " << uri->string_value() << endl;


	xs_anyURIValue* anyURIValue = vf_p->make_xs_anyURI();
	if (anyURIValue)
		cout << "anyURIValue = " << anyURIValue->string_value() << endl;

	xs_base64BinaryValue* base64BinaryValue = vf_p->make_xs_base64Binary();
	if (base64BinaryValue)
		cout << "base64BinaryValue = " << base64BinaryValue->string_value() << endl;

	xs_booleanValue* booleanValue = vf_p->make_xs_boolean(true);
	if (booleanValue)
		cout << "booleanValue = " << booleanValue->string_value() << endl;

	xs_decimalValue* decimalValue = vf_p->make_xs_decimal();
	if (decimalValue)
		cout << "decimalValue = " << decimalValue->string_value() << endl;

	xs_integerValue* integerValue = vf_p->make_xs_integer(123);
	if (integerValue)
		cout << "integerValue = " << integerValue->string_value() << endl;

	xs_longValue* longValue = vf_p->make_xs_long(123);
	if (longValue)
		cout << "longValue = " << longValue->string_value() << endl;

	xs_intValue* intValue = vf_p->make_xs_int(123);
	if (intValue)
		cout << "intValue = " << intValue->string_value() << endl;

	xs_shortValue* shortValue = vf_p->make_xs_short(123);
	if (shortValue)
		cout << "shortValue = " << shortValue->string_value() << endl;

	xs_byteValue* byteValue = vf_p->make_xs_byte(123);
	if (byteValue)
		cout << "byteValue = " << byteValue->string_value() << endl;

	xs_dateValue* dateValue = vf_p->make_xs_date();
	if (dateValue)
		cout << "dateValue = " << dateValue->string_value() << endl;

	xs_dateTimeValue* dateTimeValue = vf_p->make_xs_dateTime();
	if (dateTimeValue)
		cout << "dateTimeValue = " << dateTimeValue->string_value() << endl;

	xs_doubleValue* doubleValue = vf_p->make_xs_double(1.23);
	if (doubleValue)
		cout << "doubleValue = " << doubleValue->string_value() << endl;

	xs_durationValue* durationValue = vf_p->make_xs_duration();
	if (durationValue)
		cout << "durationValue = " << durationValue->string_value() << endl;

	xs_ENTITIESValue* ENTITIESValue = vf_p->make_xs_ENTITIES();
	if (ENTITIESValue)
		cout << "ENTITIESValue = " << ENTITIESValue->string_value() << endl;

	xs_ENTITYValue* ENTITYValue = vf_p->make_xs_ENTITY();
	if (ENTITYValue)
		cout << "ENTITYValue = " << ENTITYValue->string_value() << endl;

	xs_floatValue* floatValue = vf_p->make_xs_float(1.23);
	if (floatValue)
		cout << "floatValue = " << floatValue->string_value() << endl;

	xs_gDayValue* gDayValue = vf_p->make_xs_gDay();
	if (gDayValue)
		cout << "gDayValue = " << gDayValue->string_value() << endl;

	xs_gMonthValue* gMonthValue = vf_p->make_xs_gMonth();
	if (gMonthValue)
		cout << "gMonthValue = " << gMonthValue->string_value() << endl;

	xs_gMonthDayValue* gMonthDayValue = vf_p->make_xs_gMonthDay();
	if (gMonthDayValue)
		cout << "gMonthDayValue = " << gMonthDayValue->string_value() << endl;

	xs_gYearValue* gYearValue = vf_p->make_xs_gYear();
	if (gYearValue)
		cout << "gYearValue = " << gYearValue->string_value() << endl;

	xs_gYearMonthValue* gYearMonthValue = vf_p->make_xs_gYearMonth();
	if (gYearMonthValue)
		cout << "gYearMonthValue = " << gYearMonthValue->string_value() << endl;

	xs_hexBinaryValue* hexBinaryValue = vf_p->make_xs_hexBinary();
	if (hexBinaryValue)
		cout << "hexBinaryValue = " << hexBinaryValue->string_value() << endl;

	xs_IDValue* IDValue = vf_p->make_xs_ID();
	if (IDValue)
		cout << "IDValue = " << IDValue->string_value() << endl;

	xs_IDREFValue* IDREFValue = vf_p->make_xs_IDREF();
	if (IDREFValue)
		cout << "IDREFValue = " << IDREFValue->string_value() << endl;

	xs_IDREFSValue* IDREFSValue = vf_p->make_xs_IDREFS();
	if (IDREFSValue)
		cout << "IDREFSValue = " << IDREFSValue->string_value() << endl;


	xs_languageValue* languageValue = vf_p->make_xs_language("language");
	if (languageValue)
		cout << "languageValue = " << languageValue->string_value() << endl;

	xs_NCNameValue* NCNameValue = vf_p->make_xs_NCName("NCName");
	if (NCNameValue)
		cout << "NCNameValue = " << NCNameValue->string_value() << endl;

	xs_NMTOKENValue* NMTOKENValue = vf_p->make_xs_NMTOKEN("NMTOKEN");
	if (NMTOKENValue)
		cout << "NMTOKENValue = " << NMTOKENValue->string_value() << endl;

	xs_NMTOKENSValue* NMTOKENSValue = vf_p->make_xs_NMTOKENS("NMTOKENS");
	if (NMTOKENSValue)
		cout << "NMTOKENSValue = " << NMTOKENSValue->string_value() << endl;

	xs_NOTATIONValue* NOTATIONValue = vf_p->make_xs_NOTATION("NOTATION");
	if (NOTATIONValue)
		cout << "NOTATIONValue = " << NOTATIONValue->string_value() << endl;

	xs_NameValue* NameValue = vf_p->make_xs_Name("Name");
	if (NameValue)
		cout << "NameValue = " << NameValue->string_value() << endl;


	xs_negativeIntegerValue* negativeIntegerValue =
		vf_p->make_xs_negativeInteger(-1);
	if (negativeIntegerValue)
		cout << "negativeIntegerValue = " << negativeIntegerValue->string_value() << endl;

	xs_nonNegativeIntegerValue* nonNegativeIntegerValue =
		vf_p->make_xs_nonNegativeInteger(0);
	if (nonNegativeIntegerValue)
		cout << "nonNegativeIntegerValue = " << nonNegativeIntegerValue->string_value() << endl;

	xs_nonPositiveIntegerValue* nonPositiveIntegerValue =
		vf_p->make_xs_nonPositiveInteger(-1);
	if (nonPositiveIntegerValue)
		cout << "nonPositiveIntegerValue = " << nonPositiveIntegerValue->string_value() << endl;

	xs_normalizedStringValue* normalizedStringValue =
		vf_p->make_xs_normalizedString("normalized string");
	if (normalizedStringValue)
		cout << "normalizedStringValue = " << normalizedStringValue->string_value() << endl;

	xs_positiveIntegerValue* positiveIntegerValue =
		vf_p->make_xs_positiveInteger(1);
	if (positiveIntegerValue)
		cout << "positiveIntegerValue = " << positiveIntegerValue->string_value() << endl;


	xs_stringValue* stringValue_1 = vf_p->make_xs_string("string_1");
	if (stringValue_1)
		cout << "stringValue_1 = " << stringValue_1->string_value() << endl;
	xs_stringValue* stringValue_2 = vf_p->make_xs_string("string_2");
	if (stringValue_2)
		cout << "stringValue_2 = " << stringValue_2->string_value() << endl;


	xs_timeValue* timeValue = vf_p->make_xs_time();
	if (timeValue)
		cout << "timeValue = " << timeValue->string_value() << endl;

	xs_tokenValue* tokenValue = vf_p->make_xs_token("token");
	if (tokenValue)
		cout << "tokenValue = " << tokenValue->string_value() << endl;


	xs_unsignedByteValue* unsignedByteValue = vf_p->make_xs_unsignedByte(123);
	if (unsignedByteValue)
		cout << "unsignedByteValue = " << unsignedByteValue->string_value() << endl;

	xs_unsignedIntValue* unsignedIntValue = vf_p->make_xs_unsignedInt(123);
	if (unsignedIntValue)
		cout << "unsignedIntValue = " << unsignedIntValue->string_value() << endl;

	xs_unsignedLongValue* unsignedLongValue = vf_p->make_xs_unsignedLong(123);
	if (unsignedLongValue)
		cout << "unsignedLongValue = " << unsignedLongValue->string_value() << endl;

	xs_unsignedShortValue* unsignedShortValue = vf_p->make_xs_unsignedShort(123);
	if (unsignedShortValue)
		cout << "unsignedShortValue = " << unsignedShortValue->string_value() << endl;

}

