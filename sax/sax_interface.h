/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: sax_interface.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_SAX_INTERFACE_H
#define XQP_SAX_INTERFACE_H

#include <vector>

using namespace std;
namespace SAX {

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

// char* is treated as an opaque object; the only thing you
// can do with it is pass it to strcmp.  Clients are solely
// responsible for making sure that char* arguments and
// results point somewhere sensible.


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

class Attributes
{
public:
	// Look up the index of an attribute by XML qualified (prefixed) name.
	virtual int getIndex(const char* qName) const = 0;
	// Look up the index of an attribute by namespace name.
	virtual int getIndex(const char* uri, const char* localName) const = 0;
	// Return the number of attributes in the list.
	virtual int getLength() const = 0;
	// Look up an attribute's local name by index.
	virtual char* getLocalName(int index) const = 0;
	// Look up an attribute's XML qualified (prefixed) name by index.
	virtual char* getQName(int index) const = 0;
	// Look up an attribute's type by index.
	virtual char* getType(int index) const = 0;
	// Look up an attribute's type by XML qualified (prefixed) name.
	virtual char* getType(const char* qName) const = 0;
	// Look up an attribute's type by namespace name.
	virtual char* getType(const char* uri, const char* localName) const = 0;
	// Look up an attribute's namespace URI by index.
	virtual char* getURI(int index) const = 0;
	// Look up an attribute's value by index.
	virtual char* getValue(int index) const = 0;
	// Look up an attribute's value by XML qualified (prefixed) name.
	virtual char* getValue(const char* qName) const = 0;
	// Look up an attribute's value by namespace name.
	virtual char* getValue(const char* uri, const char* localName) const = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(int index) const = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(const char* qName) const = 0;
	// Returns false unless the attribute was declared in the DTD.
	virtual bool isDeclared(const char* uri, const char* localName) const = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(int index) const = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(const char* qName) const = 0;
	// Returns true unless the attribute value was provided by DTD defaulting.
	virtual bool isSpecified(const char* uri, const char* localName) const = 0;

};


class ContentHandler
{
public:
	// Receive notification of character data.
	virtual void characters(const char* ch, int start, int length) = 0;
	// Receive notification of the end of a document.
	virtual void endDocument() = 0;
	// Receive notification of the end of an element.
	virtual void endElement(const char* uri, const char* localName, const char* qName) = 0;
	// End the scope of a prefix-URI mapping.
	virtual void endPrefixMapping(const char* prefix) = 0;
	// Receive notification of ignorable whitespace in element content.
	virtual void ignorableWhitespace(const char* ch, int start, int length) = 0;
	// Receive notification of a processing instruction.
	virtual void processingInstruction(const char* target, const char* data) = 0;
	// Receive an object for locating the origin of SAX document events.
	virtual void setDocumentLocator(Locator& locator) = 0;
	// Receive notification of a skipped entity.
	virtual void skippedEntity(const char* name) = 0;
	// Receive notification of the beginning of a document.
	virtual void startDocument() = 0;
	// Receive notification of the beginning of an element.
	virtual void startElement(const char* uri, const char* localName, const char* qName, Attributes& atts) = 0;
	// Begin the scope of a prefix-URI namespace mapping.
	virtual void startPrefixMapping(const char* prefix, const char* uri) = 0;
};


class DTDHandler
{
public:
	// Receive notification of a notation declaration event.
	virtual void notationDecl(
		const char* name,
		const char* publicId,
		const char* systemId) = 0;

	// Receive notification of an unparsed entity declaration event.
	virtual void unparsedEntityDecl(
		const char* name,
		const char* publicId,
		const char* systemId,
		const char* notationName) = 0;
};


class EntityResolver
{
public:
	// Allow the application to resolve external entities.
	virtual const char* resolveEntity(
		const char* publicId,
		const char* systemId,
		int& size) = 0;
};


class ErrorHandler
{
public:
	// Receive notification of a recoverable error.
	virtual void error(SAXParseException& exception) = 0;
	// Receive notification of a non-recoverable error.
	virtual void fatalError(SAXParseException& exception) = 0;
	// Receive notification of a warning.
	virtual void warning(SAXParseException& exception) = 0;
};


class Locator
{
public:
	// Return the column number where the current document event ends.
	virtual int getColumnNumber() const = 0;
	// Return the line number where the current document event ends.
	virtual int getLineNumber() const = 0;
	// Return the public identifier for the current document event.
	virtual const char* getPublicId() const = 0;
	// Return the system identifier for the current document event.
	virtual const char* getSystemId() const = 0;
	// Returns the name of the character encoding for the entity.
	virtual const char*	getEncoding() const = 0;
	// Returns the version of XML used for the entity.
	virtual const char*	getXMLVersion() const = 0;
};


class XMLReader
{
public:
	// Return the current content handler.
	virtual ContentHandler& getContentHandler() const = 0;
	// Return the current declaration handler.
	virtual DeclHandler& getDeclHandler() const = 0;
	// Return the current DTD handler.
	virtual DTDHandler& getDTDHandler() const = 0;
	// Return the current entity resolver.
	virtual EntityResolver& getEntityResolver() const = 0;
	// Return the current error handler.
	virtual ErrorHandler& getErrorHandler() const = 0;
	// Return the current lexical handler.
	virtual LexicalHandler& getLexicalHandler() const = 0;
	// Look up the value of a feature flag.
	virtual bool getFeature(const char* name) const = 0;
	// Look up the value of a property.
	virtual void * getProperty(const char* name) const = 0;

	// Parse an XML document.
	virtual void parse(const char* input, int size) = 0;

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
	virtual void setFeature(const char* name, bool value) = 0;
	// Set the value of a property.
	virtual void setProperty(const char* name, const void * value) = 0;
};


class XMLFilter : public XMLReader
{
public:
	// Get the parent reader.
	virtual XMLReader& getParent() = 0;
	// Set the parent reader.
	virtual void setParent(XMLReader& parent) = 0;
};


class DeclHandler
{
public:
	// Report an attribute type declaration.
	virtual void attributeDecl(const char* eName, const char* aName, const char* type, const char* mode, const char* value) = 0;
	// Report an element type declaration.
	virtual void elementDecl(const char* name, const char* model) = 0;
	// Report a parsed external entity declaration.
	virtual void externalEntityDecl(const char* name, const char* publicId, const char* systemId) = 0;
	// Report an internal entity declaration.
	virtual void internalEntityDecl(const char* name, const char* value) = 0;
};


class LexicalHandler
{
public:
	// Report an XML comment anywhere in the document.
	virtual void comment(const char* ch, int start, int length) = 0;
	// Report the end of a CDATA section.
	virtual void endCDATA() = 0;
	// Report the end of DTD declarations.
	virtual void endDTD() = 0;
	// Report the end of an entity.
	virtual void endEntity(const char* name) = 0;
	// Report the start of a CDATA section.
	virtual void startCDATA() = 0;
	// Report the start of DTD declarations, if any.
	virtual void startDTD(const char* name, const char* publicId, const char* systemId) = 0;
	// Report the beginning of some internal and external XML entities.
	virtual void startEntity(const char* name) = 0;
};


// The following classes are concrete, but simple enough to fully inline.

class DefaultHandler :	public ContentHandler,
												public DTDHandler,
												public EntityResolver,
												public ErrorHandler,
												public LexicalHandler,
												public DeclHandler
{
public:
	// Receive notification of character data.
	void characters(const char* ch, int start, int length) {}
	// Receive notification of the end of a document.
	void endDocument() {}
	// Receive notification of the end of an element.
	void endElement(const char* uri, const char* localName, const char* qName) {}
	// End the scope of a prefix-URI mapping.
	void endPrefixMapping(const char* prefix) {}
	// Receive notification of ignorable whitespace in element content.
	void ignorableWhitespace(const char* ch, int start, int length) {}
	// Receive notification of a processing instruction.
	void processingInstruction(const char* target, const char* data) {}
	// Receive an object for locating the origin of SAX document events.
	void setDocumentLocator(Locator& locator) {}
	// Receive notification of a skipped entity.
	void skippedEntity(const char* name) {}
	// Receive notification of the beginning of a document.
	void startDocument() {}

	// Begin the scope of a prefix-URI namespace mapping.
	void startPrefixMapping(const char* prefix, const char* uri) {}
	// Receive notification of a notation declaration event.
	void notationDecl(const char* name, const char* publicId, const char* systemId) {}

	// Receive notification of a recoverable error.
	void error(SAXParseException& exception) {}
	// Receive notification of a non-recoverable error.
	void fatalError(SAXParseException& exception) {}
	// Receive notification of a warning.
	void warning(SAXParseException& exception) {}
	// Report an XML comment anywhere in the document.
	void comment(const char* ch, int start, int length) {}
	// Report the end of a CDATA section.
	void endCDATA() {}
	// Report the end of DTD declarations.
	void endDTD() {}
	// Report the end of an entity.
	void endEntity(const char* name) {}
	// Report the start of a CDATA section.
	void startCDATA() {}
	// Report the start of DTD declarations, if any.
	void startDTD(const char* name, const char* publicId, const char* systemId) {}
	// Report the beginning of some internal and external XML entities.
	void startEntity(const char* name) {}

	// Report an element type declaration.
	void elementDecl(const char* name, const char* model) {}
	// Report a parsed external entity declaration.
	void externalEntityDecl(const char* name, const char* publicId, const char* systemId) {}
	// Report an internal entity declaration.
	void internalEntityDecl(const char* name, const char* value) {}

	// Receive notification of the beginning of an element.
	void startElement(
		const char* uri,
		const char* localName,
		const char* qName,
		Attributes& atts)
	{}

	// Receive notification of an unparsed entity declaration event.
	void unparsedEntityDecl(
		const char* name, 
		const char* publicId, 
		const char* systemId, 
		const char* notationName)
	{}

	// Allow the application to resolve external entities.
	const char* resolveEntity(
		const char* publicId, 
		const char* systemId,
		int& size)
	{
		size = 0;
		return "";
	}

	// Allows applications to provide an external subset for documents
	// that don't explicitly define one.
	const char* getExternalSubset(
		const char* name,
		const char* baseURI)
	{ return NULL; }

	// Allows applications to map references to external entities into input
	// sources, or tell the parser it should use conventional URI resolution.
	const char* resolveEntity(
		const char* name,
		const char* publicId,
		const char* baseURI,
		const char* systemId)
	{ return NULL; }

	// Report an attribute type declaration.
	void attributeDecl(
		const char* eName,
		const char* aName,
		const char* type,
		const char* mode,
		const char* value)
	{}


};


class LocatorImpl : public Locator
{
protected:
	const char* publicId_;
	const char* systemId_;
	int lineNumber_;
	int columnNumber_;
	const char* encoding_;
	const char* XMLVersion_;

public:
	LocatorImpl(Locator& locator)
	:
		publicId_(locator.getPublicId()),
		systemId_(locator.getSystemId()),
		lineNumber_(locator.getLineNumber()),
		columnNumber_(locator.getColumnNumber()),
		encoding_(locator.getEncoding()),
		XMLVersion_(locator.getXMLVersion())
	{}

	LocatorImpl(
		const char* publicId, 
		const char* systemId, 
		int lineNumber, 
		int columnNumber, 
		const char* encoding, 
		const char* XMLVersion)
	:
		publicId_(publicId),
		systemId_(systemId),
		lineNumber_(lineNumber),
		columnNumber_(columnNumber),
		encoding_(encoding),
		XMLVersion_(XMLVersion)
	{}

	LocatorImpl()
	:
		publicId_(NULL),
		systemId_(NULL),
		lineNumber_(0),
		columnNumber_(0),
		encoding_(NULL),
		XMLVersion_(NULL)
	{}

public:
	const char* getPublicId() const { return publicId_; }
	const char* getSystemId() const { return systemId_; }
	int getLineNumber() const { return lineNumber_; }
	int getColumnNumber() const { return columnNumber_; }
	const char* getEncoding() const { return encoding_; }
	const char* getXMLVersion() const { return XMLVersion_; }
};


class SAXParseException : public LocatorImpl
{
private:
	const char* message_;

public:
	SAXParseException() : message_(NULL) {}

	SAXParseException(const char* message, Locator& locator)
	:
		LocatorImpl(locator),
		message_(message)
	{}

	SAXParseException(
		const char* message, 
		const char* publicId, 
		const char* systemId, 
		int lineNumber, 
		int columnNumber, 
		const char* encoding, 
		const char* XMLVersion)
	:
		LocatorImpl(publicId,systemId,lineNumber,columnNumber,encoding,XMLVersion),
		message_(message)
	{ }

public:
	const char* getMessage() const { return message_; }

};


class XMLReaderImpl : public DefaultHandler,
											public XMLReader
{
protected:
	ContentHandler* contentHandler;
	DTDHandler* dtdHandler;
	EntityResolver* entityResolver;
	ErrorHandler* errorHandler;
	LexicalHandler* lexicalHandler;
	DeclHandler* declHandler;
	SAXParseException exception;

public:
	XMLReaderImpl()
	{
		contentHandler = this;
		dtdHandler = this;
		entityResolver = this;
		errorHandler = this;
		lexicalHandler = this;
		declHandler = this;
	}

	ContentHandler& getContentHandler() const { return *contentHandler; }
	DeclHandler& getDeclHandler() const { return *declHandler; }
	DTDHandler& getDTDHandler() const { return *dtdHandler; }
	EntityResolver& getEntityResolver() const { return *entityResolver; }
	ErrorHandler& getErrorHandler() const { return *errorHandler; }
	LexicalHandler& getLexicalHandler() const { return *lexicalHandler; }
	void setContentHandler(ContentHandler& handler) { contentHandler = &handler; }
	void setDTDHandler(DTDHandler& handler) { dtdHandler = &handler; }
	void setDeclHandler(DeclHandler& handler) { declHandler = &handler; }
	void setEntityResolver(EntityResolver& resolver) { entityResolver = &resolver; }
	void setErrorHandler(ErrorHandler& handler) { errorHandler = &handler; }
	void setLexicalHandler(LexicalHandler& handler) { lexicalHandler = &handler; }

	bool getFeature(const char*) const { return false; }
	void* getProperty(const char*) const { return NULL; }
	void parse(const char*, int) {}
	void setFeature(const char*, bool) {}
	void setProperty(const char*, const void*) {}

};


class XMLFilterImpl : public XMLReaderImpl, public XMLFilter
{
private:
	XMLReader* parent_;

public:
	XMLFilterImpl(XMLReader& parent) : parent_(&parent) {}

public:
	bool getFeature(const char* name) const { return parent_->getFeature(name); }
	void* getProperty(const char* name) const { return parent_->getProperty(name); }
	void setFeature(const char* name, bool value) { parent_->setFeature(name, value); }
	void setProperty(const char* name, void * value) { parent_->setProperty(name, value); }
	XMLReader& getParent() const { return *parent_; }

public:
	void parse(const char* input, int size)
	{
		parent_->setDeclHandler(*declHandler);
		parent_->setDTDHandler(*dtdHandler);
		parent_->setEntityResolver(*entityResolver);
		parent_->setErrorHandler(*errorHandler);
		parent_->setLexicalHandler(*lexicalHandler);
		parent_->setContentHandler(*contentHandler);
		parent_->parse(input, size);
	}

	// defaults
	ContentHandler& getContentHandler() const { return parent_->getContentHandler(); }
	DeclHandler& getDeclHandler() const { parent_->getDeclHandler(); }
	DTDHandler& getDTDHandler() const { parent_->getDTDHandler(); }
	EntityResolver& getEntityResolver() const { parent_->getEntityResolver(); }
	ErrorHandler& getErrorHandler() const { parent_->getErrorHandler(); }
	LexicalHandler& getLexicalHandler() const { parent_->getLexicalHandler(); }
	void setContentHandler(SAX::ContentHandler& h) { parent_->setContentHandler(h); }
	void setDTDHandler(SAX::DTDHandler& h) { parent_->setDTDHandler(h); }
	void setDeclHandler(SAX::DeclHandler& h) { parent_->setDeclHandler(h); }
	void setEntityResolver(SAX::EntityResolver& h) { parent_->setEntityResolver(h); } 
	void setErrorHandler(SAX::ErrorHandler& h) { parent_->setErrorHandler(h); }
	void setLexicalHandler(SAX::LexicalHandler& h) { parent_->setLexicalHandler(h); }
	void setProperty(const char*, const void*) {}

	XMLReader& getParent() { return *parent_; }
	void setParent(XMLReader& parent) { parent_ = &parent; }

};


class AttributesImpl
{
private:
	struct AttributeImpl
	{
		const char* uri_;
		const char* localName_;
		const char* qName_;
		const char* type_;
		const char* value_;
		bool specified_;
		bool declared_;

	public:
		AttributeImpl(
			const char* uri,
			const char* localName,
			const char* qName,
			const char* type,
			const char* value,
			bool specified,
			bool declared)
		:
			uri_(uri),
			localName_(localName),
			qName_(qName),
			type_(type),
			value_(value),
			specified_( specified),
			declared_(declared)
		{}

		AttributeImpl(
			const char* uri,
			const char* localName,
			const char* qName,
			const char* type,
			const char* value)
		:
			uri_(uri),
			localName_(localName),
			qName_(qName),
			type_(type),
			value_(value),
			specified_(true),
			declared_(strcmp(type, "CDATA") != 0)
		{}
	};

	vector<AttributeImpl> data;

public:
	// Add an attribute to the end of the list.
	void addAttribute(
		const char* uri,
		const char* localName,
		const char* qName,
		const char* type,
		const char* value)
	{
		AttributeImpl a(uri, localName, qName, type, value);
		data.insert(data.end(), a);
	}

	void addAttribute(
		const char* uri,
		const char* localName,
		const char* qName,
		const char* type,
		const char* value,
		bool specified,
		bool declared)
	{
		AttributeImpl a(uri, localName, qName, type, value, specified, declared);
		data.insert(data.end(), a);
	}

	// Clear the attribute list for reuse.
	void clear()
	{
		data.clear();
	}

	// Look up an attribute's index by qualified (prefixed) name.
	int getIndex(const char* qName) const
	{
		// Really should use an algorithm
		int size = data.size();
		for (int i = 0; i <= size; i++) {
			if (strcmp(data[i].qName_, qName) == 0) return i;
		}
		return -1;
	}

	// Look up an attribute's index by Namespace name.
	int getIndex(const char* uri, const char* localName) const
	{
		// Really should use an algorithm
		int size = data.size();
		for (int i = 0; i <= size; i++) {
			if (strcmp(data[i].uri_, uri) == 0 && strcmp(data[i].localName_, localName) == 0) {
				return i;
			}
		}
		return -1;
	}

	// Return the number of attributes in the list.
	int getLength() const
	{
		return data.size();
	}

	// Return an attribute's local name.
	const char* getLocalName(int index) const
	{
		return data[index].localName_;
	}

	// Return an attribute's qualified (prefixed) name.
	const char* getQName(int index) const
	{
		return data[index].qName_;
	}

	// Return an attribute's type by index.
	const char* getType(int index) const
	{
		return data[index].type_;
	}

	// Look up an attribute's type by qualified (prefixed) name.
	const char* getType(const char* qName) const
	{
		return getType(getIndex(qName));
	}

	// Look up an attribute's type by Namespace-qualified name.
	const char* getType(const char* uri, const char* localName) const
	{
		return getType(getIndex(uri, localName));
	}

	// Return an attribute's Namespace URI.
	const char* getURI(int index) const
	{
		return data[index].uri_;
	}

	// Return an attribute's value by index.
	const char* getValue(int index) const
	{
		return data[index].value_;
	}

	// Look up an attribute's value by qualified (prefixed) name.
	const char* getValue(const char* qName) const
	{
		return getValue(getIndex(qName));
	}

	// Look up an attribute's value by Namespace-qualified name.
	const char* getValue(const char* uri, const char* localName) const
	{
		return getValue(getIndex(uri, localName));
	}

	// Set an attribute in the list.
	void setAttribute(
		int index,
		const char* uri,
		const char* localName,
		const char* qName,
		const char* type,
		const char* value)
	{
		AttributeImpl a(uri, localName, qName, type, value);
		data[index] = a;
	}

	// Copy an entire Attributes object.
	void setAttributes(Attributes& atts)
	{
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
	void setLocalName(int index, const char* localName)
	{
		data[index].localName_ = localName;
	}

	// Set the qualified name of a specific attribute.
	void setQName(int index, const char* qName)
	{
		data[index].qName_ = qName;
	}

	// Set the type of a specific attribute.
	void setType(int index, const char* type)
	{
		data[index].type_ = type;
	}

	// Set the Namespace URI of a specific attribute.
	void setURI(int index, const char* uri)
	{
		data[index].uri_ = uri;
	}

	// Set the value of a specific attribute.
	void setValue(int index, const char* value)
	{
		data[index].value_ = value;
	}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(int index) const
	{
		return data[index].declared_;
	}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(const char* qName) const
	{
		return isDeclared(getIndex(qName));
	}

	// Returns the current value of the attribute's "declared" flag.
	bool isDeclared(const char* uri, const char* localName) const
	{
		return isDeclared(getIndex(uri, localName));
	}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(int index) const
	{
		return data[index].specified_;
	}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(const char* qName) const
	{
		return isSpecified(getIndex(qName));
	}

	// Returns the current value of an attribute's "specified" flag.
	bool isSpecified(const char* uri, const char* localName) const
	{
		return isSpecified(getIndex(uri, localName));
	}

	// Assign a value to the "declared" flag of a specific attribute.
	void setDeclared(int index, bool value)
	{
		data[index].declared_ = value;
	}

	// Assign a value to the "specified" flag of a specific attribute.
	void setSpecified(int index, bool value)
	{
		data[index].specified_ = value;
	}
};

}	/* namespace SAX */
#endif	/* XQP_SAX_INTERFACE_H */
