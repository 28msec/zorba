/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_value_factory_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "zorba_value_factory.h"
#include "values/primitive_values.h"
#include "runtime/zorba.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	zorba_value_factory factory;
	zorba zor;
	zorba* zorp = &zor;
	char* buf = "abcdefghijklmnopqrstuvwxyz";
	void* binaryBuf = buf;
	uint32_t n = 26;

  rchandle<atomic_value> qn =
		factory.make_qname("uri", "prefix", "localname");
	if (qn!=NULL)
		cout << "qname = " << qn->str(zorp) <<endl;
	else
		cout << "qname = NULL\n";

	rchandle<atomic_value> uri =
		factory.make_xs_anyURI("uri");
	if (uri!=NULL)
	  cout << "uri = " << uri->str(zorp) << endl;
	else
	  cout << "uri = NULL\n";

	rchandle<atomic_value> base64BinaryValue =
		factory.make_xs_base64Binary(binaryBuf,n);
	if (base64BinaryValue!=NULL)
		cout << "base64BinaryValue = " << base64BinaryValue->str(zorp) << endl;
	else
		cout << "base64BinaryValue = NULL\n";

	rchandle<atomic_value> booleanValue = 
		factory.make_xs_boolean(true);
	if (booleanValue!=NULL)
		cout << "booleanValue = " << booleanValue->str(zorp) << endl;
	else
		cout << "booleanValue = NULL\n";

	rchandle<atomic_value> decimalValue = 
		factory.make_xs_decimal(123456789123456789.12);
	if (decimalValue!=NULL)
		cout << "decimalValue = " << decimalValue->str(zorp) << endl;
	else
		cout << "decimalValue = NULL\n";

	rchandle<atomic_value> integerValue =
		factory.make_xs_integer(2000000000);
	if (integerValue!=NULL)
		cout << "integerValue = " << integerValue->str(zorp) << endl;
	else
		cout << "integerValue = NULL\n";

	rchandle<atomic_value> longValue =
		factory.make_xs_long(2000000000000000000LL);
	if (longValue!=NULL)
		cout << "longValue = " << longValue->str(zorp) << endl;
	else
		cout << "longValue = NULL\n";

	rchandle<atomic_value> intValue =
		factory.make_xs_int(2000000000);
	if (intValue!=NULL)
		cout << "intValue = " << intValue->str(zorp) << endl;
	else
		cout << "intValue = NULL\n";

	rchandle<atomic_value> shortValue =
		factory.make_xs_short(30000);
	if (shortValue!=NULL)
		cout << "shortValue = " << shortValue->str(zorp) << endl;
	else
		cout << "shortValue = NULL\n";

	rchandle<atomic_value> byteValue =
		factory.make_xs_byte(100);
	if (byteValue!=NULL)
		cout << "byteValue = " << byteValue->str(zorp) << endl;
	else
		cout << "byteValue = NULL\n";

	rchandle<atomic_value> dateValue =
		factory.make_xs_date();
	if (dateValue!=NULL)
		cout << "dateValue = " << dateValue->str(zorp) << endl;
	else
		cout << "dateValue = NULL\n";

	rchandle<atomic_value> dateTimeValue =
		factory.make_xs_dateTime();
	if (dateTimeValue!=NULL)
		cout << "dateTimeValue = " << dateTimeValue->str(zorp) << endl;
	else
		cout << "dateTimeValue = NULL\n";

	rchandle<atomic_value> doubleValue =
		factory.make_xs_double(2000000.123);
	if (doubleValue!=NULL)
		cout << "doubleValue = " << doubleValue->str(zorp) << endl;
	else
		cout << "doubleValue = NULL\n";

	rchandle<atomic_value> durationValue =
		factory.make_xs_duration();
	if (durationValue!=NULL)
		cout << "durationValue = " << durationValue->str(zorp) << endl;
	else
		cout << "durationValue = NULL\n";

	rchandle<atomic_value> ENTITIESValue =
		factory.make_xs_ENTITIES("&#123;");
	if (ENTITIESValue!=NULL)
		cout << "ENTITIESValue = " << ENTITIESValue->str(zorp) << endl;
	else
		cout << "ENTITIESValue = NULL\n";

	rchandle<atomic_value> ENTITYValue =
		factory.make_xs_ENTITY("&#123;");
	if (ENTITYValue!=NULL)
		cout << "ENTITYValue = " << ENTITYValue->str(zorp) << endl;
	else
		cout << "ENTITYValue = NULL\n";

	rchandle<atomic_value> floatValue =
		factory.make_xs_float(123456.789);
	if (floatValue!=NULL)
		cout << "floatValue = " << floatValue->str(zorp) << endl;
	else
		cout << "floatValue = NULL\n";

	rchandle<atomic_value> gDayValue =
		factory.make_xs_gDay();
	if (gDayValue!=NULL)
		cout << "gDayValue = " << gDayValue->str(zorp) << endl;
	else
		cout << "gDayValue = NULL\n";

	rchandle<atomic_value> gMonthValue =
		factory.make_xs_gMonth();
	if (gMonthValue!=NULL)
		cout << "gMonthValue = " << gMonthValue->str(zorp) << endl;
	else
		cout << "gMonthValue = NULL\n";

	rchandle<atomic_value> gMonthDayValue =
		factory.make_xs_gMonthDay();
	if (gMonthDayValue!=NULL)
		cout << "gMonthDayValue = " << gMonthDayValue->str(zorp) << endl;
	else
		cout << "gMonthDayValue = NULL\n";

	rchandle<atomic_value> gYearValue =
		factory.make_xs_gYear();
	if (gYearValue!=NULL)
		cout << "gYearValue = " << gYearValue->str(zorp) << endl;
	else
		cout << "gYearValue = NULL\n";

	rchandle<atomic_value> gYearMonthValue =
		factory.make_xs_gYearMonth();
	if (gYearMonthValue!=NULL)
		cout << "gYearMonthValue = " << gYearMonthValue->str(zorp) << endl;
	else
		cout << "gYearMonthValue = NULL\n";

	rchandle<atomic_value> hexBinaryValue =
		factory.make_xs_hexBinary(binaryBuf,n);
	if (hexBinaryValue!=NULL)
		cout << "hexBinaryValue = " << hexBinaryValue->str(zorp) << endl;
	else
		cout << "hexBinaryValue = NULL\n";

	rchandle<atomic_value> IDValue =
		factory.make_xs_ID("id");
	if (IDValue!=NULL)
		cout << "IDValue = " << IDValue->str(zorp) << endl;
	else
		cout << "IDValue = NULL\n";

	rchandle<atomic_value> IDREFValue =
		factory.make_xs_IDREF("idref");
	if (IDREFValue!=NULL)
		cout << "IDREFValue = " << IDREFValue->str(zorp) << endl;
	else
		cout << "IDREFValue = NULL\n";

	rchandle<atomic_value> IDREFSValue =
		factory.make_xs_IDREFS("idref idref");
	if (IDREFSValue!=NULL)
		cout << "IDREFSValue = " << IDREFSValue->str(zorp) << endl;
	else
		cout << "IDREFSValue = NULL\n";

	rchandle<atomic_value> languageValue =
		factory.make_xs_language("language");
	if (languageValue!=NULL)
		cout << "languageValue = " << languageValue->str(zorp) << endl;
	else
		cout << "languageValue = NULL\n";

	rchandle<atomic_value> NCNameValue =
		factory.make_xs_NCName("NCName");
	if (NCNameValue!=NULL)
		cout << "NCNameValue = " << NCNameValue->str(zorp) << endl;
	else
		cout << "NCNameValue = NULL\n";

	rchandle<atomic_value> NMTOKENValue =
		factory.make_xs_NMTOKEN("NMTOKEN");
	if (NMTOKENValue!=NULL)
		cout << "NMTOKENValue = " << NMTOKENValue->str(zorp) << endl;
	else
		cout << "NMTOKENValue = NULL\n";

	rchandle<atomic_value> NMTOKENSValue =
		factory.make_xs_NMTOKENS("NMTOKENS");
	if (NMTOKENSValue!=NULL)
		cout << "NMTOKENSValue = " << NMTOKENSValue->str(zorp) << endl;
	else
		cout << "NMTOKENSValue = NULL\n";

	rchandle<atomic_value> NOTATIONValue =
		factory.make_xs_NOTATION("NOTATION");
	if (NOTATIONValue!=NULL)
		cout << "NOTATIONValue = " << NOTATIONValue->str(zorp) << endl;
	else
		cout << "NOTATIONValue = NULL\n";

	rchandle<atomic_value> NameValue =
		factory.make_xs_Name("Name");
	if (NameValue!=NULL)
		cout << "NameValue = " << NameValue->str(zorp) << endl;
	else
		cout << "NameValue = NULL\n";

	rchandle<atomic_value> negativeIntegerValue =
		factory.make_xs_negativeInteger(-2000000000);
	if (negativeIntegerValue!=NULL)
		cout << "negativeIntegerValue = " << negativeIntegerValue->str(zorp) << endl;
	else
		cout << "negativeIntegerValue = NULL\n";

	rchandle<atomic_value> nonNegativeIntegerValue =
		factory.make_xs_nonNegativeInteger(0);
	if (nonNegativeIntegerValue!=NULL)
		cout << "nonNegativeIntegerValue = " << nonNegativeIntegerValue->str(zorp) << endl;
	else
		cout << "nonNegativeIntegerValue = NULL\n";

	rchandle<atomic_value> nonPositiveIntegerValue =
		factory.make_xs_nonPositiveInteger(-2000000000);
	if (nonPositiveIntegerValue!=NULL)
		cout << "nonPositiveIntegerValue = " << nonPositiveIntegerValue->str(zorp) << endl;
	else
		cout << "nonPositiveIntegerValue = NULL\n";

	rchandle<atomic_value> normalizedStringValue =
		factory.make_xs_normalizedString("normalized string");
	if (normalizedStringValue!=NULL)
		cout << "normalizedStringValue = " << normalizedStringValue->str(zorp) << endl;
	else
		cout << "normalizedStringValue = NULL\n";

	rchandle<atomic_value> positiveIntegerValue =
		factory.make_xs_positiveInteger(2000000000);
	if (positiveIntegerValue!=NULL)
		cout << "positiveIntegerValue = " << positiveIntegerValue->str(zorp) << endl;
	else
		cout << "positiveIntegerValue = NULL\n";

	rchandle<atomic_value> stringValue_1 =
		factory.make_xs_string("string_1");
	if (stringValue_1!=NULL)
		cout << "stringValue_1 = " << stringValue_1->str(zorp) << endl;
	else
		cout << "stringValue_1 = NULL\n";
		
	rchandle<atomic_value> stringValue_2 =
		factory.make_xs_string("string_2");
	if (stringValue_2!=NULL)
		cout << "stringValue_2 = " << stringValue_2->str(zorp) << endl;
	else
		cout << "stringValue_2 = NULL\n";

	rchandle<atomic_value> timeValue =
		factory.make_xs_time();
	if (timeValue!=NULL)
		cout << "timeValue = " << timeValue->str(zorp) << endl;
	else
		cout << "timeValue = NULL\n";

	rchandle<atomic_value> tokenValue =
		factory.make_xs_token("token");
	if (tokenValue!=NULL)
		cout << "tokenValue = " << tokenValue->str(zorp) << endl;
	else
		cout << "tokenValue = NULL\n";

	rchandle<atomic_value> unsignedByteValue =
		factory.make_xs_unsignedByte(200);
	if (unsignedByteValue!=NULL)
		cout << "unsignedByteValue = " << unsignedByteValue->str(zorp) << endl;
	else
		cout << "unsignedByteValue = NULL\n";

	rchandle<atomic_value> unsignedIntValue =
		factory.make_xs_unsignedInt(2000000000);
	if (unsignedIntValue!=NULL)
		cout << "unsignedIntValue = " << unsignedIntValue->str(zorp) << endl;
	else
		cout << "unsignedIntValue = NULL\n";

	rchandle<atomic_value> unsignedLongValue =
		factory.make_xs_unsignedLong(4000000000000000000LL);
	if (unsignedLongValue!=NULL)
		cout << "unsignedLongValue = " << unsignedLongValue->str(zorp) << endl;
	else
		cout << "unsignedLongValue = NULL\n";

	rchandle<atomic_value> unsignedShortValue =
		factory.make_xs_unsignedShort(60000);
	if (unsignedShortValue!=NULL)
		cout << "unsignedShortValue = " << unsignedShortValue->str(zorp) << endl;
	else
		cout << "unsignedShortValue = NULL\n";

}

