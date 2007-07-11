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

#include <string>
#include <vector>
#include <sys/types.h>

namespace xqp {

typedef rchandle<noderep_iterator> noderep_it;

class element_noderep;
class qname;
class zorba;


class noderep : public itemRep
{
protected:
	off_t theRef;							// forwarding reference for update
	uint32_t  theGen;					// generation number
	itemid_t  theID;					// node ordinal id
	itemid_t  theParentID;		// parent node ordinal id

public:		// ctor,dtor
	noderep(
	  sequence_type_t,      	// node type
	  uint32_t length,				// length in bytes
	  off_t ref,							// forwarding reference
	  uint32_t gen,			 			// generation number
	  itemid_t id,           	// ordinal node id
	  itemid_t parent);      	// parent node id

	noderep() {}
	~noderep() {}

public:		// accessors
	off_t ref() const { return theRef; }
	uint32_t gen() const { return theGen; }
	itemid_t id() const { return theID; }
	itemid_t parentid() const { return theParentID; }

	off_t& ref() { return theRef; }
	uint32_t& gen() { return theGen; }
	itemid_t& id() { return theID; }
	itemid_t& parentid() { return theParentID; }

public:		// storage interface
	void* operator new(size_t nBytes, void* p) { return p; }
	void* operator new(size_t nBytes, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

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
	itemid_t theBaseUriID;
	itemid_t theDocUriID;
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
	itemid_t baseuri() const { return theBaseUriID; }
	itemid_t docuri() const { return theDocUriID; }
	noderep_it children() const;

private:	// ctor,dtor
	document_noderep(document_noderep& other) : noderep (other) {}
	~document_noderep() {}

public:		// output and debugging
	std::ostream& put(zorba*,std::ostream&) const;
	std::string str(zorba*) const;

};



/*..........................................
 :  element nodes                          :
 :.........................................*/

class element_noderep : public noderep
{
	friend class child_noderep_iterator;
	friend class attribute_noderep_iterator;

protected:
	itemid_t theQNameID;			// element QName
	itemid_t theTypeID;				// type QName
	itemid_t theNSID;					// in-scope namespaces
	uint32_t theNodeOffset;		// offset to first node
	char rest[0];
	/*
    attr[0]
    ...
    attr[m-1]
    node[0]      <- theNodeOffset
    ...
    node[n-1]
	*/

public:
	element_noderep() {}
	element_noderep(zorba*, itemid_t qnameid);

public:		// accessors
	itemid_t qnameID() const { return theQNameID; }
	itemid_t typeID() const { return theTypeID; }
	itemid_t nsID() const { return theNSID; }

public:		// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	noderep_it attributes() const;
	noderep_it children() const;

private:	//ctor,dtor - lock out
	element_noderep(const element_noderep& other) : noderep () {}
	~element_noderep() {}

public:		// output and debugging
	std::ostream& put(zorba*,std::ostream&) const;
	std::string str(zorba*) const;

};


/*..........................................
 :  attribute nodes                        :
 :.........................................*/

class attribute_noderep :	public noderep
{
	friend class child_noderep_iterator;

protected:
	itemid_t theQNameID;
	char rest[0];
	/*
		contentRep
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
	itemid_t qnameID() const { return theQNameID; }

private:	//ctor,dtor - lock out
	attribute_noderep(attribute_noderep&);
  ~attribute_noderep();

public:		// output,debugging
	std::ostream& put(zorba*,std::ostream&) const;
	std::string str(zorba*) const;

};


/*..........................................
 :          namespace nodes                :
 :.........................................*/

class namespace_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	nskey_t  theNsid;
	uint32_t theURIOffset;
	char rest[0];
	/*
		contentRep prefix
		contentRep uri  
	*/

public:
	namespace_noderep() {}

	namespace_noderep(
		zorba*,
		const std::string& prefix,
		const std::string& uri);

public:		// storage interface
	nskey_t& nsid() { return theNsid; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	std::string prefix() const;
	std::string uri() const;

private:	//ctor,dtor - lock out
	namespace_noderep(namespace_noderep& other) : noderep (other) {}
	~namespace_noderep() {}

public:		// output, debugging
	std::ostream& put(zorba*,std::ostream&) const;
	std::string str(zorba*) const;

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
		contentRep target
		contentRep content
	*/

public:
	pi_noderep() {}
	pi_noderep(zorba*);

public:		// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// XQuery sub-interface
	std::string content() const;
	std::string target() const;

private:	//ctor,dtor - lock out
	pi_noderep(pi_noderep& other) : noderep (other) {}
	~pi_noderep() {}

public:		// output, debugging
	std::ostream& put(zorba*,std::ostream&) const;
	std::string str(zorba*) const;

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
		contentRep content
	*/

public:
	comment_noderep(zorba*);
	comment_noderep() {}
	
public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void operator delete(void*) {}

public:		// XQuery sub-interface
	std::string content() const;

private:	// lock out default and copy constructors
	comment_noderep(comment_noderep& other) : noderep (other) {}
	~comment_noderep() {}

public:		// output, debugging
	std::ostream& put(zorba*,std::ostream&) const;
	std::string str(zorba*) const;

};



/*..........................................
 :          text nodes                     :
 :.........................................*/
class text_noderep : public noderep
{
	friend class child_noderep_iterator;

protected:
	char rest[0];
	/*
		contentRep content
	*/

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

public:		// XQuery interface
	std::string baseuri(zorba*) const;

private:	// lock out default and copy constructors
	text_noderep(text_noderep& other) : noderep (other) {}
	~text_noderep() {}

public:		// output/debugging
	std::ostream& put(zorba*,std::ostream&) const;
	std::string str(zorba*) const;

};


/*..........................................
 :          content                        :
 :.........................................*/
class contentRep : public itemRep
{
protected:
	char rest[0];

public:	// storage interface
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}
	
public:
	contentRep() {}
	contentRep(zorba* zorp,const std::string& s)
	: itemRep(xs_string,s.length())
	{
		strncpy(rest,s.c_str(),s.length());
	}
	
public:		// accessors
	const char* content() const { return rest; }
	std::string str() const { return string(rest,0,theLength); } 

private:	// lock out default and copy constructors
	contentRep(text_noderep&) {}
	~contentRep() {}

public:		// output/debugging
	std::ostream& put(zorba* zorp, std::ostream& os) const 
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
	std::string baseuri(zorba*) const;
	std::string colluri(zorba*) const;
	noderep_it children() const;

private:	// lock out default and copy constructors
	collection_noderep(const collection_noderep& other) : noderep () {}
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
