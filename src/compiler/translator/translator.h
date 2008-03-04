/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: translator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_NORMALIZE_VISITOR_H
#define XQP_NORMALIZE_VISITOR_H

#include <vector>
#include "common/shared_types.h"

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace zorba {

  expr_t translate (bool, static_context *, const parsenode &, std::vector<rchandle<static_context> > &);
  
} /* namespace zorba */
#endif /* XQP_NORMALIZE_VISITOR_H */
