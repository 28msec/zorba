#include "delegating_typemanager.h"

namespace zorba 
{

void DelegatingTypeManager::initSchema()
{ 
    Schema::initialize();
    _schema = new Schema(); 
}

} // namespace zorba
