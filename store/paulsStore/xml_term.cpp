/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: xml_term.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *	Author: John Cowan, Paul Pedersen
 *
 */

#include "xml_term.h"
#include <iostream>

using namespace std;
namespace xqp {

string xml_term::to_string() const
{
  ostringstream oss;
  oss <<'['<<term<<"("<<uri<<"):"<<pos<<']';
  return oss.str();
}

}	/* namespace xqp */

