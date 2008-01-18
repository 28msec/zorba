
#ifndef DYNAMIC_CONTEXT_API_12_DEC_2007
#define DYNAMIC_CONTEXT_API_12_DEC_2007

#include <time.h>
#include "zorba/util/rchandle.h"
#include "zorba/types/representations.h"
#include "zorba/store/api/item.h"

namespace xqp {

class DynamicQueryContext : public rcobject
{
public:
  typedef enum
  {
    //XS_DECIMAL,//derived from XS_ANY_ATOMIC_TYPE
    XS_INTEGER,//derived from XS_DECIMAL
    XS_NON_POSITIVE_INTEGER,//derived from XS_INTEGER
    XS_NEGATIVE_INTEGER,//derived from XS_NON_POSITIVE_INTEGER
    XS_LONG,//derived from XS_INTEGER
    XS_INT,//derived from XS_LONG
    XS_SHORT,//derived from XS_INT
    XS_BYTE,//derived from XS_SHORT
    XS_NON_NEGATIVE_INTEGER,//derived from XS_INTEGER
    XS_UNSIGNED_LONG,//derived from XS_NON_NEGATIVE_INTEGER
    XS_UNSIGNED_INT,//derived from XS_UNSIGNED_LONG
    XS_UNSIGNED_SHORT,//derived from XS_UNSIGNED_INT
    XS_UNSIGNED_BYTE,//derived from XS_UNSIGNED_SHORT
    XS_POSITIVE_INTEGER//derived from XS_NON_NEGATIVE_INTEGER
  } VAR_INT_TYPE;
  typedef enum
  {
    XS_STRING,//derived from XS_ANY_ATOMIC_TYPE
    XS_NORMALIZED_STRING,//derived from XS_STRING
    XS_TOKEN,//derived from XS_NORMALIZED_STRING
    XS_LANGUAGE,//derived from XS_TOKEN
    XS_NMTOKEN,//derived from XS_TOKEN
    XS_NAME,//derived from XS_TOKEN
    XS_NCNAME,//derived from XS_NAME
    XS_ID,//derived from XS_NCNAME
    XS_IDREF,//derived from XS_NCNAME
    XS_ENTITY,//derived from XS_NCNAME
    XS_NOTATION,
    XS_ANYURI,
    XS_UNTYPED_ATOMIC
  } VAR_STR_TYPE;
  typedef enum
  {
    XS_DECIMAL,
    XS_FLOAT,
    XS_DOUBLE
  } VAR_DOUBLE_TYPE;
  typedef enum
  {
    XS_DATETIME,
    XS_DATE,
    XS_TIME,
    XS_GYEAR_MONTH,
    XS_GYEAR,
    XS_GMONTH_DAY,
    XS_GDAY,
    XS_GMONTH
  } VAR_DATETIME_TYPE;
public:
//	struct ::tm  current_date_time;//includes the explicit timezone
  long     implicit_timezone_seconds;

  virtual ~DynamicQueryContext( ) {};

	virtual void		SetCurrentDateTime( struct ::tm datetime, long timezone_seconds ) = 0;
	virtual struct ::tm	GetCurrentDateTime( long *timezone_seconds ) = 0;

  // following is the input data; this is not duplicable between executions
  // virtual bool SetVariable( QNameItem_t varname, XQueryExecution_t item_iter ) = 0;
  virtual bool SetVariableAsInteger( xqp_string varname, long long int_value, VAR_INT_TYPE type = XS_INTEGER) = 0;
  virtual bool SetVariableAsString( xqp_string varname, xqp_string str_value, VAR_STR_TYPE type = XS_STRING) = 0;
  virtual bool SetVariableAsDouble( xqp_string varname, long double double_value, VAR_DOUBLE_TYPE type = XS_DOUBLE) = 0;
  virtual bool SetVariableAsBool( xqp_string varname, bool bool_value) = 0;
  virtual bool SetVariableAsDateTime( xqp_string varname, struct ::tm datetime_value, long timezone_seconds, VAR_DATETIME_TYPE type = XS_DATETIME) = 0;
  virtual bool SetVariableAsItem( xqp_string varname, Item_t item) = 0;
	virtual bool SetVariableAsDocument( xqp_string varname, xqp_anyURI documentURI) = 0;

  virtual bool DeleteVariable( xqp_string varname ) = 0;
  virtual void DeleteAllVariables( ) = 0;


  // register documents available through fn:doc() in xquery
  // virtual bool RegisterAvailableDocument(xqp_string docURI,
  //                                      xqp_string store_docURI) = 0;
  // register collections available through fn:collection() in xquery
  // default collection has empty URI ""
  // virtual bool RegisterAvailableCollection(xqp_string collectionURI,
  //                                          xqp_string store_collectionURI) = 0;

  virtual void SetDefaultCollection( xqp_string collectionURI ) = 0;
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
