#ifndef ZORBA_ZORBABASEENGINE_API_H
#define ZORBA_ZORBABASEENGINE_API_H

#include <istream>
#include <string>

#include <zorba/common/api_shared_types.h>
#include <zorba/version.h>
#include <zorba/representations.h>


namespace xqp{

  class ZorbaBaseEngine : public SimpleRCObject
  {
    public:
      /*! \brief shutdown Zorba
       *
       */
      virtual void 
      shutdown() = 0;

    public:
      virtual ~ZorbaBaseEngine() {}

      virtual XQuery_t
      createQuery( xqp_string aQueryString, StaticQueryContext_t = 0, 
                   xqp_string	xquery_source_uri = "",
                   bool routing_mode = false,
                   XQueryTreePlans_t planprint = NULL) = 0;

      virtual XQuery_t
      createQueryFromFile( xqp_string xquery_file,
                           StaticQueryContext_t = 0, 
                           bool routing_mode = false,
                           XQueryTreePlans_t planprint = NULL) = 0;

      virtual XQuery_t
      createQueryFromStream( std::istream		&is,
                             StaticQueryContext_t = 0, 
                             xqp_string xquery_source_uri = "",
                             bool routing_mode = false,
                             XQueryTreePlans_t planprint = NULL) = 0;

      virtual ZorbaAlertsManager_t
      getAlertsManagerForCurrentThread() = 0;

      // TODO try to hide icu related stuff
      // icu is not even included here
      virtual void
      setDefaultCollation(std::string coll_string,
                          ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY) = 0;

      virtual void 
      setDefaultCollation(::Collator *default_coll) = 0;

      // TODO try to hide icu related stuff
      // icu is not even included here
      virtual void 
      getDefaultCollation(std::string* coll_string,
                          ::Collator::ECollationStrength* coll_strength,
                          ::Collator** default_coll) = 0;

      virtual void 
      setItemSerializerParameter( xqp_string parameter_name, xqp_string value) = 0;

      virtual void 
      setDocSerializerParameter( xqp_string parameter_name, xqp_string value) = 0;

      virtual StaticQueryContext_t 
      createStaticContext() = 0;
      
      virtual DynamicQueryContext_t
      createDynamicContext() = 0;

      virtual	XmlDataManager_t
      getXmlDataManager() = 0;

      virtual XQueryTreePlans_t
      createDebugPlanPrintObject() = 0;

      static std::string
      getVersion() { return Version::getVersion(); }
  };

} /* namespace xqp */
#endif
