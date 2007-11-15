
#include <stdio.h>
#include <memory.h>
#include <string>
#include <libxml/xmlmemory.h>

#include "store/api/store_consts.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_loader.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/node_items.h"

namespace xqp
{

XmlLoader::XmlLoader()
{
  // This initializes the library and check potential ABI mismatches between
  // the version it was compiled for and the actual shared library used.
  LIBXML_TEST_VERSION

  // See http://xmlsoft.org/html/libxml-tree.html#xmlSAXHandler
  memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  theSaxHandler.initialized = XML_SAX2_MAGIC;
  theSaxHandler.startElementNs = &XmlLoader::startElementNs;
  theSaxHandler.endElementNs = &XmlLoader::endElementNs;
  theSaxHandler.warning = &XmlLoader::warning;
  theSaxHandler.error = &XmlLoader::error;
}


XmlLoader::~XmlLoader()
{
}


/*******************************************************************************

********************************************************************************/
long XmlLoader::readPacket(std::iostream& stream, char* buf, long size)
{
  try
  {
    stream.read(buf, size);

    if (stream.bad())
    {
      ZORBA_ERROR_ALERT(error_messages::XQP0016_LOADER_IO_ERROR,
                        error_messages::SYSTEM_ERROR,
                        NULL,
                        true,
                        "");
    }

    return stream.gcount();
  }
  catch (iostream::failure e)
  {
    ZORBA_ERROR_ALERT(error_messages::XQP0016_LOADER_IO_ERROR,
                      error_messages::SYSTEM_ERROR,
                      NULL,
                      true,
                      e.what());
  }
  return -1;
}


/*******************************************************************************

********************************************************************************/
NodeItem_t XmlLoader::loadXml(std::iostream& stream)
{
  xmlParserCtxtPtr ctxt;
  char buf[4096];
  long numChars;

  numChars = readPacket(stream, buf, 4096);
  if (numChars < 0)
  {
    return NULL;
  }

  ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, buf, numChars, NULL);
  if (ctxt == NULL)
  {
    return NULL;
  }

  while ((numChars = readPacket(stream, buf, 4096)) > 0)
  {
    xmlParseChunk(ctxt, buf, numChars, 0);
  }

  xmlParseChunk(ctxt, buf, 0, 1);

  bool ok = ctxt->wellFormed;

  // Cleanup
  xmlFreeParserCtxt(ctxt);

  while(!thePath.empty())
    thePath.pop();

  NodeItem_t resultNode = theRootNode;

  theRootNode = NULL;

  if (!ok)
  {
    ZORBA_ERROR_ALERT(error_messages::XQP0017_LOADER_NOT_WELL_FORMED_XML,
                      error_messages::USER_ERROR,
                      NULL,
                      true);
    return NULL;
  }

  std::cout << std::endl << resultNode->show() << std::endl;

  return resultNode;
}


/*******************************************************************************
  SAX2 callback when an element start has been detected by the parser. It
  provides the expanded qname of the element, as well as the new namespace
  declarations on the element (if any).

  ctx:           the user data (XML parser context)
  localname:     the local name of the element
  prefix:        the element namespace prefix if available
  URI:           the element namespace name if available
  nb_namespaces: number of namespace definitions on that node
  namespaces:    pointer to the array of prefix/URI pairs namespace definitions
  nb_attributes: the number of attributes on that node
  nb_defaulted:  the number of defaulted attributes. The defaulted ones are at
                 the end of the array
 attributes:     pointer to the array of (localname/prefix/URI/value/end)
                 attribute values.
********************************************************************************/
void XmlLoader::startElementNs(
    void * ctx, 
    const xmlChar * localName, 
    const xmlChar * prefix, 
    const xmlChar * uri,
    int numNamespaces, 
    const xmlChar ** namespaces, 
    int numAttributes, 
    int numDefaulted, 
    const xmlChar ** attributes)
{
  SimpleStore& store = *(static_cast<SimpleStore*>(&Store::getInstance()));
  BasicItemFactory& factory = *(static_cast<BasicItemFactory*>(&store.getItemFactory()));
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));

  QNameItem_t qname;
  QNameItem_t tname;
  NodeItem_t elemNode;
  std::vector<Item_t> attrNodes;
  NamespaceBindings nsBindings;

  printf("\nstartElementNs: name = '%s' prefix = '%s' uri = (%p)'%s'\n",
         localName, prefix, uri, uri);

  qname = factory.createQName(reinterpret_cast<const char*>(uri),
                              reinterpret_cast<const char*>(prefix),
                              reinterpret_cast<const char*>(localName));

  tname = factory.createQName(StoreConsts::XS_URI, "xs", "anyType");

  for (long i = 0; i < numNamespaces; ++i)
  {
    const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
    const char* uri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);

    xqpStringStore_t pooledUri;
    store.getUriPool().insert(uri, pooledUri);

    nsBindings.push_back(std::pair<xqp_string, xqp_string>(prefix, pooledUri));

    printf("  namespace: name='%s' uri=(%p)'%s'\n", prefix, uri, uri);
  }

  ulong index = 0;
  for (long i = 0; i < numAttributes; ++i, index += 5)
  {
    const char* localName = reinterpret_cast<const char*>(attributes[index]);
    const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
    const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
    const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
    const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);

    QNameItem_t qname = factory.createQName(uri, prefix, localName);
    QNameItem_t tname = factory.createQName(StoreConsts::XS_URI, "xs", "untypedAtomic");

    xqpStringStore* value = new xqpStringStore(valueBegin, valueEnd);
    Item_t lexicalValue = factory.createString(*value);
    Item_t typedValue = factory.createUntypedAtomic(*value);

    NodeItem_t attrNode = factory.createAttributeNode(qname,
                                                      tname,
                                                      lexicalValue,
                                                      typedValue);

    attrNodes.push_back(attrNode.get_ptr());

    printf("  %sattribute: localname='%s', prefix='%s', uri=(%p)'%s', value='%s'\n",
            i >= (numAttributes - numDefaulted) ? "defaulted " : "",
            localName,
            prefix,
            uri, uri,
            value->c_str());
  }

  TempSeq_t attrSeq(new SimpleTempSeq(attrNodes));

  elemNode = factory.createElementNode(qname, tname, attrSeq, nsBindings);

  for (long i = 0; i < numAttributes; ++i)
  {
    reinterpret_cast<NodeNaive*>(attrNodes[i].get_ptr())->setParent(elemNode);
  }

  if (loader.thePath.empty())
    loader.theRootNode = elemNode;

  loader.thePath.push(elemNode);
  loader.thePath.push(NULL);
}

  
/*******************************************************************************
  SAX2 callback when an element end has been detected by the parser. It
  provides the expanded qname of the element.

  ctx:       the user data (XML parser context)
  localname: the local name of the element
  prefix:    the element namespace prefix if available
  URI:       the element namespace name if available
********************************************************************************/
void  XmlLoader::endElementNs(
    void * ctx, 
    const xmlChar * localname, 
    const xmlChar * prefix, 
    const xmlChar * URI)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));

  printf("\nendElementNs: name = '%s' prefix = '%s' uri = '%s'\n",
          localname, prefix, URI );

  std::vector<Item_t> childNodes;

  NodeItem_t childNode = loader.thePath.top();

  while (childNode != NULL)
  {
    childNodes.push_back(childNode.get_ptr());
    loader.thePath.pop();
    childNode = loader.thePath.top();
  }
  loader.thePath.pop();

  TempSeq_t childSeq(new SimpleTempSeq(childNodes));

  NodeNaive* elemNode = reinterpret_cast<NodeNaive*>(loader.thePath.top().get_ptr());

  elemNode->setChildren(childSeq);
}


/*******************************************************************************
  Display and format an error messages, callback.
 
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::error(void * ctx, const char * msg, ... )
{
  XmlLoader &fsm = *( static_cast<XmlLoader *>( ctx ) );
  va_list args;
  va_start(args, msg);
  vprintf( msg, args );
  va_end(args);
}


/*******************************************************************************
   Display and format a warning messages, callback.
  
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::warning(void * ctx, const char * msg, ... )
{
  XmlLoader &fsm = *( static_cast<XmlLoader *>( ctx ) );
  va_list args;
  va_start(args, msg);
  vprintf( msg, args );
  va_end(args);
}

}


