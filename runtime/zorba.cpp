/** -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "zorba.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "store/data_manager.h"
#include "values/value_factory.h"


using namespace std;
namespace xqp {


zorba::zorba(
	rchandle<data_manager> dataManager,
	rchandle<value_factory> valueFactory,
	rchandle<static_context> staticContext,
	rchandle<dynamic_context> dynamicContext)
:
	theDataManager(dataManager),
	theValueFactory(valueFactory),
	theStaticContext(staticContext),
	theDynamicContext(dynamicContext)
{
}



}	/* namespace xqp */

