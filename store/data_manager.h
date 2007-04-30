/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: data_manager.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_DATA_MANAGER_H
#define XQP_DATA_MANAGER_H

#include "context/common.h"
#include <string>

namespace xqp {

class context;
class itemid;
class node;
class qname;
class noderep;
class update_value;
class xs_stringValue;
class document_node;

class data_manager: public rcobject
{
public:	
	virtual iterator_t collection(const std::string&) = 0;
	virtual iterator_t document(const std::string&) = 0;

	virtual bool add_document(const std::string&, const document_node&) = 0;
	virtual bool remove_document(const std::string&) = 0;

	virtual bool add_collection(const std::string&, iterator_t) = 0;
	virtual bool remove_collection(const std::string&) = 0;
	virtual bool append_to_collection(const std::string&, iterator_t) = 0;

	virtual void apply(const update_value*) = 0;

	// value index
	virtual node* get_node(itemid_t) = 0;
	virtual xs_stringValue* get_uri(itemid_t) = 0;
	virtual qname* get_qname(itemid_t) = 0;

};


} /* namespace xqp */
#endif /* XQP_DATA_MANAGER_H */

