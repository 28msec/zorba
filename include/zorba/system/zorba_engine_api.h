
#ifndef INCLUDE_ZORBA_ENGINE_API
#define INCLUDE_ZORBA_ENGINE_API

#include "store/api/store_api.h"

namespace xqp
{

class AlertCodes;
class ZorbaAlertsManager;

template <class Object> class rchandle;

typedef rchandle<class StaticQueryContext> StaticQueryContext_t;
typedef rchandle<class DynamicQueryContext> DynamicQueryContext_t;
typedef rchandle<class XQuery> XQuery_t;


class ZorbaEngine
{
public:
	static ZorbaEngine& getInstance();

public:
  virtual ~ZorbaEngine() {}

  virtual void shutdown() = 0;

	virtual void initThread() = 0;

	virtual void uninitThread() = 0;

  virtual XQuery_t createQuery(
        const char* aQueryString,
        StaticQueryContext_t = 0, 
				xqp_string	xquery_source_uri = "",
        bool routing_mode = false) = 0;

	virtual ZorbaAlertsManager& getAlertsManagerForCurrentThread() = 0;

	virtual void setDefaultCollation(
        std::string coll_string,
        ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY) = 0;

	virtual void setDefaultCollation(::Collator *default_coll) = 0;

	virtual void getDefaultCollation(
        std::string* coll_string,
        ::Collator::ECollationStrength* coll_strength,
        ::Collator** default_coll) = 0;

	virtual void setItemSerializerParameter(
        xqp_string parameter_name,
        xqp_string value) = 0;

	virtual void setDocSerializerParameter(
        xqp_string parameter_name,
        xqp_string value) = 0;

	virtual StaticQueryContext_t createStaticContext() = 0;
	virtual DynamicQueryContext_t createDynamicContext() = 0;

	virtual	XmlDataManager_t		getXmlDataManager() = 0;
};



}//end namespace xqp

#endif

