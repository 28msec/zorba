
#include <stdio.h>
#include <memory.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <string>

#include "store/naive/simple_loader.h"
#include "store/naive/node_items.h"

namespace xqp
{

XmlLoader::XmlLoader()
{
  // This initializes the library and check potential ABI mismatches between
  // the version it was compiled for and the actual shared library used.
  LIBXML_TEST_VERSION

  // See http://xmlsoft.org/html/libxml-tree.html#xmlSAXHandler
  xmlSAXHandler saxHandler; 
  memset( &saxHandler, 0, sizeof(saxHandler) );
  saxHandler.initialized = XML_SAX2_MAGIC;
  saxHandler.startElementNs = &XmlLoader::startElementNs;
  saxHandler.endElementNs = &XmlLoader::endElementNs;
  saxHandler.warning = &XmlLoader::warning;
  saxHandler.error = &XmlLoader::error;
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
    const xmlChar * localname, 
    const xmlChar * prefix, 
    const xmlChar * URI, 
    int nb_namespaces, 
    const xmlChar ** namespaces, 
    int nb_attributes, 
    int nb_defaulted, 
    const xmlChar ** attributes)
{
  XmlLoader &fsm = *( static_cast<XmlLoader *>( ctx ) );
  printf( "startElementNs: name = '%s' prefix = '%s' uri = (%p)'%s'\n", localname, prefix, URI, URI );

  for ( int indexNamespace = 0; indexNamespace < nb_namespaces; ++indexNamespace )
  {
    const xmlChar *prefix = namespaces[indexNamespace*2];
    const xmlChar *nsURI = namespaces[indexNamespace*2+1];
    printf( "  namespace: name='%s' uri=(%p)'%s'\n", prefix, nsURI, nsURI );
  }

  unsigned int index = 0;
  for ( int indexAttribute = 0; 
        indexAttribute < nb_attributes; 
        ++indexAttribute, index += 5 )
  {
    const xmlChar *localname = attributes[index];
    const xmlChar *prefix = attributes[index+1];
    const xmlChar *nsURI = attributes[index+2];
    const xmlChar *valueBegin = attributes[index+3];
    const xmlChar *valueEnd = attributes[index+4];

    std::string value( (const char *)valueBegin, (const char *)valueEnd );

    printf( "  %sattribute: localname='%s', prefix='%s', uri=(%p)'%s', value='%s'\n",
            indexAttribute >= (nb_attributes - nb_defaulted) ? "defaulted " : "",
            localname,
            prefix,
            nsURI,
            nsURI,
            value.c_str() );
  }
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
    const xmlChar * URI )
{
  XmlLoader &fsm = *( static_cast<XmlLoader *>( ctx ) );
  printf( "endElementNs: name = '%s' prefix = '%s' uri = '%s'\n", localname, prefix, URI );
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


