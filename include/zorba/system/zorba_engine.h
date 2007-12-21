
#ifndef ZORBA_ENGINE_API_12_DEC_2007
#define ZORBA_ENGINE_API_12_DEC_2007


namespace xqp {

class ZorbaEngine
{
private:
	ZorbaEngine();

public:
	static ZorbaEngine& getInstance();
	static void startupZorbaEngine();
	static void shutdownZorbaEngine();

	void InitThread(
        error_messages* em = NULL);

	void UninitThread();

  XQuery_t createQuery(
        const char* aQueryString,
        StaticQueryContext_t = 0, 
				xqp_string	xquery_source_uri = "",
        bool routing_mode = false);

	ZorbaAlertsManager& getAlertsManagerForCurrentThread();

	void		setDefaultCollation(std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);
	void		setDefaultCollation(::Collator *default_coll);
	void		getDefaultCollation(std::string  *coll_string, ::Collator::ECollationStrength *coll_strength, ::Collator **default_coll);

	void		setItemSerializerParameter(xqp_string parameter_name, xqp_string value);
	void		setDocSerializerParameter(xqp_string parameter_name, xqp_string value);


	StaticQueryContext_t createStaticContext();
	DynamicQueryContext_t createDynamicContext();

};



}//end namespace xqp

#endif

