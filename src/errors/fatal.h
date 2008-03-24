
#ifndef ZORBA_FATAL_H
#define ZORBA_FATAL_H

#include <iostream>
#include <stdlib.h>

namespace zorba
{

#ifdef WINCE
#define   abort()     exit(1)
#endif

#define ZORBA_FATAL(cond, msg)                                       \
do                                                                   \
{                                                                    \
  if (!(cond))                                                       \
  {                                                                  \
    std::cerr << "Zorba Internal Fatal Error in " << __FILE__ << ":" \
              << __LINE__ << std::endl << msg << std::endl;          \
    abort();                                                         \
  }                                                                  \
} while (0)


}

#endif
