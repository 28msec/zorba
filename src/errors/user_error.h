
#ifndef ZORBA_ERRORS_AND_TRACES_GENERATED_BY_USER_30_OCT_2007
#define ZORBA_ERRORS_AND_TRACES_GENERATED_BY_USER_30_OCT_2007

#include <vector>

namespace xqp{

class Item;

void fn_user_error (Item* err_qname,///optional
                    const std::string description,//optional
                    const std::vector<class Item*> *items);//optional

void fn_user_trace ( const std::vector<class Item*> *items,
                     const std::string label);


}///end namespace xqp

#endif

