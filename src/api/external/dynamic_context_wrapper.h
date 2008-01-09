
#ifndef EXTERNA_API_DYNAMIC_CONTEXT_WRAPPER_04_DEC_2007
#define EXTERNA_API_DYNAMIC_CONTEXT_WRAPPER_04_DEC_2007

#include "zorba_api.h"
#include "types/representations.h"
//#include "context/dynamic_context.h"

namespace xqp{

class static_context;
class dynamic_context;

class DynamicContextWrapper : public DynamicQueryContext
{

	typedef enum 
	{
		VAR_INT,
		VAR_STR,
		VAR_DOUBLE,
		VAR_BOOL,
		VAR_DATETIME
	}var_type_t;
	typedef struct
	{
		struct ::tm		datetime_value;
		long					timezone_seconds;
	}datetime_timezone_t;
	typedef struct
	{
		xqp_string		varname;
		var_type_t		vartype;
		union
		{
			VAR_INT_TYPE	int_type;
			VAR_STR_TYPE	str_type;
			VAR_DOUBLE_TYPE	double_type;
			VAR_DATETIME_TYPE	datetime_type;
		};
		union
		{
			long long		int_value;
			xqpStringStore		*str_value;
			double	double_value;
			bool		bool_value;
			datetime_timezone_t		dtt;
		};
	}dctx_extern_var_t;

	std::vector<dctx_extern_var_t>		vars;
	xqp_string			default_collection_uri;

	struct ::tm			current_date_time;
	long						current_timezone_seconds;
	bool						is_datetime_initialized;
public:
	DynamicContextWrapper();

	virtual ~DynamicContextWrapper( );

	virtual void		SetCurrentDateTime( struct ::tm datetime, long timezone_seconds );
	virtual struct ::tm	GetCurrentDateTime( long *timezone_seconds );

	///following is the input data; this is not duplicable between executions
//	virtual bool SetVariable( QNameItem_t varname, XQueryExecution_t item_iter ) = 0;
	virtual bool SetVariable( xqp_string varname, long long int_value, VAR_INT_TYPE type = XS_INTEGER);
	virtual bool SetVariable( xqp_string varname, xqp_string str_value, VAR_STR_TYPE type = XS_STRING);
	virtual bool SetVariable( xqp_string varname, long double double_value, VAR_DOUBLE_TYPE type = XS_DOUBLE);
	virtual bool SetVariable( xqp_string varname, bool bool_value);
	virtual bool SetVariable( xqp_string varname, struct ::tm datetime_value, long timezone_seconds = 0, VAR_DATETIME_TYPE type = XS_DATETIME);

	virtual bool DeleteVariable( xqp_string varname );
	virtual void DeleteAllVariables( );

	virtual void SetDefaultCollection( xqp_string collectionURI );

	dynamic_context*	create_dynamic_context(static_context *sctx);//and fill in with the values

private:
	bool	checkQName(xqp_string varname);//check if var name is well formed
};

}//end namespace xqp

#endif
