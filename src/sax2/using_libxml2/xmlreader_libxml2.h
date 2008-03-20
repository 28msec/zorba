
#ifndef ZORBA_SAX2_XML_READER_IMPLEMENTATION_USING_LIBXML2_27_FEB_2008
#define ZORBA_SAX2_XML_READER_IMPLEMENTATION_USING_LIBXML2_27_FEB_2008

#include <libxml/parser.h>
#include <list>
#include <utility>

#include "common/common.h"
#include "zorbatypes/representations.h"
#include "sax2/xmlreader.h"

namespace zorba{

class SAX2_Locator;
class SAX2_ContentHandler;
class SAX2_ErrorHandler;
class SAX2_DTDHandler;
class SAX2_DeclHandler;
class SAX2_LexicalHandler;
struct ::_xmlElementContent;

class SAX2_XMLReaderLibXML2 : public SAX2_XMLReader
{
protected:
  xmlSAXHandler                    theSaxHandler;
  xmlParserCtxtPtr                 ctxt;

  std::list< std::list< std::pair< std::string, std::string > > >   ns_list;
  SAX2_Locator                     *locator;
public:
  SAX2_XMLReaderLibXML2(
                        SAX2_ContentHandler *content_handler = NULL,
                        SAX2_ErrorHandler *error_handler = NULL,
                        SAX2_DTDHandler   *dtd_handler = NULL,
                        SAX2_DeclHandler  *decl_handler = NULL,
                        SAX2_LexicalHandler *lexical_handler = NULL);
  virtual ~SAX2_XMLReaderLibXML2();

  virtual bool parse(XQuery_t result);


public:
  //libxml2 callbacks
/**
 * internalSubsetSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  the root element name
 * @ExternalID:  the external ID
 * @SystemID:  the SYSTEM ID (e.g. filename or URL)
 *
 * Callback on internal subset declaration.
 */
  static void zorba_internalSubsetSAXFunc (void *ctx,
				const xmlChar *name,
				const xmlChar *ExternalID,
				const xmlChar *SystemID);
/**
 * externalSubsetSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  the root element name
 * @ExternalID:  the external ID
 * @SystemID:  the SYSTEM ID (e.g. filename or URL)
 *
 * Callback on external subset declaration.
 */
  static void zorba_externalSubsetSAXFunc (void *ctx,
				const xmlChar *name,
				const xmlChar *ExternalID,
				const xmlChar *SystemID);
/**
 * getEntitySAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name: The entity name
 *
 * Get an entity by name.
 *
 * Returns the xmlEntityPtr if found.
 */
  static xmlEntityPtr zorba_getEntitySAXFunc (void *ctx,
				const xmlChar *name);
/**
 * getParameterEntitySAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name: The entity name
 *
 * Get a parameter entity by name.
 *
 * Returns the xmlEntityPtr if found.
 */
  static xmlEntityPtr zorba_getParameterEntitySAXFunc (void *ctx,
				const xmlChar *name);
/**
 * entityDeclSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  the entity name 
 * @type:  the entity type 
 * @publicId: The public ID of the entity
 * @systemId: The system ID of the entity
 * @content: the entity value (without processing).
 *
 * An entity definition has been parsed.
 */
  static void zorba_entityDeclSAXFunc (void *ctx,
				const xmlChar *name,
				int type,
				const xmlChar *publicId,
				const xmlChar *systemId,
				xmlChar *content);
/**
 * notationDeclSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name: The name of the notation
 * @publicId: The public ID of the entity
 * @systemId: The system ID of the entity
 *
 * What to do when a notation declaration has been parsed.
 */
  static void zorba_notationDeclSAXFunc(void *ctx,
				const xmlChar *name,
				const xmlChar *publicId,
				const xmlChar *systemId);
/**
 * attributeDeclSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @elem:  the name of the element
 * @fullname:  the attribute name 
 * @type:  the attribute type 
 * @def:  the type of default value
 * @defaultValue: the attribute default value
 * @tree:  the tree of enumerated value set
 *
 * An attribute definition has been parsed.
 */
  static void zorba_attributeDeclSAXFunc(void *ctx,
				const xmlChar *elem,
				const xmlChar *fullname,
				int type,
				int def,
				const xmlChar *defaultValue,
				xmlEnumerationPtr tree);
/**
 * elementDeclSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  the element name 
 * @type:  the element type 
 * @content: the element value tree
 *
 * An element definition has been parsed.
 */
  static void zorba_elementDeclSAXFunc(void *ctx,
				const xmlChar *name,
				int type,
				xmlElementContentPtr content);
/**
 * unparsedEntityDeclSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name: The name of the entity
 * @publicId: The public ID of the entity
 * @systemId: The system ID of the entity
 * @notationName: the name of the notation
 *
 * What to do when an unparsed entity declaration is parsed.
 */
  static void zorba_unparsedEntityDeclSAXFunc(void *ctx,
				const xmlChar *name,
				const xmlChar *publicId,
				const xmlChar *systemId,
				const xmlChar *notationName);
/**
 * setDocumentLocatorSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @loc: A SAX Locator
 *
 * Receive the document locator at startup, actually xmlDefaultSAXLocator.
 * Everything is available on the context, so this is useless in our case.
 */
  static void zorba_setDocumentLocatorSAXFunc (void *ctx,
				xmlSAXLocatorPtr loc);
/**
 * startDocumentSAXFunc:
 * @ctx:  the user data (XML parser context)
 *
 * Called when the document start being processed.
 */
  static void zorba_startDocumentSAXFunc (void *ctx);
/**
 * endDocumentSAXFunc:
 * @ctx:  the user data (XML parser context)
 *
 * Called when the document end has been detected.
 */
  static void zorba_endDocumentSAXFunc (void *ctx);
/**
 * startElementSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  The element name, including namespace prefix
 * @atts:  An array of name/value attributes pairs, NULL terminated
 *
 * Called when an opening tag has been processed.
 */
//  static void zorba_startElementSAXFunc (void *ctx,
//				const xmlChar *name,
//				const xmlChar **atts);
/**
 * endElementSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  The element name
 *
 * Called when the end of an element has been detected.
 */
//  static void zorba_endElementSAXFunc (void *ctx,
//				const xmlChar *name);
/**
 * attributeSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  The attribute name, including namespace prefix
 * @value:  The attribute value
 *
 * Handle an attribute that has been read by the parser.
 * The default handling is to convert the attribute into an
 * DOM subtree and past it in a new xmlAttr element added to
 * the element.
 */
  static void zorba_attributeSAXFunc (void *ctx,
				const xmlChar *name,
				const xmlChar *value);
/**
 * referenceSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @name:  The entity name
 *
 * Called when an entity reference is detected. 
 */
  static void zorba_referenceSAXFunc (void *ctx,
				const xmlChar *name);
/**
 * charactersSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @ch:  a xmlChar string
 * @len: the number of xmlChar
 *
 * Receiving some chars from the parser.
 */
  static void zorba_charactersSAXFunc (void *ctx,
				const xmlChar *ch,
				int len);
/**
 * ignorableWhitespaceSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @ch:  a xmlChar string
 * @len: the number of xmlChar
 *
 * Receiving some ignorable whitespaces from the parser.
 * UNUSED: by default the DOM building will use characters.
 */
  static void zorba_ignorableWhitespaceSAXFunc (void *ctx,
				const xmlChar *ch,
				int len);
/**
 * processingInstructionSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @target:  the target name
 * @data: the PI data's
 *
 * A processing instruction has been parsed.
 */
  static void zorba_processingInstructionSAXFunc (void *ctx,
				const xmlChar *target,
				const xmlChar *data);
/**
 * commentSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @value:  the comment content
 *
 * A comment has been parsed.
 */
  static void zorba_commentSAXFunc (void *ctx,
				const xmlChar *value);
/**
 * cdataBlockSAXFunc:
 * @ctx:  the user data (XML parser context)
 * @value:  The pcdata content
 * @len:  the block length
 *
 * Called when a pcdata block has been parsed.
 */
  static void zorba_cdataBlockSAXFunc (
	                        void *ctx,
				const xmlChar *value,
				int len);
/**
 * warningSAXFunc:
 * @ctx:  an XML parser context
 * @msg:  the message to display/transmit
 * @...:  extra parameters for the message display
 * 
 * Display and format a warning messages, callback.
 */
  static void zorba_warningSAXFunc (void *ctx,
				const char *msg, ...);
/**
 * errorSAXFunc:
 * @ctx:  an XML parser context
 * @msg:  the message to display/transmit
 * @...:  extra parameters for the message display
 * 
 * Display and format an error messages, callback.
 */
  static void zorba_errorSAXFunc (void *ctx,
				const char *msg, ...);
/**
 * fatalErrorSAXFunc:
 * @ctx:  an XML parser context
 * @msg:  the message to display/transmit
 * @...:  extra parameters for the message display
 * 
 * Display and format fatal error messages, callback.
 * Note: so far fatalError() SAX callbacks are not used, error()
 *       get all the callbacks for errors.
 */
  static void zorba_fatalErrorSAXFunc (void *ctx,
				const char *msg, ...);
/**
 * isStandaloneSAXFunc:
 * @ctx:  the user data (XML parser context)
 *
 * Is this document tagged standalone?
 *
 * Returns 1 if true
 */
  static int zorba_isStandaloneSAXFunc (void *ctx);
/**
 * hasInternalSubsetSAXFunc:
 * @ctx:  the user data (XML parser context)
 *
 * Does this document has an internal subset.
 *
 * Returns 1 if true
 */
  static int zorba_hasInternalSubsetSAXFunc (void *ctx);

/**
 * hasExternalSubsetSAXFunc:
 * @ctx:  the user data (XML parser context)
 *
 * Does this document has an external subset?
 *
 * Returns 1 if true
 */
  static int zorba_hasExternalSubsetSAXFunc (void *ctx);

/**
 * startElementNsSAX2Func:
 * @ctx:  the user data (XML parser context)
 * @localname:  the local name of the element
 * @prefix:  the element namespace prefix if available
 * @URI:  the element namespace name if available
 * @nb_namespaces:  number of namespace definitions on that node
 * @namespaces:  pointer to the array of prefix/URI pairs namespace definitions
 * @nb_attributes:  the number of attributes on that node
 * @nb_defaulted:  the number of defaulted attributes. The defaulted
 *                  ones are at the end of the array
 * @attributes:  pointer to the array of (localname/prefix/URI/value/end)
 *               attribute values.
 *
 * SAX2 callback when an element start has been detected by the parser.
 * It provides the namespace informations for the element, as well as
 * the new namespace declarations on the element.
 */

  static void zorba_startElementNsSAX2Func (void *ctx,
					const xmlChar *localname,
					const xmlChar *prefix,
					const xmlChar *URI,
					int nb_namespaces,
					const xmlChar **namespaces,
					int nb_attributes,
					int nb_defaulted,
					const xmlChar **attributes);
 
/**
 * endElementNsSAX2Func:
 * @ctx:  the user data (XML parser context)
 * @localname:  the local name of the element
 * @prefix:  the element namespace prefix if available
 * @URI:  the element namespace name if available
 *
 * SAX2 callback when an element end has been detected by the parser.
 * It provides the namespace informations for the element.
 */

  static void zorba_endElementNsSAX2Func   (void *ctx,
					const xmlChar *localname,
					const xmlChar *prefix,
					const xmlChar *URI);

protected:
  xqp_string unparseElementContent(::_xmlElementContent* content);

  void push_namespaces(int nb_namespaces,
				               const xmlChar **namespaces);
  void pop_namespaces();

};

}//end namespace zorba

#endif
