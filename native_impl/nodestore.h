/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: nodestore.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_NODESTORE_H
#define XQP_NODESTORE_H

#include "../util/fxvector.h"
#include "../util/fxhashmap.h"
#include "../values/qname_value.h"
#include "../values/node_values.h"

#include <string>

namespace xqp {

#define STRING_CODE 	1
#define QNAME_CODE		2

#define ERR_BAD_CODE	-1
#define ERR_OVERRUN		-2


class context;
class item_iterator;
class node;
class nodeid;

class nodestore
{
protected:
	fxvector<unsigned char> store;		// binary data store
	fxhash64map<uint64_t> index;			// map: nodeid -> off_t

public:
	nodestore(std::string const& path);
	nodestore(nodestore const&);
	~nodestore();

public:


/*
	off_t nodestore::put(
		context & ctx,
		item_iterator & it);
*/
	

	/*...........................................
		: integers                                :
		:.........................................:
	*/
	void put( context &, uint16_t );
	int get( context &, off_t, uint16_t & );
	
	void put( context &, uint32_t ); 
	int get( context &, off_t, uint32_t & );
	
	void put( context &, uint64_t );
	int get( context &, off_t, uint64_t & );
	

	/*...........................................
		: text content                            :
		:.........................................:
	*/
	off_t put( context &, char const* content, uint32_t len );
	int get( context &, off_t, char *& data, uint32_t& len );

	off_t put( context &, string const& content ); 
	int get( context &, string & content ); 

	off_t put( context &, rchandle<text_node> );
	int get( context &, off_t, rchandle<text_node>& );

	off_t put( context &, nodeid const& parent, char const* content, uint32_t len );
	int get( context &, off_t, nodeid & parent, char *& data, uint32_t& len );

	off_t put( context &, nodeid const& parent, string const& content );


	/*...........................................
		: qname                                   :
		:.........................................:
	*/
	off_t put( context &, rchandle<QName> );
	int get( context &, off_t, rchandle<QName> & );


	/*...........................................
		: attribute node                          :
		:.........................................:
	*/
	off_t put( context &, rchandle<attribute_node> );
	int get( context &, off_t, rchandle<attribute_node> & );



};

} /* namespace xqp */
#endif /* XQP_NODE_STORE_H */

