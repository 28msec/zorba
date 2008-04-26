#ifndef ZORBA_NORMALIZE_VISITOR_H
#define ZORBA_NORMALIZE_VISITOR_H

#include "common/shared_types.h"

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace zorba {

  expr_t translate (const parsenode &, CompilerCB* aCompilerCB);
  
} /* namespace zorba */
#endif /* ZORBA_NORMALIZE_VISITOR_H */
