/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: store.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_STORE_H
#define XQP_STORE_H

#include "context/common.h"
#include <string>

namespace xqp {

class context;
class itemid;
class node;
class noderep;
class update_value;
class xs_stringValue;
class document_node;

class store : public rcobject
{
protected:
	const context* theContext;

public:		// context-specific
	iterator_t collection(const std::string&);
	iterator_t document(const std::string&);

	bool add_document(const std::string&, const document_node&);
	bool remove_document(const std::string&);

	bool add_collection(const std::string&, iterator_t);
	bool remove_collection(const std::string&);
	bool append_to_collection(const std::string&, iterator_t);

public:		// index interface
	noderep* get_noderep(itemid_t) const;

public:
	void apply(const update_value*);

	node* get_node(const itemid&);
	xs_stringValue* get_uri(const itemid&);

	node* get_node(itemid_t);
	xs_stringValue* get_uri(itemid_t);

};


} /* namespace xqp */
#endif /* XQP_STORE_H */

