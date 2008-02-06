
#include "errors/errors.h"
#include "store/api/item.h"

using namespace std;

namespace xqp
{


/*******************************************************************************

********************************************************************************/
ZorbaAlertLocation::ZorbaAlertLocation()
{
	location_is_set = false;
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



void ZorbaError::dumpAlert(std::ostream &os)
{
//  if(err->theIsFatal)
//    cerr << "Fatal Error: ";
//  else
    os << "Error: ";

  if(theLocation.location_is_set)
  {
    if(!theLocation.filename.empty())
      os << theLocation.filename;

    os << "[line: " << theLocation.line << "][col: "
         << theLocation.column << "]: ";
  } 

  os << theDescription << std::endl;
}


void ZorbaWarning::dumpAlert(std::ostream &os)
{
  os << "Warning:";
  if(theLocation.location_is_set)
  {
    if(!theLocation.filename.empty())
      os << theLocation.filename;

    os << "[line: " << theLocation.line << "][col: "
         << theLocation.column << "]";
  } 

  os << " : " << theDescription << std::endl;
}


void ZorbaNotify::dumpAlert(std::ostream &os)
{
  os << "Notif: " << theDescription << std::endl;
}


void ZorbaAskUser::dumpAlert(std::ostream &os)
{
  ///not implemented
  os << "Ask user: " << theDescription << std::endl;
}


void ZorbaFnError::dumpAlert(std::ostream &os)
{
  os << "User Error: ";
  os << "[QName: " << theErrorQName->getStringValue() 
    << "<decoded: " << theDescription << " > ]";
  os << " : " <<  theUserDescription << endl;

	std::vector<class Item*>::const_iterator item_it;

  for ( item_it = theItems.begin( ) ; item_it != theItems.end( ) ; item_it++ )
  {
    os  << " =-= " 
          << (*item_it)->getStringValue() 
          << "  [0x" << std::hex << (void*)(*item_it) << "]" << endl;
  }
}


void ZorbaFnTrace::dumpAlert(std::ostream &os)
{
  os << "User Trace: " << theDescription << endl;

  std::vector<class Item*>::const_iterator item_it;

  for ( item_it = items_trace.begin( ) ; item_it != items_trace.end( ) ; item_it++ )
  {
    os  << " =-= " 
          << (*item_it)->getStringValue() 
          << "  [0x" << std::hex << (void*)(*item_it) << "]" << endl;
  }

}

std::ostream& operator<<(std::ostream& os, ZorbaAlert &x)
{
	x.dumpAlert(os);
	return os;
}


}
