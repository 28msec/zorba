/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: nodereps.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

/*______________________________________________________________________
|
| Includes classes supporting zorba binary representations of
|	the 7 node types defined in: | XQuery 1.0 and XPath 2.0 Data Model
|	[http://www.w3.org/TR/xpath-datamodel/]
|_______________________________________________________________________*/
 
#ifndef XQP_NODEREPS_H
#define XQP_NODEREPS_H

#include "valuereps.h"
#include "noderep_iterator.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

#include <vector>
#include <sys/types.h>

namespace xqp {

typedef rchandle<noderep_iterator> noderep_it;

class xs_stringValue;
class element_noderep;
class qname;
class zorba;


class noderep : public itemRep
{
protected:
	uint32_t  theLength;			// blob storage length
	itemref_t theRef;					// forwarding reference for update
	uint32_t  theGen;					// generation number
	itemid_t  theID;					// node ordinal id
	itemid_t  theParentID;		// parent node ordinal id

public:		// ctor,dtor
	noderep(
	  sequence_type_t,      	// node type
	  uint32_t length,				// length in bytes
	  itemref_t ref,					// forwarding reference
	  uint32_t gen,			 			// generation number
	  itemid_t id,           	// ordinal node id
	  itemid_t parent);      	// parent node id

	noderep() {}
	~noderep() {}

public:		// accessors
	itemref_t ref() const { return theRef; }
	uint32_t gen() const { return theGen; }
	itemid_t id() const { return theID; }
	itemid_t parentid() const { return theParentID; }

	itemref_t& ref() { return theRef; }
	uint32_t& gen() { return theGen; }
	itemid_t& id() { return theID; }
	itemid_t& parentid() { return theParentID; }

public:		// storage interface
	void* operator new(size_t nBytes, void* p) { return p; }
	void* operator new(size_t nBytes, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}
	
public:		// XQuery sub-interface
	string string_value() const { return ""; } 
	const xs_stringValue* baseuri(zorba*) const { return NULL; }
	const xs_stringValue* docuri(zorba*)  const { return NULL; }

	qname* node_name() const { return NULL; }
	qname* type_name() const { return NULL; }

	noderep* parent(zorba*) const;

	noderep_it namespaces() const { return NULL; }
	noderep_it attributes() const { return NULL; }
	noderep_it children() const { return NULL; }

	bool is_id() const { return false; }
	bool is_idrefs() const { return false; }
	bool nilled() const { return false; }

};
	

class child_noderep_iterator : public noderep_iterator
{
protected:
	const noderep* theParentNodePtr;
	noderep* 			 theCurrentNodePtr;
	const noderep* theEndNodePtr;

public:
	child_noderep_iterator(
		const noderep* parent,
		noderep* current);

	~child_noderep_iterator() {}

public:
 	void open() {}
	void close() {}
	noderep* next(uint32_t delta = 1) { ++(*this); return **this; }
	noderep* peek() const { return **this; }
	bool done() const { return theCurrentNodePtr >= theEndNodePtr; }

public:
	noderep* operator*() const;
	child_noderep_iterator& operator++();

};


class child_const_noderep_iterator : public noderep_iterator
{
protected:
	const noderep* theParentNodePtr;
	const noderep* theCurrentNodePtr;
	const noderep* theEndNodePtr;

public:
	child_const_noderep_iterator(
		const noderep* parent,
		const noderep* current);

	~child_const_noderep_iterator() {}

public:
 	void open() {}
	void close() {}
	noderep* next(uint32_t delta = 1) { ++(*this); return **this; }
	noderep* peek() const { return **this; }
	bool done() const { return theCurrentNodePtr >= theEndNodePtr; }

public:
	noderep* operator*() const;
	child_noderep_iterator& operator++();

};


class attribute_noderep_iterator : public noderep_iterator
{
protected:
	const noderep* theParentNodePtr;
	noderep* 			 theCurrentNodePtr;
	const noderep* theEndNodePtr;

public:
	attribute_noderep_iterator(
		const noderep* parent,
		noderep* current,
		const noderep* end);

	~attribute_noderep_iterator() {}

public:
 	void open() {}
	void close() {}
	noderep* next(uint32_t delta = 1) { ++(*this); return **this; }
	noderep* peek() const { return **this; }
	bool done() const;

public:
	noderep* operator*() const;
	attribute_noderep_iterator& operator++();

};


class namespace_noderep_iterator : public noderep_iterator
{
protected:
	const noderep* theParentNodePtr;

public:
	namespace_noderep_iterator(const noderep*);
	~namespace_noderep_iterator() {}

public:
 	void open() {}
	void close() {}
	noderep* next(uint32_t delta=1) { ++(*this); return **this; }
	noderep* peek() const { return **this; }
	bool done() const;

public:
	noderep* operator*() const;
	namespace_noderep_iterator& operator++();

};


class attribute_noderep;
class namespace_noderep;


/*..........................................
 :            document_node                :
 :.........................................*/

class document_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	itemid_t theBaseuri;		// base URI
	itemid_t theDocuri;			// document URI
	char rest[0];
	/*
    node child[0]
    ...
    node child[n-1]
	*/

public:
	document_noderep() {}
	document_noderep(zorba*, itemid_t baseuri, itemid_t uri);

public:		// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	std::string string_value() const;

	const xs_stringValue* baseuri(zorba*) const;
	const xs_stringValue* docuri(zorba*) const;

	noderep_it children() const;
	noderep_it namespaces() const;

private:	// ctor,dtor
	document_noderep(document_noderep&) {}
	~document_noderep() {}

public:		// output and debugging
	std::ostream& put(zorba*,std::ostream&) const;

};



/*..........................................
 :  element nodes                          :
 :.........................................*/

class element_noderep : public noderep
{
	friend class child_noderep_iterator;
	friend class attribute_noderep_iterator;

protected:
	itemid_t qnameID;					// element QName
	itemid_t namespacesID;		// in-scope namespaces
	uint32_t nodeOffset;			// offset to first node
	char rest[0];
	/*
    attr[0]
    ...
    attr[m-1]
    node[0]      <- node_offset
    ...
    node[n-1]
	*/

public:
	element_noderep() {}
	element_noderep(zorba*, itemid_t qnameid);

public:		// accessors
	qname& get_qname() const;													// element QName
	namespace_noderep* name_space_at(uint32_t) const;	// n-th namespace
	attribute_noderep* attr_at(uint32_t) const;				// n-th attribute
	noderep* node_at(uint32_t) const;									// n-th child
	uint32_t ns_count() const;												// number of namespaces
	uint32_t attr_count() const;											// number of attributes
	uint32_t child_count() const;											// number of children

public:		// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	std::string string_value() const;
	qname* node_name(zorba*) const;

	const xs_stringValue* baseuri(zorba*) const;
	const xs_stringValue* docuri(zorba*) const;

	noderep_it attributes() const;
	noderep_it children() const;
	noderep_it namespaces(zorba*) const;

	bool is_nilled() const { return false; }
	bool is_id() const { return (theType & ID_SUB5); }
	bool is_idref() const { return (theType & IDREF_SUB5); }

private:	//ctor,dtor - lock out
	element_noderep(const element_noderep&) {}
	~element_noderep() {}

public:		// output and debugging
	std::ostream& put(zorba*,std::ostream&) const;

};


/*..........................................
 :  attribute nodes                        :
 :.........................................*/

class attribute_noderep :	public noderep
{
	friend class child_noderep_iterator;

protected:
	itemid_t qnameID;
	char rest[0];
	/*
		char[] value
	*/

public:
  attribute_noderep() {}

	attribute_noderep(
		zorba*,
		itemid_t qname);

	attribute_noderep(
		zorba*,
		itemid_t qnameid,
		const std::string& val);

public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:	// XQuery sub-interface
	std::string string_value() const;
	qname* node_name(zorba*) const;
	const xs_stringValue* baseuri(zorba*) const;

	bool is_id() const { return (theType & ID_SUB5); }
	bool is_idref() const { return (theType & IDREF_SUB5); }

private:	//ctor,dtor - lock out
	attribute_noderep(attribute_noderep&);
  ~attribute_noderep();

public:		// output,debugging
	std::ostream& put(zorba*,std::ostream&) const;

};


/*..........................................
 :          namespace nodes                :
 :.........................................*/

class namespace_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	nskey_t  theNsid;
	uint32_t uriOffset;
	char rest[0];
	/*
		char[] prefix
		char[] uri  
	*/

public:
	namespace_noderep() {}

	namespace_noderep(
		zorba*,
		const std::string& prefix,
		const std::string& uri);

public:		// storage interface
	nskey_t& nsid() { return theNsid; }

public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	std::string string_value() const;
	qname* node_name(zorba*) const;

	std::string prefix() const;
	std::string uri() const;

private:	//ctor,dtor - lock out
	namespace_noderep(namespace_noderep&) {}
	~namespace_noderep() {}

public:		// output, debugging
	std::ostream& put(zorba*,std::ostream&) const;

};



/*..........................................
 :    processing instruction nodes         :
 :.........................................*/

class pi_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	uint32_t theContentOffset;
	char rest[0];
	/*
		char[] target
		char[] content
	*/

public:
	pi_noderep() {}
	pi_noderep(zorba*);

public:		// storage interface
	uint32_t& content() { return theContentOffset; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// XQuery interface
	std::string string_value() const;
	const xs_stringValue* baseuri(zorba*) const;
	qname* node_name(zorba*) const;

private:	//ctor,dtor - lock out
	pi_noderep(pi_noderep&) {}
	~pi_noderep() {}

public:		// output, debugging
	std::ostream& put(zorba*,std::ostream&) const;

};



/*..........................................
 :          comment nodes                  :
 :.........................................*/

class comment_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	char rest[0];
	/*
		char[] content
	*/

public:
	comment_noderep(zorba*);
	comment_noderep() {}
	
public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void operator delete(void*) {}

public:		// XQUery interface
	std::string string_value() const;
	const xs_stringValue* baseuri(zorba*) const;

private:	// lock out default and copy constructors
	comment_noderep(comment_noderep&) {}
	~comment_noderep() {}

public:		// output, debugging
	std::ostream& put(zorba*,std::ostream&) const;

};



/*..........................................
 :          text nodes                     :
 :.........................................*/
class text_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	char rest[0];

public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}
	
public:
	text_noderep() {}
	text_noderep(zorba*,const std::string&);
	
public:		// accessors
	const char* content() const;
	std::string str() const;

public:		// XQuery interface
	string string_value() const;
	const xs_stringValue* baseuri(zorba*) const;

private:	// lock out default and copy constructors
	text_noderep(text_noderep&) {}
	~text_noderep() {}

public:		// output/debugging
	std::ostream& put(zorba*,std::ostream&) const;

};


/*..........................................
 :          content                        :
 :.........................................*/
class contentRep 
{
protected:
	sequence_type_t type;
	uint32_t length;
	char rest[0];

public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}
	
public:
	contentRep() {}
	contentRep(zorba* zorp,const std::string& s)
	:
		type(xs_string),
		length(s.length()),
		strcpy(rest,s.c_str(),length)
	{
	}
	
public:		// accessors
	const char* content() const { return rest; }
	std::string str() const { return string(rest,0,length); } 

private:	// lock out default and copy constructors
	contentRep(text_noderep&) {}
	~contentRep() {}

public:		// output/debugging
	std::ostream& put(std::ostream& os) const 
	{
		return os << str();
	}

};



// Zorba-specific node
//
class collection_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	char rest[0];

public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	collection_noderep() {}
	collection_noderep(zorba*,const std::string& uri);
	
public:
	const xs_stringValue* baseuri(zorba*) const;
	const xs_stringValue* colluri(zorba*) const;
	noderep_it children() const;

private:	// lock out default and copy constructors
	collection_noderep(const collection_noderep&) {}
	~collection_noderep() {}

public:		// output,debugging
	std::ostream& put(zorba*,std::ostream& os) const { return os; }

};



// node-like objects
//

class nsseqrep : public noderep
{
protected:
	uint32_t count;
	char rest[0];
	/*
		ns nodeid[0]
		ns nodeid[1]
		...
		ns nodeid[count-1]
	*/

public:
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:
	nsseqrep() {}
	nsseqrep(zorba*, const std::vector<itemid_t>&);

public:
	noderep_it namespaces() const;

private:	// lock out default and copy constructors
	nsseqrep(nsseqrep& qn);
	~nsseqrep() {}

public:		// output,debugging
	std::ostream& put(zorba*,std::ostream& os) const;

};


}	/* namespace xqp */
#endif /* XQP_NODEREPS_H */
