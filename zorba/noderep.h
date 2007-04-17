/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: noderep.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
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
 
#ifndef XQP_NODEREP_H
#define XQP_NODEREP_H

#include "valuerep.h"
#include "noderep_iterator.h"
#include "../types/sequence_type.h"
#include "../util/rchandle.h"

#include <vector>
#include <sys/types.h>

namespace xqp {

typedef rchandle<noderep_iterator> noderep_it;

class xs_stringValue;
class element_noderep;
class itemstore;
class qname_value;
class zorba;


class noderep : public itemrep
{
protected:
	itemref_t theRef;					// forwarding reference for update
	uint32_t  theGen;					// generation number
	nodeid_t  theID;					// node ordinal id
	nodeid_t  theParentID;		// parent node ordinal id

public:		// ctor,dtor
	noderep(
	  sequence_type_t,      	// node type
	  uint32_t length,				// length in bytes
	  itemref_t ref,					// forwarding reference
	  uint32_t gen,			 			// generation number
	  nodeid_t id,           	// ordinal node id
	  nodeid_t parent);      	// parent node id

	noderep() {}
	~noderep() {}

public:		// accessors
	itemref_t ref() const { return theRef; }
	uint32_t gen() const { return theGen; }
	nodeid_t id() const { return theID; }
	nodeid_t parentid() const { return theParentID; }

	itemref_t& ref() { return theRef; }
	uint32_t& gen() { return theGen; }
	nodeid_t& id() { return theID; }
	nodeid_t& parentid() { return theParentID; }

public:		// storage interface
	void* operator new(size_t nBytes, itemstore& istore) { return istore.alloc(nBytes); }
	void* operator new(size_t nBytes, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t nBytes, void * p) { return p; }
	void* operator new(size_t nBytes, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:		// XQuery sub-interface
	string string_value() const { return ""; } 
	const xs_stringValue* baseuri(zorba*) const { return NULL; }
	const xs_stringValue* docuri(zorba*)  const { return NULL; }

	qname_value* node_name() const { return NULL; }
	qname_value* type_name() const { return NULL; }

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
	void rewind() {}

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
	void rewind() {}

public:
	noderep* operator*() const;
	child_const_noderep_iterator& operator++();

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
		noderep* end);

	~attribute_noderep_iterator() {}

public:
 	void open() {}
	void close() {}
	noderep* next(uint32_t delta = 1) { ++(*this); return **this; }
	noderep* peek() const { return **this; }
	bool done() const { return theCurrentNodePtr >= theEndNodePtr; }
	void rewind() {}

public:
	noderep* operator*() const;
	attribute_noderep_iterator& operator++();

};


class namespace_noderep_iterator : public noderep_iterator
{
protected:
	const element_noderep* theParentNodePtr;

public:
	namespace_noderep_iterator(const element_noderep*);
	~namespace_noderep_iterator() {}

public:
 	void open() {}
	void close() {}
	noderep* next(uint32_t delta=1) { ++(*this); return **this; }
	noderep* peek() const { return **this; }
	bool done() const { return true; }
	void rewind() {}

public:
	noderep* operator*() const { return NULL; }
	namespace_noderep_iterator& operator++() { return *this; }

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
	nodeid_t theBaseuri;		// base URI
	nodeid_t theDocuri;			// document URI
	char rest[0];
	/*
    node child[0]
    ...
    node child[n-1]
	*/

public:
	document_noderep() {}
	document_noderep(zorba*, nodeid_t baseuri, nodeid_t uri);

public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
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
	nodeid_t qnameID;					// element QName
	nodeid_t namespacesID;		// in-scope namespaces
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
	element_noderep(zorba*, nodeid_t qnameid);

public:		// accessors
	qname_value& qname() const;												// element QName
	namespace_noderep* name_space_at(uint32_t) const;	// n-th namespace
	attribute_noderep* attr_at(uint32_t) const;				// n-th attribute
	noderep* node_at(uint32_t) const;									// n-th child
	uint32_t ns_count() const;												// number of namespaces
	uint32_t attr_count() const;											// number of attributes
	uint32_t child_count() const;											// number of children

public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	std::string string_value() const;
	qname_value* node_name(zorba*) const;

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
	nodeid_t qnameID;
	char rest[0];
	/*
		char[] value
	*/

public:
  attribute_noderep() {}

	attribute_noderep(
		zorba*,
		nodeid_t qname);

	attribute_noderep(
		zorba*,
		nodeid_t qname,
		const std::string& val);

public:	// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:	// XQuery sub-interface
	std::string string_value() const;
	qname_value* node_name(zorba*) const;
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
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	std::string string_value() const;
	qname_value* node_name(zorba*) const;

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
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:		// XQuery interface
	std::string string_value() const;
	const xs_stringValue* baseuri(zorba*) const;
	qname_value* node_name(zorba*) const;

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
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
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
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
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



// Zorba-specific node
//
class collection_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	char rest[0];

public:	// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
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
	void* operator new(size_t n,itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n,itemstore& i, itemref_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:
	nsseqrep() {}
	nsseqrep(zorba*, const std::vector<nodeid_t>&);

public:
	noderep_it namespaces() const;

private:	// lock out default and copy constructors
	nsseqrep(nsseqrep& qn);
	~nsseqrep() {}

public:		// output,debugging
	std::ostream& put(zorba*,std::ostream& os) const;

};



}	/* namespace xqp */
#endif /* XQP_NODES_H */
