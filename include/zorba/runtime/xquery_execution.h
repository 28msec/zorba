
#ifndef XQUERY_EXECUTION_API_12_DEC_2007
#define XQUERY_EXECUTION_API_12_DEC_2007

namespace xqp {

class XQueryExecution : public Iterator
{
public:
	virtual ~XQueryExecution() {};

  virtual Item_t next() = 0;
  virtual void reset() = 0;
  virtual void close() = 0;

	virtual void setAlertsParam(void *alert_callback_param) = 0;

  virtual bool serialize( std::ostream& os ) = 0;
  virtual bool serializeXML( std::ostream& os ) = 0;
  virtual bool serializeHTML( std::ostream& os ) = 0;
  virtual bool serializeTEXT( std::ostream& os ) = 0;
	virtual bool isError() = 0;

	virtual void	AbortQueryExecution() = 0;

	// extension from dynamic context (specific only for this execution)
	virtual bool SetVariable( xqp_string varname, XQueryExecution_t item_iter ) = 0;
	virtual bool SetVariable( xqp_string varname, xqp_string docUri, std::istream &is ) = 0;

	// register documents available through fn:doc() in xquery
	virtual bool AddAvailableDocument(xqp_string docURI,
																		Item_t docitem) = 0;
	// register collections available through fn:collection() in xquery
	// default collection has empty URI ""
	virtual bool AddAvailableCollection(xqp_string collectionURI,
																			Collection_t) = 0;

};

typedef rchandle<XQueryExecution>		XQueryExecution_t;


} //end namespace xqp


#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
