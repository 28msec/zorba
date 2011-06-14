#include <string>
#include <string.h>
#include "../../src/store/naive/ordpath.h"

int ordpath_big (int argc, char* argv[])
{
  std::string lOrdStr1 = "5f05f84c";
  std::string lOrdStr2 = "5f05f84d";

  zorba::simplestore::OrdPath lOrdPath1((const unsigned char*) lOrdStr1.c_str(),
                                        lOrdStr1.length());

  zorba::simplestore::OrdPath lOrdPath2((const unsigned char*) lOrdStr2.c_str(),
                                        lOrdStr2.length());

  zorba::simplestore::OrdPath lOrdPath3; 

  for (int i = 0 ; i < 100000 ; ++i) 
  {
    zorba::simplestore::OrdPath::insertBefore(lOrdPath1, lOrdPath2, lOrdPath3);
    if (i % 1000 == 0)
      std::cout << "Ordpath Nr " << i << " : " << lOrdPath3.serialize() << std::endl;
    lOrdPath2 = lOrdPath3;
  }  

  return 0;
}
/* vim:set et sw=2 ts=2: */
