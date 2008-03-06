
#include <zorba/zorba_singlethread.h>
#include <zorba/sax2.h>

#include <iostream>

using namespace std;
using namespace zorba;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Retrieve the result as SAX2.
*/

/*
Define callback class to receive XML SAX2 events
Just print the events it receives
*/
class MySAX2ContentHandler : public SAX2_ContentHandler
{
  std::string   indent_spaces;
public:
 
  virtual void characters(const char* text, unsigned long length) throw (SAX2_Exception)
  {
     cout << indent_spaces << "  " << xqpStringStore(text, length) << endl;
  }

  virtual void endDocument () throw (SAX2_Exception)
  {
    cout << "<<END DOCUMENT>>" << endl;
  }

  virtual void endElement(
	                  const xqp_string uri,
	                  const xqp_string localname,
                    const xqp_string qname)  throw (SAX2_Exception)
  {
    indent_spaces.resize(indent_spaces.length()-2);
    cout << indent_spaces << "/" << qname << endl;
  }

  virtual void ignorableWhitespace(const char* whitespace, unsigned long length)  throw (SAX2_Exception)
  {
  }

  virtual void processingInstruction(
                    const xqp_string    target,
                    const xqp_string    data) throw (SAX2_Exception)
  {
    cout << indent_spaces << "PI: " << target << " , " << data << endl;
  }

  virtual void setDocumentLocator(const SAX2_Locator* const locator)
  {
  }

  virtual void startDocument() throw (SAX2_Exception)
  {
    cout << "<<START DOCUMENT>>" << endl;
  }

  virtual void startElement(
                    const xqp_string    uri,
                    const xqp_string    localname,
                    const xqp_string    qname,
                    const SAX2_Attributes   &attrs,
                    const SAX2_Namespaces   &namespaces)  throw (SAX2_Exception)
  {
    cout << indent_spaces << qname;
    unsigned int  attrs_list_len = attrs.getLength();
    for(unsigned int i=0;i<attrs_list_len;i++)
    {
      cout << "  " << attrs.getQName(i) << "=" << attrs.getValue(i);
    }
    cout << endl;
    indent_spaces += "  ";
  }
  virtual void startPrefixMapping(
                    const	xqp_string	prefix,
                    const	xqp_string	uri)   throw (SAX2_Exception)
  {
    cout << indent_spaces << "  [xmlns:" << prefix << "=" << uri << "]" << endl;
  }

  virtual void endPrefixMapping(const	xqp_string	prefix)   throw (SAX2_Exception)
  {}
};//end class MySAX2ContentHandler

/*
Define callback class to receive SAX2 error events
*/
class MySAX2ErrorHandler : public SAX2_ErrorHandler
{
public:
  virtual void  warning (const SAX2_ParseException& exc) throw (SAX2_Exception)
  {
    cerr << "*SAX2 WARNING*:" << exc.getLineNumber() << "  " << exc.getMessage() << endl;
  }
   
  virtual void  error (const SAX2_ParseException& exc) throw (SAX2_Exception)
  {
    cerr << "*SAX2 ERROR*:" << exc.getLineNumber() << "  " << exc.getMessage() << endl;
  }
   
  virtual void  fatalError (const SAX2_ParseException& exc) throw (SAX2_Exception)
  {
    cerr << "*SAX2 FATAL ERROR*:" << exc.getLineNumber() << "  " << exc.getMessage() << endl;
  }
   
};//end class MySAX2ErrorHandler








int uc1f_simpleQueryResultSAX(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread_t		zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;

	//create and compile a query
	xquery = zorba_engine->createQuery(
    "<a> text a text a "
    "<b xmlns:ns1=\"http://flworfound.org/usecase1\" attr1=\"value1\"> text b </b>"
    "</a>");
	//init execution
	xquery->initExecution();

  //use our SAX DocumentHandler and ErrorHandler implementation to receive XML events
  MySAX2ContentHandler     my_sax_doc;
  MySAX2ErrorHandler       my_sax_err;

  xquery->getResultAsSAX2(&my_sax_doc, &my_sax_err);

	return 0;
}
