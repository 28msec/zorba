// Public domain port by John Cowan <cowan@ccil.org>
//    of org.xml.sax.* classes by David Megginson
// NO WARRANTY!  Use as you will.
// For compatibility, Java uppercasing conventions are used throughout.

// Deviations from SAX as defined at http://www.saxproject.org/apidoc/ :
// The Java package structure is flattened into a single SAX namespace.
// SAX1-specific interfaces and classes have been removed.
// Interfaces and classes ending in 2 have been merged with the originals,
//    except for EntityResolver.
// String arguments are represented by char*.
// Parsing is done from a char* plus a length rather than an
//    InputSource.  EntityResolver is repurposed to map an external
//    identifier to a char* and size.  There is no direct support
//    for parsing from a URI, therefore.
// SAXParseException derives from LocatorImpl, and has no embedded exception.
// XMLReaderFactory is not provided.
// XMLReader treats LexicalHandler and DeclHandler like all other handlers.
// XMLFilterImpl does not have a zero-argument constructor, so the
//    parent is never null.
// AttributesImpl omits the removeAttribute method, which is broken in Java anyhow.
// NamespaceSupport is not provided.

// XMLReaderImpl is a new class which provides support for get/set
// of handlers with default no-op handling.  It also has an
// embedded SAXParseException (which also serves as a Locator).
// It doesn't provide implementations for parse()
// or for feature/property handling, so it is still abstract.


#ifndef SAX_ATTRIBUTES_H
#define SAX_ATTRIBUTES_H

#include <vector>
using namespace std;

namespace SAX {

// Declare all classes forward to avoid most ordering issues.
// We still need to declare base classes before derived ones.
class Attributes;
class AttributesImpl;		// FIXME
class ContentHandler;
class DTDHandler;
class DeclHandler;
class DefaultHandler;
class EntityResolver;
class ErrorHandler;
class LexicalHandler;
class Locator;
class LocatorImpl;
class SAXParseException;
class XMLFilter;
class XMLFilterImpl;
class XMLReader;
class XMLReaderImpl;

// All these classes are abstract and correspond to Java interfaces.
// SAX parser drivers and SAX clients should implement them.

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
	virtual char* resolveEntity(char* publicId, char* systemId, int& size) = 0;
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

class XMLReader {
public:
	// Return the current content handler.
	virtual ContentHandler& getContentHandler() = 0;
	// Return the current declaration handler.
	virtual DeclHandler& getDeclHandler() = 0;
	// Return the current DTD handler.
	virtual DTDHandler& getDTDHandler() = 0;
	// Return the current entity resolver.
	virtual EntityResolver& getEntityResolver() = 0;
	// Return the current error handler.
	virtual ErrorHandler& getErrorHandler() = 0;
	// Return the current lexical handler.
	virtual LexicalHandler& getLexicalHandler() = 0;
	// Look up the value of a feature flag.
	virtual bool getFeature(char* name) = 0;
	// Look up the value of a property.
	virtual void * getProperty(char* name) = 0;
	// Parse an XML document.
	virtual void parse(char* input, int size) = 0;
	// Allow an application to register a content event handler.
	virtual void setContentHandler(ContentHandler& handler) = 0;
	// Allow an application to register a DTD event handler.
	virtual void setDTDHandler(DTDHandler& handler) = 0;
	// Allow an application to register a declaration event handler.
	virtual void setDeclHandler(DeclHandler& handler) = 0;
	// Allow an application to register an entity resolver.
	virtual void setEntityResolver(EntityResolver& resolver) = 0;
	// Allow an application to register an error event handler.
	virtual void setErrorHandler(ErrorHandler& handler) = 0;
	// Allow an application to register an lexical handler.
	virtual void setLexicalHandler(LexicalHandler& handler) = 0;
	// Set the value of a feature flag.
	virtual void setFeature(char* name, bool value) = 0;
	// Set the value of a property.
	virtual void setProperty(char* name, void * value) = 0;
	};

class XMLFilter : public XMLReader {
public:
	// Get the parent reader.
	virtual XMLReader& getParent() = 0;
	// Set the parent reader.
	virtual void setParent(XMLReader& parent) = 0;
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

// The following classes are concrete, but simple enough to fully inline.

class DefaultHandler : public ContentHandler, public DTDHandler, public EntityResolver, public ErrorHandler, public LexicalHandler, public DeclHandler {
public:
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
	char* resolveEntity(char* publicId, char* systemId) {
		return "";
		}
	// Allows applications to provide an external subset for documents that don't explicitly define one.
	char* getExternalSubset(char* name, char* baseURI) {
		return 0;
		}
	// Allows applications to map references to external entities into input sources, or tell the parser it should use conventional URI resolution.
	char* resolveEntity(char* name, char* publicId, char* baseURI, char* systemId) {
		return 0;
		}
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

class LocatorImpl : public Locator {
protected:
	char* publicId_;
	char* systemId_;
	int lineNumber_;
	int columnNumber_;
	char* encoding_;
	char* XMLVersion_;
public:
	LocatorImpl() {
		publicId_ = 0;
		systemId_ = 0;
		lineNumber_ = 0;
		columnNumber_ = 0;
		encoding_ = 0;
		XMLVersion_ = 0;
		}

	char* getPublicId() {
		return publicId_;
		}
	char* getSystemId() {
		return systemId_;
		}
	int getLineNumber() {
		return lineNumber_;
		}
	int getColumnNumber() {
		return columnNumber_;
		}
	char* getEncoding() {
		return encoding_;
		}
	char* getXMLVersion() {
		return XMLVersion_;
		}
	};


class SAXParseException : public LocatorImpl {
private:
	char* message_;

public:
	SAXParseException() {
		message_ = 0;
		}
	SAXParseException(char* message, Locator& locator) {
		message_ = message;
		publicId_ = locator.getPublicId();
		systemId_ = locator.getSystemId();
		lineNumber_ = locator.getLineNumber();
		columnNumber_ = locator.getColumnNumber();
		encoding_ = locator.getEncoding();
		XMLVersion_ = locator.getXMLVersion();
		}

	SAXParseException(char* message, char* publicId, char* systemId, int lineNumber, int columnNumber, char* encoding, char* XMLVersion) {
		message_ = message;
		publicId_ = publicId;
		systemId_ = systemId;
		lineNumber_ = lineNumber;
		columnNumber_ = columnNumber;
		encoding_ = encoding;
		XMLVersion_ = XMLVersion;
		}

	char* getMessage() {
		return message_;}

	};

class XMLReaderImpl : public DefaultHandler, public XMLReader {
protected:
	ContentHandler* contentHandler;
	DTDHandler* dtdHandler;
	EntityResolver* entityResolver;
	ErrorHandler* errorHandler;
	LexicalHandler* lexicalHandler;
	DeclHandler* declHandler;
	SAXParseException exception;
public:
	XMLReaderImpl() {
		contentHandler = this;
		dtdHandler = this;
		entityResolver = this;
		errorHandler = this;
		lexicalHandler = this;
		declHandler = this;
		}
	ContentHandler& getContentHandler() {
		return reinterpret_cast<ContentHandler&> (contentHandler);
		}
	DeclHandler& getDeclHandler() {
		return reinterpret_cast<DeclHandler&> (declHandler);
		}
	DTDHandler& getDTDHandler() {
		return reinterpret_cast<DTDHandler&> (dtdHandler);
		}
	EntityResolver& getEntityResolver() {
		return reinterpret_cast<EntityResolver&> (entityResolver);
		}
	ErrorHandler& getErrorHandler() {
		return reinterpret_cast<ErrorHandler&> (errorHandler);
		}
	LexicalHandler& getLexicalHandler() {
		return reinterpret_cast<LexicalHandler&> (lexicalHandler);
		}
	void setContentHandler(ContentHandler& handler) {
		contentHandler = reinterpret_cast <ContentHandler*>(&handler);
		}
	void setDTDHandler(DTDHandler& handler) {
		dtdHandler = reinterpret_cast <DTDHandler*>(&handler);
		}
	void setDeclHandler(DeclHandler& handler) {
		declHandler = reinterpret_cast <DeclHandler*>(&handler);
		}
	void setEntityResolver(EntityResolver& resolver) {
		entityResolver = reinterpret_cast<EntityResolver*>(&resolver);
		}
	void setErrorHandler(ErrorHandler& handler) {
		errorHandler = reinterpret_cast <ErrorHandler*>(&handler);
		}
	void setLexicalHandler(LexicalHandler& handler) {
		lexicalHandler = reinterpret_cast <LexicalHandler*>(&handler);
		}
	};

class XMLFilterImpl : public XMLReaderImpl, public XMLFilter {
private:
	XMLReader* parent_;
public:
	XMLFilterImpl(XMLReader& parent) {
		parent_ = reinterpret_cast<XMLReader*>(&parent);
		}
	bool getFeature(char* name) {
		return parent_->getFeature(name);
		}
	void * getProperty(char* name) {
		return parent_->getProperty(name);
		}
	void parse(char* input, int size) {
		parent_->setDeclHandler(reinterpret_cast<DeclHandler&>(declHandler));
		parent_->setDTDHandler(reinterpret_cast<DTDHandler&>(dtdHandler));
		parent_->setEntityResolver(reinterpret_cast<EntityResolver&>(entityResolver));
		parent_->setErrorHandler(reinterpret_cast<ErrorHandler&>(errorHandler));
		parent_->setLexicalHandler(reinterpret_cast<LexicalHandler&>(lexicalHandler));
		parent_->setContentHandler(reinterpret_cast<ContentHandler&>(contentHandler));
		parent_->parse(input, size);
		}
	void setFeature(char* name, bool value) {
		parent_->setFeature(name, value);
		}
	void setProperty(char* name, void * value) {
		parent_->setProperty(name, value);
		}
	XMLReader& getParent() {
		return reinterpret_cast<XMLReader&>(parent_);
		}
	};

class AttributesImpl {
private:
	struct AttributeImpl {
		char* uri_;
		char* localName_;
		char* qName_;
		char* type_;
		char* value_;
		bool specified_;
		bool declared_;
	public:

		AttributeImpl(char* uri, char* localName, char* qName, char* type, char* value, bool specified, bool declared) {
			uri_ = uri;
			localName_ = localName;
			qName_ = qName;
			type_ = type;
			value_ = value;
			specified_ = specified;
			declared_ = declared;
			}

		AttributeImpl(char* uri, char* localName, char* qName, char* type, char* value) {
			uri_ = uri;
			localName_ = localName;
			qName_ = qName;
			type_ = type;
			value_ = value;
			specified_ = true;
			declared_ = (strcmp(type, "CDATA") != 0);
			}

		};

	vector<AttributeImpl> data;

public:
	// Add an attribute to the end of the list.
	void addAttribute(char* uri, char* localName, char* qName, char* type, char* value) {
		AttributeImpl a(uri, localName, qName, type, value);
		data.insert(data.end(), a);
		}

	void addAttribute(char* uri, char* localName, char* qName, char* type, char* value, bool specified, bool declared) {
		AttributeImpl a(uri, localName, qName, type, value, specified, declared);
		data.insert(data.end(), a);
		}

	// Clear the attribute list for reuse.
	void clear() {
		data.clear();
		}

	// Look up an attribute's index by qualified (prefixed) name.
	int getIndex(char* qName) {
		// Really should use an algorithm
		int size = data.size();
		for (int i = 0; i <= size; i++)
			if (strcmp(data[i].qName_, qName) == 0) return i;
		return -1;
		}

	// Look up an attribute's index by Namespace name.
	int getIndex(char* uri, char* localName) {
		// Really should use an algorithm
		int size = data.size();
		for (int i = 0; i <= size; i++)
			if (strcmp(data[i].uri_, uri) == 0 && strcmp(data[i].localName_, localName) == 0)
				return i;
		return -1;
		}

	// Return the number of attributes in the list.
	int getLength() {
		return data.size();
		}

	// Return an attribute's local name.
	char* getLocalName(int index) {
		return data[index].localName_;
		}

	// Return an attribute's qualified (prefixed) name.
	char* getQName(int index) {
		return data[index].qName_;
		}

	// Return an attribute's type by index.
	char* getType(int index) {
		return data[index].type_;
		}

	// Look up an attribute's type by qualified (prefixed) name.
	char* getType(char* qName) {
		return getType(getIndex(qName));
		}

	// Look up an attribute's type by Namespace-qualified name.
	char* getType(char* uri, char* localName) {
		return getType(getIndex(uri, localName));
		}

	// Return an attribute's Namespace URI.
	char* getURI(int index) {
		return data[index].uri_;
		}

	// Return an attribute's value by index.
	char* getValue(int index) {
		return data[index].value_;
		}

	// Look up an attribute's value by qualified (prefixed) name.
	char* getValue(char* qName) {
		return getValue(getIndex(qName));
		}

	// Look up an attribute's value by Namespace-qualified name.
	char* getValue(char* uri, char* localName) {
		return getValue(getIndex(uri, localName));
		}

	// Set an attribute in the list.
	void setAttribute(int index, char* uri, char* localName, char* qName, char* type, char* value) {
		AttributeImpl a(uri, localName, qName, type, value);
		data[index] = a;
		}

	// Copy an entire Attributes object.
	void setAttributes(Attributes& atts) {
		data.clear();
		int length = getLength();
		for (int i = 0; i <= length; i++) {
			addAttribute(
				atts.getURI(i),
				atts.getLocalName(i),
				atts.getQName(i),
				atts.getType(i),
				atts.getValue(i),
				atts.isSpecified(i),
				atts.isDeclared(i)
				);
			}
		}

	// Set the local name of a specific attribute.
	void setLocalName(int index, char* localName) {
		data[index].localName_ = localName;
		}

	// Set the qualified name of a specific attribute.
	void setQName(int index, char* qName) {
		data[index].qName_ = qName;
		}

	// Set the type of a specific attribute.
	void setType(int index, char* type) {
		data[index].type_ = type;
		}

	// Set the Namespace URI of a specific attribute.
	void setURI(int index, char* uri) {
		data[index].uri_ = uri;
		}

	// Set the value of a specific attribute.
	void setValue(int index, char* value) {
		data[index].value_ = value;
		}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(int index) {
		return data[index].declared_;
		}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(char* qName) {
		return isDeclared(getIndex(qName));
		}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(char* uri, char* localName) {
		return isDeclared(getIndex(uri, localName));
		}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(int index) {
		return data[index].specified_;
		}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(char* qName) {
		return isSpecified(getIndex(qName));
		}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(char* uri, char* localName) {
		return isSpecified(getIndex(uri, localName));
		}

	// Assign a value to the "declared" flag of a specific attribute.
	void setDeclared(int index, bool value) {
		data[index].declared_ = value;
		}

	// Assign a value to the "specified" flag of a specific attribute.
	void setSpecified(int index, bool value) {
		data[index].specified_ = value;
		}
	};



	};
#endif
