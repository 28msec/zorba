#ifndef EXTERNA_API_DYNAMIC_CONTEXT_WRAPPER_04_DEC_2007
#define EXTERNA_API_DYNAMIC_CONTEXT_WRAPPER_04_DEC_2007

#include "zorbatypes/representations.h"

#include <zorba/dynamic_context.h>

namespace zorba{

class static_context;
class dynamic_context;

class DynamicContextWrapper : public DynamicQueryContext
{
	typedef enum 
	{
		VAR_ATOMIC_ITEM,
		VAR_DOCUMENT_URI
	}var_type_t;
	typedef struct
	{
		xqp_string		varname;
		store::Item_t				atomic_item;
	}dctx_extern_var_t;

	std::vector<dctx_extern_var_t>		vars;
	xqp_string			default_collection_uri;

	struct ::tm			current_date_time;
	long						current_timezone_seconds;
	bool						is_datetime_initialized;

	store::Item_t					context_item;
public:
	DynamicContextWrapper();

	virtual ~DynamicContextWrapper( );

	virtual void		setCurrentDateTime( struct ::tm datetime, long timezone_seconds );
	virtual struct ::tm	getCurrentDateTime( long *timezone_seconds );

  virtual bool setVariableAsBigInteger( xqp_string varname, xqp_integer integer_value, VAR_BIGINT_TYPE type = XS_INTEGER);
  virtual bool setVariableAsBigUInteger( xqp_string varname, xqp_uinteger uinteger_value, VAR_BIGUINT_TYPE type = XS_NON_NEGATIVE_INTEGER);

  virtual bool setVariableAsDecimal( xqp_string varname, xqp_decimal decimal_value);

  virtual bool setVariableAsLong( xqp_string varname, xqp_long long_value);
  virtual bool setVariableAsULong( xqp_string varname, xqp_ulong ulong_value);
  virtual bool setVariableAsInt( xqp_string varname, xqp_int int_value);
  virtual bool setVariableAsUInt( xqp_string varname, xqp_uint uint_value);
  virtual bool setVariableAsShort( xqp_string varname, xqp_short short_value);
  virtual bool setVariableAsUShort( xqp_string varname, xqp_ushort ushort_value);
  virtual bool setVariableAsByte( xqp_string varname, xqp_byte byte_value);
  virtual bool setVariableAsUByte( xqp_string varname, xqp_ubyte ubyte_value);

  virtual bool setVariableAsString( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsNormalizedString( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsToken( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsLanguage( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsNMToken( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsName( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsNCName( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsID( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsIDREF( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsEntity( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsNotation( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsAnyURI( xqp_string varname, xqp_string str_value);
  virtual bool setVariableAsQName( xqp_string varname, xqp_string namespace_value, xqp_string prefix_value, xqp_string local_value);
  virtual bool setVariableAsUntypedAtomic( xqp_string varname, xqp_string str_value);

  virtual bool setVariableAsDouble( xqp_string varname, xqp_double double_value);
  virtual bool setVariableAsFloat( xqp_string varname, xqp_float float_value);

  virtual bool setVariableAsBool( xqp_string varname, xqp_boolean bool_value);

  virtual bool setVariableAsDateTime( xqp_string varname, struct ::tm datetime_value, long timezone_seconds);
  virtual bool setVariableAsDateTime( xqp_string varname, xqp_dateTime datetime_value);
  virtual bool setVariableAsDateTime( xqp_string varname, short year , short month, short day, short hour, short minute, short second, short timeZone );
  virtual bool setVariableAsDuration( xqp_string varname, xqp_duration duration_value);
  virtual bool setVariableAsDuration( xqp_string varname, short years, short months, short days, short hours, short minutes, short seconds);
  virtual bool setVariableAsDate( xqp_string varname, xqp_date date_value);
  virtual bool setVariableAsDate( xqp_string varname, short year , short month, short day);
  virtual bool setVariableAsTime( xqp_string varname, xqp_time time_value);
  virtual bool setVariableAsTime( xqp_string varname, short hour, short minute, short second, short timeZone );
  virtual bool setVariableAsGYearMonth( xqp_string varname, xqp_gYearMonth gyearmonth_value);
  virtual bool setVariableAsGYearMonth( xqp_string varname, short year , short month);
  virtual bool setVariableAsGYear( xqp_string varname, xqp_gYear gyear_value);
  virtual bool setVariableAsGYear( xqp_string varname, short year);
  virtual bool setVariableAsGMonthDay( xqp_string varname, xqp_gMonthDay gmonthday_value);
  virtual bool setVariableAsGMonthDay( xqp_string varname, short month , short day);
  virtual bool setVariableAsGDay( xqp_string varname, xqp_gDay gday_value);
  virtual bool setVariableAsGDay( xqp_string varname, short day);
  virtual bool setVariableAsGMonth( xqp_string varname, xqp_gMonth gmonth_value);
  virtual bool setVariableAsGMonth( xqp_string varname, short month);

  virtual bool setVariableAsItem( xqp_string varname, store::Item_t item);

	virtual bool setVariableAsDocument( xqp_string varname, xqp_anyURI documentURI);
	virtual bool setVariableAsDocumentFromFile(
																			xqp_string		varname,
																			xqp_string		file_path,
																			xqp_string    storeUri = "");

	virtual bool setVariableAsHexBinary( xqp_string varname, xqp_hexBinary hex_value);
	virtual bool setVariableAsBase64Binary( xqp_string varname, xqp_base64Binary base64_value);

	virtual bool deleteVariable( xqp_string varname );
	virtual void deleteAllVariables( );


	//set context item into dynamic context
  virtual bool setContextItemAsBigInteger( xqp_integer integer_value, VAR_BIGINT_TYPE type = XS_INTEGER);
  virtual bool setContextItemAsBigUInteger( xqp_uinteger uinteger_value, VAR_BIGUINT_TYPE type = XS_NON_NEGATIVE_INTEGER);

  virtual bool setContextItemAsDecimal( xqp_decimal decimal_value);

  virtual bool setContextItemAsLong( xqp_long long_value);
  virtual bool setContextItemAsULong( xqp_ulong ulong_value);
  virtual bool setContextItemAsInt( xqp_int int_value);
  virtual bool setContextItemAsUInt( xqp_uint uint_value);
  virtual bool setContextItemAsShort( xqp_short short_value);
  virtual bool setContextItemAsUShort( xqp_ushort ushort_value);
  virtual bool setContextItemAsByte( xqp_byte byte_value);
  virtual bool setContextItemAsUByte( xqp_ubyte ubyte_value);

  virtual bool setContextItemAsString( xqp_string str_value);
  virtual bool setContextItemAsNormalizedString( xqp_string str_value);
  virtual bool setContextItemAsToken( xqp_string str_value);
  virtual bool setContextItemAsLanguage( xqp_string str_value);
  virtual bool setContextItemAsNMToken( xqp_string str_value);
  virtual bool setContextItemAsName( xqp_string str_value);
  virtual bool setContextItemAsNCName( xqp_string str_value);
  virtual bool setContextItemAsID( xqp_string str_value);
  virtual bool setContextItemAsIDREF( xqp_string str_value);
  virtual bool setContextItemAsEntity( xqp_string str_value);
  virtual bool setContextItemAsNotation( xqp_string str_value);
  virtual bool setContextItemAsAnyURI( xqp_string str_value);
  virtual bool setContextItemAsQName( xqp_string namespace_value, xqp_string prefix_value, xqp_string local_value);
  virtual bool setContextItemAsUntypedAtomic( xqp_string str_value);

  virtual bool setContextItemAsDouble( xqp_double double_value);
  virtual bool setContextItemAsFloat( xqp_float float_value);

  virtual bool setContextItemAsBool( xqp_boolean bool_value);

  virtual bool setContextItemAsDateTime( struct ::tm datetime_value, long timezone_seconds);
  virtual bool setContextItemAsDateTime( xqp_dateTime datetime_value);
  virtual bool setContextItemAsDateTime( short year , short month, short day, short hour, short minute, short second, short timeZone );
  virtual bool setContextItemAsDuration( xqp_duration duration_value);
  virtual bool setContextItemAsDuration( short years, short months, short days, short hours, short minutes, short seconds);
  virtual bool setContextItemAsDate( xqp_date date_value);
  virtual bool setContextItemAsDate( short year , short month, short day);
  virtual bool setContextItemAsTime( xqp_time time_value);
  virtual bool setContextItemAsTime( short hour, short minute, short second, short timeZone );
  virtual bool setContextItemAsGYearMonth( xqp_gYearMonth gyearmonth_value);
  virtual bool setContextItemAsGYearMonth( short year , short month);
  virtual bool setContextItemAsGYear( xqp_gYear gyear_value);
  virtual bool setContextItemAsGYear( short year);
  virtual bool setContextItemAsGMonthDay( xqp_gMonthDay gmonthday_value);
  virtual bool setContextItemAsGMonthDay( short month , short day);
  virtual bool setContextItemAsGDay( xqp_gDay gday_value);
  virtual bool setContextItemAsGDay( short day);
  virtual bool setContextItemAsGMonth( xqp_gMonth gmonth_value);
  virtual bool setContextItemAsGMonth( short month);

  virtual bool setContextItemAsItem( store::Item_t item);

	virtual bool setContextItemAsDocument( xqp_anyURI documentURI);
	virtual bool setContextItemAsDocumentFromFile(
																					xqp_string		file_path,
																					xqp_string    storeUri = "");

	virtual bool setContextItemAsHexBinary( xqp_hexBinary hex_value);
	virtual bool setContextItemAsBase64Binary( xqp_base64Binary base64_value);


	virtual void setDefaultCollection( xqp_string collectionURI );

	dynamic_context*	create_dynamic_context(static_context *sctx);//and fill in with the values

public:
	static void	checkVarName(xqp_string varname);//check if var name is well formed
};

}//end namespace zorba

#endif


