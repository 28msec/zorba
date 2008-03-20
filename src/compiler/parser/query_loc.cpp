#include <ostream>
#include "compiler/parser/query_loc.h"

namespace zorba {
QueryLoc QueryLoc::null;

QueryLoc::QueryLoc()
 : theFilenameBegin (""),
   theLineBegin (0),
   theColumnBegin (0),
   theFilenameEnd (""),
   theLineEnd (0),
   theColumnEnd (0)
{}

QueryLoc::QueryLoc(const QueryLoc& aQueryLoc) 
 : theFilenameBegin (aQueryLoc.theFilenameBegin),
   theLineBegin (aQueryLoc.theLineBegin),
   theColumnBegin (aQueryLoc.theColumnBegin),
   theFilenameEnd (aQueryLoc.theFilenameEnd),
   theLineEnd (aQueryLoc.theLineEnd),
   theColumnEnd (aQueryLoc.theColumnEnd)
{}

std::ostream& operator<< (std::ostream& aOstr, const QueryLoc& aQueryLoc) {
  if ( !aQueryLoc.getFilenameBegin().empty() ) {
    std::string lStr = aQueryLoc.getFilenameBegin();
    aOstr << lStr << ":";
  }
  aOstr << aQueryLoc.getLineBegin() << "." << aQueryLoc.getColumnBegin();

  return aOstr;
}

} // namespace zorba
