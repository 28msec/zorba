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
    XQuery_t lQuery = lZorba->compileQuery("declare function local:test() { fn:error() }; local:test()");                                  
                                                                                   
    std::cout << lQuery << std::endl;                                              
  }                                                                                
  catch (ZorbaException& e) {                                                      
    std::cerr << ZorbaException::STACKTRACE_YES 
              << ZorbaException::FORMAT_XML 
              << e 
              << std::endl;                            
  }                                                                                
                                                                                   
  return 0;                                                                        
};
