#include <iostream>                                                                
                                                                                   
#include <zorba/zorba.h>                                                           
#include <zorba/store_manager.h>                                                   
#include <zorba/serializer.h>                                                      
#include <zorba/singleton_item_sequence.h>                                         
#include <zorba/zorba_exception.h>                                                 
                                                                                   
using namespace zorba;                                                             
                                                                                   
int main()                                                                         
{                                                                                  
  void* lStore = StoreManager::getStore();                                         
  Zorba *lZorba = Zorba::getInstance(lStore);                                      
                                                                                   
  try {                                                                            
    XQuery_t lQuery = lZorba->compileQuery("1+");                                  
                                                                                   
    std::cout << lQuery << std::endl;                                              
  }                                                                                
  catch (ZorbaException& e) {                                                      
    std::cerr << ZorbaException::XML << e << std::endl;                            
  }                                                                                
                                                                                   
  return 0;                                                                        
};
