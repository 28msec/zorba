/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_VISITOR_H
#define XQP_VISITOR_H

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace xqp 
{

class parsenode;

class visitor
{
public:	
	virtual ~visitor() {}

public:
	virtual void visit(parsenode const&) = 0;
	virtual void visit(exprnode const&) = 0;

};

} /* namespace xqp */
#endif /* XQP_VISITOR_H */
