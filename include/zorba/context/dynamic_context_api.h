
#ifndef DYNAMIC_CONTEXT_API_12_DEC_2007
#define DYNAMIC_CONTEXT_API_12_DEC_2007

#include <time.h>
#include "zorba/util/rchandle.h"
#include "zorba/types/representations.h"


namespace xqp {

class Item;
typedef rchandle<Item>    Item_t;

class DynamicQueryContext : public SimpleRCObject
{
public:
	typedef enum
	{
    XS_INTEGER,//derived from XS_DECIMAL
    XS_NON_POSITIVE_INTEGER,//derived from XS_INTEGER
    XS_NEGATIVE_INTEGER//derived from XS_NON_POSITIVE_INTEGER
	}VAR_BIGINT_TYPE;
	typedef enum
	{
    XS_NON_NEGATIVE_INTEGER,//derived from XS_INTEGER
    XS_POSITIVE_INTEGER//derived from XS_NON_NEGATIVE_INTEGER
	}VAR_BIGUINT_TYPE;
public:
//	struct ::tm  current_date_time;//includes the explicit timezone
  long     implicit_timezone_seconds;

  virtual ~DynamicQueryContext( ) {};

	virtual void		setCurrentDateTime( struct ::tm datetime, long timezone_seconds ) = 0;
	virtual struct ::tm	getCurrentDateTime( long *timezone_seconds ) = 0;

	//set variables into dynamic context
  virtual bool setVariableAsBigInteger( xqp_string varname, xqp_integer integer_value, VAR_BIGINT_TYPE type = XS_INTEGER) = 0;
  virtual bool setVariableAsBigUInteger( xqp_string varname, xqp_uinteger uinteger_value, VAR_BIGUINT_TYPE type = XS_NON_NEGATIVE_INTEGER) = 0;

  virtual bool setVariableAsDecimal( xqp_string varname, xqp_decimal decimal_value) = 0;

  virtual bool setVariableAsLong( xqp_string varname, xqp_long long_value) = 0;
  virtual bool setVariableAsULong( xqp_string varname, xqp_ulong ulong_value) = 0;
  virtual bool setVariableAsInt( xqp_string varname, xqp_int int_value) = 0;
  virtual bool setVariableAsUInt( xqp_string varname, xqp_uint uint_value) = 0;
  virtual bool setVariableAsShort( xqp_string varname, xqp_short short_value) = 0;
  virtual bool setVariableAsUShort( xqp_string varname, xqp_ushort ushort_value) = 0;
  virtual bool setVariableAsByte( xqp_string varname, xqp_byte byte_value) = 0;
  virtual bool setVariableAsUByte( xqp_string varname, xqp_ubyte ubyte_value) = 0;

  virtual bool setVariableAsString( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsNormalizedString( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsToken( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsLanguage( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsNMToken( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsName( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsNCName( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsID( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsIDREF( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsEntity( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsNotation( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsAnyURI( xqp_string varname, xqp_string str_value) = 0;
  virtual bool setVariableAsQName( xqp_string varname, xqp_string namespace_value, xqp_string prefix_value, xqp_string local_value) = 0;
  virtual bool setVariableAsUntypedAtomic( xqp_string varname, xqp_string str_value) = 0;

  virtual bool setVariableAsDouble( xqp_string varname, xqp_double double_value) = 0;
  virtual bool setVariableAsFloat( xqp_string varname, xqp_float float_value) = 0;

  virtual bool setVariableAsBool( xqp_string varname, xqp_boolean bool_value) = 0;

  virtual bool setVariableAsDateTime( xqp_string varname, struct ::tm datetime_value, long timezone_seconds) = 0;
  virtual bool setVariableAsDateTime( xqp_string varname, xqp_dateTime datetime_value) = 0;
  virtual bool setVariableAsDateTime( xqp_string varname, short year , short month, short day, short hour, short minute, short second, short timeZone ) = 0;
  virtual bool setVariableAsDuration( xqp_string varname, xqp_duration duration_value) = 0;
  virtual bool setVariableAsDuration( xqp_string varname, short years, short months, short days, short hours, short minutes, short seconds) = 0;
  virtual bool setVariableAsDate( xqp_string varname, xqp_date date_value) = 0;
  virtual bool setVariableAsDate( xqp_string varname, short year , short month, short day) = 0;
  virtual bool setVariableAsTime( xqp_string varname, xqp_time time_value) = 0;
  virtual bool setVariableAsTime( xqp_string varname, short hour, short minute, short second, short timeZone ) = 0;
  virtual bool setVariableAsGYearMonth( xqp_string varname, xqp_gYearMonth gyearmonth_value) = 0;
  virtual bool setVariableAsGYearMonth( xqp_string varname, short year , short month) = 0;
  virtual bool setVariableAsGYear( xqp_string varname, xqp_gYear gyear_value) = 0;
  virtual bool setVariableAsGYear( xqp_string varname, short year) = 0;
  virtual bool setVariableAsGMonthDay( xqp_string varname, xqp_gMonthDay gmonthday_value) = 0;
  virtual bool setVariableAsGMonthDay( xqp_string varname, short month , short day) = 0;
  virtual bool setVariableAsGDay( xqp_string varname, xqp_gDay gday_value) = 0;
  virtual bool setVariableAsGDay( xqp_string varname, short day) = 0;
  virtual bool setVariableAsGMonth( xqp_string varname, xqp_gMonth gmonth_value) = 0;
  virtual bool setVariableAsGMonth( xqp_string varname, short month) = 0;

  virtual bool setVariableAsItem( xqp_string varname, Item_t item) = 0;

	virtual bool setVariableAsDocument( xqp_string varname, xqp_anyURI documentURI) = 0;
	virtual bool setVariableAsDocumentFromFile(
																			xqp_string		varname,
																			xqp_string		file_path,
																			xqp_string    storeUri = "") = 0;

	virtual bool setVariableAsHexBinary( xqp_string varname, xqp_hexBinary hex_value) = 0;
	virtual bool setVariableAsBase64Binary( xqp_string varname, xqp_base64Binary base64_value) = 0;


	virtual bool deleteVariable( xqp_string varname ) = 0;
  virtual void deleteAllVariables( ) = 0;




	//set context item into dynamic context
  virtual bool setContextItemAsBigInteger( xqp_integer integer_value, VAR_BIGINT_TYPE type = XS_INTEGER) = 0;
  virtual bool setContextItemAsBigUInteger( xqp_uinteger uinteger_value, VAR_BIGUINT_TYPE type = XS_NON_NEGATIVE_INTEGER) = 0;

  virtual bool setContextItemAsDecimal( xqp_decimal decimal_value) = 0;

  virtual bool setContextItemAsLong( xqp_long long_value) = 0;
  virtual bool setContextItemAsULong( xqp_ulong ulong_value) = 0;
  virtual bool setContextItemAsInt( xqp_int int_value) = 0;
  virtual bool setContextItemAsUInt( xqp_uint uint_value) = 0;
  virtual bool setContextItemAsShort( xqp_short short_value) = 0;
  virtual bool setContextItemAsUShort( xqp_ushort ushort_value) = 0;
  virtual bool setContextItemAsByte( xqp_byte byte_value) = 0;
  virtual bool setContextItemAsUByte( xqp_ubyte ubyte_value) = 0;

  virtual bool setContextItemAsString( xqp_string str_value) = 0;
  virtual bool setContextItemAsNormalizedString( xqp_string str_value) = 0;
  virtual bool setContextItemAsToken( xqp_string str_value) = 0;
  virtual bool setContextItemAsLanguage( xqp_string str_value) = 0;
  virtual bool setContextItemAsNMToken( xqp_string str_value) = 0;
  virtual bool setContextItemAsName( xqp_string str_value) = 0;
  virtual bool setContextItemAsNCName( xqp_string str_value) = 0;
  virtual bool setContextItemAsID( xqp_string str_value) = 0;
  virtual bool setContextItemAsIDREF( xqp_string str_value) = 0;
  virtual bool setContextItemAsEntity( xqp_string str_value) = 0;
  virtual bool setContextItemAsNotation( xqp_string str_value) = 0;
  virtual bool setContextItemAsAnyURI( xqp_string str_value) = 0;
  virtual bool setContextItemAsQName( xqp_string namespace_value, xqp_string prefix_value, xqp_string local_value) = 0;
  virtual bool setContextItemAsUntypedAtomic( xqp_string str_value) = 0;

  virtual bool setContextItemAsDouble( xqp_double double_value) = 0;
  virtual bool setContextItemAsFloat( xqp_float float_value) = 0;

  virtual bool setContextItemAsBool( xqp_boolean bool_value) = 0;

  virtual bool setContextItemAsDateTime( struct ::tm datetime_value, long timezone_seconds) = 0;
  virtual bool setContextItemAsDateTime( xqp_dateTime datetime_value) = 0;
  virtual bool setContextItemAsDateTime( short year , short month, short day, short hour, short minute, short second, short timeZone ) = 0;
  virtual bool setContextItemAsDuration( xqp_duration duration_value) = 0;
  virtual bool setContextItemAsDuration( short years, short months, short days, short hours, short minutes, short seconds) = 0;
  virtual bool setContextItemAsDate( xqp_date date_value) = 0;
  virtual bool setContextItemAsDate( short year , short month, short day) = 0;
  virtual bool setContextItemAsTime( xqp_time time_value) = 0;
  virtual bool setContextItemAsTime( short hour, short minute, short second, short timeZone ) = 0;
  virtual bool setContextItemAsGYearMonth( xqp_gYearMonth gyearmonth_value) = 0;
  virtual bool setContextItemAsGYearMonth( short year , short month) = 0;
  virtual bool setContextItemAsGYear( xqp_gYear gyear_value) = 0;
  virtual bool setContextItemAsGYear( short year) = 0;
  virtual bool setContextItemAsGMonthDay( xqp_gMonthDay gmonthday_value) = 0;
  virtual bool setContextItemAsGMonthDay( short month , short day) = 0;
  virtual bool setContextItemAsGDay( xqp_gDay gday_value) = 0;
  virtual bool setContextItemAsGDay( short day) = 0;
  virtual bool setContextItemAsGMonth( xqp_gMonth gmonth_value) = 0;
  virtual bool setContextItemAsGMonth( short month) = 0;

  virtual bool setContextItemAsItem( Item_t item) = 0;

	virtual bool setContextItemAsDocument( xqp_anyURI documentURI) = 0;
	virtual bool setContextItemAsDocumentFromFile(
																				xqp_string		file_path,
																				xqp_string    storeUri = "") = 0;

	virtual bool setContextItemAsHexBinary( xqp_hexBinary hex_value) = 0;
	virtual bool setContextItemAsBase64Binary( xqp_base64Binary base64_value) = 0;

  // register documents available through fn:doc() in xquery
  // virtual bool RegisterAvailableDocument(xqp_string docURI,
  //                                      xqp_string store_docURI) = 0;
  // register collections available through fn:collection() in xquery
  // default collection has empty URI ""
  // virtual bool RegisterAvailableCollection(xqp_string collectionURI,
  //                                          xqp_string store_collectionURI) = 0;

  virtual void setDefaultCollection( xqp_string collectionURI ) = 0;
};

typedef rchandle<DynamicQueryContext> DynamicQueryContext_t;

} // end namespace xqp

#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
