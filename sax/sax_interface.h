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

// All arguments are either const or references, in accordance with Java semantics.

// char* is treated as an opaque object; the only thing you
// can do with it is pass it to strcmp.  Clients are solely
// responsible for making sure that char* arguments and
// results point somewhere sensible.


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
	virtual int getIndex(char* const qName) = 0;
	// Look up the index of an attribute by namespace name.
	virtual int getIndex(char* const uri, char* const localName) = 0;
	// Return the number of attributes in the list.
	virtual int getLength() = 0;
	// Look up an attribute's local name by index.
	virtual char* getLocalName(int const index) = 0;
	// Look up an attribute's XML qualified (prefixed) name by index.
	virtual char* getQName(int const index) = 0;
	// Look up an attribute's type by index.
	virtual char* getType(int const index) = 0;
	// Look up an attribute's type by XML qualified (prefixed) name.
	virtual char* getType(char* const qName) = 0;
	// Look up an attribute's type by namespace name.
	virtual char* getType(char* const uri, char* const localName) = 0;
	// Look up an attribute's namespace URI by index.
	virtual char* getURI(int const index) = 0;
	// Look up an attribute's value by index.
	virtual char* getValue(int const index) = 0;
	// Look up an attribute's value by XML qualified (prefixed) name.
	virtual char* getValue(char* const qName) = 0;
	// Look up an attribute's value by namespace name.
	virtual char* getValue(char* const uri, char* const localName) = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(int const index) = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(char* const qName) = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(char* const uri, char* const localName) = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(int const index) = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(char* const qName) = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(char* const uri, char* const localName) = 0;
	};

class ContentHandler {
public:
	// Receive notification of character data.
	virtual void characters(char* const ch, int const start, int const length) = 0;
	// Receive notification of the end of a document.
	virtual void endDocument() = 0;
	// Receive notification of the end of an element.
	virtual void endElement(char* const uri, char* const localName, char* const qName) = 0;
	// End the scope of a prefix-URI mapping.
	virtual void endPrefixMapping(char* const prefix) = 0;
	// Receive notification of ignorable whitespace in element content.
	virtual void ignorableWhitespace(char* const ch, int const start, int const length) = 0;
	// Receive notification of a processing instruction.
	virtual void processingInstruction(char* const target, char* const data) = 0;
	// Receive an object for locating the origin of SAX document events.
	virtual void setDocumentLocator(Locator& locator) = 0;
	// Receive notification of a skipped entity.
	virtual void skippedEntity(char* const name) = 0;
	// Receive notification of the beginning of a document.
	virtual void startDocument() = 0;
	// Receive notification of the beginning of an element.
	virtual void startElement(char* const uri, char* const localName, char* const qName, Attributes& atts) = 0;
	// Begin the scope of a prefix-URI namespace mapping.
	virtual void startPrefixMapping(char* const prefix, char* const uri) = 0;
	};

class DTDHandler {
public:
	// Receive notification of a notation declaration event.
	virtual void notationDecl(char* const name, char* const publicId, char* const systemId) = 0;
	// Receive notification of an unparsed entity declaration event.
	virtual void unparsedEntityDecl(char* const name, char* const publicId, char* const systemId, char* const notationName) = 0;
	};

class EntityResolver {
public:
	// Allow the application to resolve external entities.
	virtual char* resolveEntity(char* const publicId, char* const systemId, int* const size) = 0;
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
	virtual bool getFeature(char* const name) = 0;
	// Look up the value of a property.
	virtual void * getProperty(char* const name) = 0;
	// Parse an XML document.
	virtual void parse(char* const input, int const size) = 0;
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
	virtual void setFeature(char* const name, bool const value) = 0;
	// Set the value of a property.
	virtual void setProperty(char* const name, const void * value) = 0;
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
	virtual void attributeDecl(char* const eName, char* const aName, char* const type, char* const mode, char* const value) = 0;
	// Report an element type declaration.
	virtual void elementDecl(char* const name, char* const model) = 0;
	// Report a parsed external entity declaration.
	virtual void externalEntityDecl(char* const name, char* const publicId, char* const systemId) = 0;
	// Report an internal entity declaration.
	virtual void internalEntityDecl(char* const name, char* const value) = 0;
	};

class LexicalHandler {
public:
	// Report an XML comment anywhere in the document.
	virtual void comment(char* const ch, int const start, int const length) = 0;
	// Report the end of a CDATA section.
	virtual void endCDATA() = 0;
	// Report the end of DTD declarations.
	virtual void endDTD() = 0;
	// Report the end of an entity.
	virtual void endEntity(char* const name) = 0;
	// Report the start of a CDATA section.
	virtual void startCDATA() = 0;
	// Report the start of DTD declarations, if any.
	virtual void startDTD(char* const name, char* const publicId, char* const systemId) = 0;
	// Report the beginning of some internal and external XML entities.
	virtual void startEntity(char* const name) = 0;
	};

// The following classes are concrete, but simple enough to fully inline.

class DefaultHandler : public ContentHandler, public DTDHandler, public EntityResolver, public ErrorHandler, public LexicalHandler, public DeclHandler {
public:
	// Receive notification of character data.
	void characters(char* const ch, int const start, int const length) {}
	// Receive notification of the end of a document.
	void endDocument() {}
	// Receive notification of the end of an element.
	void endElement(char* const uri, char* const localName, char* const qName) {}
	// End the scope of a prefix-URI mapping.
	void endPrefixMapping(char* const prefix) {}
	// Receive notification of ignorable whitespace in element content.
	void ignorableWhitespace(char* const ch, int const start, int const length) {}
	// Receive notification of a processing instruction.
	void processingInstruction(char* const target, char* const data) {}
	// Receive an object for locating the origin of SAX document events.
	void setDocumentLocator(Locator& locator) {}
	// Receive notification of a skipped entity.
	void skippedEntity(char* const name) {}
	// Receive notification of the beginning of a document.
	void startDocument() {}
	// Receive notification of the beginning of an element.
	void startElement(char* const uri, char* const localName, char* const qName, Attributes& atts) {}
	// Begin the scope of a prefix-URI namespace mapping.
	void startPrefixMapping(char* const prefix, char* const uri) {}
	// Receive notification of a notation declaration event.
	void notationDecl(char* const name, char* const publicId, char* const systemId) {}
	// Receive notification of an unparsed entity declaration event.
	void unparsedEntityDecl(char* const name, char* const publicId, char* const systemId, char* const notationName) {}
	// Allow the application to resolve external entities.
	char* resolveEntity(char* const publicId, char* const systemId) {
		return "";
		}
	// Allows applications to provide an external subset for documents that don't explicitly define one.
	char* getExternalSubset(char* const name, char* const baseURI) {
		return 0;
		}
	// Allows applications to map references to external entities into input sources, or tell the parser it should use conventional URI resolution.
	char* resolveEntity(char* const name, char* const publicId, char* const baseURI, char* const systemId) {
		return 0;
		}
	// Receive notification of a recoverable error.
	void error(SAXParseException& exception) {}
	// Receive notification of a non-recoverable error.
	void fatalError(SAXParseException& exception) {}
	// Receive notification of a warning.
	void warning(SAXParseException& exception) {}
	// Report an XML comment anywhere in the document.
	void comment(char* const ch, int const start, int const length) {}
	// Report the end of a CDATA section.
	void endCDATA() {}
	// Report the end of DTD declarations.
	void endDTD() {}
	// Report the end of an entity.
	void endEntity(char* const name) {}
	// Report the start of a CDATA section.
	void startCDATA() {}
	// Report the start of DTD declarations, if any.
	void startDTD(char* const name, char* const publicId, char* const systemId) {}
	// Report the beginning of some internal and external XML entities.
	void startEntity(char* const name) {}
	// Report an attribute type declaration.
	void attributeDecl(char* const eName, char* const aName, char* const type, char* const mode, char* const value) {}
	// Report an element type declaration.
	void elementDecl(char* const name, char* const model) {}
	// Report a parsed external entity declaration.
	void externalEntityDecl(char* const name, char* const publicId, char* const systemId) {}
	// Report an internal entity declaration.
	void internalEntityDecl(char* const name, char* const value) {}
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
	SAXParseException(char* const message, Locator& locator) {
		message_ = message;
		publicId_ = locator.getPublicId();
		systemId_ = locator.getSystemId();
		lineNumber_ = locator.getLineNumber();
		columnNumber_ = locator.getColumnNumber();
		encoding_ = locator.getEncoding();
		XMLVersion_ = locator.getXMLVersion();
		}

	SAXParseException(char* const message, char* const publicId, char* const systemId, int const lineNumber, int const columnNumber, char* const encoding, char* const XMLVersion) {
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
	bool getFeature(char* const name) {
		return parent_->getFeature(name);
		}
	void * getProperty(char* const name) {
		return parent_->getProperty(name);
		}
	void parse(char* const input, int const size) {
		parent_->setDeclHandler(reinterpret_cast<DeclHandler&>(declHandler));
		parent_->setDTDHandler(reinterpret_cast<DTDHandler&>(dtdHandler));
		parent_->setEntityResolver(reinterpret_cast<EntityResolver&>(entityResolver));
		parent_->setErrorHandler(reinterpret_cast<ErrorHandler&>(errorHandler));
		parent_->setLexicalHandler(reinterpret_cast<LexicalHandler&>(lexicalHandler));
		parent_->setContentHandler(reinterpret_cast<ContentHandler&>(contentHandler));
		parent_->parse(input, size);
		}
	void setFeature(char* const name, bool const value) {
		parent_->setFeature(name, value);
		}
	void setProperty(char* const name, void * value) {
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

		AttributeImpl(char* const uri, char* const localName, char* const qName, char* const type, char* const value, bool const specified, bool const declared) {
			uri_ = uri;
			localName_ = localName;
			qName_ = qName;
			type_ = type;
			value_ = value;
			specified_ = specified;
			declared_ = declared;
			}

		AttributeImpl(char* const uri, char* const localName, char* const qName, char* const type, char* const value) {
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
	void addAttribute(char* const uri, char* const localName, char* const qName, char* const type, char* const value) {
		AttributeImpl a(uri, localName, qName, type, value);
		data.insert(data.end(), a);
		}

	void addAttribute(char* const uri, char* const localName, char* const qName, char* const type, char* const value, bool const specified, bool const declared) {
		AttributeImpl a(uri, localName, qName, type, value, specified, declared);
		data.insert(data.end(), a);
		}

	// Clear the attribute list for reuse.
	void clear() {
		data.clear();
		}

	// Look up an attribute's index by qualified (prefixed) name.
	int getIndex(char* const qName) {
		// Really should use an algorithm
		int size = data.size();
		for (int i = 0; i <= size; i++)
			if (strcmp(data[i].qName_, qName) == 0) return i;
		return -1;
		}

	// Look up an attribute's index by Namespace name.
	int getIndex(char* const uri, char* const localName) {
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
	char* getLocalName(int const index) {
		return data[index].localName_;
		}

	// Return an attribute's qualified (prefixed) name.
	char* getQName(int const index) {
		return data[index].qName_;
		}

	// Return an attribute's type by index.
	char* getType(int const index) {
		return data[index].type_;
		}

	// Look up an attribute's type by qualified (prefixed) name.
	char* getType(char* const qName) {
		return getType(getIndex(qName));
		}

	// Look up an attribute's type by Namespace-qualified name.
	char* getType(char* const uri, char* const localName) {
		return getType(getIndex(uri, localName));
		}

	// Return an attribute's Namespace URI.
	char* getURI(int const index) {
		return data[index].uri_;
		}

	// Return an attribute's value by index.
	char* getValue(int const index) {
		return data[index].value_;
		}

	// Look up an attribute's value by qualified (prefixed) name.
	char* getValue(char* const qName) {
		return getValue(getIndex(qName));
		}

	// Look up an attribute's value by Namespace-qualified name.
	char* getValue(char* const uri, char* const localName) {
		return getValue(getIndex(uri, localName));
		}

	// Set an attribute in the list.
	void setAttribute(int const index, char* const uri, char* const localName, char* const qName, char* const type, char* const value) {
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
	void setLocalName(int const index, char* const localName) {
		data[index].localName_ = localName;
		}

	// Set the qualified name of a specific attribute.
	void setQName(int const index, char* const qName) {
		data[index].qName_ = qName;
		}

	// Set the type of a specific attribute.
	void setType(int const index, char* const type) {
		data[index].type_ = type;
		}

	// Set the Namespace URI of a specific attribute.
	void setURI(int const index, char* const uri) {
		data[index].uri_ = uri;
		}

	// Set the value of a specific attribute.
	void setValue(int const index, char* const value) {
		data[index].value_ = value;
		}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(int const index) {
		return data[index].declared_;
		}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(char* const qName) {
		return isDeclared(getIndex(qName));
		}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(char* const uri, char* const localName) {
		return isDeclared(getIndex(uri, localName));
		}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(int const index) {
		return data[index].specified_;
		}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(char* const qName) {
		return isSpecified(getIndex(qName));
		}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(char* const uri, char* const localName) {
		return isSpecified(getIndex(uri, localName));
		}

	// Assign a value to the "declared" flag of a specific attribute.
	void setDeclared(int const index, bool const value) {
		data[index].declared_ = value;
		}

	// Assign a value to the "specified" flag of a specific attribute.
	void setSpecified(int const index, bool const value) {
		data[index].specified_ = value;
		}
	};



	}
#endif
