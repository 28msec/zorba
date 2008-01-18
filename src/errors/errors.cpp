
#include "errors/errors.h"
#include "store/api/item.h"

namespace xqp
{


/*******************************************************************************

********************************************************************************/
ZorbaAlertLocation::ZorbaAlertLocation()
{
	filename = "";
	line = 0;
	column = 0;
}


/*******************************************************************************

********************************************************************************/
ZorbaAlert::~ZorbaAlert() {}

ZorbaError::~ZorbaError() {}

ZorbaWarning::~ZorbaWarning() {}

ZorbaNotify::~ZorbaNotify() {}

ZorbaAskUser::~ZorbaAskUser() {}

ZorbaFnError::~ZorbaFnError() {}

ZorbaFnTrace::~ZorbaFnTrace() {}

}
