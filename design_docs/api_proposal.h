// file zorba.h

#include <zorba/querycontext.h>
#include <zorba/openview.h>
#include <zorba/query.h>

// other imports needed

// file zorbafactory.h

namespace zorba {

//extern C {

class Query;
class ZorbaFactoryPtr;


// singleton access to zorba
// this class also starts the store
class ZorbaFactory : public rcobject
{
	friend class ZorbaFactoryPtr;
public:
    // singleton 
    static ZorbaFactoryPtr instance();//daniel: this will return a smart pointer

private:
    ZorbaFactory();
    ~ZorbaFactory();

public:
    // the only way to create and destroy queries 
    QueryPtr createQuery(zorba::string aQueryString);
    //void   destroyQuery();//daniel: the Query object will free itself when decrem ref 


    StaticQueryContextPtr createGenericStaticContext();
    DynamicQueryContextPtr createGenericDynamicContext();

    // loads and serialize a query (compiled or not compiled)
    QueryPtr loadQuery(istream &is);//daniel: query can be loaded from file or memory
    
//daniel: the query will serialize itself
// matthias how can this be done?
//		ZorbaError   serializeQuery(QueryPtr aQuery);

};

class ZorbaFactoryPtr : rchandle<ZorbaFactory>
{
public:
	ZorbaFactoryPtr(ZorbaFactoryPtr &q);
	ZorbaFactoryPtr(ZorbaFactory *p);
	ZorbaFactoryPtr();
	~ZorbaFactoryPtr();
};
//}
} // end namespace

// file query.h

namespace zorba {
//extern C {

// can either be used only in one thread
// or the thread mechanism proposed by Daniel can be used
//daniel: in the end I think we will stick with cloning
//			using the same Query in multiple threads is almost impossible (how to set up different input data for the same Query?)
class Query : public rcobject
{
    friend class ZorbaFactory;
		friend class QueryPtr;
private:
    Query(zorba:string );
    ~Query();

public:


    // StaticQueryContext is optional
		//daniel: return true for success
		// Matthias: how to return errors? daniel: using the error manager
    // routing_mode: should documents in a collection be filtered or queried completely
    //         if filtered, the result will be a sequences of URI, one for each qualifying documents
    bool ZorbaError compile(StaticQueryContextPtr = 0, bool routing_mode = false);

    // execute the query and compile it if necessary
		//daniel: return true for success
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
    bool ZorbaError execute(ItemIterator &result, DynamicQueryContextPtr = 0);

    bool isCompiled();

    // clone the query (can be compiled or not compiled)
    Query* clone();

		//daniel: isn't the Query more suitable to serialize itself?
		bool   serializeQuery(ostream &os);

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always availabe

    // Matthias: don't call it internal
    // there is no need to distinguish interal and external
		StaticQueryContextPtr getInternalStaticContext();
    DynamicQueryContextPtr getInternalDynamicContext();

		//daniel: get the variables out of the dynamic context class
		// Matthias: get the dynamiccontext from the query and set the variables there
		//           adhere to the XQuery processing model and don't deviate from it
		//daniel: one dynamic context object can be used in many Queries; a variable is specific to only one Query
		//				that is because an ItemIterator keeps an internal state and can be used in a single thread
		bool		SetVariable( Zorba_QName varname, ItemIterator &item_iter );
		bool		SetVariable( Zorba_QName varname, Item_t &item );
		bool		DeleteVariable( Zorba_QName varname );

public:
	///error manager holds the list of errors for this Query
	///you can set a callback function into the error manager
	///when executing the Query returns false, you can get the list of errors from the error manager
	Zorba_AlertsManager*		getAlertsManager;
};    

class QueryPtr : public rchandle<Query>
{
public:
	QueryPtr(QueryPtr &q);
	QueryPtr(Query *p);
	QueryPtr();
	~QueryPtr();
};

//}   
}// end namepsace

// file openview.h


namespace zorba {
//extern C {

//daniel: do we need a common class for parameters for dom and sax?
// Matthias: yes, because all serialization parameters are defined there;
          they apply to DOM, SAX and Stream
/*
class ViewParameters {
  // parameters on how to serialize the result
  // see http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/#serparam
  // on serialization parameters
};
*/
class DOMViewParameters // : public ViewParameters 
{
  // parameters on how to construct the dom
  // e.g. eagerly or lazily (this is completely optional
  // and only and example on how to do some optimization
  // if needed)
};

class StAXViewParameters // : public ViewParameters 
{

};

class StreamViewParameters // : public ViewParameters 
{

    void setOutputStream(std::ostream&);
};


// most Views (e.g. StreamView, DOMView, SAXView) are a special formed of serialized
// query result as specified in the 
// XSLT 2.0 and XQuery 1.0 Serialization Recommendation
// there are other Views such as IntegerView in order to
// receive the result as some other C++ data type

//daniel: what is the relation between serialization and dom and sax? I don't see any.
// Matthias: it is basically the same

//daniel: the domview and saxview don't need a common class, we don't need this abstractization
// Matthias: see above
/*
class View {

};
*/


class DOMView // : public View 
{
public:
		DOMView( ItemIterator &, DOMViewParameters * = 0 );
		DOMView( Item_t &, DOMViewParameters * = 0);

    // returns the root node of the query result
    // can be a dom binary compatible to that of libxml
    // but implemented in our engine in order to view 
    // the dom "lazily"
		//daniel: the root is called Document in DOM level 1 spec
    Document getRootNode();


};

// view the result of an ItemIterator as StAX (pull based)
class StAXView // : public View 
{
		StAXView( ItemIterator &, StAXViewParameters*=0 );
		StAXView( Item_t &, StAXViewParameters*=0);
    // returns a SAX Reader for the query result
    // should be compatible to that of libxml
    XMLStreamReader getStreamReader();

		XMLEventReader	getEventReader();
};

// get the result of an ItemIterator as Stream
// could also be written directly to a file
class StreamView // : public View 
{
		StreamView( ItemIterator &, StreamViewParameters*=0 );
		StreamView( Item_t &, StreamViewParameters*=0);

		std::ostream getStream();
};

/*daniel: this is not a view like dom and sax; this is about casting data types; returning value and casting should be part of item
// Matthias: yes, you are right, it is better to use the item functions for this
class IntegerView : public View {
    // returns the integer
    uint64_t getInteger();  
};
*/

namespace zorba {

// with this class you can open a view on the query result, i.e. the ItemIterator_t
// there can occur errors if the ItemIterator is not convertable into the specified view
/*//daniel: why templates?
// Matthias: because there would be a lot of duplicated code otherwise
//            it is more "beautiful" with templates
class OpenView<class ViewType> {

public:
    OpenView<class ViewType>(ItemIterator_t, ViewParameters* = 0);
    ~OpenView();

    ViewType* getView();

protected:
    ViewType* theView;

};
//}
} // end namespace
*/

// QueryContexts as is (containing all the information specified in the processing model)
// Error Handling as is

// the Item and ItemIterator (and probably collection) are also exported to the user
	//daniel: why export Collection to the user? He has ItemIterator.
	//To handle the data in database he has only URIs (my point of view).
	// Matthias: could be; we can decide on this later if we see the need