
/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: itemid.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_ITEMID_H
#define XQP_ITEMID_H

namespace xqp {

/*_______________________________________
| Opaque item identifiers
|________________________________________*/

class qname;
class context;

class itemid
{
public:
	bool operator==(itemid& id);
	bool operator<(itemid& id);
	bool isnode() const;
	itemid parent(context*);
	qname* name(context*);
};


} /* namespace xqp */
#endif /* XQP_ITEMID_H */


