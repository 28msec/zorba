
#include "zorba/zorba_singlethread.h"
#include <xercesc/dom/DOM.hpp>

#include <iostream>

using namespace std;
using namespace zorba;

XERCES_CPP_NAMESPACE_USE

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
  Retrieve the result as DOM.
  DOM implementation is provided by Xerces
*/

int uc1e_simpleQueryResultDOM(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread_t		zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;

	//create and compile a query
	xquery = zorba_engine->createQuery("<a> simple test </a>");
	//init execution
	xquery->initExecution();

  XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument  *result_dom;
  result_dom = xquery->getResultAsDOM();

  //now display the text of the root element
  XERCES_CPP_NAMESPACE_QUALIFIER DOMElement *root_elem;
  root_elem = result_dom->getDocumentElement();
  char  *strtemp;
  strtemp = XMLString::transcode(root_elem->getTagName());
  std::cout << "root tag name : " << strtemp << std::endl;
  XMLString::release(&strtemp);
  strtemp = XMLString::transcode(root_elem->getTextContent());
  std::cout << "text content: " << strtemp << std::endl;
  XMLString::release(&strtemp);

  result_dom->release();

	return 0;
}
