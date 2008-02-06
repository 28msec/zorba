
#ifndef ZORBA_BASE_ENGINE_API_CLASS_21_JAN_2008
#define ZORBA_BASE_ENGINE_API_CLASS_21_JAN_2008

#include "zorba/util/rchandle.h"
#include "store/api/store_api.h"
#include "zorba/system/zorba_version.h"

namespace xqp{

class AlertCodes;
class ZorbaAlertsManager;

template <class Object> class rchandle;

typedef rchandle<class StaticQueryContext> StaticQueryContext_t;
typedef rchandle<class DynamicQueryContext> DynamicQueryContext_t;
typedef rchandle<class XQuery> XQuery_t;
typedef rchandle<class ZorbaAlertsManager>	ZorbaAlertsManager_t;


class ZorbaBaseEngine : public rcobject
{
public:

	virtual void shutdown() = 0;

public:
  virtual ~ZorbaBaseEngine() {}

  virtual XQuery_t createQuery(
        xqp_string aQueryString,
        StaticQueryContext_t = 0, 
				xqp_string	xquery_source_uri = "",
        bool routing_mode = false) = 0;

  virtual XQuery_t createQueryFromFile(
        xqp_string xquery_file,
        StaticQueryContext_t = 0, 
        bool routing_mode = false) = 0;

  virtual XQuery_t createQueryFromStream(
				std::istream		&is,
        StaticQueryContext_t = 0, 
        xqp_string xquery_source_uri = "",
				bool routing_mode = false) = 0;

	virtual ZorbaAlertsManager_t getAlertsManagerForCurrentThread() = 0;

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


  static std::string
  getZorbaVersion() { return ZorbaVersion::getZorbaVersion(); }
};

}//end namespace xqp

#endif

