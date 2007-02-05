/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_pool.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 *
 */

#include "qname_pool.h"

#include <vector>
#include <string.h>

#define SOURCE __FILE__<<':'<<__LINE__<<"::"<<__FUNCTION__

using namespace std;
namespace xqp {


qname_pool::qname_pool(
	string const& _datapath,
	rchandle<namespace_pool> _nspool_h)
:
	datapath(_datapath),
	nspool_h(_nspool_h),
	qnamev(	_datapath+"qnamev"),
	qnheap(	_datapath+"qnheap",1<<16)
{
}


qname_pool::~qname_pool()
{
}


uint32_t qname_pool::put(
	uint32_t docid,
	QName::qname_type_t type,
	string const& qname)
{
cout << SOURCE << ": qname = " << qname << endl;
	rchandle<QName> qname_h = new QName(type,qname);
	return put(docid,qname_h);
}


uint32_t qname_pool::put(
	uint32_t docid,
	rchandle<QName> qname_h)
{
cout << SOURCE << endl;
	string prefix = qname_h->get_prefix();
cout << SOURCE << ": prefix = " << prefix << endl;
	string name = qname_h->get_name();
cout << SOURCE << ": name = " << name << endl;
	QName::qname_type_t type = qname_h->get_type();
cout << SOURCE << endl;

	off_t uri_offset;
cout << SOURCE << endl;
	uint32_t uri_id;
cout << SOURCE << endl;
	if (!nspool_h->prefix2uri(docid,prefix,uri_offset,uri_id)) {
		BAD_ARG_MACRO("Prefix '"<<prefix<<"' not found");
	}

cout << SOURCE << endl;
	uint32_t qname_id;
cout << SOURCE << endl;
	if (find(uri_id,qname_id)) return qname_id;
cout << SOURCE << endl;

	qname_id = qnamev.size();
cout << SOURCE << endl;
	uint32_t qn_offset = qnheap.put(name.c_str(),0,name.length());
cout << SOURCE << endl;
	qname_key qkey(qn_offset,uri_id,type);
cout << SOURCE << endl;
	qnamev.push_back(qkey);
cout << SOURCE << endl;
	return qname_id;
}


bool qname_pool::find(
	uint32_t uri_id,
	uint32_t& qname_id) const
{
	for (uint32_t k=0; k<qnamev.size(); ++k) {
		if (uri_id==qnamev[k].uri_id) {
			qname_id = k;
			return true;
		}
	}
	return false;
}

rchandle<QName> qname_pool::get(
	uint32_t qname_id) const
{
	if (qname_id>=qnamev.size()) {
		BAD_ARG_MACRO("Illegal qname_id: "<<qname_id);
	}
	qname_key qkey = qnamev[qname_id];
	QName::qname_type_t type = qkey.type;
	uint32_t uri_id = qkey.uri_id;
	string name = qnheap.get(qkey.qn_offset);
	string prefix;
	nspool_h->get_prefix(uri_id,prefix);
	return new QName(type,prefix,name,qname_id);
}


uint32_t qname_pool::count() const
{
	return qnamev.size();
}
 
 
} /* namespace xqp */

