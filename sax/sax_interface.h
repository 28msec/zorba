// Public domain port by John Cowan <cowan@ccil.org>
//    of org.xml.sax.* classes by David Megginson
//   NO WARRANTY!

// SAX1-specific interfaces have been removed.
// Interfaces and classes ending in 2 have been merged with the originals.
// InputSource and String are both represented by char*.
// No support for parsing from a URI.
// SAXParseException has no parent and no embedded exception.

#ifndef SAX_ATTRIBUTES_H
#define SAX_ATTRIBUTES_H

using namespace std;

namespace SAX {

// Declare all classes forward to avoid ordering issues.
class Attributes;
class ContentHandler;
class DTDHandler;
class EntityResolver;
class ErrorHandler;
class Locator;
class XMLFilter;
class XMLReader;
class DeclHandler;
class LexicalHandler;
class DefaultHandler;
class SAXParseException;
class AttributesImpl;		// FIXME, needs 2
class LocatorImpl;		// FIXME, needs 2
class NamespaceSupport;		// FIXME
class XMLFilterImpl;		// FIXME
class XMLReaderFactory;		// FIXME

// All these classes are abstract;
// SAX parser drivers and SAX clients should implement them.
// For compatibility, they use Java uppercasing conventions.

class Attributes {
	public:
	// Look up the index of an attribute by XML qualified (prefixed) name.
	virtual int getIndex(char* qName) = 0;
	// Look up the index of an attribute by namespace name.
	virtual int getIndex(char* uri, char* localName) = 0;
	// Return the number of attributes in the list.
	virtual int getLength() = 0;
	// Look up an attribute's local name by index.
	virtual char* getLocalName(int index) = 0;
	// Look up an attribute's XML qualified (prefixed) name by index.
	virtual char* getQName(int index) = 0;
	// Look up an attribute's type by index.
	virtual char* getType(int index) = 0;
	// Look up an attribute's type by XML qualified (prefixed) name.
	virtual char* getType(char* qName) = 0;
	// Look up an attribute's type by namespace name.
	virtual char* getType(char* uri, char* localName) = 0;
	// Look up an attribute's namespace URI by index.
	virtual char* getURI(int index) = 0;
	// Look up an attribute's value by index.
	virtual char* getValue(int index) = 0;
	// Look up an attribute's value by XML qualified (prefixed) name.
	virtual char* getValue(char* qName) = 0;
	// Look up an attribute's value by namespace name.
	virtual char* getValue(char* uri, char* localName) = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(int index) = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(char* qName) = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(char* uri, char* localName) = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(int index) = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(char* qName) = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(char* uri, char* localName) = 0;
	};

class ContentHandler {
	public:
	// Receive notification of character data.
	virtual void characters(char* ch, int start, int length) = 0;
	// Receive notification of the end of a document.
	virtual void endDocument() = 0;
	// Receive notification of the end of an element.
	virtual void endElement(char* uri, char* localName, char* qName) = 0;
	// End the scope of a prefix-URI mapping.
	virtual void endPrefixMapping(char* prefix) = 0;
	// Receive notification of ignorable whitespace in element content.
	virtual void ignorableWhitespace(char* ch, int start, int length) = 0;
	// Receive notification of a processing instruction.
	virtual void processingInstruction(char* target, char* data) = 0;
	// Receive an object for locating the origin of SAX document events.
	virtual void setDocumentLocator(Locator& locator) = 0;
	// Receive notification of a skipped entity.
	virtual void skippedEntity(char* name) = 0;
	// Receive notification of the beginning of a document.
	virtual void startDocument() = 0;
	// Receive notification of the beginning of an element.
	virtual void startElement(char* uri, char* localName, char* qName, Attributes& atts) = 0;
	// Begin the scope of a prefix-URI namespace mapping.
	virtual void startPrefixMapping(char* prefix, char* uri) = 0;
	};

class DTDHandler {
	public:
	// Receive notification of a notation declaration event.
	virtual void notationDecl(char* name, char* publicId, char* systemId) = 0;
	// Receive notification of an unparsed entity declaration event.
	virtual void unparsedEntityDecl(char* name, char* publicId, char* systemId, char* notationName) = 0;
	};

class EntityResolver {
	public:
	// Allow the application to resolve external entities.
	virtual char* resolveEntity(char* publicId, char* systemId) = 0;
	// Allows applications to provide an external subset for documents that don't explicitly define one.
	virtual char* getExternalSubset(char* name, char* baseURI) = 0;
	// Allows applications to map references to external entities into input sources, or tell the parser it should use conventional URI resolution.
	virtual char* resolveEntity(char* name, char* publicId, char* baseURI, char* systemId) = 0;
	};

class ErrorHandler {
	public:
	// Receive notification of a recoverable error.
	virtual void error(SAXParseException& exception) = 0;
	// Receive notification of a non-recoverable error.
	virtual void fatalError(SAXParseException& exception) = 0;
	// Receive notification of a warning.
	virtual void warning(SAXParseException& exception) = 0;
	};

class Locator {
	public:
	// Return the column number where the current document event ends.
	virtual int getColumnNumber() = 0;
	// Return the line number where the current document event ends.
	virtual int getLineNumber() = 0;
	// Return the public identifier for the current document event.
	virtual char* getPublicId() = 0;
	// Return the system identifier for the current document event.
	virtual char* getSystemId() = 0;
	// Returns the name of the character encoding for the entity.
	virtual char* 	getEncoding() = 0;
	// Returns the version of XML used for the entity.
	virtual char* 	getXMLVersion() = 0;
	};

class XMLFilter {
	public:
	// Get the parent reader.
	virtual XMLReader& getParent() = 0;
	// Set the parent reader.
	virtual void setParent(XMLReader& parent) = 0;
	};

class XMLReader {
	public:
	// Return the current content handler.
	virtual ContentHandler& getContentHandler() = 0;
	// Return the current DTD handler.
	virtual DTDHandler& getDTDHandler() = 0;
	// Return the current entity resolver.
	virtual EntityResolver& getEntityResolver() = 0;
	// Return the current error handler.
	virtual ErrorHandler& getErrorHandler() = 0;
	// Look up the value of a feature flag.
	virtual bool getFeature(char* name) = 0;
	// Look up the value of a property.
	virtual void * getProperty(char* name) = 0;
	// Parse an XML document.
	virtual void parse(char* input) = 0;
	// Allow an application to register a content event handler.
	virtual void setContentHandler(ContentHandler& handler) = 0;
	// Allow an application to register a DTD event handler.
	virtual void setDTDHandler(DTDHandler& handler) = 0;
	// Allow an application to register an entity resolver.
	virtual void setEntityResolver(EntityResolver& resolver) = 0;
	// Allow an application to register an error event handler.
	virtual void setErrorHandler(ErrorHandler& handler) = 0;
	// Set the value of a feature flag.
	virtual void setFeature(char* name, bool value) = 0;
	// Set the value of a property.
	virtual void setProperty(char* name, void * value) = 0;
	};

class DeclHandler {
	public:
	// Report an attribute type declaration.
	virtual void attributeDecl(char* eName, char* aName, char* type, char* mode, char* value) = 0;
	// Report an element type declaration.
	virtual void elementDecl(char* name, char* model) = 0;
	// Report a parsed external entity declaration.
	virtual void externalEntityDecl(char* name, char* publicId, char* systemId) = 0;
	// Report an internal entity declaration.
	virtual void internalEntityDecl(char* name, char* value) = 0;
	};

class LexicalHandler {
	public:
	// Report an XML comment anywhere in the document.
	virtual void comment(char* ch, int start, int length) = 0;
	// Report the end of a CDATA section.
	virtual void endCDATA() = 0;
	// Report the end of DTD declarations.
	virtual void endDTD() = 0;
	// Report the end of an entity.
	virtual void endEntity(char* name) = 0;
	// Report the start of a CDATA section.
	virtual void startCDATA() = 0;
	// Report the start of DTD declarations, if any.
	virtual void startDTD(char* name, char* publicId, char* systemId) = 0;
	// Report the beginning of some internal and external XML entities.
	virtual void startEntity(char* name) = 0;
	};

// The following classes are concrete, but trivial.

class DefaultHandler : ContentHandler, DTDHandler, EntityResolver, ErrorHandler,
			LexicalHandler, DeclHandler {
	// Receive notification of character data.
	void characters(char* ch, int start, int length) {}
	// Receive notification of the end of a document.
	void endDocument() {}
	// Receive notification of the end of an element.
	void endElement(char* uri, char* localName, char* qName) {}
	// End the scope of a prefix-URI mapping.
	void endPrefixMapping(char* prefix) {}
	// Receive notification of ignorable whitespace in element content.
	void ignorableWhitespace(char* ch, int start, int length) {}
	// Receive notification of a processing instruction.
	void processingInstruction(char* target, char* data) {}
	// Receive an object for locating the origin of SAX document events.
	void setDocumentLocator(Locator& locator) {}
	// Receive notification of a skipped entity.
	void skippedEntity(char* name) {}
	// Receive notification of the beginning of a document.
	void startDocument() {}
	// Receive notification of the beginning of an element.
	void startElement(char* uri, char* localName, char* qName, Attributes& atts) {}
	// Begin the scope of a prefix-URI namespace mapping.
	void startPrefixMapping(char* prefix, char* uri) {}
	// Receive notification of a notation declaration event.
	void notationDecl(char* name, char* publicId, char* systemId) {}
	// Receive notification of an unparsed entity declaration event.
	void unparsedEntityDecl(char* name, char* publicId, char* systemId, char* notationName) {}
	// Allow the application to resolve external entities.
	char* resolveEntity(char* publicId, char* systemId) {}
	// Allows applications to provide an external subset for documents that don't explicitly define one.
	char* getExternalSubset(char* name, char* baseURI) {}
	// Allows applications to map references to external entities into input sources, or tell the parser it should use conventional URI resolution.
	char* resolveEntity(char* name, char* publicId, char* baseURI, char* systemId) {}
	// Receive notification of a recoverable error.
	void error(SAXParseException& exception) {}
	// Receive notification of a non-recoverable error.
	void fatalError(SAXParseException& exception) {}
	// Receive notification of a warning.
	void warning(SAXParseException& exception) {}
	// Report an XML comment anywhere in the document.
	void comment(char* ch, int start, int length) {}
	// Report the end of a CDATA section.
	void endCDATA() {}
	// Report the end of DTD declarations.
	void endDTD() {}
	// Report the end of an entity.
	void endEntity(char* name) {}
	// Report the start of a CDATA section.
	void startCDATA() {}
	// Report the start of DTD declarations, if any.
	void startDTD(char* name, char* publicId, char* systemId) {}
	// Report the beginning of some internal and external XML entities.
	void startEntity(char* name) {}
	// Report an attribute type declaration.
	void attributeDecl(char* eName, char* aName, char* type, char* mode, char* value) {}
	// Report an element type declaration.
	void elementDecl(char* name, char* model) {}
	// Report a parsed external entity declaration.
	void externalEntityDecl(char* name, char* publicId, char* systemId) {}
	// Report an internal entity declaration.
	void internalEntityDecl(char* name, char* value) {}
	};

class SAXParseException {
	char* message_;
	char* publicId_;
	char* systemId_;
	int lineNumber_;
	int columnNumber_;

	SAXParseException(char* message, Locator& locator) {
		message_ = message;
		publicId_ = locator.getPublicId();
		systemId_ = locator.getSystemId();
		lineNumber_ = locator.getLineNumber();
		columnNumber_ = locator.getColumnNumber();
		}

	SAXParseException(char* message, char* publicId, char* systemId, int lineNumber, int columnNumber) {
		message_ = message;
		publicId_ = publicId;
		systemId_ = systemId;
		lineNumber_ = lineNumber;
		columnNumber_ = columnNumber;
		}

	char* getMessage() { return message_;}
	char* getPublicId() { return publicId_;}
	char* getSystemId() { return systemId_;}
	int getLineNumber() { return lineNumber_;}
	int getColumnNumber() { return columnNumber_;}
	};

};
#endif
