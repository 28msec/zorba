/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "compiler/indexing/value_ic.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "store/api/iterator.h"
#include "zorbaserialization/class_serializer.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(ValueIC)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIC)


/*******************************************************************************

*******************************************************************************/
void ValueIC::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theSctx;
  ar & theName;
  //ar & theICKind;
  ar & theCollectionName;
  ar & theFromCollectionName;
  ar & theToCollectionName;
  ar & thePlanWrapper;
}


/*******************************************************************************
  Check that the pathexpr 
  (a) is deterministic,
  (b) does not have any free variables,
  (c) does not reference any input functions other than dc:collection()
  (d) the arg to each dc:collection is a const qname 
*******************************************************************************/
//void ValueIC::analyze()
//{
//}



std::string ValueIC::toString()
{
  std::ostringstream os;

  os << "IC : " << theName->getStringValue()->c_str() << " " << 
    (theICKind==store::IC::ic_collection) << " ";
  
  switch( theICKind )
  {
  case store::IC::ic_collection:
    os << "Coll: " << theCollectionName->getStringValue()->c_str();
    break;
  
  case store::IC::ic_foreignkey:
    os << "ToColl: " << theToCollectionName->getStringValue()->c_str() << 
      " FromColl: " << theFromCollectionName->getStringValue()->c_str() ;
      }

  os << std::endl;
  
  return os.str();
}


/*******************************************************************************
********************************************************************************/
bool ICCheckerImpl::check(const store::Item* collName)
{
  store::Iterator_t activeICNames = theDctx->listActiveICNames();

  store::Item_t activeICName;
  activeICNames->open();

  while ( activeICNames->next(activeICName) )
  {
    store::IC* ic = theDctx->getIC(activeICName);
  
    if ( ic == NULL ) 
    {
      // if icname in activelist but not available something went wrong
      ZORBA_ASSERT(false);
    }

    store::Item_t icCollName;
    switch ( ic->getICKind() )
    {
    case store::IC::ic_collection:
      icCollName = ic->getCollectionName();
      break;

    case store::IC::ic_foreignkey:
      icCollName = ic->getToCollectionName();
      break;

    default:
      ZORBA_ASSERT(false);
    }

    if ( !collName->equals(icCollName) )
      // if this ic doesn't have a dependency on current collection
      // skip it
      continue;

    std::cout << "ic check : " << ic->getICName()->getLocalName()->str() <<
      "@" << ic->getICName()->getNamespace()->str() << 
      "  coll: " << collName->getLocalName()->str() << " @ " << 
      collName->getNamespace()->str() << std::endl; std::cout.flush(); 

    ValueIC* vic = theSctx->lookup_ic(activeICName);

    store::Item_t partialRes;
    store::Iterator* iter = vic->getIterator();
  
    iter->open();
    iter->next(partialRes);
    iter->close(); 
  
    if( !partialRes->getBooleanValue() )
      return false;
  }

  activeICNames->close();
  
  return true;
}

}
/* vim:set ts=2 sw=2: */
